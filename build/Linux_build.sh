#!/bin/sh

cmake CMakeLists.txt

echo "\n"

make && rm -rf ../bin && mv bin ../

while true; do
    echo "\n"
    read -p "Do you wish to clean up this folder (y/n) ? :  " yn
    case $yn in

	[Nn]* ) break;;

	[Yy]* )

	    # Clean
	    echo "Cleaning build folder"
	    rm -rf CMakeFiles cmake_install.cmake CPackConfig.cmake CPackSourceConfig.cmake CMakeCache.txt Makefile	    

	    break;;
    esac
done

echo "\n[\033[32mThe executable has been moved to the bin folder at the root of the project\033[0m]\n"
