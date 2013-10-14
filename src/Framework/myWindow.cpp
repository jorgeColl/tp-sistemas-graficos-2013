#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glext.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

#include "myWindow.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "figura.h"
#include "Esfera.h"
#include "Cubo.h"

void myWindow::renderObject (glm::mat4 model_matrix, GLfloat* vertex_buff, GLfloat* normal_buff,
							 GLuint* index_buff, unsigned int index_buff_size, GLenum modo)
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

	glVertexPointer(3, GL_FLOAT, 0, vertex_buff);
	glNormalPointer(GL_FLOAT, 0, normal_buff);

    glDrawElements (modo, index_buff_size, GL_UNSIGNED_INT, index_buff);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

const char* loadShaderAsString(const char* file)
{
    std::ifstream shader_file(file, std::ifstream::in);
    std::string str((std::istreambuf_iterator<char>(shader_file)), std::istreambuf_iterator<char>());
    return str.c_str();
}

/* funcion auxiliar utilizada por OnKeyDown y axuuuu para escalar los vectores*/
void escalar_aux(glm::vec3& vector,float sensibilidad){
	vector.x = (vector.x /sensibilidad);
	vector.y = (vector.y /sensibilidad);
	vector.z = (vector.z /sensibilidad);
}
void myWindow::axuuu(int a, int b){
	//std::cout<<"x:"<<a<<" y:"<<b<<std::endl;
	//std::cout<<"centroX: "<<width/2<<" centroY: "<<height/2<<std::endl;

	int centroX = (width/2);
	int centroY = (height/2);
	float difx = ( centroX - a);
	float difY = ( centroY -b);
	//std::cout<<"difereciaX: "<<difx<<" diferenciaY: "<<difY<<std::endl;

	glm::vec3 ejeZ(0.0f, 0.0f, 1.0f);
	glm::vec3 dir = (m_pos - m_direct);
	glm::vec3 rotx = glm::normalize(glm::cross(dir, ejeZ));
	glm::vec3 roty = glm::normalize(glm::cross(rotx, dir));

	dir = glm::normalize(dir);

	float sensibilidad = 30.0f;
	escalar_aux(rotx, sensibilidad);
	escalar_aux(roty, sensibilidad);

	if (difx < 0) {
		m_direct = m_pos - dir - rotx;
		glutWarpPointer(width / 2, height / 2);
	} else if (difx > 0) {
		m_direct = m_pos - dir + rotx;
		glutWarpPointer(width / 2, height / 2);
	}
	if (difY > 0) {
		if (roty.z > 0.005f || subio_antes == false) {
			m_direct = m_pos - dir + roty;
		}
		subio_antes = true;
		glutWarpPointer(width/2,height/2);
	}else if (difY<0){
		if (roty.z > 0.005f || subio_antes == true) {
			m_direct = m_pos - dir - roty;
		}
		subio_antes = false;
		glutWarpPointer(width/2,height/2);
	}
	std::cout<<"ROTY: "<<roty.x<<" , "<<roty.y<<" , "<<roty.z<<std::endl;

	this->Repaint();

}
extern void* instancia;
void aux (int a, int b){
	((myWindow*)instancia)->axuuu(a,b);
}

myWindow::~myWindow() {
	delete this->mySphere;
	delete this->myCube;
}

myWindow::myWindow():m_pos(8.0f, 0.0f,3.0f), m_direct(1.0f,0.0f,0.0f)
{
	myCube=NULL;
	mySphere=NULL;
    full_screen = false;
    subio_antes = false;
    glutPassiveMotionFunc(aux);
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

    this->view_matrix = glm::lookAt ( this->m_pos,this->m_direct, glm::vec3 ( 0.0, 0.0, 1.0 ) );

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


    // Drawing Grid
    /*changeObjectColor(0.5, 0.5, 0.5);
    glm::mat4 model_matrix_grid = glm::mat4 ( 1.0f );
	this->myGrid->render(model_matrix_grid);
	*/


    // ARM
    glm::mat4 model_matrix = glm::mat4 ( 1.0f );
    changeObjectColor(0.8, 0.8, 0.3);
    
    for (unsigned int i = 0; i < figs.size(); ++i) {
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
    this->mySphere = new Esfera (this, 1.0, 32, 32);
    this->myCube = new Cubo (this);
    
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
//        int major, minor, revision;
        const GLubyte* sVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
        if (glGetError() == GL_INVALID_ENUM)
        {
//            major = 1; minor = 0; revision=51;
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
//! Called when Mouse is moved (without pressing any button)
void myWindow::OnMouseMove(int x, int y){
//std::cout<<"se movio en x: "<<x<<std::endl;
//std::cout<<"se movio en y: "<<y<<std::endl;
}

void myWindow::OnKeyDown(int nKey, char cAscii)
{
	glm::vec3 ejeZ (0.0f,0.0f,1.0f);
	glm::vec3 ejeY (0.0f,1.0f,0.0f);
	glm::vec3 dir = (m_pos-m_direct);
	glm::vec3 rotx = glm::normalize( glm::cross(dir, ejeZ) );
	glm::vec3 roty = glm::normalize( glm::cross(rotx,dir) );

	dir = glm::normalize(dir);

	float sensibilidad = 5.0f;
	escalar_aux(dir,sensibilidad);
	escalar_aux(rotx,sensibilidad);
	escalar_aux(roty,sensibilidad);

	bool cerrada = false;
	if (cAscii == 27) // 0x1b = ESC
	{
		cerrada = true;
		this->Close(); // Close Window!
	}
	sensibilidad=sensibilidad*2;
	switch(cAscii) {
	case ('4'):
		escalar_aux(rotx,sensibilidad);
		m_direct = m_pos-dir+rotx;
		break;
	case ('6'):
		escalar_aux(rotx,sensibilidad);
		m_direct = m_pos-dir-rotx;
		break;
	case ('8'):
		escalar_aux(roty,sensibilidad);
		if(roty.z>0.002 || subio_antes==false){
		m_direct = m_pos-dir+roty;
		}
		subio_antes=true;
		//std::cout<<"ROTY: "<<roty.x<<" , "<<roty.y<<" , "<<roty.z<<std::endl;
		break;
	case ('5'):
		escalar_aux(roty,sensibilidad);
		if(roty.z>0.002 || subio_antes==true){
			m_direct = m_pos-dir-roty;
		}
		subio_antes=false;
		//std::cout<<"ROTY: "<<roty.x<<" , "<<roty.y<<" , "<<roty.z<<std::endl;
		break;
	case ('w'):
		this->m_pos -= dir;
		this->m_direct = m_pos - dir;
		break;
	case ('s'):
		this->m_pos += dir;
		this->m_direct = m_pos - dir;
		break;
	case ('a'):
		this->m_pos += rotx;
		m_direct = m_pos - dir;
		break;
	case ('d'):
		this->m_pos -= rotx;
		m_direct = m_pos - dir;
		break;
	case ('h'):
		for(unsigned int i=0;i<this->figs.size();++i) {
			figs[i]->animar();
		}
		break;
	case ('i'):
		this->m_pos.z++;
		this->m_direct.z++;
		break;
	case ('k'):
		this->m_pos.z--;
		this->m_direct.z--;
		break;
	}
	//std::cout<<"at: "<<m_direct.x<<","<<m_direct.y<<","<<m_direct.z<<"from: "<<m_pos.x<<","<<m_pos.y<<","<<m_pos.z<<std::endl;
	if (!cerrada) this->OnRender();
}

void myWindow::OnKeyUp(int nKey, char cAscii)
{
	if (cAscii == 'f')
	{
		if(full_screen){
			full_screen = false;
		}else {
			full_screen = true;
		}

		SetFullscreen(full_screen);
	}

}
