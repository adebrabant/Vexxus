#pragma once

namespace VexEngine::Graphics
{
	class IWindow
	{
	public:
		virtual ~IWindow() = default;
		virtual void Open() = 0;
		virtual bool IsOpen() = 0;
		virtual void Close() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
	};
}