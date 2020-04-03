#include "Event\MouseEvent\MouseButtonPressedEvent.h"
#include <sstream>

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseCode button) : MouseButtonEvent(button)
{
}

std::string MouseButtonPressedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonPressedEvent: " << button;
	return ss.str();
}