#pragma once

#include "Graphics/IRenderer.hpp"
#include "Graphics/SFMLWindow.hpp"

namespace VexEngine::Graphics
{
	class SFMLRenderer : public IRenderer
	{
	public:
		SFMLRenderer(SFMLWindow& sfmlWindow);
		~SFMLRenderer() override;
		void Clear() override;
		void DrawSprite(/*sprite params*/) override;
		void Display() override;

	private:
		SFMLWindow& m_sfmlWindow;
	};
}