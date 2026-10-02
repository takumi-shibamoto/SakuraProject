#pragma once
#include "Event.h"

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

	};

	/// <summary>
	/// Event that handles when the key is released.
	/// </summary>
	class SKR_API KeyReleasedEvent : public KeyEvent
	{

	};
}