// header.h: включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>
#include <windowsx.h>
// Файлы заголовков среды выполнения C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "CBall.h"
#include "CHLimiter.h"
#include "CBallsArray.h"
#include "CBallSettingsMonitor.h"
#include "CColoredBall.h"
#include "CBallsTimeLmited.h"
#include "Trap.h"
#include "wind.h"
#include <typeinfo>



