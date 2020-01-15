/** \file OpenGLTexture.h
*/
#pragma once

#include "rendering/texture.h"

namespace Engine {

	class OpenGLTexture : public Texture
	{
	public:
		OpenGLTexture(const std::string& filepath);
		OpenGLTexture(unsigned int width, unsigned int height, unsigned int channels, unsigned char * texData); //!< Currently only load signle channel bitmaps
		~OpenGLTexture();
		inline virtual unsigned int getWidth() const override { return m_width; } //!< Get the width of the texture
		inline virtual unsigned int getHeight() const override { return m_height; }; //!< Get the height of the texture
		inline virtual unsigned int getChannels() const override { return m_channels; }	//!< Get the number of channels of the texture (1 = Greyscale, 3 = RGB, 4 = RGBA)
		inline virtual unsigned int getSlot() const override { return m_TextureSlot; }	//!< Get the memory slot in the GPU where the texture resides
		inline virtual unsigned char * getData() const { return m_data; } //!< Get the texture data
		virtual void bindToSlot(unsigned int slot); //!< Rebind the texture to a given slot
	private:
		unsigned int m_OpenGL_ID; //!< Texture id
		unsigned int m_TextureSlot; //!< GPU slot where texture resides
		unsigned int m_width; //!< Width of the texture in pixels
		unsigned int m_height; //!< Height of the texture in pixels
		unsigned int m_channels; //!< Number of channels (1 = Greyscale, 3 = RGB, 4 = RGBA)
		unsigned char* m_data; //!< Data of the texture

		static unsigned int s_TextureSlot; //!< Next free GPU texture slot 
	};
}