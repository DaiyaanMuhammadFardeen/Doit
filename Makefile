CFLAGS = -g -Wall
OUTPUT = -o doit
RunArguments :=

Compile:
	g++ ./src/main.cpp $(OUTPUT) $(CFLAGS)

Run:
	./doit $(ProgArgs)
