#include "Event/KeyEvent/KeyEvent.h"

KeyEvent::KeyEvent(KeyCode keycode)	: keyCode(keycode)
{
}

inline KeyCode KeyEvent::GetKeyCode() const { return keyCode; }