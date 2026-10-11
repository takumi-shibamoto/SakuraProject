#pragma once

#include <string>

#include "event/Event.h"

namespace SKR {

	/// <summary>
	/// Base class for a single layer.
	/// </summary>
	class SKR_API Layer
	{
	public:
		/// <summary>
		/// Constructor. Set the debug name of the layer.
		/// </summary>
		/// <param name="name">debug name of the layer.</param>
		Layer(std::string const& name);

		/// <summary>
		/// Default virtual destructor.
		/// </summary>
		virtual ~Layer() = default;

		/// <summary>
		/// Called when the layer is attached.
		/// </summary>
		virtual void OnAttached() {};

		/// <summary>
		/// Called when the layer is detached.
		/// </summary>
		virtual void OnDetached() {};

		/// <summary>
		/// Called every frame to update the layer.
		/// </summary>
		virtual void OnUpdate() {};

		/// <summary>
		/// Event callback function for the layer.
		/// </summary>
		/// <param name="event"></param>
		virtual void OnEvent(Event& event) {};

		/// <summary>
		/// Get the debug name.
		/// </summary>
		/// <returns>std::string that represents the debug name.</returns>
		inline const std::string GetName() const { return debugName; }

	private:
		// Debug name of the layer.
		std::string debugName;
	};

}