#pragma once

#include "Event/KeyEvent/KeyPressedEvent.h"

KeyPressedEvent::KeyPressedEvent(KeyCode keycode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount)
{
}

std::string KeyPressedEvent::ToString() const
{
	std::stringstream ss;
	ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
	return ss.str();
}

inline int KeyPressedEvent::GetRepeatCount() const
{
	return repeatCount;
}