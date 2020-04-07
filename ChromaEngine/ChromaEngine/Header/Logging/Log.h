#pragma once

#include <iostream>
#include <CoreWindow.h>

namespace Chroma
{
#define DEFAULT_COLOR 0x000A
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
		static void ResetConsoleLog(HANDLE handle);

		static void LogError(const std::string& error);

		static void LogWarning(const std::string& warning);

		static void LogInfo(const std::string& info);
	};
}