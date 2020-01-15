/** \file uniformBuffer.h
*/
#pragma once

#include "shader.h"

namespace Engine
{
	/**
	\class UniformBuffer
	An interface class for creating API specific Uniform Buffers.
	*/

	class UniformBuffer
	{
	protected:
	public:
		virtual void bind() = 0; //!< Bind the buffer
		virtual void unbind() = 0; //!< unbind the buffer
		virtual void attachShaderBlock(const std::shared_ptr<Shader>& shader, const std::string& blockName) = 0; //!< Bind shader block to this buffer
		virtual void setData(unsigned int offset, unsigned int size, void * data) = 0; //!< Set data in the buffer
		virtual UniformBufferLayout getLayout() const = 0; //!< Get the layout of this buffer

		static UniformBuffer * create(unsigned int size, UniformBufferLayout& layout); //!< Returns an Rendering API specific UniformBuffer
		static UniformBuffer * create(unsigned int size, unsigned int rangeStart, unsigned int rangeEnd, UniformBufferLayout& layout); //!< Returns an Rendering API specific UniformBuffer
	};
}
