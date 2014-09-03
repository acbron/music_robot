# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/szy/文档/CMake_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/szy/文档/CMake_Project

# Include any dependencies generated for this target.
include src/onsets/CMakeFiles/onset.dir/depend.make

# Include the progress variables for this target.
include src/onsets/CMakeFiles/onset.dir/progress.make

# Include the compile flags for this target's objects.
include src/onsets/CMakeFiles/onset.dir/flags.make

src/onsets/CMakeFiles/onset.dir/onsetsds.c.o: src/onsets/CMakeFiles/onset.dir/flags.make
src/onsets/CMakeFiles/onset.dir/onsetsds.c.o: src/onsets/onsetsds.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/szy/文档/CMake_Project/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/onsets/CMakeFiles/onset.dir/onsetsds.c.o"
	cd /home/szy/文档/CMake_Project/src/onsets && g++  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/onset.dir/onsetsds.c.o   -c /home/szy/文档/CMake_Project/src/onsets/onsetsds.c

src/onsets/CMakeFiles/onset.dir/onsetsds.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onset.dir/onsetsds.c.i"
	cd /home/szy/文档/CMake_Project/src/onsets && g++  $(C_DEFINES) $(C_FLAGS) -E /home/szy/文档/CMake_Project/src/onsets/onsetsds.c > CMakeFiles/onset.dir/onsetsds.c.i

src/onsets/CMakeFiles/onset.dir/onsetsds.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onset.dir/onsetsds.c.s"
	cd /home/szy/文档/CMake_Project/src/onsets && g++  $(C_DEFINES) $(C_FLAGS) -S /home/szy/文档/CMake_Project/src/onsets/onsetsds.c -o CMakeFiles/onset.dir/onsetsds.c.s

src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.requires:
.PHONY : src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.requires

src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.provides: src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.requires
	$(MAKE) -f src/onsets/CMakeFiles/onset.dir/build.make src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.provides.build
.PHONY : src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.provides

src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.provides.build: src/onsets/CMakeFiles/onset.dir/onsetsds.c.o

# Object files for target onset
onset_OBJECTS = \
"CMakeFiles/onset.dir/onsetsds.c.o"

# External object files for target onset
onset_EXTERNAL_OBJECTS =

lib/libonset.a: src/onsets/CMakeFiles/onset.dir/onsetsds.c.o
lib/libonset.a: src/onsets/CMakeFiles/onset.dir/build.make
lib/libonset.a: src/onsets/CMakeFiles/onset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library ../../lib/libonset.a"
	cd /home/szy/文档/CMake_Project/src/onsets && $(CMAKE_COMMAND) -P CMakeFiles/onset.dir/cmake_clean_target.cmake
	cd /home/szy/文档/CMake_Project/src/onsets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/onsets/CMakeFiles/onset.dir/build: lib/libonset.a
.PHONY : src/onsets/CMakeFiles/onset.dir/build

src/onsets/CMakeFiles/onset.dir/requires: src/onsets/CMakeFiles/onset.dir/onsetsds.c.o.requires
.PHONY : src/onsets/CMakeFiles/onset.dir/requires

src/onsets/CMakeFiles/onset.dir/clean:
	cd /home/szy/文档/CMake_Project/src/onsets && $(CMAKE_COMMAND) -P CMakeFiles/onset.dir/cmake_clean.cmake
.PHONY : src/onsets/CMakeFiles/onset.dir/clean

src/onsets/CMakeFiles/onset.dir/depend:
	cd /home/szy/文档/CMake_Project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szy/文档/CMake_Project /home/szy/文档/CMake_Project/src/onsets /home/szy/文档/CMake_Project /home/szy/文档/CMake_Project/src/onsets /home/szy/文档/CMake_Project/src/onsets/CMakeFiles/onset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/onsets/CMakeFiles/onset.dir/depend

