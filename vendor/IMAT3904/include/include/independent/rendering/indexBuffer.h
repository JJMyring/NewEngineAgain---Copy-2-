/** \file indexBuffer.h
*/
#pragma once

namespace Engine {

	class IndexBuffer
	{
	public:
		virtual void bind() = 0; //!< Bind the buffer
		virtual void unbind() = 0; //!< unbind the buffer

		virtual unsigned int getCount() const = 0; //!< Get the buffer count

		static IndexBuffer * create(unsigned int* indices, unsigned int count); //!< Returns an Rendering API specific IndexBuffer
	};
}