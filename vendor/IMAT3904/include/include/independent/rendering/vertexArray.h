/** \file vertexArray.h
*/
#pragma once

#include <memory>

#include "rendering/IndexBuffer.h"
#include "rendering/vertexBuffer.h"

namespace Engine {
	class VertexArray {
	public:
		virtual void bind() const = 0; //!< Bind the vertex array object
		virtual void unbind() const = 0; //!< Unbind the vertex array object
		virtual void setVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBeffer) = 0; //!< Add a vertex buffer
		virtual void setindexBuffer(const std::shared_ptr<IndexBuffer>& indexBeffer) = 0; //!< Set the index buffer for all vertex buffer
		virtual std::shared_ptr<VertexBuffer> getVertexBuffer() const = 0; //!< Get the vertex buffers
		virtual std::shared_ptr<IndexBuffer> getIndexBuffer() const = 0; //!< Get the index buffer
		virtual unsigned int getDrawCount() const = 0; //!< returns the number of triangles to draw
		virtual unsigned int getSize() const = 0; //!< Get the size of the data stored in the VBO

		static VertexArray * create(); // Return an API sepcific VertexArray
	};
}