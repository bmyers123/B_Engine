//#include "B_RenderWindow.h"
#include "Engine.h"

B_RenderWindow::B_RenderWindow(void)
{
	Reset();
}


B_RenderWindow::~B_RenderWindow(void)
{
	Release();
}

void B_RenderWindow::Reset()
{
	quit = false;
	mHWND = NULL;
	mHDC  = NULL;
	mHRC  = NULL;
}

void B_RenderWindow::Release()
{
	if ( mHRC )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( *mHRC );
	}

	if ( mHWND && mHDC )
	{
		ReleaseDC( mHWND, *mHDC );
	}

	Reset();
}

void B_RenderWindow::createB_RenderWindow(HINSTANCE hInstance)
{
	
	wc.style = CS_OWNDC;
	//wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH ); 
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "GLSample";
	RegisterClass( &wc );
	
	// create main window
	mHWND = CreateWindow( 
		"GLSample", "OpenGL Sample", 
		WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
		0, 0, 1024, 720,
		NULL, NULL, hInstance, NULL );

}

void B_RenderWindow::initB_RenderWindow(HWND HWND)
{
	// remember the window handle (HWND)
      //  mHWND = HWND;

        // get the device context (DC)
        *mHDC = GetDC( HWND );

        // set the pixel format for the DC
        PIXELFORMATDESCRIPTOR pfd;
        ZeroMemory( &pfd, sizeof( pfd ) );
        pfd.nSize = sizeof( pfd );
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
                      PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 24;
        pfd.cDepthBits = 16;
        pfd.iLayerType = PFD_MAIN_PLANE;
        int format = ChoosePixelFormat( *mHDC, &pfd );
        SetPixelFormat( *mHDC, format, &pfd );

        // create the render context (RC)
        *mHRC = wglCreateContext( *mHDC );

        // make it the current render context
        wglMakeCurrent( *mHDC, *mHRC );
}

void B_RenderWindow::EnableOpenGL()
{
	PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    // get the device context (DC)
    *mHDC = GetDC( mHWND );

    // set the pixel format for the DC
    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
                  PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat( *mHDC, &pfd );
    SetPixelFormat( *mHDC, iFormat, &pfd );

    // create and enable the render context (RC)
    *mHRC = wglCreateContext( *mHDC );
    wglMakeCurrent( *mHDC, *mHRC );
}

void B_RenderWindow::DisableOpenGL()
{
	wglMakeCurrent( NULL, NULL );
    wglDeleteContext( *mHRC );
    ReleaseDC( mHWND, *mHDC );
}

WNDCLASS B_RenderWindow::getWC()
{
	return wc;
}

HWND B_RenderWindow::getHWND()
{
	return mHWND;
}

HDC * B_RenderWindow::getHDC()
{
	return mHDC;
}

HGLRC * B_RenderWindow::getHRC()
{
	return mHRC;
}