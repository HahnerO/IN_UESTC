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
CMAKE_SOURCE_DIR = /Users/hahn/CLionProjects/Min_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hahn/CLionProjects/Min_tree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Min_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Min_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Min_tree.dir/flags.make

CMakeFiles/Min_tree.dir/main.c.o: CMakeFiles/Min_tree.dir/flags.make
CMakeFiles/Min_tree.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hahn/CLionProjects/Min_tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Min_tree.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Min_tree.dir/main.c.o   -c /Users/hahn/CLionProjects/Min_tree/main.c

CMakeFiles/Min_tree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Min_tree.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hahn/CLionProjects/Min_tree/main.c > CMakeFiles/Min_tree.dir/main.c.i

CMakeFiles/Min_tree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Min_tree.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hahn/CLionProjects/Min_tree/main.c -o CMakeFiles/Min_tree.dir/main.c.s

CMakeFiles/Min_tree.dir/main.c.o.requires:

.PHONY : CMakeFiles/Min_tree.dir/main.c.o.requires

CMakeFiles/Min_tree.dir/main.c.o.provides: CMakeFiles/Min_tree.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Min_tree.dir/build.make CMakeFiles/Min_tree.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Min_tree.dir/main.c.o.provides

CMakeFiles/Min_tree.dir/main.c.o.provides.build: CMakeFiles/Min_tree.dir/main.c.o


# Object files for target Min_tree
Min_tree_OBJECTS = \
"CMakeFiles/Min_tree.dir/main.c.o"

# External object files for target Min_tree
Min_tree_EXTERNAL_OBJECTS =

Min_tree: CMakeFiles/Min_tree.dir/main.c.o
Min_tree: CMakeFiles/Min_tree.dir/build.make
Min_tree: CMakeFiles/Min_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hahn/CLionProjects/Min_tree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Min_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Min_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Min_tree.dir/build: Min_tree

.PHONY : CMakeFiles/Min_tree.dir/build

CMakeFiles/Min_tree.dir/requires: CMakeFiles/Min_tree.dir/main.c.o.requires

.PHONY : CMakeFiles/Min_tree.dir/requires

CMakeFiles/Min_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Min_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Min_tree.dir/clean

CMakeFiles/Min_tree.dir/depend:
	cd /Users/hahn/CLionProjects/Min_tree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hahn/CLionProjects/Min_tree /Users/hahn/CLionProjects/Min_tree /Users/hahn/CLionProjects/Min_tree/cmake-build-debug /Users/hahn/CLionProjects/Min_tree/cmake-build-debug /Users/hahn/CLionProjects/Min_tree/cmake-build-debug/CMakeFiles/Min_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Min_tree.dir/depend

