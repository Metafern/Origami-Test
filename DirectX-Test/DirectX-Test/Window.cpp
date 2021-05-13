#include "Window.h"
using namespace std;


Window::Window(int width, int height, const char* name) {

	this->width = width;
	this->height = height;
	this->name = name;

	//register window class
	wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = setupMsg;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = getInstance();
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszClassName = name;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(
		0, name,
		"Windowww",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		nullptr, nullptr, getInstance(),this
	);

}
LRESULT CALLBACK Window::handleMsgStatic(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	Window* pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	return pWnd->handleMsg(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::handleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == 'A')
			SetWindowText(hWnd, "AAA");
		else if (wParam == 'D')
			SetWindowText(hWnd, "BBB");
		break;
	case WM_CHAR:
		static std::string title;
		title.push_back((char)wParam);
		SetWindowText(hWnd, title.c_str());
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::setupMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	if (msg == WM_NCCREATE) {
		const CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		Window* pWnd = static_cast<Window*>(pCreate->lpCreateParams);

		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&handleMsgStatic));
		return pWnd->handleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

HINSTANCE Window::getInstance() {
	return GetModuleHandle(nullptr);
}

void Window::showWindow() {
	ShowWindow(hWnd, SW_SHOW);
}

Window::~Window() {}