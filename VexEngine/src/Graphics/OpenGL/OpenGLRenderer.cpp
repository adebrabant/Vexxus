#include "Graphics/OpenGL/OpenGLRenderer.hpp"

#include <GL/glew.h>

namespace VexEngine::Graphics
{
	OpenGLRenderer::OpenGLRenderer(OpenGLRenderProps properties) :
		m_properties(properties)
	{
		glViewport(
			0,
			0,
			static_cast<GLsizei>(properties.Width),
			static_cast<GLsizei>(properties.Height)
		);
	}

	void OpenGLRenderer::Clear()
	{
		glClearColor(
			m_properties.ClearRed,
			m_properties.ClearGreen,
			m_properties.ClearBlue,
			m_properties.ClearAlpha
		);

		glClear(GL_COLOR_BUFFER_BIT);
	}
}