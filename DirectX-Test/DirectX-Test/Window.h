#pragma once
#include <string>
#include <Windows.h>

class Window {
public:
	
	Window(int width, int height, const char* name);
	~Window();
	//int getWidth();
	//int getHeight();
	HINSTANCE getInstance();
	void showWindow();
private:

	static LRESULT CALLBACK setupMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK handleMsgStatic(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK handleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	MSG msg;
	std::string name;
	int width;
	int height;
	HWND hWnd;
	WNDCLASSEX wc;
};