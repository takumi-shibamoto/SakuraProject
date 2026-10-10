#include "skrpch.h"
#include "logging/Log.h"
#include "WindowsWindow.h"

#include "event/ApplicationEvent.h"
#include "event/KeyEvent.h"
#include "event/WindowEvent.h"
#include "event/MouseEvent.h"

namespace SKR {

	/// <summary>
	/// Error callback function that prints the error message.
	/// </summary>
	/// <param name="error">error number</param>
	/// <param name="description">description of the error.</param>
	static void GLFWErrorCallback(int error, const char* description)
	{
		SKR_CORE_ERROR("GLFW Error ({0}) : {1}", error, description);
	}

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

			// Set the error callback so that the error can be logged.
			glfwSetErrorCallback(GLFWErrorCallback);

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

		// Set the GLFW event callbacks
		// Window close callback
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
			{
				// Get the user window data from the user pointer.
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				// Create an instance of the window close event class.
				WindowCloseEvent closeEvent{};

				// Call the event callback function with the instance.
				data.eventCallback(closeEvent);
			});

		// Window size callback
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				// Set the window width and height to the data.
				data.width = width;
				data.height = height;

				WindowResizeEvent resizeEvent{ width, height };
				data.eventCallback(resizeEvent);
			});

		// Window focus callback
		glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				
				// Check if the window has focused or lost focus.
				if (focused)
				{
					WindowFocusEvent focusEvent{};
					data.eventCallback(focusEvent);
				}
				else
				{
					WindowLostFocusEvent lostFocusEvent{};
					data.eventCallback(lostFocusEvent);
				}
			});

		// Window moved callback
		glfwSetWindowPosCallback(window, [](GLFWwindow* window, int xPos, int yPos)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				WindowMovedEvent movedEvent{ xPos, yPos };
				data.eventCallback(movedEvent);
			});

		// Key callback
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				// Check if the action is pressed, released, or repeat.
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent pressedEvent{ key, 0 };
						data.eventCallback(pressedEvent);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent releasedEvent{ key };
						data.eventCallback(releasedEvent);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent pressedEvent{ key, 1 };
						data.eventCallback(pressedEvent);
						break;
					}
				}
			});

		// Mouse Button callback
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_RELEASE)
				{
					MouseButtonReleasedEvent releasedEvent{ button };
					data.eventCallback(releasedEvent);
				}
				else
				{
					MouseButtonPressedEvent pressedEvent{ button };
					data.eventCallback(pressedEvent);
				}
			});

		// Mouse moved callback
		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseMovedEvent movedEvent{ xPos, yPos };
				data.eventCallback(movedEvent);
			});

		// Mouse scrolled event
		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseScrollEvent scrollEvent{ xOffset, yOffset };
				data.eventCallback(scrollEvent);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}
}