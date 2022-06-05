# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /config/Desktop/OpenGL-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /config/Desktop/OpenGL-project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /config/Desktop/OpenGL-project/CMakeFiles /config/Desktop/OpenGL-project/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /config/Desktop/OpenGL-project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 2022_03_30

# Build rule for target.
2022_03_30: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 2022_03_30
.PHONY : 2022_03_30

# fast build rule for target.
2022_03_30/fast:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/build
.PHONY : 2022_03_30/fast

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Quaternion.o: src/Quaternion.cpp.o

.PHONY : src/Quaternion.o

# target to build an object file
src/Quaternion.cpp.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Quaternion.cpp.o
.PHONY : src/Quaternion.cpp.o

src/Quaternion.i: src/Quaternion.cpp.i

.PHONY : src/Quaternion.i

# target to preprocess a source file
src/Quaternion.cpp.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Quaternion.cpp.i
.PHONY : src/Quaternion.cpp.i

src/Quaternion.s: src/Quaternion.cpp.s

.PHONY : src/Quaternion.s

# target to generate assembly for a file
src/Quaternion.cpp.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/Quaternion.cpp.s
.PHONY : src/Quaternion.cpp.s

src/common/GLShader.o: src/common/GLShader.cpp.o

.PHONY : src/common/GLShader.o

# target to build an object file
src/common/GLShader.cpp.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/common/GLShader.cpp.o
.PHONY : src/common/GLShader.cpp.o

src/common/GLShader.i: src/common/GLShader.cpp.i

.PHONY : src/common/GLShader.i

# target to preprocess a source file
src/common/GLShader.cpp.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/common/GLShader.cpp.i
.PHONY : src/common/GLShader.cpp.i

src/common/GLShader.s: src/common/GLShader.cpp.s

.PHONY : src/common/GLShader.s

# target to generate assembly for a file
src/common/GLShader.cpp.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/common/GLShader.cpp.s
.PHONY : src/common/GLShader.cpp.s

src/libs/tiny_obj_loader.o: src/libs/tiny_obj_loader.cc.o

.PHONY : src/libs/tiny_obj_loader.o

# target to build an object file
src/libs/tiny_obj_loader.cc.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/libs/tiny_obj_loader.cc.o
.PHONY : src/libs/tiny_obj_loader.cc.o

src/libs/tiny_obj_loader.i: src/libs/tiny_obj_loader.cc.i

.PHONY : src/libs/tiny_obj_loader.i

# target to preprocess a source file
src/libs/tiny_obj_loader.cc.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/libs/tiny_obj_loader.cc.i
.PHONY : src/libs/tiny_obj_loader.cc.i

src/libs/tiny_obj_loader.s: src/libs/tiny_obj_loader.cc.s

.PHONY : src/libs/tiny_obj_loader.s

# target to generate assembly for a file
src/libs/tiny_obj_loader.cc.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/libs/tiny_obj_loader.cc.s
.PHONY : src/libs/tiny_obj_loader.cc.s

src/loader.o: src/loader.cpp.o

.PHONY : src/loader.o

# target to build an object file
src/loader.cpp.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/loader.cpp.o
.PHONY : src/loader.cpp.o

src/loader.i: src/loader.cpp.i

.PHONY : src/loader.i

# target to preprocess a source file
src/loader.cpp.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/loader.cpp.i
.PHONY : src/loader.cpp.i

src/loader.s: src/loader.cpp.s

.PHONY : src/loader.s

# target to generate assembly for a file
src/loader.cpp.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/loader.cpp.s
.PHONY : src/loader.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/2022_03_30.dir/build.make CMakeFiles/2022_03_30.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... 2022_03_30"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Quaternion.o"
	@echo "... src/Quaternion.i"
	@echo "... src/Quaternion.s"
	@echo "... src/common/GLShader.o"
	@echo "... src/common/GLShader.i"
	@echo "... src/common/GLShader.s"
	@echo "... src/libs/tiny_obj_loader.o"
	@echo "... src/libs/tiny_obj_loader.i"
	@echo "... src/libs/tiny_obj_loader.s"
	@echo "... src/loader.o"
	@echo "... src/loader.i"
	@echo "... src/loader.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

