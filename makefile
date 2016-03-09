CC=g++
FLAGS=-Wall -pedantic -g -std=c++11
LINKS=
INCLUDE=include
OUT=bin/filter
ARGS=$(wildcard *.png)
ARGOUT=$(ARGS:.png=out.png)
FILES=$(wildcard *.cpp)
OBJS=$(addprefix build/, $(FILES:.cpp=.o))
HEADERS=$(wildcard *.h)

all: $(OUT) tools build
	cd tools && $(MAKE)

build:
	mkdir build

$(OUT): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LINKS)


build/%.o: %.cpp $(HEADERS)
	$(CC) -I $(INCLUDE) $(FLAGS) -c $(filter %.cpp,$^) -o $@

%.h:

clean:
	rm $(OUT) $(OBJS)

run: $(OUT)
	./$(OUT) $(firstword $(ARGS)) $(ARGOUT)

debug:
	gdb --args $(OUT) $(firstword $(ARGS)) $(ARGOUT)
