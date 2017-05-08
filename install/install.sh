#! /bin/sh

############
# IRRLICHT #
############

while true; do
    read -p "Do you wish to install irrlicht (y/n) ? :  " yn
    case $yn in

        [Nn]* ) break;;

        [Yy]* )

        # Clean
        echo "hey"
        rm -rf irrlicht*
        # Download Irrlicht
        wget http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.4.zip -q --show-progress &&
        echo "salu"
        # Unzip the target
        unzip irrlicht-1.8.4.zip &&
        # Compile and create the library
        make -C irrlicht-1.8.4/source/Irrlicht/ &&
        # Copy Library .a and headers in the project
        rm -rf ../lib/Linux ../lib/MacOSX ../lib/Win32-gcc ../lib/Win32-visualstudio ../lib/Win64-visualStudio &&
        mkdir -p ../lib &&
        cp -r irrlicht-1.8.4/lib/* ../lib/ &&
        rm -rf ../includes/Extern/irr &&
        mkdir -p ../includes/Extern/irr &&
        cp -r irrlicht-1.8.4/include/* ../includes/Extern/irr &&
        # Erase the tarball and the irrlicht folder
        rm -rf irrlicht-1.8.4.zip irrlicht-1.8.4 &&

        echo "Install Complete"
	break;;

    esac
done

############
#  OPENGL  #
############

while true; do
    read -p "Do you wish to project dependencies (y/n) ?  " yn
    case $yn in

        [Nn]* ) break;;

        [Yy]* )

        sudo apt-get install    libegl1-mesa \
                                libgl1-mesa-dev \
                                libglu1-mesa \
                                libglu1-mesa-dev \
                                libsfml-dev \
                                libgtest-dev \
                                binutils-dev \
                                libtool \
                                lua5.2 \
                                liblua5.2-dev \
                                liblua5.2-0 \
                                graphviz
    esac
done
