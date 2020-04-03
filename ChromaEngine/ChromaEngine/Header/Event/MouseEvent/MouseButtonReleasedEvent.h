#pragma once

#include "Event/MouseEvent/MouseButtonEvent.h"

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(MouseCode button);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseButtonReleased)
};