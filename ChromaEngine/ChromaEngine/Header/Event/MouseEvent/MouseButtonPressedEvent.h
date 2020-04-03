#pragma once

#include "Event/MouseEvent/MouseButtonEvent.h"

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(MouseCode button);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseButtonPressed)
};