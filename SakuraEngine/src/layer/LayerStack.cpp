#include "skrpch.h"
#include "LayerStack.h"

namespace SKR {
	LayerStack::LayerStack()
		: layers{}, layerInsertIndex{} {}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		layers.emplace(begin() + layerInsertIndex, layer);
		++layerInsertIndex;
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		layers.push_back(layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// Find the given layer from the layers list (not from the overlay).
		std::vector<Layer*>::iterator iter = std::find(begin(), begin() + layerInsertIndex, layer);

		// If found, erase the layer from the list and decrement the insert index.
		if (iter != begin() + layerInsertIndex)
		{
			layers.erase(iter);
			--layerInsertIndex;
		}
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		std::vector<Layer*>::iterator iter = std::find(begin() + layerInsertIndex, end(), layer);
		if (iter != end())
			layers.erase(iter);
	}
}