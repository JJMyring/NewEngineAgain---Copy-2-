/** \file OpenGLIndexBuffer.h
*/
#pragma once

#include "rendering/IndexBuffer.h"

namespace Engine {
	class OpenGLIndexBuffer : public IndexBuffer
	{
	private:
		unsigned int m_OpenGL_ID; //!< Id of the buffer in OpenGL
		unsigned int m_count; //!< number of indices held in the buffer
	public:
		OpenGLIndexBuffer(unsigned int* indices, unsigned int count); //!< Constructor with buffer data and size of buffer in byte
		void bind() override; //!< Bind the buffer
		void unbind() override; //!< unbind the buffer
		unsigned int getCount() const override; //!< get the number of indices stored in the buffer
	};
}