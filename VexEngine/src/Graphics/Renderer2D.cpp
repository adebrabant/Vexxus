#include "Graphics/Renderer2D.hpp"

namespace VexEngine::Graphics
{
	Renderer2D::Renderer2D(IGraphicsDevice& graphicsDevice) :
		m_graphicsDevice(graphicsDevice)
	{

	}

	void Renderer2D::Clear()
	{
		m_graphicsDevice.Clear();
	}
}