#pragma once
#include "Event.h"

#include <sstream>

namespace sakura {
	
	/// <summary>
	/// Event that occur on every tick of the application
	/// </summary>
	class SKR_API AppTickEvent : public Event
	{
	public:
		// Set the event type to AppTick
		EVENT_CLASS_TYPE(AppTick);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/// <summary>
	/// Event that occur on every Update function of the application
	/// </summary>
	class SKR_API AppUpdateEvent : public Event
	{
	public:
		// Set the event type to AppTick
		EVENT_CLASS_TYPE(AppUpdate);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	/// <summary>
	/// Event that occur on every render fucntion of the application
	/// </summary>
	class SKR_API AppRenderEvent : public Event
	{
	public:
		// Set the event type to AppTick
		EVENT_CLASS_TYPE(AppRender);

		// Set the event category to application
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};
}