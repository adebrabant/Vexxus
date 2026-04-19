#include "GameApplication.hpp"
#include "Application.hpp"
#include "Scenes/TestScene.hpp"

namespace Vexxus
{
	GameApplication::GameApplication() 
		: Application(800, 600, "Vexxus")
	{
		m_sceneManager.AddScene<TestScene>();
		m_sceneManager.SetScene<TestScene>();
	}
}