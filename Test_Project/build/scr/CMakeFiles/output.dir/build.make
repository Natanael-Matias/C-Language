# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build"

# Include any dependencies generated for this target.
include scr/CMakeFiles/output.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scr/CMakeFiles/output.dir/compiler_depend.make

# Include the progress variables for this target.
include scr/CMakeFiles/output.dir/progress.make

# Include the compile flags for this target's objects.
include scr/CMakeFiles/output.dir/flags.make

scr/CMakeFiles/output.dir/main.c.o: scr/CMakeFiles/output.dir/flags.make
scr/CMakeFiles/output.dir/main.c.o: ../scr/main.c
scr/CMakeFiles/output.dir/main.c.o: scr/CMakeFiles/output.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object scr/CMakeFiles/output.dir/main.c.o"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT scr/CMakeFiles/output.dir/main.c.o -MF CMakeFiles/output.dir/main.c.o.d -o CMakeFiles/output.dir/main.c.o -c "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/scr/main.c"

scr/CMakeFiles/output.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/output.dir/main.c.i"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/scr/main.c" > CMakeFiles/output.dir/main.c.i

scr/CMakeFiles/output.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/output.dir/main.c.s"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/scr/main.c" -o CMakeFiles/output.dir/main.c.s

# Object files for target output
output_OBJECTS = \
"CMakeFiles/output.dir/main.c.o"

# External object files for target output
output_EXTERNAL_OBJECTS =

../bin/output: scr/CMakeFiles/output.dir/main.c.o
../bin/output: scr/CMakeFiles/output.dir/build.make
../bin/output: lib/libUTILSC.a
../bin/output: lib/libCBOOKC.a
../bin/output: lib/libBINOMIOC.a
../bin/output: scr/CMakeFiles/output.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/output"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/output.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scr/CMakeFiles/output.dir/build: ../bin/output
.PHONY : scr/CMakeFiles/output.dir/build

scr/CMakeFiles/output.dir/clean:
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" && $(CMAKE_COMMAND) -P CMakeFiles/output.dir/cmake_clean.cmake
.PHONY : scr/CMakeFiles/output.dir/clean

scr/CMakeFiles/output.dir/depend:
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/scr" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/Linguagem_C/Test_Project/build/scr/CMakeFiles/output.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : scr/CMakeFiles/output.dir/depend

