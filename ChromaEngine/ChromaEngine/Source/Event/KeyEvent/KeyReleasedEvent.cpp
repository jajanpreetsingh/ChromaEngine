#pragma once

#include "Event/KeyEvent/KeyReleasedEvent.h"
#include <sstream>

KeyReleasedEvent::KeyReleasedEvent(KeyCode keycode)	: KeyEvent(keycode) 
{

}

std::string KeyReleasedEvent::ToString() const
{
	std::stringstream ss;
	ss << "KeyReleasedEvent: " << keyCode;
	return ss.str();
}