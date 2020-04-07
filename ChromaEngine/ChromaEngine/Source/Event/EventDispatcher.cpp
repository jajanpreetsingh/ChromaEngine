#include <Event/EventDispatcher.h>

EventDispatcher::EventDispatcher(Event& event) : event(event)
{
}

template<typename T>
bool EventDispatcher::Dispatch(const EventHandlerFn<T>& func)
{
	if (event.GetEventType() == T::GetStaticType())
	{
		event.IsHandled = func(*(T*)&event);
		return true;
	}
	return false;
}