#pragma once

#include "Windows.h"

struct processValues 
{
	uintptr_t process;
	uintptr_t clientModule;
	uintptr_t engineModule;
}pv;