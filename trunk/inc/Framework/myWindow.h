#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include "glutWindow.h"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <string>
#include <vector>
#include <map>
class Figura;

#include "Superficie.h"
#include <exception>
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
	void cargarTextura(std::string nombreTextura, GLuint programShader, std::string nombreVariableUniforme);
	void cargarTexturaYNormal(std::string nombreTextura, GLuint programShader, std::string nombreVariableUniforme,std::string nombreTexturaNormal,std::string nombreVUniformeNormal);
	void cargarTexturaYNormalParaReflexion(std::string nombreTextura, GLuint programShader, std::string nombreVariableUniforme,std::string nombreTexturaNormal,std::string nombreVUniformeNormal);
	void cargarTexturasReflexion(std::vector<std::string> texturas,GLuint programShader,std::string nombreVariableUniforme);
	
	// render CON buffers de tangentes y texturas
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo);

	// render CON buffers de tangentes y texturas
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			GLuint* index_buff, unsigned int index_buff_size, GLenum modo);

	// render SIN buffers de tangentes y texturas
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* normal_buff, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo);

	// renderObject que recibe parametros del material (Ka Kd Ks Shininess)
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* normal_buff, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo, glm::vec3 Ka,
			glm::vec3 Kd, glm::vec3 Ks, float Shininess);

	// renderObject que recibe parametros del material (Ka Kd Ks Shininess) y Textura Y PROGRAM HANDLE
	void renderObjectTextureCore (glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo, glm::vec3 Ka,
			glm::vec3 Kd, glm::vec3 Ks, float Shininess, GLuint programShader);
	
	// renderObject que recibe parametros del material (Ka Kd Ks Shininess) y Textura
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo, glm::vec3 Ka,
			glm::vec3 Kd, glm::vec3 Ks, float Shininess);
	
	// renderObject que recibe parametros del material (Ka Kd Ks Shininess), Textura y parametros de animacion
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, GLuint* index_buff,
			unsigned int index_buff_size, GLenum modo,
			glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, float Shininess,
			float amplitud, float numeroOnda, float velocidad, float tiempo);
	
	// renderObject que recibe parametros del material (Ka Kd Ks Shininess), Textura y Mapa de Normales
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, std::string nombreTexturaNormales,
			GLuint* index_buff, unsigned int index_buff_size, GLenum modo,
			glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, float Shininess);
	
	// renderObject que recibe parametros del material (Ka Kd Ks Shininess), Textura , Mapa de Normales y imagenes de reflexion
	void renderObject(glm::mat4 model_matrix, GLfloat* vertex_buff,
			GLfloat* tangent_buff, GLfloat* normal_buff, GLfloat* texture_buff,
			std::string nombreTextura, std::string nombreTexturaNormales,
			GLuint* index_buff, unsigned int index_buff_size, GLenum modo,
			glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, float Shininess,std::string negx,std::string negy,std::string negz,std::string posx,std::string posy,std::string posz);

	virtual void agregar_figura(Figura* fig);
	void axuuu(int a, int b);
	
private:
	bool animar;
	glm::vec3 background_color;
	void setDefault(GLuint programHandle);
	glm::vec3 m_pos, m_direct;
	std::vector<Figura*> figs;
	bool full_screen, Cmode, subio_antes;

    void changeObjectColor(float r, float g, float b);
    virtual void compilarPrograma(const char* nombreVertexShader, const char* nombreFragmentShader, GLuint& punteroProgramaFinal);
    // tener en cuenta que utiliza el ShaderProgram que le pasas
    void renderObjectCore (glm::mat4 model_matrix, GLfloat* vertex_buff, GLfloat* normal_buff,
    							 GLuint* index_buff, unsigned int index_buff_size, GLenum modo,
    							 glm::vec3 Ka,glm::vec3 Kd,glm::vec3 Ks,float Shininess,GLuint programShader);
    
    glm::mat3 calculateNormalMatrix (glm::mat4 model_matrix);
    
    glm::mat4 view_matrix;
    std::map<std::string,int> cacheTextureId;
    std::map<std::string,int> cacheTextureNormalId;
    Superficie* mySphere;
    Superficie* myCube;

    GLuint programHandleSoloPhong;
    GLuint programHandlePhongAndTexture;
    GLuint programHandlePhongAndTextureAndAnimation;
    GLuint programHandlePhongAndTextureAndNormalMap;
    GLuint programHandlePhongAndTextureAndNormalMapAndReflection;
    GLuint vertShader;
    GLuint fragShader;
};
