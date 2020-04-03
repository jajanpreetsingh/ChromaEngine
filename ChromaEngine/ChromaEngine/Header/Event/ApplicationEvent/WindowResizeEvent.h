#pragma once

#include "Event/Event.h"

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(unsigned int width, unsigned int height);

	inline unsigned int GetWidth() const;
	inline unsigned int GetHeight() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
	unsigned int width, height;
};