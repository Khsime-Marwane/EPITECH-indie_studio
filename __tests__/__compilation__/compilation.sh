#! /bin/sh

# Run the project with Clang++ and with debug mode
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "\n\033[93m [Run Clang++ with debug mode] \033[0m\n"

cmake CMakeLists.txt && make
rm -rf CMakeFiles cmake_install.cmake CPackConfig.cmake CPackSourceConfig.cmake CMakeCache.txt Makefile bin

# Run the project with G++ and with debug mode
echo "\n\033[93m [Run G++ with debug mode] \033[0m\n"
export CC=/usr/bin/gcc
export CXX=/usr/bin/g++

cmake CMakeLists.txt && make
rm -rf CMakeFiles cmake_install.cmake CPackConfig.cmake CPackSourceConfig.cmake CMakeCache.txt Makefile bin
