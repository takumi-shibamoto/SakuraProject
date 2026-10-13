#pragma once

#include <vector>

#include "layer/Layer.h"

namespace SKR {

	/// <summary>
	/// Storage to store all the layers.
	/// </summary>
	class LayerStack
	{
	public:
		/// <summary>
		/// Constructor. Create the empty vector of layers and set
		/// the layer insert index to 0.
		/// </summary>
		LayerStack();

		/// <summary>
		/// Destructor. Delete all the layers in the layers vector.
		/// </summary>
		~LayerStack();

		/// <summary>
		/// Push the layer to the layers vector.
		/// Push it as the layer right before the overlay.
		/// </summary>
		/// <param name="layer">Pointer to the layer to push.</param>
		void PushLayer(Layer* layer);

		/// <summary>
		/// Push the layer to the layers vector.
		/// Push it to the very last of the layers vector.
		/// </summary>
		/// <param name="layer">Pointer to the layer to push.</param>
		void PushOverlay(Layer* layer);

		/// <summary>
		/// Erase the layer from the list if it exists.
		/// </summary>
		/// <param name="layer">Pointer to the layer to pop.</param>
		void PopLayer(Layer* layer);

		/// <summary>
		/// Erase the overlay layer from the list if it exists.
		/// </summary>
		/// <param name="layer">Pointer to the layer to pop.</param>
		void PopOverlay(Layer* layer);

		/// <summary>
		/// Get the starting iterator of the layers vector.
		/// </summary>
		/// <returns>starting iterator of the layers vector</returns>
		inline std::vector<Layer*>::iterator begin() { return layers.begin(); }

		/// <summary>
		/// Get the iterator of the last element of the layers vector.
		/// </summary>
		/// <returns>iterator of the last element of the layers vector.</returns>
		inline std::vector<Layer*>::iterator end() { return layers.end(); }

	private:
		// List of layers.
		std::vector<Layer*> layers;

		// Index to separate the layer and overlay layer.
		unsigned int layerInsertIndex;
	};

}