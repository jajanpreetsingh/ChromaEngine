#pragma once

#include "Event/Event.h"
#include "MouseCode.h"

class MouseButtonEvent : public Event
{
public:
	inline MouseCode GetMouseButton() const;

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

protected:

	MouseButtonEvent(MouseCode button);

	MouseCode button;
};