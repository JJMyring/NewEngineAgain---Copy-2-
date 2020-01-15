#pragma once

#pragma once

#include "rendering/batchedTextLabel.h"
#include "rendering/texture.h"

#include <glad/glad.h>


namespace Engine {

	class OpenGLBatchedTextLabel : public BatchedTextLabel
	{
	private:
		std::string m_font;//!< Name of the font
		unsigned int m_charsize; //!< Charsizxe in pt
		std::string m_text; //!< Label contents
		glm::vec2 m_position; //!< 2D screen position
		float m_orientation; //!< Angle in degrees
		float m_scale; //!< SCale as a scalar
		std::vector<glm::vec3> m_colours; //!< RGB colour
		glm::mat4 m_model; //!< Model matrix

		std::shared_ptr<Shader> m_shader; //!< Shader
		std::shared_ptr<VertexArray> m_VAO; //!< VAO
		std::vector<float> m_vertices; //!< CPU side vertex storage
		static unsigned int s_labelNumber; //!< Next label
		unsigned int m_labelNumber; //!< Label number
		std::shared_ptr<Material> m_material; //!< material

		void initGeometry(); //!< Initialise VAO, VBO and 
	public:
		OpenGLBatchedTextLabel(const std::string& fontName, unsigned int charSize, const std::string& text, const glm::vec2& position, float orientation, float scale, const std::vector<glm::vec3>& colours);
		bool setFont(const std::string& fontName) override { return false; };
		bool setCharSize(unsigned int charSize) override { return false; };
		void setText(const std::string& text) override {};
		void setPosition(const glm::vec2& position) override {};
		void setOrientation(float angle) override {}; //Set angle in degrees
		void setScale(float scale) override {};
		inline const std::string& getFont() const  override { return m_font; }
		inline unsigned int getCharSize() const override { return m_charsize; }
		inline const std::string& getText() const override { return m_text; };
		inline glm::vec2 getPosition() const override { return m_position; };
		inline float getOrientation() const override { return m_orientation; };
		inline float getScale() const override { return m_scale; };
		inline glm::mat4 getModel() const override { return m_model; }
		inline std::shared_ptr<Material> getMaterial() const override { return m_material; };
	};
}
