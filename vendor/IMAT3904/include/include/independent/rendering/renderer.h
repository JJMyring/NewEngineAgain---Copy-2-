#pragma once

#include <memory>
#include <map>
#include <unordered_map>

#include "renderCommands.h"
#include "rendering/uniformBuffer.h"
#include "rendering/material.h"

namespace Engine
{
	using SceneData = std::unordered_map<std::shared_ptr<UniformBuffer>, std::vector<void*>>;
	using PerDrawData = std::map<std::string, void *>;

	// Interface for rendering
	class Renderer
	{
	public:
		virtual void actionCommand(RenderCommand* command) = 0; //!< Action a render command
		virtual void beginScene(const std::shared_ptr<SceneData>& sceneData) = 0; //!< Prepare a scene for submission
		virtual void endScene() = 0; //!< End of scene
		virtual void submit(const std::shared_ptr<Material>& material) = 0; //!< Submit a material for drawing
		virtual void flush() = 0; //!< Draw everything

		static Renderer* createBasic3D();
		static Renderer* createTextRenderer();
		static Renderer* createBatchTextRenderer(std::shared_ptr<Shader> shader);
	};
}
