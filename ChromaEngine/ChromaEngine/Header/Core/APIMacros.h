#pragma once

#include "Logging/Log.h"

#ifdef CHROMA_WIN
	#ifdef CHROMA_DLL
		#define CHROMA_API __declspec(dllexport)
	#else 
		#define CHROMA_API __declspec(dllimport)
	#endif // CHROMA_API
#else
	#error Chroma supports window only
#endif // CHROMA_WIN

#define BIT(x) (1 << x)

#ifdef CHROMA_DEBUG
#define CHROMA_ENABLE_ASSERTS
#endif

#ifdef CHROMA_ENABLE_ASSERTS
#define CHROMA_ASSERT(x,y) { if(!(x)) { CHROMA_ERROR(y); __debugbreak(); } } //x is condition, y is error
#else
#define CHROMA_ASSERT(x,y)
#endif
