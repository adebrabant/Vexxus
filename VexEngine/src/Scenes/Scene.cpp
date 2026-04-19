#include "Scenes/Scene.hpp"
#include "Graphics/IRenderer.hpp"

namespace VexEngine::Scenes
{
	Scene::Scene() :
		m_world()
	{

	}

	void Scene::Update(float deltaTime)
	{
		m_world.Update(deltaTime);
	}

	void Scene::Render(Graphics::IRenderer & renderer, float alpha)
	{
		m_world.Render(renderer, alpha);
	}
}