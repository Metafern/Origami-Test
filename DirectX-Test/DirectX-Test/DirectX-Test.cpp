// DirectX-Test.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DirectX-Test.h"
#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	
	const auto pClassName = _T("test");


	Window window(480, 640, "test");
	window.showWindow();

	//message pump
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}