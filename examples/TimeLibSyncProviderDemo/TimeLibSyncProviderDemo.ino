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

#include <Arduino.h>
#include <Grove_RTC_DS1307_Extension.hpp>
#include <Grove_RTC_DS1307_TimeLibSyncProvider.hpp>
#include <Time_Extension.hpp>

// define RTC clock
GroveRtcDs1307 clock;

// define Time_Extension wrapper for RTC clock
TimeExtension timeObj;

void setup() {

	Serial.begin(9600);

	// begin the DS1307 RTC (real time clock)
	clock.begin();

	// ensures that the Time.h (or TimeLib.h) is in-sync with the DS1307 RTC (real time clock)
	//
	// the times printed below should usually be the same (they may differ every now and then)
	//
	GroveRtcDs1307TimeLibSyncProvider::initialize(&clock);
}

void loop() {

	delay(1000);

	Serial.print("GroveRtcDs1307: ");
	Serial.println(clock.getDateTimeString()); // print time, it should be the same as with timeObj below

	Serial.print("TimeLib       : ");
	Serial.println(timeObj.getDateTimeString()); // print time, it should be the same as with clock above

	Serial.println();
}
