#include "Event/EventDispatcher.h"

EventDispatcher::EventDispatcher(Event& event) : event(event)
{
}

template<typename T, typename F>
bool EventDispatcher::Dispatch(const F& func)
{
	if (event.GetEventType() == T::GetStaticType())
	{
		event.IsHandled = func(static_cast<T&>(event));
		return true;
	}
	return false;
}