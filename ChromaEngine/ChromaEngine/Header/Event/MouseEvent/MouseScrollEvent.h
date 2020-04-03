#pragma once

#include "Event/Event.h"

class MouseScrolledEvent : public Event
{
public:

	MouseScrolledEvent(float xOffset, float yOffset);

	inline float GetXOffset() const;
	inline float GetYOffset() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:

	float xOffset, yOffset;
};