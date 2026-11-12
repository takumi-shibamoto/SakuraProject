#pragma once

#include "graphics/Buffer.h"

#include <cstdint>

namespace SKR {

	/// <summary>
	/// OpenGL implementation of the vertex buffer.
	/// </summary>
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		/// <summary>
		/// Constructor. Create an instance of the OpenGL vertex buffer.
		/// </summary>
		/// <param name="vertices">Pointer to the first element of the vertex data</param>
		/// <param name="size">Size of the vertex data in bytes</param>
		OpenGLVertexBuffer(float* vertices, uint32_t size);

		/// <summary>
		/// Destructor. Delete the OpenGL vertex buffer.
		/// </summary>
		~OpenGLVertexBuffer();

		/// <summary>
		/// Bind the vertex buffer.
		/// </summary>
		void Bind() override;

		/// <summary>
		/// Unbind the vertex buffer.
		/// </summary>
		void UnBind() override;

	private:
		// The OpenGL vertex buffer object (VBO) identifier.
		uint32_t VBO;
	};

	/// <summary>
	/// OpenGL implementation of the index buffer.
	/// </summary>
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		/// <summary>
		/// Constructor. Create an instance of the OpenGL index buffer.
		/// </summary>
		/// <param name="indices">Pointer to the first element of the index data</param>
		/// <param name="count">Number of indices</param>
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);

		/// <summary>
		/// Destructor. Delete the OpenGL index buffer.
		/// </summary>
		~OpenGLIndexBuffer();

		/// <summary>
		/// Bind the index buffer.
		/// </summary>
		void Bind() override;

		/// <summary>
		/// Unbind the index buffer.
		/// </summary>
		void UnBind() override;

		/// <summary>
		/// Get the index count of the index buffer.
		/// </summary>
		/// <returns>Unsigned 32-bit integer representing the number of indices</returns>
		inline uint32_t GetCount() const override { return count; }

	private:
		// The OpenGL index buffer object (IBO) identifier.
		uint32_t IBO;
		// The number of indices in the index buffer.
		uint32_t count;
	};

}