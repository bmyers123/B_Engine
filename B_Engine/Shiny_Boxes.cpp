#include "Engine.h"


//using namespace bmath;

Shiny_Boxes::Shiny_Boxes()
{
	world3DCam = new b_graphics::b_prefabs::Camera3D(&glrenderWindow);

	testObj = new b_graphics::b_parsers::ObjLoader();
	passThruProgram = new b_graphics::b_shaders::GLSLShaderProgram();
	endOfGame = false;
	shaderDebug = false;

	rotValue = 0.0f;
	zoom = 0.0f;
	world3DCam->pos = b_math::b_vectors::B_Vec3(0.0f, 100.0f, 0.0f);
}

Shiny_Boxes::~Shiny_Boxes()
{
	delete passThruProgram;
	delete world3DCam;
	delete testObj;
}


void Shiny_Boxes::initializeTestWorld()
{

	//Set context and Render Window settings.
	contextSettings.depthBits = 32;
	contextSettings.antialiasingLevel = 4;
	glrenderWindow.create(sf::VideoMode(800, 600), "Test", sf::Style::Default, contextSettings);
	glrenderWindow.setVerticalSyncEnabled(true);
	//
	//
	//Activate the Render Window
	glrenderWindow.setActive();

	//window.B_initialize_and_Create_Window("Test", true, 4, 32, 800, 600, glrenderWindow);
	//window.B_activateWindow(glrenderWindow);

	//Depth and Color clears (setting to default)
	glClearColor(0.2f, 0.5f, 0.6f, 1.f);//black


	//Enable Depth Test
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	//Load GLSL Shaders
	b_graphics::b_shaders::GLSLShader *vertPtr = &vertShader, *fragPtr = &fragShader;
	vertShader.createFromFile(b_graphics::b_shaders::GLSL_VERTEX_SHADER, "Shaders/GLSL/passThru_clip_v.glsl");
	fragShader.createFromFile(b_graphics::b_shaders::GLSL_FRAGMENT_SHADER, "Shaders/GLSL/applyTexture_f.glsl");


	passThruProgram->attachShader(vertPtr);
	passThruProgram->attachShader(fragPtr);

	//mvMat = passThruProgram->getUniformLocation("modelView");
	//worldToObj = passThruProgram->getUniformLocation("worldToObjectMat");
	mvpMat = passThruProgram->getUniformLocation("MVP");
	//color = passThruProgram->getUniformLocation("colour");
	texture1 = passThruProgram->getUniformLocation("tex");


	testObj->loadObj("Objfiles/palmTree.obj");
	testObj->position = b_math::b_vectors::B_Vec3(0.0f, 0.0f, 0.0f);


	vertShader.Release();
	fragShader.Release();

	////
	////
	////
	////
	////


	//TEXTURES HAVE BEEN WRAPPED, JUST NEED TO BE APPLIED WITH WRAPPING CLASS'S FUNCTIONS


	////
	////
	////
	////
	////
	//Load Test Texture For worldObj
	if(!testTexImg.loadFromFile("Textures/palmTreeTex3.png"))
	{
		std::cout << "Error Loading Test Image" << std::endl;
	}
	else
	{
		testTexImg.flipVertically();
	}

	glGenTextures(1, &testTex);
	glBindTexture(GL_TEXTURE_2D, testTex);

	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, testTexImg.getSize().x, testTexImg.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, testTexImg.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBindTexture(GL_TEXTURE_2D, 0);

	for(int i = 0; i<sf::Keyboard::KeyCount; i++)
	{
		key[i] = false;
	}

}



void Shiny_Boxes::GameLoop()
{
	world3DCam->Activate();
	world3DCam->setWindow(&glrenderWindow);

		glClearColor(0.0f, 1.0f, 0.0f, 0.0f);

		while(glrenderWindow.isOpen() && !endOfGame)//!endOfGame
	{
		
        while (glrenderWindow.pollEvent(event))
        {

            if(event.type == sf::Event::Closed)
             glrenderWindow.close();

			//When a key is pressed, set it to true
            if(event.type == sf::Event::KeyPressed)
			{
				key[event.key.code] = true;
			}

			//When a key is released, set it to false
			if(event.type == sf::Event::KeyReleased)
			{
				key[event.key.code] = false;
			}

            // Adjust the viewport when the window is resized
            if(event.type == sf::Event::Resized)
               glViewport(0, 0, event.size.width, event.size.height);

		/*	if(event.type == */

        }

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		keyChecks();


		eyeToWorld = world3DCam->Target(testObj->position, diff, zoom);

		updateCameraMatrices();

		drawTestWorld();

		Update();
		


		glrenderWindow.display();
		//window.B_Window_Display(glrenderWindow);

	}
}

void Shiny_Boxes::Update()
{
	updateClock();
	mouseUpdate();
}

void Shiny_Boxes::updateClock()
{
	//Not currently being used....wrap it up, make it better...
	dt = Clock.restart().asSeconds();
}

void Shiny_Boxes::keyChecks()
{
	if(key[sf::Keyboard::Escape])
	{
		glrenderWindow.close();
	}//End Escape IF

	if(key[sf::Keyboard::W])
	{
		zoom -= 0.01f;
		std::cout << zoom << std::endl;
	}
	if(key[sf::Keyboard::S])
	{
		zoom += 0.01f;
		std::cout << zoom << std::endl;

	}
}

void Shiny_Boxes::mouseUpdate()
{

	sf::Vector2i center = sf::Vector2i(glrenderWindow.getSize().x/2 + glrenderWindow.getPosition().x, 
		glrenderWindow.getSize().y/2 + glrenderWindow.getPosition().y);

	sf::Vector2i mousePos;
	mousePos = sf::Vector2i(mouse.getPosition().x, 
		mouse.getPosition().y);

	diff = mousePos-center;

	//std::cout << diff.x;
	//std::cout << diff.y << std::endl;

	mouse.setPosition(sf::Vector2i(glrenderWindow.getSize().x/2 + glrenderWindow.getPosition().x, 
		glrenderWindow.getSize().y/2 + glrenderWindow.getPosition().y));

}


void Shiny_Boxes::drawTestWorld()
{

	//=========================================================================


	//1. Activate Shader Program
	passThruProgram->Activate();
	
	//=========================================================================


	//2. Activate Object's VBO
	testObj->activateVBO();	

	//=========================================================================


	//3. Get the vertex, normal, and uv data from the loaded obj
	testVData = testObj->vertData;
	testNData = testObj->normalData;
	testTexData = testObj->uvData;

	//=========================================================================


	//4. Send the vertex, normal and uv data to shaders using VBO
	glNormalPointer(GL_FLOAT, 0, testNData);
	glVertexPointer(3, GL_FLOAT, 0, testVData);
	glTexCoordPointer(2, GL_FLOAT, 0, testTexData);

	//=========================================================================


	//5. Send uniforms to the shaders
	passThruProgram->UniformMat4(mvpMat, false, modelViewProjectionMatrix.m);
	glBindTexture(GL_TEXTURE_2D, testTex);
	glUniform1i(texture1, 0);

	//=========================================================================


	//6. Update transformations on object
	updateObjectMatrices(testObj);

	//=========================================================================


	//7. Render Object	
	testObj->renderVBO();

	//=========================================================================


	//7. Deactivate Object's VBO
	testObj->deactivateVBO();

	//=========================================================================


	//8. Unbind Texture so it doesn't apply to object's renders after this one
	glBindTexture(GL_TEXTURE_2D, 0);


	//=========================================================================
	
	
	//9. Release Shader Program Data (ERRORS ATM)

	//Causes the color to be removed from the object
	//passThruProgram->Release();


}

void Shiny_Boxes::updateCameraMatrices()
{

	world3DCam->viewMat = world3DCam->viewMat.B_Mat4TransformInverseUniformScale(eyeToWorld);

	viewProjectionMatrix = world3DCam->projectionMat * world3DCam->viewMat;
	
}

void Shiny_Boxes::updateObjectMatrices(b_graphics::b_parsers::ObjLoader *obj)
{


	rotationMat = rotationMat.B_Mat3RotateEulerXYZ(obj->rotation.x, 
									 obj->rotation.y, 
									 obj->rotation.z);

	const b_math::b_vectors::B_Vec3 t = obj->position;
	const float s = obj->uniformScale;
	modelMatrix = modelMatrix.B_Mat4MakeTransform(rotationMat, t);
	//const bmath::vec::vec3 t = obj->position;
	//const float s = obj->uniformScale;
	//modelMat = bmath::mat::makeTransform(r, s, t);
	

	//modelMatrix.B_Mat4Translate(zoom, zoom, zoom);

	// compute model-view matrix
	modelViewMatrix = world3DCam->viewMat * modelMatrix;

	// compute model-view-projection matrix
	modelViewProjectionMatrix = viewProjectionMatrix * modelMatrix;

	//// compute object-space matrix
	//worldToObject = worldToObject.B_Mat4TransformInverseUniformScale(modelMatrix);

}





//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	
//	switch (message)
//	{
//		
//	case WM_CREATE:
//		return 0;
//		
//	case WM_CLOSE:
//		PostQuitMessage( 0 );
//		return 0;
//		
//	case WM_DESTROY:
//		return 0;
//		
//	case WM_KEYDOWN:
//		switch ( wParam )
//		{
//			
//		case VK_ESCAPE:
//			PostQuitMessage(0);
//			return 0;
//			
//		}
//		return 0;
//	
//	default:
//		return DefWindowProc( hWnd, message, wParam, lParam );
//			
//	}
//	
//}
//
//// Enable OpenGL
//
//void EnableOpenGL(HWND hWnd, HDC * hDC, HGLRC * hRC)
//{
//	PIXELFORMATDESCRIPTOR pfd;
//	int format;
//	
//	// get the device context (DC)
//	*hDC = GetDC( hWnd );
//	
//	// set the pixel format for the DC
//	ZeroMemory( &pfd, sizeof( pfd ) );
//	pfd.nSize = sizeof( pfd );
//	pfd.nVersion = 1;
//	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
//	pfd.iPixelType = PFD_TYPE_RGBA;
//	pfd.cColorBits = 24;
//	pfd.cDepthBits = 16;
//	pfd.iLayerType = PFD_MAIN_PLANE;
//	format = ChoosePixelFormat( *hDC, &pfd );
//	SetPixelFormat( *hDC, format, &pfd );
//	
//	// create and enable the render context (RC)
//	*hRC = wglCreateContext( *hDC );
//	wglMakeCurrent( *hDC, *hRC );
//	
//}
//
//// Disable OpenGL
//
//void DisableOpenGL(HWND hWnd, HDC hDC, HGLRC hRC)
//{
//	wglMakeCurrent( NULL, NULL );
//	wglDeleteContext( hRC );
//	ReleaseDC( hWnd, hDC );
//}
//
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
//{
//
//	B_RenderWindow RW;
//	WNDCLASS wc;
//	HWND hWnd;
//	HDC hDC;
//	HGLRC hRC;
//	MSG msg;
//	BOOL quit = FALSE;
//	float theta = 0.0f;
//
//	//RW.
//	//RW.createB_RenderWindow(hInstance);
////	RW.EnableOpenGL();
//	
//	//RW.initB_RenderWindow(RW.mHWND);
//	//Attempt at by-passing the class ordeal with regards to the window creation's WndProc definition.
//	//WNDCLASS tempWC = RW.getWC();
//
//	wc.style = CS_OWNDC;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
//	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
//	wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH ); 
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = "GLSample";
//	RegisterClass( &wc );
//	
//	// create main window
//	hWnd = CreateWindow( 
//		"GLSample", "OpenGL Sample", 
//		WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
//		0, 0, 1024, 720,
//		NULL, NULL, hInstance, NULL );
//
//	// enable OpenGL for the window
//	//OLD
//	EnableOpenGL( hWnd, &hDC, &hRC );
//	//NEW
//	
//	
//	//Initialize world after OpenGL is enabled
//	//SB->initializeTestWorld();
//	
//	// program main loop
//	while ( !quit )
//	{
//		
//		// check for messages
//		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE )  )
//		{
//			
//			// handle or dispatch messages
//			if ( msg.message == WM_QUIT ) 
//			{
//				quit = TRUE;
//			} 
//			else 
//			{
//				TranslateMessage( &msg );
//				DispatchMessage( &msg );
//			}
//			
//		} 
//		else 
//		{
//			
//			// OpenGL animation code goes here
//			
//			//SB.drawTestWorld();
//
//			glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
//			glClear( GL_COLOR_BUFFER_BIT );
//			
//			glPushMatrix();
//			glRotatef( theta, 0.0f, 0.0f, 1.0f );
//			glBegin( GL_TRIANGLES );
//			glColor3f( 1.0f, 0.0f, 0.0f ); glVertex2f( 0.0f, 1.0f );
//			glColor3f( 0.0f, 1.0f, 0.0f ); glVertex2f( 0.87f, -0.5f );
//			glColor3f( 0.0f, 0.0f, 1.0f ); glVertex2f( -0.87f, -0.5f );
//			glEnd();
//			glPopMatrix();
//			
//			//================================================================================
//			//RENDER BELOW
//
//
//			SB.GameLoop();
//
//
//			//RENDER ABOVE
//			//================================================================================
//			SwapBuffers( hDC );
//			
//			theta += 1.0f;
//			
//		}
//		
//	}
//	
//	// shutdown OpenGL
//	//DisableOpenGL( RW.mHWND, *RW.mHDC, *RW.mHRC );
//	DisableOpenGL(hWnd, hDC, hRC);
//	// destroy the window explicitly
//	//DestroyWindow( RW.mHWND );
//	DestroyWindow(hWnd);
//	return msg.wParam;
//
//}