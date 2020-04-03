#pragma once

#include "Contract/Runnable.h"
#include "APIMacros.h"
#include "MSWindow.h"

namespace Chroma
{
	class CHROMA_API ChromaEngineApp : public Runnable
	{
	public:
		ChromaEngineApp();

		void Run() override;

		~ChromaEngineApp();

		Window* win;
	};
}