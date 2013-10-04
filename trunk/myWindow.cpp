#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

#include "myWindow.h"
   
#include <iostream>
#include <fstream>
#include <vector>
#include "figura.h"
void myWindow::createCube()
{
    if (this->cube_vertex_buffer != NULL)
    {
        delete this->cube_vertex_buffer;
    }
    this->cube_vertex_buffer_size = 3*8;
    this->cube_vertex_buffer = new GLfloat[this->cube_vertex_buffer_size];

    if (this->cube_normal_buffer != NULL)
    {
        delete this->cube_normal_buffer;
    }
    this->cube_normal_buffer_size = 3*8;
    this->cube_normal_buffer = new GLfloat[this->cube_normal_buffer_size];
    
    if (this->cube_index_buffer != NULL)
    {
        delete this->cube_index_buffer;
    }
    this->cube_index_buffer_size = 4 * 6;
    this->cube_index_buffer = new GLuint[this->cube_index_buffer_size];

    this->cube_vertex_buffer[0] = 0.5f;
    this->cube_vertex_buffer[1] = 0.5f;
    this->cube_vertex_buffer[2] = -0.5f;

    this->cube_vertex_buffer[3] = 0.5f;
    this->cube_vertex_buffer[4] = -0.5f;
    this->cube_vertex_buffer[5] = -0.5f;

    this->cube_vertex_buffer[6] = -0.5f;
    this->cube_vertex_buffer[7] = -0.5f;
    this->cube_vertex_buffer[8] = -0.5f;

    this->cube_vertex_buffer[9] = -0.5f;
    this->cube_vertex_buffer[10] = 0.5f;
    this->cube_vertex_buffer[11] = -0.5f;

    this->cube_vertex_buffer[12] = 0.5f;
    this->cube_vertex_buffer[13] = 0.5f;
    this->cube_vertex_buffer[14] = 0.5f;

    this->cube_vertex_buffer[15] = 0.5f;
    this->cube_vertex_buffer[16] = -0.5f;
    this->cube_vertex_buffer[17] = 0.5f;

    this->cube_vertex_buffer[18] = -0.5f;
    this->cube_vertex_buffer[19] = -0.5f;
    this->cube_vertex_buffer[20] = 0.5f;

    this->cube_vertex_buffer[21] = -0.5f;
    this->cube_vertex_buffer[22] = 0.5f;
    this->cube_vertex_buffer[23] = 0.5f;

    this->cube_index_buffer[0] = 0;
    this->cube_index_buffer[1] = 1;
    this->cube_index_buffer[2] = 2;
    this->cube_index_buffer[3] = 3;
 
    this->cube_index_buffer[4] = 4;
    this->cube_index_buffer[5] = 5;
    this->cube_index_buffer[6] = 6;
    this->cube_index_buffer[7] = 7;
    
    this->cube_index_buffer[8] = 0;
    this->cube_index_buffer[9] = 4;
    this->cube_index_buffer[10] = 5;
    this->cube_index_buffer[11] = 1;

    this->cube_index_buffer[12] = 1;
    this->cube_index_buffer[13] = 5;
    this->cube_index_buffer[14] = 6;
    this->cube_index_buffer[15] = 2;

    this->cube_index_buffer[16] = 2;
    this->cube_index_buffer[17] = 6;
    this->cube_index_buffer[18] = 7;
    this->cube_index_buffer[19] = 3;

    this->cube_index_buffer[20] = 3;
    this->cube_index_buffer[21] = 7;
    this->cube_index_buffer[22] = 4;
    this->cube_index_buffer[23] = 0;

    this->cube_normal_buffer[0] = 0.5f;
    this->cube_normal_buffer[1] = 0.5f;
    this->cube_normal_buffer[2] = 0.0f;

    this->cube_normal_buffer[3] = 0.5f;
    this->cube_normal_buffer[4] = -0.5f;
    this->cube_normal_buffer[5] = 0.0f;

    this->cube_normal_buffer[6] = -0.5f;
    this->cube_normal_buffer[7] = -0.5f;
    this->cube_normal_buffer[8] = 0.0f;

    this->cube_normal_buffer[9] = -0.5f;
    this->cube_normal_buffer[10] = 0.5f;
    this->cube_normal_buffer[11] = 0.0f;

    this->cube_normal_buffer[12] = 0.5f;
    this->cube_normal_buffer[13] = 0.5f;
    this->cube_normal_buffer[14] = 0.0f;

    this->cube_normal_buffer[15] = 0.5f;
    this->cube_normal_buffer[16] = -0.5f;
    this->cube_normal_buffer[17] = 0.0f;

    this->cube_normal_buffer[18] = -0.5f;
    this->cube_normal_buffer[19] = -0.5f;
    this->cube_normal_buffer[20] = 0.0f;

    this->cube_normal_buffer[21] = -0.5f;
    this->cube_normal_buffer[22] = 0.5f;
    this->cube_normal_buffer[23] = 0.0f;
}

void myWindow::createGrid(int size)
{
    if (this->grid_vertex_buffer != NULL)
    {
        delete this->grid_vertex_buffer;
    }
    this->grid_vertex_buffer_size = 12*(2*size +1);
    this->grid_vertex_buffer = new GLfloat[this->grid_vertex_buffer_size];
    
    
    if (this->grid_index_buffer != NULL)
    {
        delete this->grid_index_buffer;
    }
    this->grid_index_buffer_size = 4*(2*size +1);
    this->grid_index_buffer = new GLuint[this->grid_index_buffer_size];

    int offset;
    for (int i=0; i<size; i++)
    {
        offset = 24*i;
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = 0;


        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = 0;
    }

    offset = 24 * size;
    this->grid_vertex_buffer[offset++]   = -size;
    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = size;
    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = -size;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = size;
    this->grid_vertex_buffer[offset++] = 0;

    for (int i=0; i< this->grid_index_buffer_size; i++)
    {
        this->grid_index_buffer[i] = i;
    }
}

void myWindow::createSpiralSphere(const float radius, const unsigned int loops, const unsigned int segmentsPerLoop)
{
 
    if (this->vertex_buffer.size() >0)
    {
        this->vertex_buffer.clear();
    }

    if (this->index_buffer.size() >0)
    {
        this->index_buffer.clear();
    }

    float PI = 3.1415f;

	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		float theta = 0;
		float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
		float sinTheta = std::sin(theta);
		float sinPhi = std::sin(phi);
		float cosTheta = std::cos(theta);
		float cosPhi = std::cos(phi);

        // 
        this->vertex_buffer.push_back(radius * cosPhi * sinTheta); // Vx
        this->vertex_buffer.push_back(radius * sinPhi * sinTheta); // Vy
        this->vertex_buffer.push_back(radius * cosTheta);          // Vz
	}
	for (unsigned int loopNumber = 0; loopNumber <= loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			float theta = (loopNumber * PI / loops) + ((PI * loopSegmentNumber) / (segmentsPerLoop * loops));
			if (loopNumber == loops)
			{
				theta = PI;
			}
			float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
			float sinTheta = std::sin(theta);
			float sinPhi = std::sin(phi);
			float cosTheta = std::cos(theta);
			float cosPhi = std::cos(phi);

            this->vertex_buffer.push_back(radius * cosPhi * sinTheta);
            this->vertex_buffer.push_back(radius * sinPhi * sinTheta);
            this->vertex_buffer.push_back(radius * cosTheta);
		}
	}
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		this->index_buffer.push_back(loopSegmentNumber);
		this->index_buffer.push_back(segmentsPerLoop + loopSegmentNumber);
	}
	for (unsigned int loopNumber = 0; loopNumber < loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			this->index_buffer.push_back(((loopNumber + 1) * segmentsPerLoop) + loopSegmentNumber);
			this->index_buffer.push_back(((loopNumber + 2) * segmentsPerLoop) + loopSegmentNumber);
		}
	}

    //
    if (this->sphere_vertex_buffer != NULL)
    {
        delete[] this->sphere_vertex_buffer;
    }
    this->sphere_vertex_buffer = new float[this->vertex_buffer.size()];
    
    if ( this->sphere_index_buffer != NULL)
    {
        delete[] this->sphere_index_buffer;
    }
    this->sphere_index_buffer = new unsigned int[this->index_buffer.size()];

    std::vector<float>::iterator vertex_it;
    unsigned int v = 0;
    for (vertex_it = this->vertex_buffer.begin(); vertex_it != this->vertex_buffer.end(); vertex_it++)
    {
        this->sphere_vertex_buffer[v] = *vertex_it;
        v++;
    }

    std::vector<unsigned int>::iterator index_it;
    unsigned int i = 0;
    for (index_it = this->index_buffer.begin(); index_it != this->index_buffer.end(); index_it++)
    {
        this->sphere_index_buffer[i] = *index_it;
        i++;
    }
}

void myWindow::renderGrid(glm::mat4 model_matrix)
{
    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
    
    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->programHandle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->programHandle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}

    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, this->grid_vertex_buffer);
    
    glDrawElements(GL_LINES, this->grid_index_buffer_size, GL_UNSIGNED_INT, this->grid_index_buffer);
        
    glDisableClientState(GL_VERTEX_ARRAY);
}

void myWindow::renderSpiralSphere(glm::mat4 model_matrix)
{
    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
    glm::mat4 aux = this->view_matrix * model_matrix;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            normal_matrix[i][j] = aux[i][j];

    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->programHandle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->programHandle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}

    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, sphere_vertex_buffer);
	glNormalPointer(GL_FLOAT, 0, sphere_vertex_buffer);

    glDrawElements(GL_TRIANGLE_STRIP, index_buffer.size(), GL_UNSIGNED_INT, sphere_index_buffer);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void myWindow::renderCube(glm::mat4 model_matrix)
{
    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
        
    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->programHandle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->programHandle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}

    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, cube_vertex_buffer);
	glNormalPointer(GL_FLOAT, 0, cube_normal_buffer);

    glDrawElements(GL_QUADS, this->cube_index_buffer_size, GL_UNSIGNED_INT, this->cube_index_buffer);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

void myWindow::renderArm(glm::mat4 model_matrix)
{
    this->renderSpiralSphere(model_matrix);
    glm::mat4 m = glm::mat4 ( 1.0f );
    m = glm::scale(model_matrix, glm::vec3 (0.6f, 0.6f, 3.0f) );
    m = glm::translate(m , glm::vec3(0.0, 0.0, 0.5) );

    this->renderCube(m);
}

const char* loadShaderAsString(const char* file)
{
    std::ifstream shader_file(file, std::ifstream::in);
    std::string str((std::istreambuf_iterator<char>(shader_file)), std::istreambuf_iterator<char>());
    return str.c_str();
}

myWindow::myWindow()
{
    this->sphere_vertex_buffer = NULL;
    this->sphere_index_buffer = NULL;
    this->grid_index_buffer = NULL;
    this->grid_vertex_buffer = NULL;
    this->cube_index_buffer = NULL;
    this->cube_vertex_buffer = NULL;
    this->cube_normal_buffer = NULL;

    this->x=8.0f;
    this->y=0.0f;
    this->z=3.0f;

    this->atX=0;
    this->atY=0;
    this->angz=0;
}

void myWindow::changeObjectColor(float r, float g, float b)
{
    glm::vec3 diffuse_reflectivity = glm::vec3( r, g, b );

    GLuint location_diffuse_reflectivity = glGetUniformLocation( this->programHandle, "Kd"); 
    if( location_diffuse_reflectivity >= 0 ) 
	{ 
		glUniform3fv( location_diffuse_reflectivity, 1, &diffuse_reflectivity[0]); 
	}
}

void myWindow::OnRender(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //////////////////////////////////////
    // View and Projection Matrices Setting
    //
    // View (camera) Matrix
    this->view_matrix = glm::lookAt ( glm::vec3 ( x, y, z ), glm::vec3 (atX, atY, angz ), glm::vec3 ( 0.0, 0.0, 1.0 ) );

    // Projection Matrix
    glm::mat4 projection_matrix = glm::mat4 ( 1.0f );
    projection_matrix = glm::infinitePerspective( 52.0f , (float)this->width / (float)this->height, 0.1f);

    glUseProgram( this->programHandle );

    // Bind View MAtrix
    GLuint location_view_matrix = glGetUniformLocation( this->programHandle, "ViewMatrix"); 
    if( location_view_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_view_matrix, 1, GL_FALSE, &view_matrix[0][0]); 
	}

    // Bind View MAtrix
    GLuint location_projection_matrix = glGetUniformLocation( this->programHandle, "ProjectionMatrix"); 
    if( location_projection_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_projection_matrix, 1, GL_FALSE, &projection_matrix[0][0]); 
	}
    //
    ///////////////////////////////////////////
    

    //////////////////////////////////////
    // Bind Light Settings
    glm::vec4 light_position = glm::vec4( 8.0f, 8.0f, 2.0f, 1.0f );
    glm::vec3 light_intensity = glm::vec3( 1.0f, 1.0f, 1.0f );
       
    GLuint location_light_position = glGetUniformLocation( this->programHandle, "LightPosition"); 
    if( location_light_position >= 0 ) 
	{ 
        glUniform4fv( location_light_position, 1, &light_position[0]); 
	}

    GLuint location_light_intensity = glGetUniformLocation( this->programHandle, "Ld"); 
    if( location_light_intensity >= 0 ) 
	{ 
		glUniform3fv( location_light_intensity, 1, &light_intensity[0]); 
	}
    //
    ///////////////////////////////////////////


    // Drawwing Grid
    changeObjectColor(0.5, 0.5, 0.5);
    glm::mat4 model_matrix_grid = glm::mat4 ( 1.0f );

    this->renderGrid(model_matrix_grid);



    // ARM
    glm::mat4 model_matrix = glm::mat4 ( 1.0f );
    changeObjectColor(0.8, 0.8, 0.3);
    
    for (int i = 0; i < figs.size(); ++i) {
   		figs[i]->renderizar(model_matrix);
   	}

    // Rotaci\F3n de ejemplo
    model_matrix = glm::rotate (model_matrix, -95.0f, glm::vec3( 1.0, 0.0, 1.0));

    //this->renderArm(model_matrix);
    
    glutSwapBuffers();
}
void myWindow::agregar_figura(Figura* fig){
	this->figs.push_back(fig);
}
void  myWindow::OnIdle()
{
}

// When OnInit is called, a render context (in this case GLUT-Window) 
// is already available!
void  myWindow::OnInit()
{
    this->createSpiralSphere(1.0, 32, 32);
    this->createGrid(10);
    this->createCube();
    
	glClearColor(0.3f, 0.3f, 0.4f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

    

	// ********************************************
    // Compiling the shader programms
    //*********************************************

	// Do your GLEW experiments here:
    if (GLEW_ARB_shading_language_100) 
    { 
        std::cout << "GLEW_ARB_shading_language_100" << std::endl;
        int major, minor, revision;
        const GLubyte* sVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
        if (glGetError() == GL_INVALID_ENUM)
        {
            major = 1; minor = 0; revision=51;
        }
        else
        {
            std::string version((char*)sVersion);
            std::cout << version.c_str() << std::endl;
        }

        // Load vertex Shader
        this->vertShader = glCreateShader (GL_VERTEX_SHADER);
        if ( 0 == this->vertShader )
        {
            std::cout << "Error creating vertex shader" << std::endl;
        }

        std::ifstream v_shader_file("DiffuseShadingVShader.vert", std::ifstream::in);
        std::string v_str((std::istreambuf_iterator<char>(v_shader_file)), std::istreambuf_iterator<char>());
        const char* vs_code_array[] = {v_str.c_str()};
        
        glShaderSource( this->vertShader, 1, vs_code_array, NULL);

        // Compilar el shader
        glCompileShader( this->vertShader );

        // verificar resultado de la compilacion
        GLint vs_compilation_result;
        glGetShaderiv( this->vertShader, GL_COMPILE_STATUS, &vs_compilation_result );
        if( GL_FALSE == vs_compilation_result )
        {
            std::cout << "Vertex shader compilation failed!\n" << std::endl;
            GLint logLen;
            glGetShaderiv( this->vertShader, GL_INFO_LOG_LENGTH, &logLen );
            if( logLen > 0 )
            {
                char * log = (char *)malloc(logLen);
                GLsizei written;
                glGetShaderInfoLog(vertShader, logLen, &written, log);
                std::cout << "Shader log: " << log << std::endl;
                free(log);
            }
        }

         // Load fragment Shader
        this->fragShader = glCreateShader (GL_FRAGMENT_SHADER);
        if ( 0 == this->fragShader )
        {
            std::cout << "Error creating fragment shader" << std::endl;
        }

        std::ifstream f_shader_file("DiffuseShadingFShader.frag", std::ifstream::in);
        std::string f_str((std::istreambuf_iterator<char>(f_shader_file)), std::istreambuf_iterator<char>());
        const char* fs_code_array[] = {f_str.c_str()};
        
        glShaderSource( this->fragShader, 1, fs_code_array, NULL);

        // Compilar el shader
        glCompileShader( this->fragShader );

        // verificar resultado de la compilacion
        GLint fs_compilation_result;
        glGetShaderiv( this->fragShader, GL_COMPILE_STATUS, &fs_compilation_result );
        if( GL_FALSE == fs_compilation_result )
        {
            std::cout << "Fragment shader compilation failed!\n" << std::endl;
            GLint logLen;
            glGetShaderiv( this->fragShader, GL_INFO_LOG_LENGTH, &logLen );
            if( logLen > 0 )
            {
                char * log = (char *)malloc(logLen);
                GLsizei written;
                glGetShaderInfoLog( this->fragShader, logLen, &written, log);
                std::cout << "Shader log: " << log << std::endl;
                free(log);
            }
        }
	// *******************************************

    // *******************************************
    // Linking the shader programms
    // *******************************************
        this->programHandle = glCreateProgram();
        if ( 0 == this->programHandle )
        {
            std::cout << "Error creating program object" << std::endl;
        }
        else
        {
            glAttachShader( this->programHandle, this->vertShader );
            glAttachShader( this->programHandle, this->fragShader );

            glLinkProgram( this->programHandle );

            GLint status;
            glGetProgramiv( this->programHandle, GL_LINK_STATUS, &status );
            if( GL_FALSE == status )
            {
                std::cout << "Failed to link shader program!\n" << std::endl;
                GLint logLen;
                glGetProgramiv( this->programHandle, GL_INFO_LOG_LENGTH, &logLen);
                if( logLen > 0 )
                {
                    char * log = (char *)malloc(logLen);
                    GLsizei written;
                    glGetProgramInfoLog(programHandle, logLen, &written, log);
                    std::cout << "Program log: \n%s" << std::endl;
                    free(log);
                }
            }
            else
            {
                glUseProgram( this->programHandle );
            }
        }
    }
}

void myWindow::OnResize(int w, int h) 
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    this->width = w;
    this->height = h;
}

void  myWindow::OnClose(void)
{
}

void myWindow::OnMouseDown(int button, int x, int y)
{
}

void myWindow::OnMouseUp(int button, int x, int y)
{
}

void myWindow::OnMouseWheel(int nWheelNumber, int nDirection, int x, int y)
{
}

void myWindow::OnKeyDown(int nKey, char cAscii)
{       
	if (cAscii == 27) // 0x1b = ESC
	{
		this->Close(); // Close Window!
	}
	switch(cAscii){
	case('4'):
		this->atY--;
		break;
	case('6'):
		this->atY++;
		break;
	case('8'):
		this->angz++;
		break;
	case('5'):
		this->angz--;
		break;
	}
	switch(nKey){
	case(GLUT_KEY_UP):
		this->x--;
		this->atX--;
		break;
	case(GLUT_KEY_DOWN):
		this->x++;
		this->atX++;
		break;
	case(GLUT_KEY_LEFT ):
		this->y--;
		this->atY--;
		break;
	case(GLUT_KEY_RIGHT):
		this->atY++;
		this->y++;
		break;
	}
	this->OnRender();
};

void myWindow::OnKeyUp(int nKey, char cAscii)
{
	if (cAscii == 'f')
	{
		SetFullscreen(true);
	}
	else if (cAscii == 'w')
	{
		SetFullscreen(false);
	}
};
