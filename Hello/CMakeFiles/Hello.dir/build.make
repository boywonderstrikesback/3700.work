# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mikeross/3700.work/Hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mikeross/3700.work/Hello

# Include any dependencies generated for this target.
include CMakeFiles/Hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hello.dir/flags.make

CMakeFiles/Hello.dir/src/hello.cc.o: CMakeFiles/Hello.dir/flags.make
CMakeFiles/Hello.dir/src/hello.cc.o: src/hello.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mikeross/3700.work/Hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hello.dir/src/hello.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hello.dir/src/hello.cc.o -c /Users/mikeross/3700.work/Hello/src/hello.cc

CMakeFiles/Hello.dir/src/hello.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hello.dir/src/hello.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mikeross/3700.work/Hello/src/hello.cc > CMakeFiles/Hello.dir/src/hello.cc.i

CMakeFiles/Hello.dir/src/hello.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hello.dir/src/hello.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mikeross/3700.work/Hello/src/hello.cc -o CMakeFiles/Hello.dir/src/hello.cc.s

CMakeFiles/Hello.dir/src/hello.cc.o.requires:

.PHONY : CMakeFiles/Hello.dir/src/hello.cc.o.requires

CMakeFiles/Hello.dir/src/hello.cc.o.provides: CMakeFiles/Hello.dir/src/hello.cc.o.requires
	$(MAKE) -f CMakeFiles/Hello.dir/build.make CMakeFiles/Hello.dir/src/hello.cc.o.provides.build
.PHONY : CMakeFiles/Hello.dir/src/hello.cc.o.provides

CMakeFiles/Hello.dir/src/hello.cc.o.provides.build: CMakeFiles/Hello.dir/src/hello.cc.o


# Object files for target Hello
Hello_OBJECTS = \
"CMakeFiles/Hello.dir/src/hello.cc.o"

# External object files for target Hello
Hello_EXTERNAL_OBJECTS =

Hello: CMakeFiles/Hello.dir/src/hello.cc.o
Hello: CMakeFiles/Hello.dir/build.make
Hello: CMakeFiles/Hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mikeross/3700.work/Hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hello.dir/build: Hello

.PHONY : CMakeFiles/Hello.dir/build

CMakeFiles/Hello.dir/requires: CMakeFiles/Hello.dir/src/hello.cc.o.requires

.PHONY : CMakeFiles/Hello.dir/requires

CMakeFiles/Hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hello.dir/clean

CMakeFiles/Hello.dir/depend:
	cd /Users/mikeross/3700.work/Hello && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mikeross/3700.work/Hello /Users/mikeross/3700.work/Hello /Users/mikeross/3700.work/Hello /Users/mikeross/3700.work/Hello /Users/mikeross/3700.work/Hello/CMakeFiles/Hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hello.dir/depend

