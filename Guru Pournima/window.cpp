#include <Windows.h>

LRESULT CALLBACK WndProc(HWND,UINT, WPARAM, LPARAM);

static int ChangeFontSize = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyWindow");
	
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT(" अनिरुद्ध दादा"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	//डॉ.विजय गोखले सर
	ShowWindow(hwnd, SW_MAXIMIZE);
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
	

	//TCHAR str[255];

	switch (iMsg)
	{
	case WM_CREATE:
		MessageBox(hwnd, TEXT("नमस्कार दादा  !!!	 :)"), TEXT(" गुरू पौर्णिमा"), MB_OK);
		PlaySound(TEXT("GuruBramha.wav"), NULL, SND_ASYNC | SND_FILENAME);
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		//PlaySound(TEXT("GuruBramha.wav"), NULL, SND_ASYNC|SND_FILENAME);
		for (ChangeFontSize = 0; ChangeFontSize <= 58; ChangeFontSize++)
		{
			ChangeFontSize = ChangeFontSize + 1;
			hfont = CreateFont(ChangeFontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("HELLO"));
			SelectObject(hdc, hfont);
			SetBkColor(hdc, RGB(0, 0, 0));
			SetTextColor(hdc, RGB(225, 139, 2));
			DrawText(hdc, TEXT("॥ गुरुर्ब्रह्मा गुरुर्विष्णुः गुरुर्देवो महेश्वरः । गुरुःसाक्षात् परब्रह्म तस्मै श्रीगुरवे नम : ॥"), -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
		DeleteObject(hfont);
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