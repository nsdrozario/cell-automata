CXX := g++
PKGCONF := pkg-config
CXXFLAGS := -Wall -Werror -std=c++17 -Iinclude/ `$(PKGCONF) sol2 --cflags` `$(PKGCONF) lua5.3 --cflags`
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system `$(PKGCONF) lua5.3 --libs`
OBJ_DIR := obj/
SRCS := $(shell find . -name "*.cpp" -exec basename {} \;)
OBJS := $(addprefix $(OBJ_DIR),$(SRCS:%.cpp=%.o))

$(OBJ_DIR)%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

.PHONY: build
build:	$(OBJS)
	$(CXX) $(OBJS) -o bin/cell_automata_simulator $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf bin obj dist
	mkdir bin
	mkdir obj
	mkdir dist

.PHONY: package
package: build
	rm -rf dist/
	cp bin dist -r -v
	cp scripts dist -r
	cp font dist -r

.PHONY: test
test: package
	./dist/cell_automata_simulator