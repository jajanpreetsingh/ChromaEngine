#pragma once

#include "Event/Event.h"
#include "KeyEvent.h"
#include "KeyCode.h"

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(KeyCode keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyTyped)
};