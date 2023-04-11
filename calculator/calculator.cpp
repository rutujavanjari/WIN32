#include<Windows.h>
#include <shellapi.h>

// global function decleration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// GOLBAL variable decleration
//entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// local variable declerations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;

	

	TCHAR szAppName[] = TEXT("Rutuja's Window");

	//code
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
	//create a window in memory

	hwnd = CreateWindow(szAppName, TEXT("Rutuja's Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		//wsprintf(str, TEXT("HELLO"));

		LPWSTR* szArglist;
		int nArgs;
		int i;
		TCHAR str[255];

		szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
		if (NULL == szArglist)
		{
			wsprintf(str,TEXT("CommandLineToArgvW failed"));
			return 0;
		}
		else for (i = 0; i < nArgs; i++) wsprintf(str,TEXT("%d: %ws\n"), i, szArglist[i]); 
		// Free memory allocated for CommandLineToArgvW arguments.

		LocalFree(szArglist);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}