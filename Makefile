all:
	g++ application.cpp room.cpp event.cpp wumpus.cpp bats.cpp pit.cpp gold.cpp -o wumpus
clean:
	rm -rf *.o
room:
	g++ -c room.cpp 
event:
	g++ -c event.cpp
val:
	g++ -g application.cpp room.cpp event.cpp wumpus.cpp bats.cpp pit.cpp gold.cpp -o wumpus
