/** \file resourceManager.h
*/
#pragma once

#include <unordered_map>



#include "system.h"
#include "core/assetManager.h"

#include "rendering/IndexBuffer.h"
#include "rendering/shader.h"
#include "rendering/texture.h"
#include "rendering/vertexArray.h"
#include "rendering/vertexBuffer.h"
#include "rendering/uniformBuffer.h"
#include "rendering/material.h"
#include "rendering/character.h"

namespace Engine {

	/**
	\class ResourceManager
	A system which hold all resources
	*/

	class ResourceManager : public System
	{
	private:
		static AssetManager<IndexBuffer> m_indexBuffers;  //!< Index buffers
		static AssetManager<Shader> m_shaders; //!< Shaders
		static AssetManager<Texture> m_textures; //!< Textures
		static AssetManager<VertexArray> m_VAOs; //!< Vertex arrays
		static AssetManager<VertexBuffer> m_VBOs; //!< Vertex buffers
		static AssetManager<UniformBuffer> m_UBOs; //!< Uniform buffers
		static AssetManager<Material> m_materials; //!< Materials
		static std::map<std::string, std::vector<Character>> m_characters; //!< Renderable characters
		static const int m_ASCIIstart = 32;
		static const int m_ASCIIend = 126;
		static std::shared_ptr<Texture> m_fontTexture; //!< Texture which stroe fonts
		static std::string parseFilePath(const std::string& str); //!< Strip preceding dirs and file extension
	public:
		void start(SystemSignal init = SystemSignal::None, ...) {}; //!< Start the system
		void stop(SystemSignal close = SystemSignal::None, ...) {}; //!< Stop the system - change this to free all resources
		
		static std::shared_ptr<IndexBuffer> addIndexBuffer(const std::string& name, unsigned int* indices, unsigned int count); //!< Add an index buffer
		static std::shared_ptr<Shader> addShader(const std::string& filepath);//!< Add a shader
		static std::shared_ptr<Texture> addTexture(const std::string& filepath);//!< Add a texture by load and import from filename
		static std::shared_ptr<Texture> addTexture(const std::string& name, unsigned int width, unsigned int height, unsigned int channels,  unsigned char * texData);//!< Add a texture with data
		static std::shared_ptr<VertexArray> addVAO(const std::string& name);//!< Add a vertex array
		static std::shared_ptr<VertexBuffer> addVBO(const std::string& name, float* vertices, unsigned int size, VertexBufferLayout& layout);//!< Add a vertex buffer
		static std::shared_ptr<VertexBuffer> addVBO(const std::string& name, void* vertices, unsigned int size, VertexBufferLayout& layout);//!< Add a vertex buffer
		static std::shared_ptr<UniformBuffer> addUBO(const std::string& name, unsigned int size, UniformBufferLayout& layout);//!< Add a uniform buffer, binding all
		static std::shared_ptr<UniformBuffer> addUBO(const std::string& name, unsigned int size, unsigned int rangeStart, unsigned int rangeEnd, UniformBufferLayout& layout);//!< Add a uniform buffer, binding between start and end
		static std::shared_ptr<Material> addMaterial(const std::string & name, const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO);//!< Add a material
		static void populateCharacters(std::unordered_map<std::string, unsigned int> fontsAndSizes);
		static std::shared_ptr<Character> getCharacter(std::string font, unsigned int ASCIIcode);
		inline static std::shared_ptr<Texture> getFontTexture() { return m_fontTexture; };
	};

}