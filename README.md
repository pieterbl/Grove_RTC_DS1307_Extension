# Grove\_RTC\_DS1307\_Extension

Extension for: Seeedstudio, Grove - RTC DS1307 library
(RTC\_DS1307, see [Required Libraries](#required-libraries) below).
Offers wrapper for `DS1307` class, synchronization implementation to work with the `Time` library, simple YYYY-MM-SS / HH:MM:SS calculation.

## Purpose

This library was developed as a convenience wrapper for the Grove - RTC DS1307 library, and for usage in this GitHub [Grove LCD RGB Clock](https://github.com/pieterbl/Grove_LCD_RGB_Clock) project.

## License

License information can be found [here](./LICENSE.md).

## Development

- For Arduino/C++ development **Sloeber** was used (<https://eclipse.baeyens.it>).
- For Markdown editing Visual Studio Code was used, with following plug-ins for:
  - Language checking: **Code Spell Checker**
  - Style checking: **Markdown All in One**, and **markdownlint**

## Hardware

Following hardware was used for this project:

- [Arduino UNO R3](https://www.seeedstudio.com/Arduino-Uno-Rev3-p-2995.html) (my board says UNO R3, from arduino.org)
- [Grove Base Shield V2.0 for Arduino](http://wiki.seeedstudio.com/Base_Shield_V2/) (using version 2.1)
  - see also: <https://www.seeedstudio.com/Base-Shield-V2.html>
- [Grove - RTC](http://wiki.seeedstudio.com/Grove-RTC/) (using version 1.2)

## Required Libraries

This library requires:

- <https://github.com/pieterbl/RTC_DS1307>
  - which is a slightly modified version of <https://github.com/Seeed-Studio/RTC_DS1307>
  - none of the performed changes, modifies the original library behavior
- Standard Arduino "Wire" library
  - \<Wire.h\> is required by "DS1307.cpp" from the (Grove) RTC\_DS1307 library

## Provided Examples

| Example | Description |
| ------- | ----------- |
| First run [ClockTimeInitializeOnce](./examples/ClockTimeInitializeOnce/ClockTimeInitializeOnce.ino), to a time quite close to the current time. | Initialize the clock in setup(), prints date/time string in loop(). |
| Then run this few times [ClockTimeAdjustByMinuteOrSecond](./examples/ClockTimeAdjustByMinuteOrSecond/ClockTimeAdjustByMinuteOrSecond.ino), to adjust the missing minutes and/or seconds. | Adjusts the clock time by minute or second in setup(), prints date/time string in loop(). |
| Finally just run [PrintTimeToSerial](./examples/PrintTimeToSerial/PrintTimeToSerial.ino). | Prints date/time string in loop(). |
| [TimeLibSyncProviderDemo](./examples/TimeLibSyncProviderDemo/TimeLibSyncProviderDemo.ino) | The demo shows how the `GroveRtcDs1307TimeLibSyncProvider` class can be used to synchronize the `DS1307` (or `GroveRtcDs1307`) Real-Time-Clock (RTC), and then print out a standard `HH:MM:SS` string, with just a few lines of code. It demonstrates how the libraries `Time.h` (aka `TimeLib.h`), `Grove_RTC_DS1307_Extension.hpp`, `Grove_RTC_DS1307_TimeLibSyncProvider.hpp` and `Time_Extension.hpp` work together. |

**TAKE CARE:** Once you are done with `ClockTimeAdjustByMinuteOrSecond` ... don't reset/restart your Arduino, it will again repeat the currently programmed action, e.g. increase time by some minutes and/or seconds. Even if you should have exactly reached/set the current time.

**TO BE SAFE:** Your last action should be to upload (e.g.) `PrintTimeToSerial`.
