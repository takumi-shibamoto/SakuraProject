#pragma once

namespace SKR {
	
	class VertexBuffer
	{
	public:
		static VertexBuffer* Create(float* vertices, size_t size);
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;
	};

	//class IndexBuffer
	//{
	//	static IndexBuffer* Create();
	//	virtual ~IndexBuffer() = default;

	//	virtual void Bind() = 0;
	//	virtual void UnBind() = 0;
	//};

}