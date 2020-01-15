#pragma once

#include <string>

#include "events/event.h"
#include "rendering/renderer.h"
#include "rendering/cameras/cameraController.h"
#include "systems/resourceManager.h"



namespace Engine {
	class Layer
	{
	protected:
		std::string m_name;														//!< Name of the layer for debuging purposes
		std::shared_ptr<ResourceManager> m_resources;							//!< Centralised resources avalible to the layer
		std::shared_ptr<Renderer> m_renderer;									//!< Renderer used by the layer
		std::shared_ptr<CameraController> m_camera;								//!< Camera used by the layer
		std::shared_ptr<SceneData> m_sceneData;													//!< Scene used by renderer - UBO data pairs

		std::vector<Engine::UniformBuffer> m_uniformBuffers;					//!< Uniform buffers

	public:
		Layer(const std::string& name = "Layer");								//!< Constructor

		virtual void onAttach() {}												//!< Runs when layer is attached
		virtual void onDetach() {}												//!< Runs when layer is detached
		virtual void onUpdate(float timestep) {}								//!< Runs every frame
		virtual void onEvent(Event& event) {}									//!< Runs when an event occurs

		inline const std::string& getName() const { return m_name; }			//!< Accessors
		inline std::shared_ptr<CameraController>& getCamera() { return m_camera; }
		inline std::shared_ptr<Renderer>& getRenderer() { return m_renderer; }
		inline const std::shared_ptr<ResourceManager>& getResources() { return m_resources; }
		inline const std::shared_ptr<SceneData>& getSceneData() { return m_sceneData; }
	};
}