#pragma once

#include <memory>
#include <map>
#include <variant>

#include "shader.h"
#include "vertexBuffer.h"
#include "vertexArray.h"

namespace Engine {

	/**
	\class Material
	An material interface class for use with a range of renderers
	*/

	class Material
	{
	public:
		virtual void setShader(const std::shared_ptr<Shader>& shader) = 0;//!< Set the shader
		virtual void setGeometry(void* geometry) = 0; //!< Set the geometry
		virtual void setDataBlock(const std::map<std::string, void *>& data) = 0; //!< Set a block of data as the per draw data
		virtual void setDataElement(const std::string& dataName, void * data) = 0; //!< Set a single uniform
		virtual void setVertexData(float * vertices, unsigned int size, unsigned int offset) = 0; //!< Set the geometry directly with vertex data

		virtual std::shared_ptr<Shader> getShader() = 0;   //!< Get the shader
		virtual void* getGeometry() = 0; //!< Get the geometry
		virtual std::map<std::string, void *> getData() = 0; //!< Get the per draw data

		static Material * create(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO); //!< Create a material with a VAO
		static Material * create(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexBuffer>& VBO); //!< Create a material with a VBO
	};
}