# general variables
COMPILER = g++
FLAGS = -std=c++23 -Ofast -Wall -Wextra -pedantic

# object (.o) files needed for compilation
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard ./src/polynomial/*.cpp)) \
			$(patsubst %.cpp,%.o,$(wildcard ./src/modular/*.cpp)) \
			$(patsubst %.cpp,%.o,$(wildcard ./src/graph/*.cpp)) \
			$(patsubst %.cpp,%.o,$(wildcard ./src/combinatorics/*.cpp))

# rule for creating the static library
discrete_math_redux.a: $(OBJECTS)
	ar rcs discrete_math_redux.a $(OBJECTS)

# object file creation rule
%.o: %.cpp
	$(COMPILER) $< -o $@ -c $(FLAGS)

# cleans the object files, but NOT the library
.PHONEY:
clean:
	rm $(OBJECTS)

# cleans the object files AND the .a file (if in default location)
.PHONEY:
clean_all:
	rm $(OBJECTS)
	rm discrete_math_redux.a