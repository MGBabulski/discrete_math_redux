# variables
COMPILER = g++
FLAGS = -stc=c++23 -Ofast -Wall -Wextra -pedantic

# object file creation rule
%.o : %.cpp
	$(COMPILER) $< -o $@ -c $(FLAGS)