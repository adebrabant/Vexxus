#pragma once

namespace VexEngine::Graphics
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;
		virtual void Clear() = 0;
	};
}