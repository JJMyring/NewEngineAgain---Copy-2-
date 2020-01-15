#pragma once

#include <vector>
#include <memory>

#include "system.h"
#include "rendering/layer.h"

namespace Engine {
	class LayerStack : public System {
	private:
		std::vector<std::shared_ptr<Layer>> m_layers;
	public:
		void start(SystemSignal sig = SystemSignal::None, ...) override; //!< Start the layerstack
		void stop(SystemSignal sig = SystemSignal::None, ...) override; //!< Stop the layerstack and clear all layers
		void push(std::shared_ptr<Layer> layer);
		void pop();

		inline std::vector<std::shared_ptr<Layer>>::iterator begin() { return m_layers.begin(); }
		inline std::vector<std::shared_ptr<Layer>>::iterator end() { return m_layers.end(); }
	};
}