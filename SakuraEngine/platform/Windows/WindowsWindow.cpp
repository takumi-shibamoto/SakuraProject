#include "skrpch.h"
#include "logging/Log.h"
#include "WindowsWindow.h"

namespace SKR {

	// Static variable to check if the glfw window has been initialized or not.
	static bool glfwInitialized = false;

	Window* Window::Create(WindowProps const& prop)
	{
		// Create a dynamically alocated window pointer.
		return new WindowsWindow(prop);
	}

	WindowsWindow::WindowsWindow(WindowProps const& prop)
	{
		Init(prop);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		data.vSync = enabled;

		// If vsync is enabled, swap the buffer once after the screen refreshes
		enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);
	}

	void WindowsWindow::Init(WindowProps const& prop)
	{
		// Set the data from the windows properties given.
		data.title = prop.title;
		data.width = prop.width;
		data.height = prop.height;

		// Log the window initialization.
		SKR_CORE_INFO("Window Initializing : title = {0}, size = {1} x {2}", data.title, data.width, data.height);

		// Check if the window has not been initialized.
		if (!glfwInitialized)
		{
			// Set the GLFW version to 4.1
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

			// Set the opengl profile to core profile so that old functions are not being used.
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			// Call the glfw Init function.
			int success = glfwInit();

			// Check if glfw was initialized successfully.
			SKR_CORE_ASSERT(success, "Could not initialize GLFW.");

			glfwInitialized = true;
		}

		// Create the window and set the window pointer.
		window = glfwCreateWindow(prop.width, prop.height, prop.title.c_str(), NULL, NULL);

		// Set the current context to the window created.
		glfwMakeContextCurrent(window);

		// Set the window data to the user data of glfw so that the event callback funciton can be used.
		glfwSetWindowUserPointer(window, &data);

		// Set the vsync to be true by default.
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}
}