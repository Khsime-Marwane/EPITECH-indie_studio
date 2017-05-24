##
## Author: Marwane Khsime 
## Date: 2017-05-09 19:44:21 
##
## Last Modified by:   Marwane Khsime 
## Last Modified time: 2017-05-09 19:44:21
##

cmake_minimum_required( VERSION 3.0 )
project( indie_studio )

SET(ROOT_DIR ..)

INCLUDE_DIRECTORIES( ${ROOT_DIR}/includes )
INCLUDE_DIRECTORIES( SYSTEM ${ROOT_DIR}/includes/Extern )

FILE(
      GLOB_RECURSE

      source_files

      ./${ROOT_DIR}/src/*

      ./${ROOT_DIR}/includes/*
)

if(WIN32)

      ADD_EXECUTABLE(
                  indie_studio

                  ${source_files}

                  ${data}
      )

      # link libraries with the project
      TARGET_LINK_LIBRARIES(

                  indie_studio
                  
                  ${PROJECT_SOURCE_DIR}/${ROOT_DIR}/lib/Win64-visualStudio/Irrlicht.lib

      )

endif()

# If we are on Linux
if(UNIX AND NOT APPLE)

      ###############################################################################
      ## Project Config  ############################################################
      ###############################################################################

      ### Compilation flags and links
      SET(GCC_COVERAGE_COMPILE_FLAGS      "-std=c++14 -O2 -W -Wall -Wextra -Weffc++ -Wshadow -Wnon-virtual-dtor               \
                                          -Wunreachable-code -Wundef -Wold-style-cast -Woverloaded-virtual -Wfloat-equal      \
                                          -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion               \
                                          -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default                   \
                                          -Wswitch-enum -Winline" )
      SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
      SET( GCC_COVERAGE_LINK_FLAGS  "-lpthread -L./../lib/Linux -lIrrlicht -lXrandr -lXi -lXrender -ldrm -lXdamage -lXxf86vm -lXext -lX11 -lpthread -lGL -lGLU" )
      SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

      ### Folder where the binary will be generated
      SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

      ###############################################################################
      ##  Exec  #####################################################################
      ###############################################################################

      # add the data to the target, so it becomes visible in some IDE
      ADD_EXECUTABLE(
                  indie_studio

                  ${source_files}

                  ${data}
      )

      # link libraries with the project
      TARGET_LINK_LIBRARIES(

                  indie_studio
                  
                  ${PROJECT_SOURCE_DIR}/${ROOT_DIR}/lib/Linux/libIrrlicht.a

                  -lIrrlicht
                  -lXrandr
                  -lXi
                  -lXrender
                  -ldrm
                  -lXdamage
                  -lXxf86vm
                  -lXext
                  -lX11
                  -lpthread
                  -lGL
                  -lGLU
      )


endif()


ADD_CUSTOM_COMMAND(TARGET indie_studio POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ./${ROOT_DIR}/resources $<TARGET_FILE_DIR:indie_studio>)

###############################################################################
##   END    ###################################################################
###############################################################################

# now comes everything we need, to create a package
# there are a lot more variables you can set, and some
# you need to set for some package types, but we want to
# be minimal here
SET( CPACK_PACKAGE_NAME "IndieStudio" )
SET( CPACK_PACKAGE_VERSION "0.0.1")

# we don't want to split our program up into several things
SET( CPACK_MONOLITHIC_INSTALL 1 )

# This must be last
INCLUDE( CPack )
