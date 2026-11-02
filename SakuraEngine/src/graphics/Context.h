#pragma once

namespace SKR {

	/// <summary>
	/// Base class of renderer context.
	/// </summary>
	class Context
	{
	public:
		/// <summary>
		/// Initialize the context.
		/// </summary>
		virtual void Init() = 0;

		/// <summary>
		/// Swap buffers to update the screen.
		/// </summary>
		virtual void SwapBuffer() = 0;
	};

}