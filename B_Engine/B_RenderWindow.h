#ifndef B_RENDERWINDOW_H
#define B_RENDERWINDOW_H

#include <Windows.h>

class B_RenderWindow
{

public:
	B_RenderWindow();
	~B_RenderWindow();

	void createB_RenderWindow(HINSTANCE hInstance);
	void initB_RenderWindow(HWND hWnd);
	void EnableOpenGL();
	void DisableOpenGL();

	WNDCLASS getWC();
	HWND getHWND();
	HDC *getHDC();
	HGLRC * getHRC();

	void Release();
	void Reset();

	WNDCLASS wc;
	bool quit;

	HWND mHWND;
	HDC *mHDC;
	HGLRC *mHRC;

};

#endif