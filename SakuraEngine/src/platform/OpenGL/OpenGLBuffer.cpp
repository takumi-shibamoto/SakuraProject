#include "skrpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace SKR {

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		//Generate the vertex buffer object
		glGenBuffers(1, &VBO);

		//Bind the buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//Copy the vertex data into the buffer's memory.
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &VBO);
	}

	void OpenGLVertexBuffer::Bind()
	{
		//Bind the buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	}

	void OpenGLVertexBuffer::UnBind()
	{
		//Unbind VBO
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t indexCount)
		: count{ indexCount }
	{
		//Generate the index buffer object
		glGenBuffers(1, &IBO);

		//Bind the buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		//Copy the index data into the buffer's memory.
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &IBO);
	}

	void OpenGLIndexBuffer::Bind()
	{
		//Bind the buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	}

	void OpenGLIndexBuffer::UnBind()
	{
		//Unbind VBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}