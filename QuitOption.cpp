#include "QuitOption.h"
#include "EventManager.h"
#include "SDBMCalculator.h"

namespace
{
	constexpr char* const QuitEventString = "QuitEvent";
	constexpr int QuitEventStringLength =
#ifndef constexpr
		constexpr_strlen(QuitEventString);
#else
		9;
#endif
	constexpr int QuitEvent = SDBMCalculator<QuitEventStringLength>::CalculateValue(QuitEventString);
}

void QuitOption::Evaluate(Player& player)
{
	SendEvent(QuitEvent);
}