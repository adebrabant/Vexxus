#pragma once

#include "Core/Systems/ISystem.hpp"
#include "Core/ECS/World.hpp"
#include "Graphics/IRenderer.hpp"
#include "Inputs/InputHandler.hpp"

namespace Vexxus::Systems
{
	class InputSystem : public VexEngine::Core::ISystem
	{
	public:
		InputSystem();
		~InputSystem() = default;
		void Update(VexEngine::Core::World& world, float deltaTime) override;
		void Render(VexEngine::Core::World& world, VexEngine::Graphics::IRenderer& renderer, float alpha) override;

	private:
		VexEngine::Inputs::InputHandler m_inputHandler;
	};
}