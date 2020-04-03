#include "Event/MouseEvent/MouseMoveEvent.h"
#include <sstream>

MouseMoveEvent::MouseMoveEvent(float x, float y) : mouseX(x), mouseY(y)
{
}

inline float MouseMoveEvent::GetX() const
{
	return mouseX;
}

inline float MouseMoveEvent::GetY() const
{
	return mouseY;
}

std::string MouseMoveEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
	return ss.str();
}