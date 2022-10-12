compile:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCS.cpp

run:
	cd src && ./main ../maps/map.txt UCS 1 2 2 3

test:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCS.cpp && ./main ../maps/test.map UCS 1 2 1 4

forest:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCS.cpp && ./main ../maps/floresta.map UCS 13 7 90 0

city:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCS.cpp && ./main ../maps/cidade.map UCS 0 0 79 0