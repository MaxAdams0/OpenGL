#include"Clock.hpp"
#include<ctime>

long int Clock::getTime() {
	std::time_t currentTime = std::time(nullptr);
	return static_cast<long int>(currentTime);
}