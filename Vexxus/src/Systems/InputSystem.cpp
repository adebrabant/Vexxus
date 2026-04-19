#include "Systems/InputSystem.hpp"
#include "Core/ECS/World.hpp"
#include "Core/ECS/View.hpp"
#include "Graphics/IRenderer.hpp"
#include "Core/Components/VelocityComponent.hpp"	

namespace Vexxus::Systems
{
	InputSystem::InputSystem() :
		m_inputHandler()
	{

	}

	void InputSystem::Update(VexEngine::Core::World& world, float deltaTime)
	{
		VexEngine::Core::View<VexEngine::Core::VelocityComponent> view(world);
		for (auto [velocity] : view)
		{
			if (m_inputHandler.IsUpPressed())
			{
				velocity.DeltaY -= 0.5f * deltaTime;
			}
			if (m_inputHandler.IsDownPressed())
			{
				velocity.DeltaY += 0.5f * deltaTime;
			}

			if (m_inputHandler.IsRightPressed())
			{
				velocity.DeltaX += 0.5f * deltaTime;
			}
			
			if (m_inputHandler.IsLeftPressed())
			{
				velocity.DeltaX -= 0.5f * deltaTime;
			}

			velocity.DeltaX = 0.0f;
			velocity.DeltaY = 0.0f;
		}
	}

	void InputSystem::Render(VexEngine::Core::World& world, VexEngine::Graphics::IRenderer& renderer, float alpha)
	{

	}
}