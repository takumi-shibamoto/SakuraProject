#pragma once

#include "graphics/Buffer.h"

#include <cstdint>

namespace SKR {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, size_t size);
		~OpenGLVertexBuffer();

		void Bind() override;
		void UnBind() override;

	private:
		uint32_t VBO;
	};

	//class OpenGLIndexBuffer : public IndexBuffer
	//{

	//};

}