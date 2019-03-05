all:
	g++ -g -std=c++11 application.cpp ai.cpp room.cpp event.hpp game.cpp wumpus.cpp bats.cpp pit.cpp gold.cpp -o wumpus
clean:
	rm -rf *.o
room:
	g++ -c room.cpp 
event:
	g++ -c event.hpp
val:
	g++ -g application.cpp room.cpp event.hpp game.cpp wumpus.cpp bats.cpp pit.cpp gold.cpp -o wumpus
