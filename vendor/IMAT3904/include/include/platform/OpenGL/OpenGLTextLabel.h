#pragma once

#include "rendering/textLabel.h"
#include "rendering/texture.h"

#include <glad/glad.h>


namespace Engine {

	class OpenGLTextLabel : public TextLabel
	{
	private:
		std::string m_font;//!< Name of the font
		unsigned int m_charsize; //!< Charsizxe in pt
		std::string m_text; //!< Label contents
		glm::vec2 m_position; //!< 2D screen position
		float m_orientation; //!< Angle in degrees
		float m_scale; //!< SCale as a scalar
		glm::vec3 m_colour; //!< RGB colour
		glm::mat4 m_model; //!< Model matrix

		std::shared_ptr<Texture> m_fontTexture; //!< Storage for glyph textures
		std::shared_ptr<Shader> m_shader; //!< Shader
		std::shared_ptr<VertexArray> m_VAO; //!< VAO
		static const int m_maxTextSize = 128; //!< Maximum number of characters in the label's text
		static unsigned int s_labelNumber; //!< Next label
		unsigned int m_labelNumber; //!< Label number

		std::shared_ptr<Material> m_material;
		void initGeometry(); //!< Initialise VAO, VBO and 
	public:
		OpenGLTextLabel(const std::string& fontName, unsigned int charSize, const std::string& text, const glm::vec2& position, float orientation, float scale, const glm::vec3& colour);
		bool setFont(const std::string& fontName) override { return false; };
		bool setCharSize(unsigned int charSize) override { return false; };
		void setText(const std::string& text) override {};
		void setPosition(const glm::vec2& position) override {};
		void setOrientation(float angle) override {}; //Set angle in degrees
		void setScale(float scale) override {};
		void setColour(const glm::vec3& colour) override {};
		inline const std::string& getFont() const  override { return m_font; }
		inline unsigned int getCharSize() const override { return m_charsize; }
		inline const std::string& getText() const override { return m_text; };
		inline glm::vec2 getPosition() const override { return m_position; };
		inline float getOrientation() const override { return m_orientation; };
		inline float getScale() const override { return m_scale; };
		inline glm::vec3 getColour() const override { return m_colour; };
		inline glm::mat4 getModel() const override { return m_model; }
		inline std::shared_ptr<Material> getMaterial() const override { return m_material; };
	};
}
