#pragma once

#include "Window.h"
#include <GLFW/glfw3.h>

namespace sakura {

	class SKR_API WindowsWindow : public Window
	{
	public:
		/// <summary>
		/// Constructor for the window.
		/// </summary>
		WindowsWindow(WindowProps const& props);

		/// <summary>
		/// Destructor for the window.
		/// </summary>
		virtual ~WindowsWindow();

		/// <summary>
		/// Called every time the window is updated.
		/// </summary>
		void OnUpdate() override;

		/// <summary>
		/// Get the width of the window
		/// </summary>
		/// <returns>unsigned int that represents the width of the window.</returns>
		inline unsigned int GetWidth() const override { return data.width; }

		/// <summary>
		/// Get the height of the window
		/// </summary>
		/// <returns>unsigned int that represents the height of the window.</returns>
		inline unsigned int GetHeight() const override { return data.height; }

		/// <summary>
		/// Set the event callback function to the window data.
		/// </summary>
		/// <param name="callbackFn">The event callback function to set.</param>
		inline void SetEventCallback(EventCallbackFn const& callbackFn) override { data.eventCallback = callbackFn; }

		/// <summary>
		/// Check if the window is in VSync mode.
		/// </summary>
		/// <returns>Boolean value that represents if the window is in VSync mode.</returns>
		inline bool IsVSync() const override { return data.vSync; }

		/// <summary>
		/// SEt the VSync mode of the window.
		/// </summary>
		/// <param name="enabled">The value to set the VSync mode.</param>
		void SetVSync(bool enabled) override;

	private:
		void Init(WindowProps const& props);
		void Shutdown();

	private:
		// Pointer to the glfw window.
		GLFWwindow* window;

		/// <summary>
		/// Structure to contain all the window data. Mainly for event callback.
		/// </summary>
		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};

}