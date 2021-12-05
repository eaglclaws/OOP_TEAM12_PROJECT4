DEBUGINCLUDE = ./headers
INCLUDE = ../headers
CXX = clang++
FLAGS = -g -I$(DEBUGINCLUDE) -I$(INCLUDE) --std=c++20
OBJFLAGS = -c $(FLAGS)
OBJ = obj/main.o obj/DebugDeskComp.o obj/DebugView.o obj/DebugModel.o
HEADER = headers/DebugModel.hpp headers/DebugView.hpp headers/DebugDeskComp.hpp

run: all
	./main.out

all: $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o main.out

obj/main.o: src/main.cpp
	$(CXX) $(OBJFLAGS) -o obj/main.o src/main.cpp

obj/DebugDeskComp.o: src/DebugDeskComp.cpp headers/DebugDeskComp.hpp ../headers/DeskComp.hpp
	$(CXX) $(OBJFLAGS) -o obj/DebugDeskComp.o src/DebugDeskComp.cpp

obj/DebugModel.o: src/DebugModel.cpp $(HEADER) ../headers/Model.hpp
	$(CXX) $(OBJFLAGS) -o obj/DebugModel.o src/DebugModel.cpp

obj/DebugView.o: src/DebugView.cpp $(HEADER) ../headers/View.hpp
	$(CXX) $(OBJFLAGS) -o obj/DebugView.o src/DebugView.cpp
