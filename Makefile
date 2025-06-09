# alizalazar9@gmail.com

# compiler and flags I'm using
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic
INC = -Iinclude -Itests
BIN_DIR = bin

# source files for the different parts
MAIN_SRC = main.cpp
DEMO_SRC = Demo.cpp
TEST_SRC = tests/test.cpp

# where the compiled files will go
MAIN_OUT = $(BIN_DIR)/Main
DEMO_OUT = $(BIN_DIR)/Demo
TEST_OUT = $(BIN_DIR)/Tests

# main targets I want to support
.PHONY: all main demo test run-main run-demo valgrind clean

# run everything together (main, demo, and tests)
all: main demo test

# compile the main.cpp file
main: $(MAIN_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) $(INC) -o $(MAIN_OUT)

# compile the demo version
demo: $(DEMO_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(DEMO_SRC) $(INC) -o $(DEMO_OUT)

# run the compiled main binary
run-main: main
	./$(MAIN_OUT)

# run the demo binary (for showing off)
run-demo: demo
	./$(DEMO_OUT)

# build and run the tests (I'm using doctest)
test: $(TEST_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -Wno-unused-variable $(TEST_SRC) $(INC) -o $(TEST_OUT)
	./$(TEST_OUT)

# use valgrind on the demo to check for memory issues
valgrind: demo
	valgrind --leak-check=full --show-leak-kinds=all ./$(DEMO_OUT)

# clean up all the compiled stuff
clean:
	rm -rf $(BIN_DIR)

# make sure the bin directory exists before compiling
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
