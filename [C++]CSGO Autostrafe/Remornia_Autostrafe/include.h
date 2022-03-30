#pragma once

#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <string>
#include <vector>

#include "Windows.h"
#include "offsets.h"
#include "MemMan.h"
#include "ConsoleColors.h"
#include "Vector.h"
#include "KeyInput.h"
#include "ProcessValues.h"
MemMan mem;


//Подключаем неймспейсы чтобы получать сигнатуры и оффсеты
using namespace offsets::netvars;
using namespace offsets::signatures;
using namespace std;