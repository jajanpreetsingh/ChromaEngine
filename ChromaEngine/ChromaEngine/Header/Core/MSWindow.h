#pragma once

#include "Event/Event.h"
#include "Contract/Window.h"
#include "GLFW/glfw3.h"

class MSWindow : public Window
{
public:

	static bool glfwInitialized;
	MSWindow(WindowProps props);

	virtual ~MSWindow();

	void OnUpdate() override;

	inline unsigned int GetWidth() const override;
	inline unsigned int GetHeight() const override;

	inline void SetEventCallback(const EventCallbackFn& callback) override;

	void SetVSync(bool enabled) override;
	bool IsVSync() const override;

	inline virtual void* GetNativeWindow() const { return glWindow; }

private:
	virtual void Init();
	virtual void Shutdown();

	GLFWwindow* glWindow;
	//GraphicsContext* graphicsContext;

	WindowProps props;
};
