#include "TrigLut.h"

TrigTableLookup TrigLUT;

TrigTableLookup::TrigTableLookup()
{
	for (int i = 0; i <= HalfPi; i++)
		_cosTable[i] = std::cos(i * M_PI / Pi);
}

float TrigTableLookup::cos(int angle) const
{
	angle &= TwoPiMask;

	if (angle > Pi)
		angle = TwoPi - angle;

	if (angle < HalfPi)
		return _cosTable[angle];
	else
		return -_cosTable[Pi - angle];
}

float TrigTableLookup::sin(int angle) const
{
	return cos(angle - HalfPi);
}

int TrigTableLookup::atan2(int x, int y) const
{
	const auto angle = std::atan2(static_cast<double>(y), static_cast<double>(x));

	return static_cast<int>(angle / M_PI * Pi) & TwoPiMask;
}
