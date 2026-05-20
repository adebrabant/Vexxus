#pragma once

#include "Scenes/Systems/ISystem.hpp"
#include "Scenes/ECS/World.hpp"
#include "Graphics/IRenderer.hpp"
#include "Inputs/InputHandler.hpp"

namespace Vexxus::Systems
{
	class InputSystem : public VexEngine::Scenes::ISystem
	{
	public:
		InputSystem();
		~InputSystem() = default;
		void Update(VexEngine::Scenes::World& world, float deltaTime) override;
		void Render(VexEngine::Scenes::World& world, VexEngine::Graphics::IRenderer& renderer, float alpha) override;

	private:
		VexEngine::Inputs::InputHandler m_inputHandler;
	};
}