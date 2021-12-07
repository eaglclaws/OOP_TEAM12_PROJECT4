CXX = clang++
HEADERS = ./headers
SRC = ./src
FLAGS = -g --std=c++20 -I$(HEADERS) -O2
MODEL_SRC = $(SRC)/DebugModel.cpp
MODEL_H = $(HEADERS)/DebugModel.hpp
VIEW_SRC = $(SRC)/TextView.cpp
VIEW_H = $(HEADERS)/TextView.hpp
DCOMP_SRC = $(SRC)/mycandle.cpp
DCOMP_H = $(HEADERS)/mycandle.hpp
OBJ = obj/DebugModel.o obj/TextView.o obj/mycandle.o obj/main.o

run: all
	./main.out

all: $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o main.out

obj/DebugModel.o: $(MODEL_SRC) $(MODEL_H) $(VIEW_H) $(DCOMP_H)
	$(CXX) $(FLAGS) -c $(MODEL_SRC) -o obj/DebugModel.o

obj/TextView.o: $(VIEW_H) $(VIEW_SRC) $(HEADERS)/Model.hpp $(HEADERS)/DeskComp.hpp
	$(CXX) $(FLAGS) -c $(VIEW_SRC) -o obj/TextView.o

obj/mycandle.o: $(DCOMP_SRC) $(DCOMP_H)
	$(CXX) $(FLAGS) -c $(DCOMP_SRC) -o obj/mycandle.o

obj/main.o: main.cpp $(MODEL_H)
	$(CXX) $(FLAGS) -c main.cpp -o obj/main.o
