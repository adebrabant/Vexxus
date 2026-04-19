#pragma once

namespace VexEngine::Graphics
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;
		virtual void Clear() = 0;
		virtual void DrawSprite(/*sprite params*/) = 0;
		virtual void Display() = 0;
	};
}