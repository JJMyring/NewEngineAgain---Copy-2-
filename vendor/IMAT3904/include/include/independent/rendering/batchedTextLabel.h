#pragma once

#include "rendering/material.h"
#include <glm/glm.hpp>


namespace Engine
{
	class BatchedTextLabel
	{
	public:
		virtual bool setFont(const std::string& fontName) = 0; //!< Set the font - must be preloaded
		virtual bool setCharSize(unsigned int charSize) = 0; //!< Set the font size  - must be preloaded
		virtual void setText(const std::string& text) = 0; //!< Set the text
		virtual void setPosition(const glm::vec2& position) = 0; //!< Set the position
		virtual void setOrientation(float angle) = 0; //Set angle in degrees
		virtual void setScale(float scale) = 0; //!< Set the scale as scalar
		virtual const std::string& getFont() const = 0; //!< Retrun the current font name
		virtual unsigned int getCharSize() const = 0; //!< Return the current char size
		virtual const std::string& getText() const = 0; //!< Retunr the current text
		virtual glm::vec2 getPosition() const = 0; //!< Return the position
		virtual float getOrientation() const = 0; //!< Return the orientation
		virtual float getScale() const = 0; //!< Return the scale
		virtual glm::mat4 getModel() const = 0; //!< Return the model matrix
		virtual std::shared_ptr<Material> getMaterial() const = 0; //!< Return the material

		static BatchedTextLabel * create(const std::string& fontName, unsigned int charSize,
			const std::string& text, const glm::vec2& position, float orientation, float scale, 
			const std::vector<glm::vec3>& colours); //!< Create API specific implementation. Colour vector size should match text length
	};
}
