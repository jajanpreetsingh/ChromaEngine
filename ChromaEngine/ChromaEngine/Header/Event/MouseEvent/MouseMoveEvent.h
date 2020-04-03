#pragma once

#include "Event/Event.h"

class MouseMoveEvent : public Event
{
public:

	MouseMoveEvent(float x, float y);

	inline float GetX() const;
	inline float GetY() const;

	virtual std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseMoved)

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:

	float mouseX, mouseY;
};