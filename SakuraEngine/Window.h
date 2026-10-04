#pragma once

#include "core/Core.h"
#include "event/Event.h"

#include <string>

namespace sakura {

	/// <summary>
	/// Structure that contains window properties
	/// </summary>
	struct WindowProps
	{
		std::string title;
		unsigned int width, height;

		/// <summary>
		/// Constructor for the window prperties
		/// </summary>
		/// <param name="windowTitle">Title of the window to set. Default value is Sakura Engine</param>
		/// <param name="windowWidth">Width of the window to set. Default value is 1280</param>
		/// <param name="windowHeight">Height of the window to set. Default value is 720</param>
		WindowProps(std::string windowTitle = "Sakura Engine", 
			        unsigned int windowWidth = 1280, 
			        unsigned int windowHeight = 720)
			: title{ windowTitle }, width{ windowWidth }, height{ windowHeight } {}
	};

	/// <summary>
	/// Interface for a desktop based window.
	/// </summary>
	class SKR_API Window
	{
	public:
		// Using function object as an event callback function.
		using EventCallbackFn = std::function<void(Event&)>;

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~Window() {}

		/// <summary>
		/// Called every frame for the window to update.
		/// </summary>
		virtual void OnUpdate() = 0;

		/// <summary>
		/// Get the width of the window.
		/// </summary>
		/// <returns>Unsigned integer that represents the window width.</returns>
		virtual unsigned int GetWidth() const = 0;

		/// <summary>
		/// Get the height of the window.
		/// </summary>
		/// <returns>Unsigned integer that represents the window height.</returns>
		virtual unsigned int GetHeight() const = 0;

		/// <summary>
		/// Register a function that will be called when an event occur.
		/// </summary>
		/// <param name="callback">The event callback function to set.</param>
		virtual void SetEventCallback(EventCallbackFn const& callback) = 0;

		/// <summary>
		/// Check if the window is in VSync mode.
		/// </summary>
		/// <returns>Boolean value that represents if the window is in VSync mode or not.</returns>
		virtual bool IsVSync() const = 0;

		/// <summary>
		/// Set the VSync mode
		/// </summary>
		/// <param name="sync">Boolean value to set the mode to.</param>
		virtual void SetVSync(bool sync) = 0;

		/// <summary>
		/// Create the window with the given properties.
		/// </summary>
		/// <param name="props">property of the window to create.</param>
		/// <returns>Heap allocated pointer of the window.</returns>
		static Window* Create(const WindowProps& props = WindowProps{});
	};

}