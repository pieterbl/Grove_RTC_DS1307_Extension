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

void GroveRtcDs1307::addTwoDigitNumberWithZeroPrefix( //
		String &str, uint8_t number) {

	if (number < 10) {
		str += '0';
	}
	str += number;
}

const String GroveRtcDs1307::getDateTimeString() {
	String dateTime = "";
	dateTime += getDateString();
	dateTime += " ";
	dateTime += getTimeString();
	return dateTime;
}

const String GroveRtcDs1307::getDateString() {

	DS1307::getTime();

	String dateString = "";
	dateString += (2000 + DS1307::year);
	dateString += "-";
	addTwoDigitNumberWithZeroPrefix(dateString, DS1307::month);
	dateString += "-";
	addTwoDigitNumberWithZeroPrefix(dateString, DS1307::dayOfMonth);

	return dateString;
}

const String GroveRtcDs1307::getTimeString() {

	DS1307::getTime();

	String timeString = "";
	addTwoDigitNumberWithZeroPrefix(timeString, DS1307::hour);
	timeString += ":";
	addTwoDigitNumberWithZeroPrefix(timeString, DS1307::minute);
	timeString += ":";
	addTwoDigitNumberWithZeroPrefix(timeString, DS1307::second);

	return timeString;
}
