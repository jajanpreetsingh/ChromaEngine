#pragma once

#include "Event/KeyEvent/KeyEvent.h"
#include "KeyCode.h"

class KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(KeyCode keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyReleased)
};