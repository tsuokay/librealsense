#ifndef DS4OSX_Util_h
#define DS4OSX_Util_h

#ifdef _WIN32
#include <GL\glew.h>
#elif __APPLE__
#include <OpenGL/gl3.h>
#elif __linux__
#include <GL/glew.h>
#include <GL/gl.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdint>
#include <array>

#ifndef CHECK_GL_ERROR
#define CHECK_GL_ERROR() CheckGLError(__FILE__, __LINE__)
#endif

void convert_yuyv_rgb(const uint8_t *src, int width, int height, uint8_t *dst);

void CheckGLError(const char* file, int32_t line);

GLuint CreateGLProgram(const std::string & vertSource, const std::string & fragSource);

GLuint CreateTexture(int width, int height, GLint internalFmt);

void ConvertDepthToRGBUsingHistogram(uint8_t img[], const uint16_t depthImage[], int width, int height, const float nearHue, const float farHue);

std::array<double, 3> rgbToHsv(uint8_t r, uint8_t g, uint8_t b);

std::array<int, 3> hsvToRgb(float h, float s, float v);

void drawTexture(GLuint prog, GLuint vbo, GLuint texHandle, GLuint texId, const void * pixels, int width, int height, GLint fmt, GLenum type);

#endif
