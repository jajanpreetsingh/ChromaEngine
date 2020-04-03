#include "Event\MouseEvent\MouseScrollEvent.h"
#include <sstream>

MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset)
{
}

inline float MouseScrolledEvent::GetXOffset() const
{
	return xOffset;
}

inline float MouseScrolledEvent::GetYOffset() const
{
	return yOffset;
}

std::string MouseScrolledEvent::ToString() const
{
	std::stringstream ss;
	ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
	return ss.str();
}