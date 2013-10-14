#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include "glutWindow.h"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 

#include <vector>
class Figura;

#include "Superficie.h"

class myWindow : public cwc::glutWindow
{
public:
	myWindow();
	~myWindow();
	virtual void OnRender(void);
	virtual void OnIdle();

	// When OnInit is called, a render context (in this case GLUT-Window) 
	// is already available!
	virtual void OnInit();

	virtual void OnResize(int w, int h);
	virtual void OnClose(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y);
	 //! Called when Mouse is moved (without pressing any button)
	virtual void OnMouseMove(int x, int y);
	virtual void OnKeyDown(int nKey, char cAscii);

	virtual void OnKeyUp(int nKey, char cAscii);

    // Scene functions
    void renderArm(glm::mat4 model_matrix);
	
	void renderObject (glm::mat4 model_matrix, GLfloat* vertex_buff, GLfloat* normal_buff,
					   GLuint* index_buff, unsigned int index_buff_size, GLenum modo);
	
	
	virtual void agregar_figura(Figura* fig);
	void axuuu(int a, int b);
	
private:
	glm::vec3 m_pos, m_direct;
	std::vector<Figura*>figs;
	bool full_screen;
	bool subio_antes;
    void changeObjectColor(float r, float g, float b);


    glm::mat4 view_matrix;

    Superficie* mySphere;
    Superficie* myCube;

    GLuint programHandle;
    GLuint vertShader;
    GLuint fragShader;
};
