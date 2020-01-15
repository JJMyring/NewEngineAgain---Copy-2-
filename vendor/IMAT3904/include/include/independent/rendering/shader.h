/** \file OpenGLShader.h
*/
#pragma once

#include <string>
#include <map>
#include "bufferLayout.h"

namespace Engine {

	using UniformLayout = std::map<std::string, void *>;

	/**
	\class Shader
	An interface class for creating API specific shader programmes.
	*/

	class Shader
	{
	public:
		virtual unsigned int id() = 0; //!< Get the API id of the shader programme
		virtual void bind() = 0; //!< Bind the shader
		virtual void unbind() = 0; //!< Unbind the shader
		virtual bool uploadData(const std::string& name, void * data) = 0; //!< Upload data of any type to the GPU
		virtual bool uploadData(const UniformLayout& uniforms) = 0; //!< Upload data of any type to the GPU
		virtual VertexBufferLayout getBufferLayout() const = 0; //!< Get the buffer layout for the shader
		virtual UniformLayout getUniformLayout() const = 0; //!< Get the structure of the data whcih can be uploaded

		static Shader* create(const std::string& filepath); //!< Create, compile and link API specific shader from single source file 
		static Shader* create(const std::string& vertexFilepath, const std::string& fragmentFilepath); //!< Create, compile and link API specific shader from vertex and fragment/pixel shder files
	};

}
