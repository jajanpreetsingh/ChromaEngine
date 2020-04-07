#include <Core/MSWindow.h>
#include <Logging/Log.h>
#include <Event/KeyEvent/KeyEvent.h>
#include <Event/KeyEvent/KeyPressedEvent.h>
#include <Event/KeyEvent/KeyReleasedEvent.h>
#include <Event/ApplicationEvent/WindowResizeEvent.h>
#include <Event/ApplicationEvent/WindowCloseEvent.h>
#include <Event/MouseEvent/MouseCode.h>
#include <Event/MouseEvent/MouseScrollEvent.h>
#include <Event/MouseEvent/MouseMoveEvent.h>
#include <Event/MouseEvent/MouseButtonReleasedEvent.h>
#include <Event/MouseEvent/MouseButtonPressedEvent.h>
#include <Event/KeyEvent/KeyTypedEvent.h>

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

void MSWindow::SetEventCallback(const EventCallbackFn& callback)
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

	glfwSetWindowSizeCallback(glWindow, [](GLFWwindow* target, int newWidth, int newHeight)
		{
			((MSWindow*)target)->OnResize(target, newWidth, newHeight);
		});

	glfwSetWindowCloseCallback(glWindow, [](GLFWwindow* target)
		{
			((MSWindow*)target)->OnClose(target);
		});

	glfwSetKeyCallback(glWindow, [](GLFWwindow* target, int key, int scancode, int action, int mods)
		{
			((MSWindow*)target)->OnKeyEvent(target, key, scancode, action, mods);
		});

	glfwSetCharCallback(glWindow, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(static_cast<KeyCode>(keycode));
			data.callback(event);
		});

	glfwSetMouseButtonCallback(glWindow, [](GLFWwindow* target, int button, int action, int mods)
		{
			((MSWindow*)target)->OnMouseButtonEvent(target, button, action, mods);
		});

	glfwSetScrollCallback(glWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.callback(event);
		});

	glfwSetCursorPosCallback(glWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event((float)xPos, (float)yPos);
			data.callback(event);
		});
}

void MSWindow::Shutdown()
{
	glfwDestroyWindow(glWindow);
}

void MSWindow::OnResize(GLFWwindow* target, int newWidth, int newHeight)
{
	WindowProps& wp = *(WindowProps*)glfwGetWindowUserPointer(target);
	wp.Width = newWidth;
	wp.Height = newHeight;

	WindowResizeEvent rse(newWidth, newHeight);

	CHROMA_INFO(rse.ToString());

	wp.callback(rse);
}

void MSWindow::OnClose(GLFWwindow* target)
{
	WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(target);
	WindowCloseEvent event;
	data.callback(event);
}

void MSWindow::OnKeyEvent(GLFWwindow* target, int key, int scanCode, int action, int mods)
{
	WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(target);

	switch (action)
	{
	case GLFW_PRESS:
	{
		KeyPressedEvent event(static_cast<KeyCode>(key), 0);
		data.callback(event);
		break;
	}
	case GLFW_RELEASE:
	{
		KeyReleasedEvent event(static_cast<KeyCode>(key));
		data.callback(event);
		break;
	}
	case GLFW_REPEAT:
	{
		KeyPressedEvent event(static_cast<KeyCode>(key), 1);
		data.callback(event);
		break;
	}
	}
}

void MSWindow::OnMouseButtonEvent(GLFWwindow* target, int button, int action, int mods)
{
	WindowProps& data = *(WindowProps*)glfwGetWindowUserPointer(target);

	switch (action)
	{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent event(static_cast<MouseCode>(button));
			data.callback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
			data.callback(event);
			break;
		}
	}
}

Window* Window::Create(const WindowProps& props)
{
	return new MSWindow(props);
}