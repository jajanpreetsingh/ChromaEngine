#pragma once

#include "Event.h"

class EventDispatcher
{
public:

	EventDispatcher(Event& event);

	// F will be deduced by the compiler
	template<typename T, typename F>
	bool Dispatch(const F& func);

private:

	Event& event;
};