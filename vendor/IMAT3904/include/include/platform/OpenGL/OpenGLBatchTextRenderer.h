#pragma once

#include "rendering/renderer.h"
#include <memory>

#include <glad/glad.h>
namespace Engine {

	/**
	\class OpenGLBatchTextRenderer
	An OpenGL renderer which draws text in batches
	*/

	class OpenGLBatchTextRenderer : public Renderer
	{
	private:
		unsigned int m_currentVertexCount = 0;
		unsigned int m_currentOffset = 0;
		unsigned int m_maxVertexCount; //!< Batch size of just under 32Mb
		std::shared_ptr <VertexArray> m_VAO; //!< Vertex Array
		std::shared_ptr <VertexBuffer> m_VBO; //!< Vertex Buffer to be copied to
		std::shared_ptr <IndexBuffer> m_IBO; //!< Index buffer to be written to
		std::shared_ptr <Shader> m_shader; //!< This implementation only uses a single shader
	public:
		OpenGLBatchTextRenderer(std::shared_ptr <Shader> shader);
		void actionCommand(RenderCommand* command) override; //!< Action a render command
		void beginScene(const std::shared_ptr<SceneData>& sceneData) override; //!< Prepare a scene for submission
		void endScene() override {}; //!< End of scene
		void submit(const std::shared_ptr<Material>& material) override; //!< Submit a material for drawing
		void flush() override; //!< Draw everything
	};
}
