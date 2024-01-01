#pragma once

class Event;

class EventHandler
{
public:
	virtual void HandleEvent(const Event* event) = 0;
};

