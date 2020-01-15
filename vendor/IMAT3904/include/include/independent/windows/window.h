/** \file window.h
*/
#pragma once

#include "graphicsContext.h"
#include <string>
#include <functional>

namespace Engine {

	class Event; // Be replaced

	struct WindowProperties
	{
		std::string m_title; //!< Title in titlebar
		unsigned int m_width; //!< Width in px
		unsigned int m_height; //!< Height in px
		bool m_isFullScreen; //!< is it fullscreen?
		bool m_isVSync; //!< Is vSync enabled

		WindowProperties(const std::string& title = "My Window", unsigned int width = 800, unsigned int height = 600, bool fullscreen = false) :
			m_title(title), m_width(width), m_height(height), m_isFullScreen(fullscreen) {}
	};

	class Window
	{
	public:
		virtual void init(const WindowProperties& properties) = 0; //!< Init function
		virtual void close() = 0; //!< Close the window
		virtual ~Window() {};
		virtual void onUpdate(float timestep) = 0; //!< Run every frame
		virtual void onResize(unsigned int width, unsigned int height) = 0; //!< Run when the windo is resized
		virtual void setVSync(bool VSync) = 0; //!< Set vSync
		virtual void setEventCallback(const std::function<void(Event&)>& callback) = 0; //!< Set the callback function
		virtual unsigned int getWidth() const = 0; //!< Return the width
		virtual unsigned int getHeight() const = 0; //!< Return the height
		virtual void* getNativeWindow() const = 0; //!< Return the native window
		virtual bool isFullScreenMode() const = 0; //!< Are we in full screen mode
		virtual bool isVSync() const = 0; //!< IS VSYNC enabled

		static Window* create(const WindowProperties& properties = WindowProperties()); //!< Create an API specific window
	protected:
		std::shared_ptr<GraphicsContext> m_context; //!< Graphics context
	};
}