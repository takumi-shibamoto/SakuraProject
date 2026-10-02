#pragma once
#include "Event.h"

#include <sstream>

namespace sakura {

	/// <summary>
	/// Base class for the key events.
	/// </summary>
	class SKR_API KeyEvent : public Event
	{
	public:
		/// <summary>
		/// Getter of the data member.
		/// </summary>
		/// <returns>int stored in the key code data member.</returns>
		inline int GetKeyCode() const { return keyCode; };
		
		// Override the GetEventCategory function with the keyboard and input category.
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		/// <summary>
		/// Constructor. This is a protected constructor since there should not be
		/// a event of this class. The actual event should be it's child class.
		/// </summary>
		/// <param name="key">key code of the event key.</param>
		KeyEvent(int key) 
			: keyCode{ key }
		{
		}

		// data member that stores the key code.
		int keyCode;
	};

	/// <summary>
	/// Event that handles when the key is pressed.
	/// </summary>
	class SKR_API KeyPressedEvent : public KeyEvent
	{
	public:
		/// <summary>
		/// Constructor for the key pressed event
		/// </summary>
		/// <param name="key">key code of the key pressed</param>
		/// <param name="repeat">repeat count of the key press</param>
		KeyPressedEvent(int key, unsigned int repeat)
			: KeyEvent{ key }, repeatCount { repeat } {}

		// Set the event type to key pressed event
		EVENT_CLASS_TYPE(KeyPressed);

		/// <summary>
		/// Getter of the repeat count data member.
		/// </summary>
		/// <returns>Unsigned int that represent the repeat count.</returns>
		inline unsigned int GetRepeatCount() const { return repeatCount; }

		/// <summary>
		/// Overload ToString function to format the key pressed event string.
		/// </summary>
		/// <returns>String that display the key code and the repeat count of the event.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Key Pressed Event : " << keyCode << " (Repeated : " << repeatCount << ")";
			return ss.str();
		}

	private:
		// Data member that stores the repeat count of the key press.
		unsigned int repeatCount;
	};

	/// <summary>
	/// Event that handles when the key is released.
	/// </summary>
	class SKR_API KeyReleasedEvent : public KeyEvent
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="key">key code of the released key.</param>
		KeyReleasedEvent(int key)
			: KeyEvent{ key } {}

		// Set the event type to key released event
		EVENT_CLASS_TYPE(KeyReleased);

		/// <summary>
		/// Overload ToString function to format the key released event string.
		/// </summary>
		/// <returns>String that display the key code of the event.</returns>
		std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Key Pressed Event : " << keyCode;
			return ss.str();
		}
	};
}