#pragma once

#include "rendering/material.h"
#include <glm/glm.hpp>


namespace Engine
{
	class TextLabel
	{
	public:
		virtual bool setFont(const std::string& fontName) = 0;
		virtual bool setCharSize(unsigned int charSize) = 0;
		virtual void setText(const std::string& text) = 0;
		virtual void setPosition(const glm::vec2& position) = 0;
		virtual void setOrientation(float angle) = 0; //Set angle in degrees
		virtual void setScale(float scale) = 0;
		virtual void setColour(const glm::vec3& colour) = 0;
		virtual const std::string& getFont() const = 0;
		virtual unsigned int getCharSize() const = 0;
		virtual const std::string& getText() const = 0;
		virtual glm::vec2 getPosition() const = 0;
		virtual float getOrientation() const = 0;
		virtual float getScale() const = 0;
		virtual glm::vec3 getColour() const = 0;
		virtual glm::mat4 getModel() const = 0;
		virtual std::shared_ptr<Material> getMaterial() const = 0;

		static TextLabel * create(const std::string& fontName, unsigned int charSize, 
			const std::string& text, const glm::vec2& position, float orientation, float scale, const glm::vec3& colour);

	};
}
