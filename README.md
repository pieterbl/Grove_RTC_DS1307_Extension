# Grove\_RTC\_DS1307\_Extension

Extension for: Seeed RTC DS1307 library
(RTC\_DS1307, see [Required Libraries](#required-libraries) below).

## Project Status

UNDER CONSTRUCTION

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
| PrintTimeToSerial | Shows how to initialize the clock in setup(), and print date/time string in loop(). |
