CC=g++
FLAGS=-Wall -pedantic -g -std=c++11
LINKS=
OUT=filter
ARGS=$(wildcard *.png)
ARGOUT=$(ARGS:.png=out.png)
FILES=$(wildcard *.cpp)
OBJS=$(FILES:.cpp=.o)
HEADERS=$(wildcard *.h)

$(OUT): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LINKS)


$(OBJS): $(FILES) $(HEADERS)
	$(CC) $(FLAGS) -c $(filter %.cpp,$^)

%.h:

clean:
	rm $(OUT) *.o

run: $(OUT)
	./$(OUT) $(firstword $(ARGS)) $(ARGOUT)

debug:
	gdb --args $(OUT) $(firstword $(ARGS)) $(ARGOUT)
