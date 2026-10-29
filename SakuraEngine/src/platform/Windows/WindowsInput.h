#pragma once

#include "input/Input.h"

namespace SKR {

	/// <summary>
	/// Windows implementation of the input system.
	/// </summary>
	class WindowsInput : public Input
	{
	protected:
		/// <summary>
		/// Windows implementation of the function to check if the key is currently pressed or not.
		/// </summary>
		/// <param name="keyCode">Key code to check</param>
		/// <returns>Boolean that represent if the key is pressed or not.</returns>
		bool IsKeyPressedImpl(int keyCode) override;

		/// <summary>
		/// Windows implementation of the function to check if the mouse is currently pressed or not.
		/// </summary>
		/// <param name="buttonCode">Button code to check</param>
		/// <returns>Boolean that represent if the button is pressed or not.</returns>
		bool IsMouseButtonPressedImpl(int buttonCode) override;

		/// <summary>
		/// Windows implementation of the function to get the mouse position.
		/// </summary>
		/// <returns>Pair of doubles representing the mouse position.</returns>
		std::pair<double, double> GetMousePosImpl() override;

		/// <summary>
		/// Windows implementation of the function to get the mouse x position.
		/// </summary>
		/// <returns>Double representing the mouse x position.</returns>
		double GetMouseXImpl() override;

		/// <summary>
		/// Windows implementation of the function to get the mouse y position.
		/// </summary>
		/// <returns>Double representing the mouse y position.</returns>
		double GetMouseYImpl() override;
	};

}