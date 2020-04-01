#pragma once

#include "Contract/Runnable.h"
#include "APIMacros.h"

class CHROMA_API ChromaEngineApp : public Runnable
{
public:
	ChromaEngineApp();

	void Run() override;

	~ChromaEngineApp();
};