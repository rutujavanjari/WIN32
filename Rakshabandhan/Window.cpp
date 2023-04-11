#include <Windows.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

void paint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 1));
	//graphics.DrawLine(&pen,900,200,100,200);
	graphics.DrawLine(&pen, 900, 200, 103, 200);
	Ellipse(hdc, 480, 130, 620, 270);	//big
	Ellipse(hdc,500,150,600,250);		//medium
	Ellipse(hdc,535,188,562,210);		//small
	

}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RUTU");
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);
	
	hwnd = CreateWindow(szAppName, TEXT("अनिरुद्ध दादा"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	PAINTSTRUCT ps;
	HFONT hfont;

	switch(iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("दादा  !!!	 :)"), TEXT(" रक्षाबंधन"), MB_OK);
		PlaySound(TEXT("rakshabandhan.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		hfont = CreateFont(50, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("HELLO"));
		SelectObject(hdc, hfont);
		//SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(225, 139, 2));
		DrawText(hdc, TEXT("॥ रक्षाबंधनाच्या शुभेच्छा ॥"), -1, &rc, DT_SINGLELINE);
		DrawText(hdc, TEXT("॥ माझ्या कडून तुझ्या साठी डिजिटल राखी  ॥"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		paint(hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



// compile command : cl.exe /c /EHsc /D UNICODE window.cpp
// link command : link.exe window.obj user32.lib gdi32.lib kernel32.lib Winmm.lib


