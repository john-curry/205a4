CC=g++
FLAGS=-Wall -pedantic -g -std=c++11
LINKS=
INCLUDE=../include
OUTDIR=../bin
SRCDIR=src
BINARIES=gauss gauss_cumulative
OUT=$(addprefix $(OUTDIR)/, $(BINARIES))
ARGS=$(wildcard *.png)
ARGOUT=$(ARGS:.png=out.png)
FILES=$(addprefix $(SRCDIR)/,   $(addsuffix .cpp, $(BINARIES)))
OBJS =$(addprefix build/, $(addsuffix .o,   $(BINARIES)))
HEADERS=$(wildcard $(INLCUDE)/*.h)

all: $(OUT)

$(OUTDIR)/%: $(SRCDIR)/%.cpp
	$(CC) -I $(INCLUDE) $(FLAGS) $^ -o $@ $(LINKS)


#build/%.o: %.cpp $(HEADERS)
#	$(CC) -I $(INCLUDE) $(FLAGS) -c $(filter %.cpp,$^) -o $@

%.h:

clean:
	rm $(OUT) $(OBJS)

run: $(OUT)
	./$(OUT) $(firstword $(ARGS)) $(ARGOUT)

debug:
	gdb --args $(OUT) $(firstword $(ARGS)) $(ARGOUT)
