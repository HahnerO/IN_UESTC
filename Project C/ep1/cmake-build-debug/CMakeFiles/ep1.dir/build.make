# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hahn/CLionProjects/ep1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hahn/CLionProjects/ep1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ep1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ep1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ep1.dir/flags.make

CMakeFiles/ep1.dir/main.c.o: CMakeFiles/ep1.dir/flags.make
CMakeFiles/ep1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hahn/CLionProjects/ep1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ep1.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ep1.dir/main.c.o   -c /Users/hahn/CLionProjects/ep1/main.c

CMakeFiles/ep1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ep1.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hahn/CLionProjects/ep1/main.c > CMakeFiles/ep1.dir/main.c.i

CMakeFiles/ep1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ep1.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hahn/CLionProjects/ep1/main.c -o CMakeFiles/ep1.dir/main.c.s

CMakeFiles/ep1.dir/main.c.o.requires:

.PHONY : CMakeFiles/ep1.dir/main.c.o.requires

CMakeFiles/ep1.dir/main.c.o.provides: CMakeFiles/ep1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/ep1.dir/build.make CMakeFiles/ep1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/ep1.dir/main.c.o.provides

CMakeFiles/ep1.dir/main.c.o.provides.build: CMakeFiles/ep1.dir/main.c.o


# Object files for target ep1
ep1_OBJECTS = \
"CMakeFiles/ep1.dir/main.c.o"

# External object files for target ep1
ep1_EXTERNAL_OBJECTS =

ep1: CMakeFiles/ep1.dir/main.c.o
ep1: CMakeFiles/ep1.dir/build.make
ep1: CMakeFiles/ep1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hahn/CLionProjects/ep1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ep1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ep1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ep1.dir/build: ep1

.PHONY : CMakeFiles/ep1.dir/build

CMakeFiles/ep1.dir/requires: CMakeFiles/ep1.dir/main.c.o.requires

.PHONY : CMakeFiles/ep1.dir/requires

CMakeFiles/ep1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ep1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ep1.dir/clean

CMakeFiles/ep1.dir/depend:
	cd /Users/hahn/CLionProjects/ep1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hahn/CLionProjects/ep1 /Users/hahn/CLionProjects/ep1 /Users/hahn/CLionProjects/ep1/cmake-build-debug /Users/hahn/CLionProjects/ep1/cmake-build-debug /Users/hahn/CLionProjects/ep1/cmake-build-debug/CMakeFiles/ep1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ep1.dir/depend

