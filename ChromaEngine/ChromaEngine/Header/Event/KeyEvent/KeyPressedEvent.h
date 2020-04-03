#pragma once

#include "Event/KeyEvent/KeyEvent.h"
#include <sstream>

class KeyPressedEvent : public KeyEvent
{
public:

	KeyPressedEvent(KeyCode keycode, int repeatCount);

	inline int GetRepeatCount() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyPressed)

private:

	int repeatCount;
};