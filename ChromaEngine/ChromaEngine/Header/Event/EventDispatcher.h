#pragma once

#include <Event/Event.h>
#include <functional>

class EventDispatcher
{
	template<typename T>
	using EventHandlerFn = std::function<bool(T&)>;
public:

	EventDispatcher(Event& event);

	template<typename T>
	bool Dispatch(const EventHandlerFn<T>& func);

private:

	Event& event;
};