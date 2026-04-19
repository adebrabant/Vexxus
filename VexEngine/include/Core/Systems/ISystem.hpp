#pragma once

#include "Graphics/IRenderer.hpp"

namespace VexEngine::Core
{
	class World;

	class ISystem
	{
	public:
		virtual ~ISystem() = default;
		virtual void Update(World& world, float deltaTime) = 0;
		virtual void Render(World& world, Graphics::IRenderer& renderer, float alpha) = 0;
	};
}