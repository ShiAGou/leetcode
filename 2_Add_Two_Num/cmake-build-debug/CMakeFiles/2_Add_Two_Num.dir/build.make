# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /Users/redrock/github/leetcode/2_Add_Two_Num

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2_Add_Two_Num.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_Add_Two_Num.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_Add_Two_Num.dir/flags.make

CMakeFiles/2_Add_Two_Num.dir/main.cpp.o: CMakeFiles/2_Add_Two_Num.dir/flags.make
CMakeFiles/2_Add_Two_Num.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2_Add_Two_Num.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_Add_Two_Num.dir/main.cpp.o -c /Users/redrock/github/leetcode/2_Add_Two_Num/main.cpp

CMakeFiles/2_Add_Two_Num.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_Add_Two_Num.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/redrock/github/leetcode/2_Add_Two_Num/main.cpp > CMakeFiles/2_Add_Two_Num.dir/main.cpp.i

CMakeFiles/2_Add_Two_Num.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_Add_Two_Num.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/redrock/github/leetcode/2_Add_Two_Num/main.cpp -o CMakeFiles/2_Add_Two_Num.dir/main.cpp.s

CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.requires

CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.provides: CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_Add_Two_Num.dir/build.make CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.provides

CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.provides.build: CMakeFiles/2_Add_Two_Num.dir/main.cpp.o


CMakeFiles/2_Add_Two_Num.dir/library.cpp.o: CMakeFiles/2_Add_Two_Num.dir/flags.make
CMakeFiles/2_Add_Two_Num.dir/library.cpp.o: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2_Add_Two_Num.dir/library.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_Add_Two_Num.dir/library.cpp.o -c /Users/redrock/github/leetcode/2_Add_Two_Num/library.cpp

CMakeFiles/2_Add_Two_Num.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_Add_Two_Num.dir/library.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/redrock/github/leetcode/2_Add_Two_Num/library.cpp > CMakeFiles/2_Add_Two_Num.dir/library.cpp.i

CMakeFiles/2_Add_Two_Num.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_Add_Two_Num.dir/library.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/redrock/github/leetcode/2_Add_Two_Num/library.cpp -o CMakeFiles/2_Add_Two_Num.dir/library.cpp.s

CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.requires:

.PHONY : CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.requires

CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.provides: CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.requires
	$(MAKE) -f CMakeFiles/2_Add_Two_Num.dir/build.make CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.provides.build
.PHONY : CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.provides

CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.provides.build: CMakeFiles/2_Add_Two_Num.dir/library.cpp.o


# Object files for target 2_Add_Two_Num
2_Add_Two_Num_OBJECTS = \
"CMakeFiles/2_Add_Two_Num.dir/main.cpp.o" \
"CMakeFiles/2_Add_Two_Num.dir/library.cpp.o"

# External object files for target 2_Add_Two_Num
2_Add_Two_Num_EXTERNAL_OBJECTS =

2_Add_Two_Num: CMakeFiles/2_Add_Two_Num.dir/main.cpp.o
2_Add_Two_Num: CMakeFiles/2_Add_Two_Num.dir/library.cpp.o
2_Add_Two_Num: CMakeFiles/2_Add_Two_Num.dir/build.make
2_Add_Two_Num: CMakeFiles/2_Add_Two_Num.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 2_Add_Two_Num"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2_Add_Two_Num.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_Add_Two_Num.dir/build: 2_Add_Two_Num

.PHONY : CMakeFiles/2_Add_Two_Num.dir/build

CMakeFiles/2_Add_Two_Num.dir/requires: CMakeFiles/2_Add_Two_Num.dir/main.cpp.o.requires
CMakeFiles/2_Add_Two_Num.dir/requires: CMakeFiles/2_Add_Two_Num.dir/library.cpp.o.requires

.PHONY : CMakeFiles/2_Add_Two_Num.dir/requires

CMakeFiles/2_Add_Two_Num.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_Add_Two_Num.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_Add_Two_Num.dir/clean

CMakeFiles/2_Add_Two_Num.dir/depend:
	cd /Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/redrock/github/leetcode/2_Add_Two_Num /Users/redrock/github/leetcode/2_Add_Two_Num /Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug /Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug /Users/redrock/github/leetcode/2_Add_Two_Num/cmake-build-debug/CMakeFiles/2_Add_Two_Num.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2_Add_Two_Num.dir/depend
