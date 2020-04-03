#pragma once

#include "Core/APIMacros.h"

enum class EventType
{
	None = 0,

	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,

	AppTick,
	AppUpdate,
	AppRender,

	KeyPressed,
	KeyReleased,
	KeyTyped,

	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication = BIT(0),	//means shifted by n bits so 00000001
	EventCategoryInput = BIT(1),		//00000010
	EventCategoryKeyboard = BIT(2),		//00000100
	EventCategoryMouse = BIT(3),		//00001000
	EventCategoryMouseButton = BIT(4)	//00010000
};