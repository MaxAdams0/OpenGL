#pragma once
#ifndef CLOCK_CLASS_HPP
#define CLOCK_CLASS_HPP

class Clock
{
	private:
		float hour_hand_rot; // 360° per hour
		float minute_hand_rot; // 21600° per hour
		float second_hand_rot; // 1296000° per hour
	public:
		long int getTime();
};

#endif
