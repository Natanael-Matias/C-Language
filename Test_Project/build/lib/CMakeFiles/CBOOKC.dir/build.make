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
CMAKE_SOURCE_DIR = "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build"

# Include any dependencies generated for this target.
include lib/CMakeFiles/CBOOKC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/CBOOKC.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/CBOOKC.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/CBOOKC.dir/flags.make

lib/CMakeFiles/CBOOKC.dir/CBook.c.o: lib/CMakeFiles/CBOOKC.dir/flags.make
lib/CMakeFiles/CBOOKC.dir/CBook.c.o: ../lib/CBook.c
lib/CMakeFiles/CBOOKC.dir/CBook.c.o: lib/CMakeFiles/CBOOKC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/CMakeFiles/CBOOKC.dir/CBook.c.o"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/CMakeFiles/CBOOKC.dir/CBook.c.o -MF CMakeFiles/CBOOKC.dir/CBook.c.o.d -o CMakeFiles/CBOOKC.dir/CBook.c.o -c "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/lib/CBook.c"

lib/CMakeFiles/CBOOKC.dir/CBook.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CBOOKC.dir/CBook.c.i"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/lib/CBook.c" > CMakeFiles/CBOOKC.dir/CBook.c.i

lib/CMakeFiles/CBOOKC.dir/CBook.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CBOOKC.dir/CBook.c.s"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/lib/CBook.c" -o CMakeFiles/CBOOKC.dir/CBook.c.s

# Object files for target CBOOKC
CBOOKC_OBJECTS = \
"CMakeFiles/CBOOKC.dir/CBook.c.o"

# External object files for target CBOOKC
CBOOKC_EXTERNAL_OBJECTS =

lib/libCBOOKC.a: lib/CMakeFiles/CBOOKC.dir/CBook.c.o
lib/libCBOOKC.a: lib/CMakeFiles/CBOOKC.dir/build.make
lib/libCBOOKC.a: lib/CMakeFiles/CBOOKC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libCBOOKC.a"
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && $(CMAKE_COMMAND) -P CMakeFiles/CBOOKC.dir/cmake_clean_target.cmake
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CBOOKC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/CBOOKC.dir/build: lib/libCBOOKC.a
.PHONY : lib/CMakeFiles/CBOOKC.dir/build

lib/CMakeFiles/CBOOKC.dir/clean:
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" && $(CMAKE_COMMAND) -P CMakeFiles/CBOOKC.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/CBOOKC.dir/clean

lib/CMakeFiles/CBOOKC.dir/depend:
	cd "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/lib" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib" "/mnt/c/Users/natan/OneDrive/Área de Trabalho/Cursos/C-Language/Test_Project/build/lib/CMakeFiles/CBOOKC.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/CBOOKC.dir/depend

