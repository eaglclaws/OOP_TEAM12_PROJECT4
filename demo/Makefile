CXX = clang++
HEADERS = ./headers
SRC = ./src
FLAGS = -g --std=c++20 -I$(HEADERS) -O2
MODEL_SRC = $(SRC)/TestModel.cpp
MODEL_H = $(HEADERS)/TestModel.hpp
VIEW_SRC = $(SRC)/TextView.cpp
VIEW_H = $(HEADERS)/TextView.hpp
DCOMP_H = $(LIGHT_H) $(CALC_H) $(DATE_H) $(NOTE_H)
LIGHT_SRC = $(SRC)/mycandle.cpp
LIGHT_H = $(HEADERS)/mycandle.hpp
CALC_SRC = $(SRC)/mycalculator.cpp
CALC_H = $(HEADERS)/mycalculator.hpp
DATE_SRC = $(SRC)/mycalender.cpp
DATE_H = $(HEADERS)/mycalender.hpp
NOTE_SRC = $(SRC)/mynote.cpp
NOTE_H = $(HEADERS)/mynote.hpp
OBJ = obj/TestModel.o obj/TextView.o obj/mycandle.o obj/mycalender.o obj/mycalculator.o obj/mynote.o obj/main.o

run: all
	./main.out

all: $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o main.out

obj/TestModel.o: $(MODEL_SRC) $(MODEL_H) $(VIEW_H) $(DCOMP_H)
	$(CXX) $(FLAGS) -c $(MODEL_SRC) -o obj/TestModel.o

obj/TextView.o: $(VIEW_H) $(VIEW_SRC) $(HEADERS)/Model.hpp $(HEADERS)/DeskComp.hpp
	$(CXX) $(FLAGS) -c $(VIEW_SRC) -o obj/TextView.o

obj/mycandle.o: $(LIGHT_SRC) $(LIGHT_H)
	$(CXX) $(FLAGS) -c $(LIGHT_SRC) -o obj/mycandle.o

obj/mycalculator.o: $(CALC_SRC) $(CALC_H)
	$(CXX) $(FLAGS) -c $(CALC_SRC) -o obj/mycalculator.o

obj/mycalender.o: $(DATE_SRC) $(DATE_H)
	$(CXX) $(FLAGS) -c $(DATE_SRC) -o obj/mycalender.o

obj/mynote.o: $(NOTE_SRC) $(NOTE_H)
	$(CXX) $(FLAGS) -c $(NOTE_SRC) -o obj/mynote.o

obj/main.o: main.cpp $(MODEL_H)
	$(CXX) $(FLAGS) -c main.cpp -o obj/main.o
