#pragma once
#include <GL/gl.h>
#include "glutWindow.h"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 

#include <vector>

class myWindow : public cwc::glutWindow
{
public:
	myWindow();

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

	virtual void OnKeyDown(int nKey, char cAscii);

	virtual void OnKeyUp(int nKey, char cAscii);

private:

	void createCube();
	void loadAndInitTexture(const char* filename);
	void changeObjectColor(float r, float g, float b);
    
    glm::mat4 view_matrix;

	GLfloat* sphere_vertex_buffer;
	GLuint* sphere_index_buffer;

	std::vector<float> vertex_buffer;
	std::vector<unsigned int> index_buffer;

	GLint alfa;
	GLuint programHandle;
	GLuint vertShader;
	GLuint fragShader;

	GLuint textureid;
};
