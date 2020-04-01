#pragma once

#ifdef CHROMA_WIN
	#ifdef CHROMA_DLL
		#define CHROMA_API __declspec(dllexport)
	#else 
		#define CHROMA_API __declspec(dllimport)
	#endif // CHROMA_API
#else
	#error Chroma supports window only
#endif // CHROMA_WIN
