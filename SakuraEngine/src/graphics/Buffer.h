#pragma once

#include "core/Core.h"
#include "logging/Log.h"

namespace SKR {

	enum class ShaderDataType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	static uint32_t GetDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Float:		return 4;
			case ShaderDataType::Float2:	return 4 * 2;
			case ShaderDataType::Float3:	return 4 * 3;
			case ShaderDataType::Float4:	return 4 * 4;
			case ShaderDataType::Mat3:		return 4 * 3 * 3;
			case ShaderDataType::Mat4:		return 4 * 4 * 4;
			case ShaderDataType::Int:		return 4;
			case ShaderDataType::Int2:		return 4 * 2;
			case ShaderDataType::Int3:		return 4 * 3;
			case ShaderDataType::Int4:		return 4 * 4;
			case ShaderDataType::Bool:		return 1;
		}

		SKR_CORE_ASSERT(false, "Shader Data Type not recognized!");
		return 0;
	}

	struct BufferElement
	{
		std::string name;
		uint32_t size;
		uint32_t offset;
		ShaderDataType type;

		BufferElement(std::string const& elementName, ShaderDataType elementType)
			: name{ elementName }, size{ GetDataTypeSize(elementType) }, offset{}, type{ elementType } {}
	};

	class BufferLayout
	{
	public:
		BufferLayout(std::initializer_list<BufferElement> const& elements)
			: bufferElements{elements}, stride{}
		{
			CalculateOffsetsAndStride();
		}

		inline std::vector<BufferElement>& GetBufferElements() { return bufferElements; }
		inline uint32_t GetStride() const { return stride; }

	private:
		void CalculateOffsetsAndStride()
		{
			uint32_t offset{};
			for (BufferElement& element : bufferElements)
			{
				element.offset = offset;
				offset += element.size;
				stride += element.size;
			}
		}
	
	private:
		std::vector<BufferElement> bufferElements;
		uint32_t stride;
	};
	
	/// <summary>
	/// Vertex buffer base class
	/// </summary>
	class VertexBuffer
	{
	public:
		/// <summary>
		/// Create an instance of the vertex buffer.
		/// </summary>
		/// <param name="vertices">pointer to the first element of the vertex data</param>
		/// <param name="size">size of the vertex data in bytes</param>
		/// <returns>pointer to the created vertex buffer</returns>
		static VertexBuffer* Create(float* vertices, uint32_t size);

		/// <summary>
		/// Default destructor.
		/// </summary>
		virtual ~VertexBuffer() = default;

		/// <summary>
		/// Bind the vertex buffer.
		/// </summary>
		virtual void Bind() = 0;

		/// <summary>
		/// Unbind the vertex buffer.
		/// </summary>
		virtual void UnBind() = 0;
	};

	/// <summary>
	/// Index Buffer base class.
	/// </summary>
	class IndexBuffer
	{
	public:
		/// <summary>
		/// Create an instance of the index buffer.
		/// </summary>
		/// <param name="indices">Pointer to the first element of the index data</param>
		/// <param name="count">Number of indices</param>
		/// <returns>pointer to the created index buffer</returns>
		static IndexBuffer* Create(uint32_t* indices, uint32_t count);

		/// <summary>
		/// Default destructor.
		/// </summary>
		virtual ~IndexBuffer() = default;

		/// <summary>
		/// Bind the index buffer.
		/// </summary>
		virtual void Bind() = 0;

		/// <summary>
		/// Unbind the index buffer.
		/// </summary>
		virtual void UnBind() = 0;

		/// <summary>
		/// Get the index count of the index buffer.
		/// </summary>
		/// <returns>unsigned integer representing the number of indices</returns>
		virtual uint32_t GetCount() const = 0;
	};

}