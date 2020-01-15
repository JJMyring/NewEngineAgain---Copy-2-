/** \file vertexBuffer.h
*/
#pragma once

#include "bufferLayout.h"

namespace Engine {

	class VertexBuffer
	{
	public:
		virtual void bind() = 0; //!< Bind the buffer
		virtual void unbind() = 0; //!< unbind the buffer
		virtual void edit(float* vertices, unsigned int size, unsigned int offset) = 0; //!< Edit data stored in the buffer
		virtual const VertexBufferLayout& getLayout() const = 0; //!< Get the buffer layout
		virtual unsigned int id() const = 0; //!< Get the API specific GPU ID
		virtual unsigned int getSize() const = 0; //!< Get the size of the data stored in the VBO

		static VertexBuffer * create(float* vertices, unsigned int size, VertexBufferLayout& layout); //!< Returns an Rendering API specific IndexBuffer
		static VertexBuffer * create(void* vertices, unsigned int size, VertexBufferLayout& layout); //!< Returns an Rendering API specific IndexBuffer
	};
}