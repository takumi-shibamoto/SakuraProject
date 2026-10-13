#pragma once
#include "core/Core.h"
#include "Event.h"

#include <sstream>

namespace SKR {

	/// <summary>
	/// Event that handles mouse movement
	/// </summary>
	class SKR_API MouseMovedEvent : public Event
	{
	public:
		/// <summary>
		/// Constructor of the mouse moved event
		/// </summary>
		/// <param name="x">x position of the moved mouse</param>
		/// <param name="y">y position of the moved mouse</param>
		MouseMovedEvent(double x, double y)
			: xPos{ x }, yPos{ y } {}

		// Set the event type to be the MouseMoved type
		EVENT_CLASS_TYPE(MouseMoved);

		// Set the category to be input and mouse.
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		/// <summary>
		/// Debug function to print out the mouse moved event.
		/// </summary>
		/// <returns>String that contains the x and y position of the mouse.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Moved Event : (" << xPos << ", " << yPos << ")";
			return ss.str();
		}

		/// <summary>
		/// Get the x position of the mouse.
		/// </summary>
		/// <returns>Double that represents the x position of the mouse</returns>
		inline double GetXPos() const { return xPos; }
		
		/// <summary>
		/// Get the y position of the mouse.
		/// </summary>
		/// <returns>Double that represents the y position of the mouse</returns>
		inline double GetYPos() const { return yPos; }

	private:
		// X poisition of the moved mouse
		double xPos;

		// Y position of the moved mouse
		double yPos;
	};

	/// <summary>
	/// Event that handles mouse scroll (vertical and horizontal scroll)
	/// </summary>
	class SKR_API MouseScrollEvent : public Event
	{
	public:
		/// <summary>
		/// Constructor of the mouse scroll event
		/// </summary>
		/// <param name="x">x offset of the scrolling</param>
		/// <param name="y">y offset of the scrolling</param>
		MouseScrollEvent(double x, double y)
			: xOffset{ x }, yOffset { y } {}

		// Set the event type to be the MouseScroll type
		EVENT_CLASS_TYPE(MouseScrolled);

		// Set the category to be input and mouse.
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		/// <summary>
		/// Debug function to print out the mouse scroll event.
		/// </summary>
		/// <returns>String that contains the x and y offset of the mouse scrolling.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Scroll Event : Offset = (" << xOffset << ", " << yOffset << ")";
			return ss.str();
		}

		/// <summary>
		/// Get the x offset of the scrolling.
		/// </summary>
		/// <returns>Double that represents the x offset.</returns>
		inline double GetXOffset() const { return xOffset; }

		/// <summary>
		/// Get the y offset of the scrolling.
		/// </summary>
		/// <returns>Double that represetns the y offset.</returns>
		inline double GetYOffset() const { return yOffset; }

	private:
		// X Offset of the scrolling
		double xOffset;

		// Y Offset of the scrolling
		double yOffset;
	};

	/// <summary>
	/// Base class for the mouse button events.
	/// </summary>
	class SKR_API MouseButtonEvent : public Event
	{
	public:
		/// <summary>
		/// Get the button code of the event button
		/// </summary>
		/// <returns>Integer that represents the button code.</returns>
		inline int GetButtonCode() const { return buttonCode; }

		// Set the event category as input and mouse button event
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton);
	
	protected:
		/// <summary>
		/// Constructor. This is a protected constructor since there should not be
		/// a event of this class. The actual event should be it's child class.
		/// </summary>
		/// <param name="key">key code of the mouse button pressed.</param>
		MouseButtonEvent(int key)
			: buttonCode{ key } {}

		// Button code of the event button.
		int buttonCode;
	};

	/// <summary>
	/// Event that occur when the mouse button is pressed.
	/// </summary>
	class SKR_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		/// <summary>
		/// Constructor for the mouse button pressed event
		/// </summary>
		/// <param name="button">button code for the button pressed.</param>
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent{ button } {}

		// Set the event type to be MouseButtonPressed
		EVENT_CLASS_TYPE(MouseButtonPressed);

		/// <summary>
		/// Format the mouse button pressed string to include the button code.
		/// </summary>
		/// <returns>String that contains the button code.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Button Pressed Event : " << buttonCode;
			return ss.str();
		}
	};

	/// <summary>
	/// Event that occur when the mouse button is released.
	/// </summary>
	class SKR_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		/// <summary>
		/// Constructor for the mouse button released event.
		/// </summary>
		/// <param name="button">button code or the button released.</param>
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent{ button } {}
		
		// Set the event type to be MouseButtonReleased
		EVENT_CLASS_TYPE(MouseButtonReleased);

		/// <summary>
		/// Format the mouse button released string to include the button code.
		/// </summary>
		/// <returns>String that contains the button code.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Button Released Event : " << buttonCode;
			return ss.str();
		}
	};
}