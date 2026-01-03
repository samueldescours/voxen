SRC=$(wildcard src/*.cpp)
OBJ=obj/ $(SRC:src/%.cpp=obj/%.o)

LIBS=-lglfw -lGLEW -lGL
FLAGS=-Iinclude -Wall -Wextra -Werror

all: libvoxen.a

re: fclean all

libvoxen.a: $(OBJ)
	ar -rc libvoxen.a $(wildcard obj/*.o)

obj/%.o: src/%.cpp
	$(CXX) $^ -o $@ -c $(FLAGS) $(LIBS)

obj/:
	mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f libvoxen.a

test: libvoxen.a test.cpp
	$(CXX) test.cpp -L. -lvoxen -o test $(FLAGS) -fsanitize=address $(LIBS)
