#pragma once

#include "rendering/renderer.h"
#include "rendering/uniformBuffer.h"
#include <memory>

#include <glad/glad.h>
namespace Engine {

	/**
	\class OpenGLBasicRenderer
	An OpenGL renderer whcih draw as soon as a material is submitted
	*/

	class OpenGLBasicRenderer : public Renderer
	{
	private:
	public:
		void actionCommand(RenderCommand* command) override; //!< Action a render command
		void beginScene(const std::shared_ptr<SceneData>& sceneData) override; //!< Prepare a scene for submission
		void endScene() override {}; //!< End of scene
		void submit(const std::shared_ptr<Material>& material) override; //!< Submit a material for drawing
		void flush() override {}; //!< Draw everything
	};
}
