#pragma once

#include "rendering/material.h"

namespace Engine {

	/**
	\class OpenGLMaterial
	A renderable material for use with OpenGL renderers
	*/

	class OpenGLMaterial : public Material
	{
	public:
		void init(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO); //!< Initialise the material
		void setShader(const std::shared_ptr<Shader>& shader) override; //!< Set the shader
		void setGeometry(void* geometry) override; //!< Set the geometry as a VAO
		void setDataBlock(const std::map<std::string, void *>& data) override; //!< Set a block of data as the per draw data
		void setDataElement(const std::string& dataName, void * data) override; //!< Set a single uniform
		void setVertexData(float * vertex, unsigned int offset, unsigned int size) override; //!< Set the geometry directly with vertex data
		inline std::shared_ptr<Shader> getShader() override { return m_shader; } //!< Get the shader
		inline void*  getGeometry() override { return (void*)&m_geometry; }//!< Get the geometry
		inline std::map<std::string, void *> getData() override { return m_data; } //!< Get the per draw data
	private:
		std::shared_ptr<Shader> m_shader; //!< The shader
		std::shared_ptr<VertexArray> m_geometry; //!< The geometry
		std::map<std::string, void *> m_data; //!< The data
	};
}