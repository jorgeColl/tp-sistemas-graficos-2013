#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

#include "myWindow.h"

#include "SOIL.h"

#include <iostream>
#include <fstream>
#include <vector>

float positionData[] = 
{
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f
};
GLuint positionBufferHandle;

float normalData[] = 
{
    1.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  0.0f,
     
    0.0f,  1.0f,  0.0f,
    0.0f,  1.0f,  0.0f,
    0.0f,  1.0f,  0.0f,
    0.0f,  1.0f,  0.0f,

   -1.0f,  0.0f,  0.0f,
   -1.0f,  0.0f,  0.0f,
   -1.0f,  0.0f,  0.0f,
   -1.0f,  0.0f,  0.0f,
     
    0.0f, -1.0f,  0.0f,
    0.0f, -1.0f,  0.0f,
    0.0f, -1.0f,  0.0f,
    0.0f, -1.0f,  0.0f,
     
    0.0f,  0.0f,  1.0f,
    0.0f,  0.0f,  1.0f,
    0.0f,  0.0f,  1.0f,
    0.0f,  0.0f,  1.0f,

    0.0f,  0.0f, -1.0f,
    0.0f,  0.0f, -1.0f,
    0.0f,  0.0f, -1.0f,
    0.0f,  0.0f, -1.0f
};

GLuint normalBufferHandle;

float textureData[] = 
{
    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,
     
    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,

    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,
     
    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,
     
    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,

    0.0f,  0.0f,
    1.0f,  0.0f,
    1.0f,  1.0f,
    0.0f,  1.0f,
};


void myWindow::createCube()
{
}

// Handle to the vertex array object
GLuint vaoHandle;

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
    this->alfa = 0;
}

void  myWindow::loadAndInitTexture(const char* filename)
{
    // Load texture file
   	int image_witdh;
	int image_height;
	int image_channels;
	unsigned char* image_buffer  = SOIL_load_image(filename, &image_witdh, &image_height, &image_channels, SOIL_LOAD_RGBA);
    
    // Copy file to OpenGL
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &this->textureid);
    glBindTexture(GL_TEXTURE_2D, this->textureid);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_witdh, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_buffer);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    // Set the Tex1 sampler uniform to refer to texture unit 0
    int loc = glGetUniformLocation(this->programHandle, "Tex1");
    
    if( loc >= 0 )
    {
		// We indicate that Uniform Variable sampler2D "text" uses  Texture Unit 0 
        glUniform1i(loc, 0);
    }
    else
    {
        fprintf(stderr, "Uniform variable Tex1 not found!\n");
    }
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
    
    // View (camera) Matrix
    glm::mat4 view_matrix = glm::lookAt ( glm::vec3 ( 3.0, 3.0, 3.0 ),
                                          glm::vec3 ( 0.0, 0.0, 0.0 ),
                                          glm::vec3 ( 0.0, 0.0, 1.0 ) );

    // Model Matrix
    glm::mat4 model_matrix = glm::mat4 ( 1.0f );
    model_matrix = glm::scale ( model_matrix,  glm::vec3 (2.0f, 2.0f, 2.0f)  );
    model_matrix = glm::rotate( model_matrix, (GLfloat)this->alfa, glm::vec3(0.0f, 0.0f, 1.0f) );

    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
    // normal_matrix = 
    glm::mat4 aux = view_matrix * model_matrix;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            normal_matrix[i][j] = aux[i][j];

    // Projection Matrix
    glm::mat4 projection_matrix = glm::mat4 ( 1.0f );
    projection_matrix = glm::infinitePerspective( 60.0f , (float)this->width / (float)this->height, 0.1f);

    glUseProgram( this->programHandle );

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->programHandle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}

    // Bind View MAtrix
    GLuint location_view_matrix = glGetUniformLocation( this->programHandle, "ViewMatrix"); 
    if( location_view_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_view_matrix, 1, GL_FALSE, &view_matrix[0][0]); 
	}

    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->programHandle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind View MAtrix
    GLuint location_projection_matrix = glGetUniformLocation( this->programHandle, "ProjectionMatrix"); 
    if( location_projection_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_projection_matrix, 1, GL_FALSE, &projection_matrix[0][0]); 
	}
    
    //////////////////////////////////////
    // Bind Light Settings
    glm::vec4 light_position = glm::vec4( 0.0f, 1.0f, 1.0f, 1.0f );
    glm::vec3 light_intensity = glm::vec3( 1.0f, 1.0f, 1.0f );
    glm::vec3 diffuse_reflectivity = glm::vec3( 0.8f, 0.8f, 0.8f );
    
    GLuint location_light_position = glGetUniformLocation( this->programHandle, "LightPosition"); 
    if( location_light_position >= 0 ) 
	{ 
        glUniform4fv( location_light_position, 1, &light_position[0]); 
	}

    GLuint location_diffuse_reflectivity = glGetUniformLocation( this->programHandle, "Kd"); 
    if( location_diffuse_reflectivity >= 0 ) 
	{ 
		glUniform3fv( location_diffuse_reflectivity, 1, &diffuse_reflectivity[0]); 
	}

    GLuint location_light_intensity = glGetUniformLocation( this->programHandle, "Ld"); 
    if( location_light_intensity >= 0 ) 
	{ 
		glUniform3fv( location_light_intensity, 1, &light_intensity[0]); 
	}
    //
    ///////////////////////////////////////////

    glBindVertexArray( vaoHandle );
    glDrawArrays(GL_QUADS, 0, 24);

    glutSwapBuffers();
}

void  myWindow::OnIdle()
{
    this->alfa +=1;
    this->alfa %= 360;
    
    this->Repaint();
}

// When OnInit is called, a render context (in this case GLUT-Window) 
// is already available!
void  myWindow::OnInit()
{
    glClearColor(0.3f, 0.3f, 0.4f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, positionData);
	glNormalPointer(GL_FLOAT, 0, normalData);
	glTexCoordPointer(2, GL_FLOAT, 0, textureData);

	// *******************************************
    // Load Texture
    // *********************************************
    

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

        std::ifstream v_shader_file("TexturingAndDiffuseShadingVShader.vert", std::ifstream::in);
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

        std::ifstream f_shader_file("TexturingAndDiffuseShadingFShader.frag", std::ifstream::in);
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
    loadAndInitTexture("brick.jpg");
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
