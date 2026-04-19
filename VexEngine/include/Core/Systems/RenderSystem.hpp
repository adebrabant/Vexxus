#pragma once

#include "Core/Systems/ISystem.hpp"
#include "Graphics/IRenderer.hpp"

namespace VexEngine::Core
{
	class RenderSystem : public ISystem
	{
		void Update(World& world, float deltaTime) override;
		void Render(World& world, Graphics::IRenderer& renderer, float alpha) override;
	};
}