#pragma once
#include "Windows.h"


struct procValues
{
	uintptr_t process;
	uintptr_t clientModule;
	uintptr_t engineModule;
	BYTE flag;
}pv;