#include "Scenes/TestScene.hpp"
#include "Core/Components/TransformComponent.hpp"
#include "Core/Components/CameraComponent.hpp"
#include "Core/Systems/CameraSystem.hpp"

namespace Vexxus
{
    void TestScene::Load()
    {
        auto cameraEntity = m_world.CreateEntity();
        m_world.AddComponent(cameraEntity, VexEngine::Core::TransformComponent{ 0, 0, 0, 0, 0 });
        m_world.AddComponent(cameraEntity, VexEngine::Core::CameraComponent{ 0, 0, 0, 60.0f });
        m_world.AddSystem<VexEngine::Core::CameraSystem>();
    }

	void TestScene::Unload()
	{

	}
}