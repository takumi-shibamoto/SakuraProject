#pragma once
#include "Event.h"

#include <sstream>

namespace sakura {

	/// <summary>
	/// Event that occur when the window is closed.
	/// </summary>
	class SKR_API WindowCloseEvent : public Event
	{
	public:
		// Set the event type to WindowClose
		EVENT_CLASS_TYPE(WindowClose);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};


	class SKR_API WindowResizeEvent : public Event
	{
	public:
		/// <summary>
		/// Constructor of the WindowResizeEvent.
		/// </summary>
		/// <param name="winWidth">Width of the window after resize.</param>
		/// <param name="winHeight">Height of the window after resize.</param>
		WindowResizeEvent(int winWidth, int winHeight)
			: width{ winWidth }, height{ winHeight } {}

		// Set the event type to WindowResize
		EVENT_CLASS_TYPE(WindowResize);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCaegoryApplicaiton);

		/// <summary>
		/// Formatted string of the event for debug use.
		/// </summary>
		/// <returns>String that includes the event name and the width and heigh of the window.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Resize Event : (" << width << ", " << height << ")";
			return ss.str();
		}

		/// <summary>
		/// Get the width of the window.
		/// </summary>
		/// <returns>Integer that represents the width of the window.</returns>
		inline int GetWidth() const { return width; }

		/// <summary>
		/// Get the height of the window.
		/// </summary>
		/// <returns>INteger that represents the height of the window.</returns>
		inline int GetHeight() const { return height; }

	private:
		// Width and Height of the window.
		int width, height;
	};

	/// <summary>
	/// Event that occur when the window became focused
	/// </summary>
	class SKR_API WindowFocusEvent : public Event
	{
	public:
		// Set the event type to WindowFocus
		EVENT_CLASS_TYPE(WindowFocus);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};


	/// <summary>
	/// Event that occur when the window became focused
	/// </summary>
	class SKR_API WindowLostFocusEvent : public Event
	{
	public:
		// Set the event type to WindowFocus
		EVENT_CLASS_TYPE(WindowLostFocus);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/// <summary>
	/// Event that occur when the window is moved
	/// </summary>
	class SKR_API WindowMovedEvent : public Event
	{
	public:
		/// <summary>
		/// Constructor of the Window Moved Event
		/// </summary>
		/// <param name="x">x position of the window</param>
		/// <param name="y">y position of the window</param>
		WindowMovedEvent(int x, int y)
			: xPos{ x }, yPos{ y } {}

		// Set the event type to WindowResize
		EVENT_CLASS_TYPE(WindowMoved);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCaegoryApplicaiton);

		/// <summary>
		/// Formatted string of the event for debug use.
		/// </summary>
		/// <returns>String that includes the event name and the x and y position of the window.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Moved Event : (" << xPos << ", " << yPos << ")";
			return ss.str();
		}

		/// <summary>
		/// Get the x positoin of the window.
		/// </summary>
		/// <returns>Integer that represents the x position of the window.</returns>
		inline int GetXPos() const { return xPos; }

		/// <summary>
		/// Get the y position of the window.
		/// </summary>
		/// <returns>INteger that represents the y position of the window.</returns>
		inline int GetYPos() const { return yPos; }

	private:
		// Data member that stores the x and y pos of the window.
		int xPos, yPos;
	};
}