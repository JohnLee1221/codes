# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzh/driving-planning-1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzh/driving-planning-1.0/build

# Include any dependencies generated for this target.
include localization/CMakeFiles/localization.dir/depend.make

# Include the progress variables for this target.
include localization/CMakeFiles/localization.dir/progress.make

# Include the compile flags for this target's objects.
include localization/CMakeFiles/localization.dir/flags.make

localization/CMakeFiles/localization.dir/localization_estimate.cc.o: localization/CMakeFiles/localization.dir/flags.make
localization/CMakeFiles/localization.dir/localization_estimate.cc.o: ../localization/localization_estimate.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzh/driving-planning-1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object localization/CMakeFiles/localization.dir/localization_estimate.cc.o"
	cd /home/lzh/driving-planning-1.0/build/localization && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/localization.dir/localization_estimate.cc.o -c /home/lzh/driving-planning-1.0/localization/localization_estimate.cc

localization/CMakeFiles/localization.dir/localization_estimate.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localization.dir/localization_estimate.cc.i"
	cd /home/lzh/driving-planning-1.0/build/localization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzh/driving-planning-1.0/localization/localization_estimate.cc > CMakeFiles/localization.dir/localization_estimate.cc.i

localization/CMakeFiles/localization.dir/localization_estimate.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localization.dir/localization_estimate.cc.s"
	cd /home/lzh/driving-planning-1.0/build/localization && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzh/driving-planning-1.0/localization/localization_estimate.cc -o CMakeFiles/localization.dir/localization_estimate.cc.s

# Object files for target localization
localization_OBJECTS = \
"CMakeFiles/localization.dir/localization_estimate.cc.o"

# External object files for target localization
localization_EXTERNAL_OBJECTS =

lib/liblocalization.a: localization/CMakeFiles/localization.dir/localization_estimate.cc.o
lib/liblocalization.a: localization/CMakeFiles/localization.dir/build.make
lib/liblocalization.a: localization/CMakeFiles/localization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzh/driving-planning-1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/liblocalization.a"
	cd /home/lzh/driving-planning-1.0/build/localization && $(CMAKE_COMMAND) -P CMakeFiles/localization.dir/cmake_clean_target.cmake
	cd /home/lzh/driving-planning-1.0/build/localization && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/localization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
localization/CMakeFiles/localization.dir/build: lib/liblocalization.a

.PHONY : localization/CMakeFiles/localization.dir/build

localization/CMakeFiles/localization.dir/clean:
	cd /home/lzh/driving-planning-1.0/build/localization && $(CMAKE_COMMAND) -P CMakeFiles/localization.dir/cmake_clean.cmake
.PHONY : localization/CMakeFiles/localization.dir/clean

localization/CMakeFiles/localization.dir/depend:
	cd /home/lzh/driving-planning-1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzh/driving-planning-1.0 /home/lzh/driving-planning-1.0/localization /home/lzh/driving-planning-1.0/build /home/lzh/driving-planning-1.0/build/localization /home/lzh/driving-planning-1.0/build/localization/CMakeFiles/localization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : localization/CMakeFiles/localization.dir/depend
