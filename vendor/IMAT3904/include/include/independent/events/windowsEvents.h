/** \file windowsEvents.h
*/
#pragma once

#include "event.h"

#include <glm/glm.hpp>

namespace Engine {
	/** \class WindowCloseEvent Captures data when the window is closed*/
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		static EventType getStaticType() { return EventType::WindowClose; }
		EventType getEventType() const override { return EventType::WindowClose; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
	};

	/** \class WindowResizeEvent Captures data when the window is resized*/
	class WindowResizeEvent : public Event
	{
	private:
		int m_width;
		int m_height;
	public:
		WindowResizeEvent(int width, int height) : m_width(width), m_height(height) {}
		static EventType getStaticType() { return EventType::WindowResize; }
		virtual EventType getEventType() const override { return EventType::WindowResize; }
		virtual int getCategoryFlags() const override { return EventCategoryWindow; }

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }
		inline int getSize() const { glm::ivec2(m_width, m_height); }
	};

	/** \class WindowLostFocusEvent Captures data when the window loses focus*/
	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}
		static EventType getStaticType() { return EventType::WindowLostFocus; }
		EventType getEventType() const override { return EventType::WindowLostFocus; }
		int getCategoryFlags() const override { return EventCategoryWindow; }
	};

	/** \class WindowMovedEvent Captures data when the window is moved*/
	class WindowMovedEvent : public Event
	{
	private:
		int m_xPos;
		int m_yPos;
	public:
		WindowMovedEvent(int x, int y) : m_xPos(x), m_yPos(y) {}
		static EventType getStaticType() { return EventType::WindowMoved; }
		virtual EventType getEventType() const override { return EventType::WindowMoved; }
		virtual int getCategoryFlags() const override { return EventCategoryWindow; }

		inline int getXPos() const { return m_xPos; }
		inline int getYPos() const { return m_yPos; }
		inline glm::ivec2 getPos() const { glm::ivec2(m_xPos, m_yPos); }
	};
}

