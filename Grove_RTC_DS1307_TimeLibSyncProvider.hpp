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
#ifndef __GROVE_RTC_DS1307_TIMELIB_SYNC_PROVIDER_HPP__
#define __GROVE_RTC_DS1307_TIMELIB_SYNC_PROVIDER_HPP__

#include <DS1307.h>
#include <TimeLib.h>

class GroveRtcDs1307TimeLibSyncProvider {

private:

	static DS1307 *__CLOCK;

public:

	static void initialize(DS1307 *clock) {
		__CLOCK = clock;
		setSyncProvider(requestSync);
	}

private:

	static time_t requestSync() {

		if (__CLOCK == 0) {
			return 0;
		}

		tmElements_t tm;

		readTime(*__CLOCK, tm);

		return makeTime(tm);
	}

	static void readTime(DS1307 &clock, tmElements_t &tm) {

		clock.getTime();

		// from TimeLib.h
		//
		//convenience macros to convert to and from tm years
		//#define  tmYearToCalendar(Y) ((Y) + 1970)  // full four digit year
		//#define  CalendarYrToTm(Y)   ((Y) - 1970)
		//#define  tmYearToY2k(Y)      ((Y) - 30)    // offset is from 2000
		//#define  y2kYearToTm(Y)      ((Y) + 30)
		//
		// 20 + 2000 = 2020 - 1970 = 50 years since 1970.
		// Time.h/Timelib.h works with 1970 base.
		//
		tm.Year = CalendarYrToTm(clock.year + 2000);

		tm.Month = clock.month;
		tm.Day = clock.dayOfMonth;
		tm.Hour = clock.hour;
		tm.Minute = clock.minute;
		tm.Second = clock.second;

		// from the respective comments
		// tm.Wday:           day of week,Sun=1,Mon=2,Tue=3,Wed=4,Thu=5,Fri=6,Sat=7
		// clock.dayOfWeek:   day of week,Mon=1,Tue=2,Wed=3,Thu=4,Fri=5,Sat=6,Sun=7
		if (clock.dayOfWeek == SUN) {
			tm.Wday = dowSunday;
		} else {
			tm.Wday = clock.dayOfWeek + 1;
		}
	}

};

#endif // __GROVE_RTC_DS1307_TIMELIB_SYNC_PROVIDER_HPP__
