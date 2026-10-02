#pragma once

#include "core/Core.h"
#include <string>
#include <functional>

namespace sakura {

	/// <summary>
	/// Enum that handles all the event types so that it can be filtered.
	/// </summary>
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/// <summary>
	/// Enum that handles the category of events. Each event can have multiple categories.
	/// </summary>
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	// Macro to define the pure virtual functions for the event type easily.
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								   virtual EventType GetEventType() const override { return GetStaticType(); }\
								   virtual const char* GetName() const override { return #type; }

	// Macro to define the pure virtual function for the category of the event easily.
	#define EVENT_CLASS_CATEGORY(category) virtual unsigned int GetCategoryFlags() const override { return category; }

	/// <summary>
	/// Base class for the events.
	/// </summary>
	class SKR_API Event
	{
	public:
		/// <summary>
		/// Get the event type.
		/// Need to be defined by the child class.
		/// </summary>
		/// <returns>Enum that represents the event type.</returns>
		virtual EventType GetEventType() const = 0;

		/// <summary>
		/// Get the name of the event.
		/// Need to be defined by the child class.
		/// </summary>
		/// <returns>c string that represents the name.</returns>
		virtual const char* GetName() const = 0;

		/// <summary>
		/// Get the number that represents the category flag.
		/// Need to be defined by the child class.
		/// </summary>
		/// <returns>Unsigned integer that represents all the flag set to the event.</returns>
		virtual unsigned int GetCategoryFlags() const = 0;

		/// <summary>
		/// Get the name of the event as std::string
		/// </summary>
		/// <returns>std::string that represents the name of the event.</returns>
		virtual std::string ToString() const { return GetName(); };

		/// <summary>
		/// Check if the event is in the given category
		/// </summary>
		/// <param name="category">The category to check</param>
		/// <returns>boolean value if the event is in the category or not.</returns>
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		// data member to check if the event has already been handled.
		bool handled = false;
	};

}