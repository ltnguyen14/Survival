#include "EventNode.h"

EventNode::EventNode()
{
}


EventNode::~EventNode()
{
}

void EventNode::AddEventBus(EventBus * eventBus)
{
	m_eventBuses.push_back(eventBus);
}

std::function<void(Event)> EventNode::GetNotifyFunction()
{
	auto eventListener = [=](Event event) -> void {
		this->OnNotify(event);
	};
	return eventListener;
}

void EventNode::SendEvent(Event event)
{
	for (auto eventBus : m_eventBuses) {
		eventBus->AddEvent(&event);
	}
}
