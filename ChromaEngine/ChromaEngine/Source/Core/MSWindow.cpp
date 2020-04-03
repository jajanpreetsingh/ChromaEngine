#include "Core/MSWindow.h"
#include "Logging/Log.h"


bool MSWindow::glfwInitialized = false;

MSWindow::MSWindow(const WindowProps& props) : props(props)
{
	Init();
}

MSWindow::~MSWindow()
{
	Shutdown();
}

void MSWindow::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(glWindow);
}

inline unsigned int MSWindow::GetWidth() const
{
	return props.Width;
}

inline unsigned int MSWindow::GetHeight() const
{
	return props.Height;
}

inline void MSWindow::SetEventCallback(const EventCallbackFn& callback)
{
	props.callback = callback;
}

void MSWindow::SetVSync(bool enabled)
{
	props.VSync = enabled;

	glfwSwapInterval(props.VSync ? 1 : 0);
}

bool MSWindow::IsVSync() const
{
	return props.VSync;
}

void MSWindow::Init()
{
	if (!glfwInitialized)
	{
		int success = glfwInit();

		CHROMA_ASSERT(success, "Failed to init glfw");
		CHROMA_INFO("success to init glfw");

		glfwInitialized = true;
	}

	glWindow = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(glWindow);
	glfwSetWindowUserPointer(glWindow, &props);
	SetVSync(props.VSync);
}

void MSWindow::Shutdown()
{
	glfwDestroyWindow(glWindow);
}

Window* Window::Create(const WindowProps& props)
{
	return new MSWindow(props);
}
