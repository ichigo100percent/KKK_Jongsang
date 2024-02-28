#pragma once
#include <Windows.h>
#include <assert.h>
#include <iostream>

#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <functional>
#include <filesystem>


#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <mmsystem.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include "JSMath.h"
#include "JSEnums.h"