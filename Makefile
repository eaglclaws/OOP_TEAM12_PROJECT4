CXX = clang++
flags = -g -O2 -Iheaders

objects = obj/Model.o obj/View.o obj/Control.o obj/DeskComp.o obj/main.o

run: all
	./main.out

all: obj
	$(CXX) $(flags) $(objects) -o ./main.out

obj: $(objects)

obj/Model.o: src/Model.cpp headers/Model.hpp
	$(CXX) $(flags) -c src/Model.cpp -o obj/Model.o

obj/View.o: src/View.cpp headers/View.hpp
	$(CXX) $(flags) -c src/View.cpp -o obj/View.o

obj/Control.o: src/Control.cpp headers/Control.hpp
	$(CXX) $(flags) -c src/Control.cpp -o obj/Control.o

obj/DeskComp.o: src/DeskComp.cpp headers/DeskComp.hpp
	$(CXX) $(flags) -c src/DeskComp.cpp -o obj/DeskComp.o

obj/main.o: src/main.cpp
	$(CXX) $(flags) -c src/main.cpp -o obj/main.o
