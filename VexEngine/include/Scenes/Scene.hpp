#pragma once

#include "Scenes/ECS/World.hpp"
#include "Graphics/IRenderer.hpp"

namespace VexEngine::Scenes
{
	class Scene
	{
	public:
		Scene();
		virtual ~Scene() = default;
		virtual void Load() = 0;
		virtual void Unload() = 0;
		virtual void Update(float deltaTime);
		virtual void Render(Graphics::IRenderer& renderer, float alpha);

	protected:
		World m_world;
	};
}