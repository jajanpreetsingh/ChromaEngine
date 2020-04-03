#include "Event\Event.h"

inline bool Event::IsInCategory(EventCategory category)
{
	return GetCategoryFlags() & category;
}