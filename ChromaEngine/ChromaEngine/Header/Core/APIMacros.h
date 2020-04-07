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

#define BIT(x) (1 << x)

#ifdef CHROMA_DEBUG
#define CHROMA_ENABLE_ASSERTS
#endif

#ifdef CHROMA_ENABLE_ASSERTS
#define CHROMA_ASSERT(x,y) { if(!(x)) { CHROMA_ERROR(y); __debugbreak(); } } //x is condition, y is error string

#define CHROMA_INFO(x)     Chroma::Log::LogInfo(x)
#define CHROMA_WARN(x)     Chroma::Log::LogWarning(x)
#define CHROMA_ERROR(x)    Chroma::Log::LogError(x)
#else
#define CHROMA_ASSERT(x,y)
#define CHROMA_INFO(x) 
#define CHROMA_WARN(x) 
#define CHROMA_ERROR(x) 
#endif
