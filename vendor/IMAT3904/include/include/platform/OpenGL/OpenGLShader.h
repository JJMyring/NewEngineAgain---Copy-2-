#pragma once

#include "rendering/shader.h"
#include "rendering/ShaderDataTypes.h"

#include <glad/glad.h>
#include <string>
#include <map>

namespace Engine
{
	/**
	\class OpenGLShader
	An interface class for creating OpenGL shader programmes.
	*/

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& filepath); //!< Constructor with path to all source code
		OpenGLShader(const std::string& vertexFilepath, const std::string& fragmentFilepath); //!< Constructor with path to two source code files
		inline unsigned int id() override { return m_OpenGL_ID; } //!< Get the API id of the shader programme
		void bind() override; //!< Bind the shader
		void unbind() override; //!< Unbind the shader
		bool uploadData(const std::string& name, void * data) override; //!< Upload data to the GPU
		bool uploadData(const UniformLayout& uniforms) override; //!< Upload a group of data to the GPU
		inline VertexBufferLayout getBufferLayout() const override { return m_bufferLayout; }
		inline UniformLayout getUniformLayout() const override { return m_uniformLayout; }
	private:
		unsigned int m_OpenGL_ID; //!< Shader ID
		void parseSource(const std::string& filepath); //!< Parse the source code seperating into different shader source files. Parse for uniforms, compile, link and cache uniform information
		void compileAndLink(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc); //Compile and link vertex and fragment shader. Can be expanded to other source types
		void dispatchUniformUpload(ShaderDataType type, GLuint location, void * data); //Dispatches uniform uploads
		std::map <std::string, std::pair<ShaderDataType, GLuint>> m_uniformCache; //!< Caches uniform types and locations
		VertexBufferLayout m_bufferLayout; //!< Layout of the vertex buffer as read from the shader file
		UniformLayout m_uniformLayout; //!< Data map that can be uploaded to this shader
	};
}