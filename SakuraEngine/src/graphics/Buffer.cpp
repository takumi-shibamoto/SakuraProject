#include "skrpch.h"
#include "Buffer.h"

#include "platform/OpenGL/OpenGLBuffer.h"

namespace SKR {

	VertexBuffer* VertexBuffer::Create(float* vertices, size_t size)
	{
		return new OpenGLVertexBuffer(vertices, size);
	}

	//IndexBuffer* IndexBuffer::Create()
	//{

	//}

}