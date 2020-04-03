#pragma once

#include <string>
#include <functional>

using EventCallbackFn = std::function<void(Event&)>;

struct WindowProps
{
	std::string Title;
	unsigned int Width;
	unsigned int Height;
	bool VSync;
	//EventCallbackFn callback;

	WindowProps(
		unsigned int width,
		unsigned int height, 
		std::string title,
		bool vsync = false)
		: Title(title), Width(width), Height(height), VSync(vsync)
	{
	}
};

// Interface representing a desktop system based Window
class Window
{
public:

	virtual ~Window() = default;

	virtual void OnUpdate() = 0;

	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	// Window attributes
	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
	virtual void SetVSync(bool enabled) = 0;
	virtual bool IsVSync() const = 0;

	virtual void* GetNativeWindow() const = 0;

	static Window* Create(WindowProps props);
};