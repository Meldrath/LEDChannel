#include "ledChannel.h"
#include "Arduino.h"


LEDChannel::LEDChannel(uint32_t channel)
{
	_channel = channel;
}

void LEDChannel::setFade(uint32_t fadeTime)
{
	_fadeTime = fadeTime;
}

void LEDChannel::setPin(uint32_t pin)
{
	_pin = pin;
}

void LEDChannel::setTotal(uint32_t totalTime)
{
	_totalTime = totalTime;
}

void LEDChannel::setStart(uint32_t startTime)
{
	_startTime = startTime;
}

void LEDChannel::setIntensity(uint32_t intensity)
{
	_intensity = intensity;
}

void LEDChannel::setLEDChannel(uint32_t channel, uint32_t pin, uint32_t startTime, uint32_t fadeTime, uint32_t totalTime, uint32_t intensity)
{
	_channel = channel;
	_pin = pin;
	_startTime = startTime;
	_fadeTime = fadeTime;
	_totalTime = totalTime;
	_intensity = intensity;
}

int LEDChannel::getPin()
{
	return _pin;
}

int LEDChannel::pwm(int minutes)
{
	uint32_t pwm = 0;

	if (minutes > _startTime || minutes <= (_startTime + _fadeTime))
	{
		pwm = map((minutes - _startTime), 0, _fadeTime, 0, _intensity);
	}

	if (minutes > ((_startTime + _totalTime) - _fadeTime) && minutes <= (_startTime + _totalTime))
	{
		pwm = map((minutes - (_startTime + _totalTime - _fadeTime)), 0, _fadeTime, _intensity, 0);
	}

	if (minutes <= _startTime || minutes > _startTime + _totalTime)
	{
		if ((_startTime + _totalTime ) % 1440 < _startTime && (_startTime + _totalTime) % 1440 > minutes)
		{
			pwm = map(((_startTime + _totalTime) - minutes) % 1440, 0, _fadeTime, 0, _intensity);
		}
		else
		{
			pwm = 0;
		}
	}

	if (pwm > _intensity)
	{
		pwm = _intensity;
	}

	if (pwm < 0)
	{
		pwm = 0;
	}

	analogWrite(_pin, map(pwm, 0, 100, 0, 255));

	return pwm;
}

