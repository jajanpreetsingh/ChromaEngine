#pragma once

#include "Event/KeyEvent/KeyTypedEvent.h"
#include <sstream>


KeyTypedEvent::KeyTypedEvent(KeyCode keycode) : KeyEvent(keycode) 
{
}

std::string KeyTypedEvent::ToString() const
{
	std::stringstream ss;
	ss << "KeyTypedEvent: " << keyCode;
	return ss.str();
}