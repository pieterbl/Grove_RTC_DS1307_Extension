/*
 MIT License

 Copyright (c) 2020 Pieter Bloemendaal (https://github.com/pieterbl)

 Project Grove_RTC_DS1307_Extension
 (https://github.com/pieterbl/Grove_RTC_DS1307_Extension)

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#ifndef __GROVE_RTC_DS1307_EXTENSION_HPP__
#define __GROVE_RTC_DS1307_EXTENSION_HPP__

#include <Arduino.h>
#include "DS1307.h"

class String;

class GroveRtcDs1307: public DS1307 {

private:

public:

	GroveRtcDs1307() {
	}

	virtual ~GroveRtcDs1307() {
	}

	void initializeDayOfWeekYMDHMS(uint8_t _dow, //
			uint16_t _year, uint8_t _month, uint8_t _day, //
			uint8_t _hour, uint8_t _minute, uint8_t _second) {

		DS1307::fillDayOfWeek(_dow);
		DS1307::fillByYMD(_year, _month, _day);
		DS1307::fillByHMS(_hour, _minute, _second);

		//write time to the RTC chip
		DS1307::setTime();
	}

	const String getDateTimeString();

	const String getDateString();

	const String getTimeString();

	void increaseClockByMinutesAndSeconds( //
			uint8_t numMinutes, uint8_t numSeconds);

	void increaseClockByMinute();

	void increaseClockBySecond();

private:

	void addTwoDigitNumberWithZeroPrefix(String &str, uint8_t number);

};

#endif
