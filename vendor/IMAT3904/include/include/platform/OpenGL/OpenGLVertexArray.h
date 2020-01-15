/** \file OpenGLVertexArray.h
*/
#pragma once

#include "rendering/vertexArray.h"

namespace Engine {

	class OpenGLVertexArray : public VertexArray
	{
	private:
		std::shared_ptr<VertexBuffer> m_vertexBuffer; //!< Container for vertex buffers
		std::shared_ptr<IndexBuffer> m_indexBuffer; //!< Index bufer for all vertex buffers
		unsigned int m_OpenGL_ID; //!< Id of the buffer in OpenGL
		unsigned int m_drawCount; //!< Number of vertice to be drawn
	public:
		OpenGLVertexArray(); //!< Constructor
		~OpenGLVertexArray(); //!< Destructor;
		void bind() const override; //!< Bind the vertex array object
		void unbind() const override; //!< Unbind the vertex array object
		void setVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override; //!< Add a vertex buffer
		void setindexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override; //!< Set the index buffer for all vertex buffer
		std::shared_ptr<VertexBuffer> getVertexBuffer() const override; //!< Get the vertex buffers
		std::shared_ptr<IndexBuffer> getIndexBuffer() const override; //!< Get the index buffer
		inline unsigned int getDrawCount() const override { return m_drawCount; }; //!< returns the number of triangles to draw
		inline unsigned int getSize() const override { return m_vertexBuffer->getSize(); }
	};
}


