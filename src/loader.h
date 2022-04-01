#ifndef INC_2022_03_30_LOADER_H
#define INC_2022_03_30_LOADER_H

#include <cmath>
#include <iostream>

#include "GL/glew.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GLFW/glfw3.h"

#include "common/GLShader.h"
#include "libs/tiny_obj_loader.h"
#include "Vertex.h"

void initialize(GLShader *shader);

float *loadModel();

#endif //INC_2022_03_30_LOADER_H
