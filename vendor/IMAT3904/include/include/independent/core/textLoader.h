#pragma once

#include <string>
#include <fstream>
#include <sstream>

// Temporary until we use ASSIMP
namespace Engine
{
	class TextModel
	{
	public:
		TextModel() : vertices(nullptr), indices(nullptr), verticesCount(0), indicesCount(0), shader(nullptr), texture(nullptr) {}
		~TextModel()
		{

		}
		float * vertices; //!< Vertice in the model
		unsigned int* indices; //!< Indices in the model
		unsigned int verticesCount; //!< Number of vertices in the model
		unsigned int indicesCount; //!< Number of indices in the model
		std::shared_ptr<Shader> shader; //!< Shader file used to render the model
		std::shared_ptr<Texture> texture; //!< Texture (single) associated with the model
	};

	class TextLoader
	{
	public:
		static bool loadModel(std::shared_ptr<ResourceManager> res, const std::string& filepath, TextModel& model) //!< Load a model from file
		{
			std::fstream handle(filepath, std::ios::in);
			if (!handle.is_open()) return false;

			std::string line;
			std::stringstream ss;

			// Read vertex size
			getline(handle, line);
			ss.str(line);
			if (!ss.eof())
			{
				ss >> model.verticesCount;
				if (model.verticesCount <= 0) return false;
			}
			else return false;

			// Set up vertex array
			model.vertices = new float[model.verticesCount];

			// read vertex data
			getline(handle, line);
			float value;

			ss.clear();
			ss.str(line);
			int i = 0;
			while (!ss.eof())
			{
				ss >> value;
				model.vertices[i] = value;
				i++;
			}

			// Read indices size
			getline(handle, line);
			ss.clear();
			ss.str(line);
			if (!ss.eof())
			{
				ss >> model.indicesCount;
				if (model.indicesCount <= 0) return false;
			}
			else
			{
				return false;
			}

			// Set up array
			model.indices = new unsigned int[model.indicesCount];

			// read data
			getline(handle, line);
			unsigned int value2;

			ss.clear();
			ss.str(line);
			i = 0;
			while (!ss.eof())
			{
				ss >> value2;
				model.indices[i] = value2;
				i++;
			}

			// read Shader
			getline(handle, line);
			if (line.compare("NULL") != 0)
			{
				model.shader = res->addShader(line);
			}
			else model.texture = nullptr;

			// read texture
			getline(handle, line);
			if (line.compare("NULL") != 0)
			{
				model.texture = res->addTexture(line);
			}
			else model.texture = nullptr;			
		}
	};
}