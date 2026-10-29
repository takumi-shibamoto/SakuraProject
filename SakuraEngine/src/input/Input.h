#pragma once

#include "core/Core.h"
#include <utility>

namespace SKR {
	
	/// <summary>
	/// Input system of the engine. It is a singleton class that will be used to get the input from the user.
	/// </summary>
	class SKR_API Input
	{
	public:
		/// <summary>
		/// Check if the key is currently pressed or not.
		/// </summary>
		/// <param name="keyCode">Key code to check if it is pressed</param>
		/// <returns>Boolean that represent if the key is pressed or not.</returns>
		static inline bool IsKeyPressed(int keyCode) { return instance->IsKeyPressedImpl(keyCode); }

		/// <summary>
		/// Check if the mouse is currently pressed or not.
		/// </summary>
		/// <param name="buttonCode">Button code to check if it is pressed</param>
		/// <returns>Boolean that represent if the button is pressed or not.</returns>
		static inline bool IsMouseButtonPressed(int buttonCode) { return instance->IsMouseButtonPressedImpl(buttonCode); }

		/// <summary>
		/// Get the mouse position.
		/// </summary>
		/// <returns>Pair of doubles representing the mouse position.</returns>
		static inline std::pair<double, double> GetMousePos() { return instance->GetMousePosImpl(); }

		/// <summary>
		/// Get the mouse x position.
		/// </summary>
		/// <returns>Double representing the mouse x position.</returns>
		static inline double GetMouseX() { return instance->GetMouseXImpl(); }

		/// <summary>
		/// Get the mouse y position.
		/// </summary>
		/// <returns>Double representing the mouse y position.</returns>
		static inline double GetMouseY() { return instance->GetMouseYImpl(); }

	protected:
		/// <summary>
		/// Pure virtual function to check if the key is currently pressed or not.
		/// Need to be implemented in each platform.
		/// </summary>
		/// <param name="keyCode">Key code to check</param>
		/// <returns>Boolean that represent if the key is pressed or not.</returns>
		virtual bool IsKeyPressedImpl(int keyCode) = 0;

		/// <summary>
		/// Pure virtual function to check if the mouse is currently pressed or not.
		/// Need to be implemented in each platform.
		/// </summary>
		/// <param name="buttonCode">Button code to check</param>
		/// <returns>Boolean that represent if the button is pressed or not.</returns>
		virtual bool IsMouseButtonPressedImpl(int buttonCode) = 0;

		/// <summary>
		/// Pure virtual function to get the mouse position.
		/// Need to be implemented in each platform.
		/// </summary>
		/// <returns>Pair of doubles representing the mouse position.</returns>
		virtual std::pair<double, double> GetMousePosImpl() = 0;

		/// <summary>
		/// Pure virtual function to get the mouse x position.
		/// Need to be implemented in each platform.
		/// </summary>
		/// <returns>Double representing the mouse x position.</returns>
		virtual double GetMouseXImpl() = 0;

		/// <summary>
		/// Pure virtual function to get the mouse y position.
		/// Need to be implemented in each platform.
		/// </summary>
		/// <returns>Double representing the mouse y position.</returns>
		virtual double GetMouseYImpl() = 0;

	private:
		// Singleton instance of the input class.
		static Input* instance;
	};

}