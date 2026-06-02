#pragma once

#include <cstdint>

namespace Cocoa::Graphics
{
	class OpenGLIndexBuffer
	{
	public:
		OpenGLIndexBuffer(const uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		OpenGLIndexBuffer(const OpenGLIndexBuffer&) = delete;
		OpenGLIndexBuffer& operator=(const OpenGLIndexBuffer&) = delete;

		OpenGLIndexBuffer(OpenGLIndexBuffer&& other) noexcept;
		OpenGLIndexBuffer& operator=(OpenGLIndexBuffer&& other) noexcept;

		void Bind() const;
		void Unbind() const;
		uint32_t GetCount() const;

	private:
		void Destroy();

	private:
		uint32_t m_ibo;
		uint32_t m_count;
	};
}