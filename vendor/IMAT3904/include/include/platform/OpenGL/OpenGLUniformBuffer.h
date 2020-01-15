/** \file OpenGLUniformBuffer.h
*/
#pragma once

#include "rendering/uniformBuffer.h"

namespace Engine {

	/**
	\class OpenGLUniformBuffer
	A class for creating OpenGL Uniform Buffer Objects.
	*/

	class OpenGLUniformBuffer : public UniformBuffer
	{
	private:
		unsigned int m_OpenGL_ID; //!< Id of the buffer in OpenGL
		static unsigned int s_blockNumber; //!< Next availible UBO block
		unsigned int m_blockNumber; //!< Block number which this UBO is bound to
		UniformBufferLayout m_bufferLayout; //!< Layout of the Uniform Buffer (normalised isn't used)
	public:
		OpenGLUniformBuffer(unsigned int size, UniformBufferLayout& layout); //!< Constructor where range equals size
		OpenGLUniformBuffer(unsigned int size, unsigned int rangeStart, unsigned int rangeEnd, UniformBufferLayout& layout); //!< Constructor where range is defined
		void bind() override; //!< Bind the buffer
		void unbind() override; //!< unbind the buffer
		void attachShaderBlock(const std::shared_ptr<Shader>& shader, const std::string& blockName) override; //!< Bind shader block to this buffer
		void setData(unsigned int offset, unsigned int size, void * data) override; //!< Set data in the buffer
		inline UniformBufferLayout getLayout() const override { return m_bufferLayout; }; //!< Get the layout of this buffer
	};
}