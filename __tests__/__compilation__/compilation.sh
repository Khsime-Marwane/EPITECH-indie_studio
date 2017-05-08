#! /bin/sh

# Run the project with G++ and no debug
echo "\n\033[93m [Run G++ no debug] \033[0m\n"
make re CXX=g++ DEBUG=no -s -C ./../../

# Run the project with Clang++ and no debug
echo "\n\033[93m [Run Clang++ no debug] \033[0m\n"
make re CXX=clang++ DEBUG=no -s -C ./../../

# Run the project with G++ and with debug mode
echo "\n\033[93m [Run G++ with debug mode] \033[0m\n"
make re CXX=g++ DEBUG=yes -s -C ./../../

# Run the project with Clang++ and with debug mode
echo "\n\033[93m [Run Clang++ with debug mode] \033[0m\n"
make re CXX=clang++ DEBUG=yes -s -C ./../../
