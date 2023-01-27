#ifndef __COMMON__
#define __COMMON__ "common.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"

GLFWwindow* WindowCreate();

void WindowRunloop(GLFWwindow*, unsigned char*, GLuint, GLuint);

GLuint NewShader(GLenum shaderType, const char*);

GLuint NewTexture(unsigned char*);

#endif /* ! */
