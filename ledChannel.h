#ifndef ledChannel_h
#define ledChannel_h

#include "Arduino.h"

class LEDChannel
{
	public:
		LEDChannel(uint32_t channel);
		void setFade(uint32_t fadeTime);
		void setPin(uint32_t pin);
		void setTotal(uint32_t totalTime);
		void setStart(uint32_t startTime);
		void setIntensity(uint32_t intensity);
		void setLEDChannel(uint32_t channel, uint32_t pin, uint32_t startTime, uint32_t fadeTime, uint32_t totalTime, uint32_t intensity);
		int pwm(int minuntes);
		int getPin();
	private:
		uint32_t _channel;
		uint32_t _pin;
		uint32_t _startTime;
		uint32_t _fadeTime;
		uint32_t _totalTime;
		uint32_t _intensity;
};

#endif