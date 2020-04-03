#include "Event\MouseEvent\MouseButtonReleasedEvent.h"
#include <sstream>

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseCode button) : MouseButtonEvent(button)
{
}

std::string MouseButtonReleasedEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseButtonReleasedEvent: " << button;
	return ss.str();
}
