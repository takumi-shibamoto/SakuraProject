#include "skrpch.h"
#include "Buffer.h"

#include "platform/OpenGL/OpenGLBuffer.h"

namespace SKR {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		return new OpenGLVertexBuffer(vertices, size);
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		return new OpenGLIndexBuffer(indices, count);
	}

}