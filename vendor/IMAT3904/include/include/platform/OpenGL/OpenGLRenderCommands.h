#pragma once

#include "rendering/renderCommands.h"

namespace Engine {

	class OpenGLClearColourBufferCommand : public RenderCommand
	{
	private:
		bool m_keepAlive;
	public:
		OpenGLClearColourBufferCommand(bool keepAlive = false) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};

	class OpenGLClearDepthColourBufferCommand : public RenderCommand
	{
	private:
		bool m_keepAlive;
	public:
		OpenGLClearDepthColourBufferCommand(bool keepAlive = false) : m_keepAlive(keepAlive) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};

	class OpenGLSetClearColourCommand : public RenderCommand
	{
	private:
		bool m_keepAlive;
		float m_r, m_g, m_b, m_a;
	public:
		OpenGLSetClearColourCommand(float r, float g, float b, float a, bool keepAlive = false) : m_r(r), m_g(g), m_b(b), m_a(a), m_keepAlive(keepAlive) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};

	class OpenGLSetDepthTestLessCommand : public RenderCommand
	{
	private:
		bool m_enabled;
		bool m_keepAlive;
	public:
		OpenGLSetDepthTestLessCommand(bool enabled, bool keepAlive = false) : m_enabled(enabled), m_keepAlive(keepAlive) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};

	class OpenGLSetBackfaceCullingCommand : public RenderCommand
	{
	private:
		bool m_enabled;
		bool m_keepAlive;
	public:
		OpenGLSetBackfaceCullingCommand(bool enabled, bool keepAlive = false) : m_enabled(enabled), m_keepAlive(keepAlive) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};

	class OpenGLSetOneMinusAlphaBlending : public RenderCommand
	{
	private:
		bool m_enabled;
		bool m_keepAlive;
	public:
		OpenGLSetOneMinusAlphaBlending(bool enabled, bool keepAlive = false) : m_enabled(enabled), m_keepAlive(keepAlive) {};
		void action() override;
		inline bool keepAlive() override { return m_keepAlive; }
	};
}