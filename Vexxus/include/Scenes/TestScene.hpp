#pragma once

#include "Scenes/Scene.hpp"

namespace Vexxus
{
	class TestScene : public VexEngine::Scenes::Scene
	{
	public:
		TestScene() = default;
		~TestScene() = default;
		void Load() override;
		void Unload() override;

	private:

	};
}