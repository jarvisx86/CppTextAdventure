#pragma once

#include "Entity.h"
#include "Option.h"

#include <array>
#include <map>
#include <vector>

class Room : public Entity
{
public:
	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	using JoiningRooms = std::array<Room*, static_cast<size_t>(JoiningDirections::Max)>;
	JoiningRooms m_pJoiningRooms;

	using StaticOptions = std::map<unsigned int, Option*>;
	StaticOptions m_staticOptions;
	unsigned int m_staticOptionsKey{ 1 };

	using DynamicOptions = std::vector<Option*>;
	DynamicOptions m_dynamicOptions;

public:
	void AddRoom(JoiningDirections direction, Room* pRoom);
	Room* GetRoom(JoiningDirections direction) const;

	void AddStaticOption(Option* option);
	void AddDynamicOption(Option* option);
	void PrintOptions() const;
	
	Option* EvaluateInput(unsigned int playerInput);

	Room();

};

