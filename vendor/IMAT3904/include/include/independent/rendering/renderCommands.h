/** \file renderCommands.h
*/
#pragma once

namespace Engine {

	class RenderCommand
	{
	public:
		virtual void action() = 0;
		virtual bool keepAlive() = 0;
	public:
		static RenderCommand * ClearColourBufferCommand(bool keepAlive = false);
		static RenderCommand * ClearDepthColourBufferCommand(bool keepAlive = false);
		static RenderCommand * setClearColourCommand(float r, float g, float b, float a, bool keepAlive = false);
		static RenderCommand * setDepthTestLessCommand(bool enabled, bool keepAlive = false);
		static RenderCommand * setBackfaceCullingCommand(bool enabled, bool keepAlive = false);
		static RenderCommand * setOneMinusAlphaBlending(bool enabled, bool keepAlive = false);

	};
}