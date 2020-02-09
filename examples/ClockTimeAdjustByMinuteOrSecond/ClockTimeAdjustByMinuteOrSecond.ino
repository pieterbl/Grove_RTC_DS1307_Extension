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

#include "Grove_RTC_DS1307_Extension.hpp"

// define clock
GroveRtcDs1307 clock;

void setup() {

	clock.begin();

	Serial.begin(9600);
	Serial.println();
	Serial.println();

	Serial.println("Before increaseClockByMinutesAndSeconds");
	Serial.println(clock.getDateTimeString());

	Serial.println("Calling increaseClockByMinutesAndSeconds");
	clock.increaseClockByMinutesAndSeconds(0, 1);

	Serial.println("After increaseClockByMinutesAndSeconds");
}

void loop() {
	Serial.println(clock.getDateTimeString());
	delay(500);
}

