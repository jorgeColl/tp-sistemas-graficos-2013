//=============================================================================
// Sample Application for GLEW, and cwc Application/Window class using freeglut
//=============================================================================

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "myApplication.h"
void* instancia;
#include "myWindow.h"
#include "cangrejo.h"
#include "piedra.h"


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------

int main(void)
{
	myApplication*  pApp = new myApplication;
	myWindow* myWin = new myWindow();
	instancia = (void*)myWin;
	Cangrejo cangrejo (myWin);
	Piedra piedra1 (myWin);

	myWin->agregar_figura(&cangrejo);
	myWin->agregar_figura(&piedra1);
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "Failed to initialize GLEW!" << std::endl;
    }
    std::cout << "Using GLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;

	pApp->run();
	delete pApp;
	return 0;
}

//-----------------------------------------------------------------------------

