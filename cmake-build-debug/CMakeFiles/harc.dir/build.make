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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/abbit/dev/university/harc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/abbit/dev/university/harc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/harc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/harc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/harc.dir/flags.make

CMakeFiles/harc.dir/harc.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/harc.c.o: ../harc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/harc.dir/harc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/harc.c.o   -c /Users/abbit/dev/university/harc/harc.c

CMakeFiles/harc.dir/harc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/harc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/harc.c > CMakeFiles/harc.dir/harc.c.i

CMakeFiles/harc.dir/harc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/harc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/harc.c -o CMakeFiles/harc.dir/harc.c.s

CMakeFiles/harc.dir/cli.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/cli.c.o: ../cli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/harc.dir/cli.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/cli.c.o   -c /Users/abbit/dev/university/harc/cli.c

CMakeFiles/harc.dir/cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/cli.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/cli.c > CMakeFiles/harc.dir/cli.c.i

CMakeFiles/harc.dir/cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/cli.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/cli.c -o CMakeFiles/harc.dir/cli.c.s

CMakeFiles/harc.dir/archiver.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/archiver.c.o: ../archiver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/harc.dir/archiver.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/archiver.c.o   -c /Users/abbit/dev/university/harc/archiver.c

CMakeFiles/harc.dir/archiver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/archiver.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/archiver.c > CMakeFiles/harc.dir/archiver.c.i

CMakeFiles/harc.dir/archiver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/archiver.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/archiver.c -o CMakeFiles/harc.dir/archiver.c.s

CMakeFiles/harc.dir/extractor.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/extractor.c.o: ../extractor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/harc.dir/extractor.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/extractor.c.o   -c /Users/abbit/dev/university/harc/extractor.c

CMakeFiles/harc.dir/extractor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/extractor.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/extractor.c > CMakeFiles/harc.dir/extractor.c.i

CMakeFiles/harc.dir/extractor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/extractor.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/extractor.c -o CMakeFiles/harc.dir/extractor.c.s

CMakeFiles/harc.dir/actions.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/actions.c.o: ../actions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/harc.dir/actions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/actions.c.o   -c /Users/abbit/dev/university/harc/actions.c

CMakeFiles/harc.dir/actions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/actions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/actions.c > CMakeFiles/harc.dir/actions.c.i

CMakeFiles/harc.dir/actions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/actions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/actions.c -o CMakeFiles/harc.dir/actions.c.s

CMakeFiles/harc.dir/files.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/files.c.o: ../files.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/harc.dir/files.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/files.c.o   -c /Users/abbit/dev/university/harc/files.c

CMakeFiles/harc.dir/files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/files.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/files.c > CMakeFiles/harc.dir/files.c.i

CMakeFiles/harc.dir/files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/files.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/files.c -o CMakeFiles/harc.dir/files.c.s

CMakeFiles/harc.dir/huffman.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/huffman.c.o: ../huffman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/harc.dir/huffman.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/huffman.c.o   -c /Users/abbit/dev/university/harc/huffman.c

CMakeFiles/harc.dir/huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/huffman.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/huffman.c > CMakeFiles/harc.dir/huffman.c.i

CMakeFiles/harc.dir/huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/huffman.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/huffman.c -o CMakeFiles/harc.dir/huffman.c.s

CMakeFiles/harc.dir/heap.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/heap.c.o: ../heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/harc.dir/heap.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/heap.c.o   -c /Users/abbit/dev/university/harc/heap.c

CMakeFiles/harc.dir/heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/heap.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/heap.c > CMakeFiles/harc.dir/heap.c.i

CMakeFiles/harc.dir/heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/heap.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/heap.c -o CMakeFiles/harc.dir/heap.c.s

CMakeFiles/harc.dir/bitset.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/bitset.c.o: ../bitset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/harc.dir/bitset.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/bitset.c.o   -c /Users/abbit/dev/university/harc/bitset.c

CMakeFiles/harc.dir/bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/bitset.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/bitset.c > CMakeFiles/harc.dir/bitset.c.i

CMakeFiles/harc.dir/bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/bitset.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/bitset.c -o CMakeFiles/harc.dir/bitset.c.s

CMakeFiles/harc.dir/crc32.c.o: CMakeFiles/harc.dir/flags.make
CMakeFiles/harc.dir/crc32.c.o: ../crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/harc.dir/crc32.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/harc.dir/crc32.c.o   -c /Users/abbit/dev/university/harc/crc32.c

CMakeFiles/harc.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/harc.dir/crc32.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abbit/dev/university/harc/crc32.c > CMakeFiles/harc.dir/crc32.c.i

CMakeFiles/harc.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/harc.dir/crc32.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abbit/dev/university/harc/crc32.c -o CMakeFiles/harc.dir/crc32.c.s

# Object files for target harc
harc_OBJECTS = \
"CMakeFiles/harc.dir/harc.c.o" \
"CMakeFiles/harc.dir/cli.c.o" \
"CMakeFiles/harc.dir/archiver.c.o" \
"CMakeFiles/harc.dir/extractor.c.o" \
"CMakeFiles/harc.dir/actions.c.o" \
"CMakeFiles/harc.dir/files.c.o" \
"CMakeFiles/harc.dir/huffman.c.o" \
"CMakeFiles/harc.dir/heap.c.o" \
"CMakeFiles/harc.dir/bitset.c.o" \
"CMakeFiles/harc.dir/crc32.c.o"

# External object files for target harc
harc_EXTERNAL_OBJECTS =

harc: CMakeFiles/harc.dir/harc.c.o
harc: CMakeFiles/harc.dir/cli.c.o
harc: CMakeFiles/harc.dir/archiver.c.o
harc: CMakeFiles/harc.dir/extractor.c.o
harc: CMakeFiles/harc.dir/actions.c.o
harc: CMakeFiles/harc.dir/files.c.o
harc: CMakeFiles/harc.dir/huffman.c.o
harc: CMakeFiles/harc.dir/heap.c.o
harc: CMakeFiles/harc.dir/bitset.c.o
harc: CMakeFiles/harc.dir/crc32.c.o
harc: CMakeFiles/harc.dir/build.make
harc: CMakeFiles/harc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable harc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/harc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/harc.dir/build: harc

.PHONY : CMakeFiles/harc.dir/build

CMakeFiles/harc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/harc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/harc.dir/clean

CMakeFiles/harc.dir/depend:
	cd /Users/abbit/dev/university/harc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abbit/dev/university/harc /Users/abbit/dev/university/harc /Users/abbit/dev/university/harc/cmake-build-debug /Users/abbit/dev/university/harc/cmake-build-debug /Users/abbit/dev/university/harc/cmake-build-debug/CMakeFiles/harc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/harc.dir/depend

