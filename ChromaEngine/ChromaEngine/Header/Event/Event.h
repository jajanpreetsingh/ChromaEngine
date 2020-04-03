#pragma once

#include "EventTypes.h"
#include <iostream>
#include <string>

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

class Event
{
public:

	bool IsHandled = false;

	virtual EventType GetEventType() const = 0;

	virtual const char* GetName() const = 0;

	virtual int GetCategoryFlags() const = 0;

	virtual std::string ToString() const { return GetName(); }

	inline bool IsInCategory(EventCategory category);	
};

inline std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << e.ToString();
}
