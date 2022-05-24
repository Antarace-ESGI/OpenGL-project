cmake_minimum_required(VERSION 3.21)
project (2022_03_30)

set(CMAKE_CXX_STANDARD 14)

add_executable(2022_03_30
        src/main.cpp src/main.h
        src/common/GLShader.cpp src/common/GLShader.h
        src/Game.cpp src/Game.h
        src/DragonData.h
        src/libs/tiny_obj_loader.cc src/libs/tiny_obj_loader.h
        src/loader.cpp src/loader.h src/Vertex.h src/Quaternion.cpp src/Quaternion.h)

# Libraries

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(2022_03_30 PUBLIC ${OPENGL_INCLUDE_DIRS})
target_link_libraries(2022_03_30 OpenGL::GL)
target_link_libraries(2022_03_30 OpenGL::GLU)

# GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})
target_link_libraries(2022_03_30 GLEW::GLEW)

# GLFW
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(2022_03_30 glfw)

# Copy
#file(COPY shaders DESTINATION .)
#file(COPY resources DESTINATION .)