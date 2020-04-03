#pragma once

#include "Event\ApplicationEvent\WindowResizeEvent.h"
#include <sstream>

WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
	: width(width), height(height)
{
}

inline unsigned int WindowResizeEvent::GetWidth() const
{
	return width;
}

inline unsigned int WindowResizeEvent::GetHeight() const
{
	return height;
}

std::string WindowResizeEvent::ToString() const
{
	std::stringstream ss;
	ss << "WindowResizeEvent: " << width << ", " << height;
	return ss.str();
}
