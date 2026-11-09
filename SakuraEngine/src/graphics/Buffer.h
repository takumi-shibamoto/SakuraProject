#pragma once

namespace SKR {
	
	class VertexBuffer
	{
	public:
		static VertexBuffer* Create(float* vertices, uint32_t size);
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;
	};

	class IndexBuffer
	{
	public:
		static IndexBuffer* Create(uint32_t* indices, uint32_t count);
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual uint32_t GetCount() const = 0;
	};

}