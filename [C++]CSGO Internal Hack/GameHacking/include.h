#pragma once
#define PANIC VK_HOME
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "Windows.h"
#include "offsets.h"


//Функции
#include "Trigger.h"
#include "Glow.h"
#include "BunnyHop.h"

//Подключаем неймспейсы чтобы получать сигнатуры и оффсеты
using namespace offsets::netvars;
using namespace offsets::signatures;
