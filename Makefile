##
## Makefile for Makefile in /home/marwane/Projects/C++/sockets
## 
## Made by marwane
## Login   <marwane.khsime@epitech.eu>
## 
## Started on  Wed May  3 00:22:29 2017 marwane
## Last update Sun Jun  4 05:02:39 2017 marwane
##

#
##
##	-[UTILS]-
##
#

# Shorcut Rules
RM 				=	rm -rf
# Run this project with debug flags ? (yes / no)
DEBUG 			=	no
# If display_opt is set to "percentage", shows the progress of the compilation in percentage, else use the index.
DISPLAY_OPT		=	percentage
# Utils for the compilation's progress
COUNT 			= 	1
NBSOURCES 		= 	$(shell find src/ -type f -name '*.cpp' | wc -l)
PERCENT			= 	0
DISPLAY_ONE     = 	"[\033[95m$(PERCENT)%\033[0m][\033[92m$<\033[0m]"
DISPLAY_TWO     = 	"[\033[95m$(COUNT)\033[0m/\033[93m$(NBSOURCES)\033[0m][\033[92m$<\033[0m]"
DISPLAY_THREE	=	"[\033[92mOK\033[0m]  $<"

#
##
##	-[CONFIGURATION]
##
#

# Name of the projet
NAME			=	indie
# OS Used
OS_detected		=	$(shell uname -s)
# Compiler
CXX				=	g++
# Compiler flags
CXXFLAGS		=	-std=c++14
# Performance
CXXFLAGS		+=	-O2
# Warnings
CXXFLAGS		+=	-W -Wall -Wextra -Weffc++ -Wshadow -Wnon-virtual-dtor -Wunreachable-code		\
					-Wundef	-Wold-style-cast -Woverloaded-virtual -Wfloat-equal 							\
					-Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion 					\
					-Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default 						\
					-Wswitch-enum -Winline -Wno-narrowing										\

# Include folders
INCDIRS			:=	$(addprefix -I,$(shell find includes -type d -print))
CXXFLAGS		+=	$(INCDIRS)
# Ignore Irrlicht warnings
CXXFLAGS		+=	-isystem includes/Extern/
# Libraries
LDFLAGS			=	-lpthread -lGL -lGLU
LDFLAGS			+=	-lXrandr -lXi -lXrender -ldrm -lXdamage -lXxf86vm -lXext -lX11 -lsndfile -lopenal

# Add the library according to the OS
ifeq ($(OS_detected), Linux)
	LDFLAGS		+=	-L./lib/Linux -lIrrlicht
else ifeq ($(OS_detected), Windows_NT)
	LDFLAGS		+=	-L./lib/Win64-visualStudio
endif

# If the compiler is clang++, add the flag -Weverything
ifeq ($(CXX), clang++)
	CXXFLAGS	+=	-Weverything
	# Superfluous warnings
	CXXFLAGS	+=	-Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-documentation -Wno-extra-semi
	CXXFLAGS	+=	-Wno-weak-vtables -Qunused-arguments -Wno-reserved-id-macro
endif

# If debug is set to yes, add -g3 flag
ifeq ($(DEBUG),yes)
	CXXFLAGS += -g3
else
	CXXFLAGS += -s
endif

# Set the compilation message
ifeq ($(DISPLAY_OPT), percentage)
        COMPILATION_MSG=$(DISPLAY_ONE)
else ifeq ($(DISPLAY_OPT), count)
		COMPILATION_MSG=$(DISPLAY_TWO)
else
		COMPILATION_MSG=$(DISPLAY_THREE)
endif

# Resource folder (root), object folder, and directory where the binary will be created.
SRCDIR   		= src
OBJDIR   		= obj
BINDIR   		= ./bin

# SOURCES
SOURCES			= 	$(wildcard $(SRCDIR)/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Core/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Graphical/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Graphical/Gfx/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Graphical/Model/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Common/*.cpp)
SOURCES			+=	$(wildcard $(SRCDIR)/Sound/*.cpp)
# OBJECTS
OBJECTS			:= 	$(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#
##
##	-[RULES]-
##
#

.PHONY: 	clean fclean re install compilation_tests build

$(BINDIR)/$(NAME):	$(OBJECTS)
					@mkdir -p $(BINDIR)
					@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)
					@echo "[\033[94mProject $(NAME) build successfully!\033[0m]"

$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
					@mkdir -p $(dir $@)
					@$(CXX) $(CXXFLAGS) -c $< -o $@
					@$(eval PERCENT=$(shell echo $$((($(COUNT)*100/$(NBSOURCES))))))
					@echo $(COMPILATION_MSG)
					@$(eval COUNT=$(shell echo $$((($(COUNT)+1)))))

# Build From CMAKE
build:
					cd build && ./Linux_build.sh && cd ../

# Install dependencies
install:
					@cd install && ./install.sh && cd ../

# Try the compilation with g++ and clang++ in order to detect warnings
compilation_tests:
					@cd ./__tests__/__compilation__/ && ./compilation.sh && cd ../../

clean:
					@$(RM) $(OBJDIR)
					@echo "[\033[97mCleanup complete!\033[0m]"

fclean: 			clean
					@$(RM) $(BINDIR)
					@echo "[\033[97mExecutable removed!\033[0m]"

re:					fclean $(BINDIR)/$(NAME)
