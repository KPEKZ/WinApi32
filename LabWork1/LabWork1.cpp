// LabWork1.cpp : Определяет точку входа для приложения.
//

// пользовательские классы

#include "framework.h"
#include "LabWork1.h"
#include <vector>
#define MAX_LOADSTRING 100

using namespace std;
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
HWND hWnd;                  // экзмемпляр окна
bool drB{ false };
bool gravity{ false };

CBallsArray balls(50);

//RECT rect_wndSize;
DWORD prev_frame_time;
CBallSettingsMonitor monitor;
wind wind1;
Trap trap;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



void OnIdle() {
    DWORD cur_time = GetTickCount64();
    DWORD delta_time = cur_time - prev_frame_time;
    balls.Move(delta_time);
    balls.SetTrap(&trap);
    balls.SetWind(&wind1);
    if (gravity)
        balls.SetGravityFactor(19.8, delta_time);
    prev_frame_time = cur_time;
    InvalidateRect(hWnd,NULL, true);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LABWORK1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABWORK1));
   
    RECT wnd_size;
  
    GetClientRect(hWnd, &wnd_size);
    prev_frame_time = GetTickCount64();
    trap.SetParams(200, 200, 5000.0, 50);
    balls.SetBounds(wnd_size);
   
    // Цикл основного сообщения:
    MSG msg;

    while (1)
    {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            DispatchMessage(&msg);
        }
        else {
            Sleep(20);
            OnIdle();
          
        }
    }

   

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABWORK1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LABWORK1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

     hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT,400, 400, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   
    
    static double xxpos;
    static double yypos;
    

    switch (message)
    {
   
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_DOWN:
        {
            monitor.SpeedDown();
        }
            break;
        case VK_UP:
        {
            monitor.SpeedUP();
        }
            break;
        case VK_LEFT:
        {
            monitor.AngleUp();
        }
            break;
        case VK_RIGHT:
        {
            monitor.AngleDown();
        }
        break;
        case 0x53: // S
        {
            wind1.SpeedDown();
        }
        break;
        case 0x57: //W
        {
            wind1.SpeedUP();
        }
        break;
        case 0x44: // D
        {
            wind1.AngleDown();
        }
        break;
        case 0x41: // A
        {
            wind1.AngleUp();
        }
        break;
        case 0x47: //G
        {
            if (!gravity)
                gravity = true;
            else gravity = false;
        }
 
        break;
       
        default:
            break;
        }
        
        
    }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_TIMER: {

        balls.del();
          
    }
    break;

    case WM_MOUSEMOVE: {
       xxpos = GET_X_LPARAM(lParam);
       yypos = GET_Y_LPARAM(lParam);
    }
      break;
    case WM_MBUTTONUP: {
        drB = true;
        SetTimer(hWnd, 12, 5000, NULL);

    }
    break;
    case WM_LBUTTONUP: {
        CColoredBall* cball = balls.AddColoredBall();
        if (cball != NULL) {
            PAINTSTRUCT ps;
            RECT cr;
            GetClientRect(hWnd, &cr);
            HDC hdc = BeginPaint(hWnd, &ps);
             double v_x, v_y;
             monitor.GetVXVY(v_x, v_y);
            cball->SetParams(xxpos, yypos, 10, v_x, v_y);
            cball->SetBounds(cr);
            cball->SetColor(0, 0, 255);
            EndPaint(hWnd, &ps);
        }
        return 0;
    }
     break;
    case WM_PAINT:
        {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

            balls.Draw(hdc);
            monitor.Draw(hdc);
            wind1.Draw(hdc);
            trap.Draw(hdc);
            if (gravity)
                TextOutW(hdc, 65, 8, L"Gravity: On", 13);
            else 
                TextOutW(hdc, 65, 8, L"Gravity: Off", 14);

            if (drB) {
                
                CBallsTimeLmited* cball = balls.AddLImitedBall();
                if (cball != NULL) {
                    RECT cr;
                    GetClientRect(hWnd, &cr);
                    double v_x, v_y;
                    monitor.GetVXVY(v_x, v_y);
                    cball->SetParams(xxpos, yypos, 10, v_x, v_y);
                    cball->SetBounds(cr);
                
                }
            }
             drB = false;
             

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_SIZE:
        {
            RECT rect;
            rect.top = 0;
            rect.left = 0;
            rect.bottom = HIWORD(lParam);
            rect.right = LOWORD(lParam);
            balls.SetBounds(rect);
         
        }
        break;
        case WM_DESTROY:
            KillTimer(hWnd, 12);
            PostQuitMessage(0);
            break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
