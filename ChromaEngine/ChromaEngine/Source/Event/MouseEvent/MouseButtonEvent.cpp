#include "Event\MouseEvent\MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(MouseCode button) : button(button)
{

}

inline MouseCode MouseButtonEvent::GetMouseButton() const
{
	return button;
}
