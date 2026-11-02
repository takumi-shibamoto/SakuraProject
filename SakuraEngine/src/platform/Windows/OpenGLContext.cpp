#include "skrpch.h"

#include "OpenGLContext.h"
#include "core/Core.h"
#include "logging/Log.h"

#include <glad/glad.h>

namespace SKR {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: window{ windowHandle }
	{
		SKR_CORE_ASSERT(window, "Couldn't get the window.");
	}

	void OpenGLContext::Init()
	{
		// Set the current context to the window created.
		glfwMakeContextCurrent(window);

		// Initialize Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SKR_CORE_ASSERT(status, "Failed to initialize Glad.")
	}

	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(window);
	}

}