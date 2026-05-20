#pragma once

#include "Scenes/Systems/ISystem.hpp"
#include "Graphics/IRenderer.hpp"

namespace VexEngine::Scenes
{
	class MovementSystem : public ISystem
	{
		void Update(World& world, float deltaTime) override;
		void Render(World& world, Graphics::IRenderer& renderer, float alpha) override;
	};
}