#pragma once
#include "Event.h"

#include <vector>
#include <queue>
#include <functional>

class EventBus
{
public:
	EventBus();
	virtual ~EventBus();

	void AddConsumer(std::function<void (Event)> consumer);
	void AddEvent(Event* event);
	void Notify();

private:
	std::vector<std::function<void (Event)>> m_consumers;
	std::queue<Event> m_events;
};

