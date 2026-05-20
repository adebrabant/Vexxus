#pragma once

#include "Scenes/Systems/ISystem.hpp"
#include <Graphics/IRenderer.hpp>

namespace VexEngine::Scenes
{
	class World;

	class CollisionSystem : public ISystem
	{
	public:
		CollisionSystem() = default;
		void Update(World& world, float deltaTime) override;
		void Render(World& world, Graphics::IRenderer& renderer, float alpha) override;
	};
}