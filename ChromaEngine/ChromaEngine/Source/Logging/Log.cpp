#include "Logging\Log.h"
#include <iostream>
#include <CoreWindow.h>

namespace Chroma
{
	void Log::ResetConsoleLog(HANDLE handle)
	{
		SetConsoleTextAttribute(handle, DEFAULT_COLOR);
	}

	void Log::LogError(const std::string& error)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, ERROR_COLOR);
		std::cout << "\n" << error << "\n";

		ResetConsoleLog(hConsole);
	}

	void Log::LogWarning(const std::string& warning)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, WARNING_COLOR);
		std::cout << "\n" << warning << "\n";

		ResetConsoleLog(hConsole);
	}

	void Log::LogInfo(const std::string& info)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, INFO_COLOR);
		std::cout << "\n" << info << "\n";

		ResetConsoleLog(hConsole);
	}
}