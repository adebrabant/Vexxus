#pragma once

#include "Graphics/IRenderer.hpp"
#include <cstdint>

namespace VexEngine::Graphics
{
	struct OpenGLRenderProps
	{
		uint32_t Width = 0;
		uint32_t Height = 0;
		float ClearRed = 0.1f;
		float ClearGreen = 0.1f;
		float ClearBlue = 0.1f;
		float ClearAlpha = 1.0f;
	};

	class OpenGLRenderer : public IRenderer
	{
	public:
		OpenGLRenderer(OpenGLRenderProps properties);
		~OpenGLRenderer() = default;
		void Clear() override;

	private:
		OpenGLRenderProps m_properties;
	};
}