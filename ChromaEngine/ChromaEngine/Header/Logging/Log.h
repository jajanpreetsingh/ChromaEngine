#pragma once

#include <iostream>
#include <CoreWindow.h>

#define DEFAULT_COLOR 0x0001A
#define ERROR_COLOR 0x000C
#define INFO_COLOR 0x000B
#define WARNING_COLOR 0x000E

//0 = Black       8 = Gray
//1 = Blue        9 = Light Blue
//2 = Green       A = Light Green
//3 = Aqua        B = Light Aqua
//4 = Red         C = Light Red
//5 = Purple      D = Light Purple
//6 = Yellow      E = Light Yellow
//7 = White       F = Bright White

class Log
{
public:
	void ResetConsoleLog(HANDLE handle) const;

	void LogError(const std::string& error) const;

	void LogWarning(const std::string& warning) const;

	void LogInfo(const std::string& info) const;
};