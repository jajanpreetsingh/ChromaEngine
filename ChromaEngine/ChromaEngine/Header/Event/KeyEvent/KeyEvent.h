#pragma once

#include "Event/Event.h"
#include "KeyCode.h"

class KeyEvent : public Event
{
public:
	inline KeyCode GetKeyCode() const;

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(KeyCode keycode);

	KeyCode keyCode;
};