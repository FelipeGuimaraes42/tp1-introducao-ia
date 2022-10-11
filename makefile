compile:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCS.cpp

run:
	cd src && ./main ../maps/map.txt UCS 1 2 2 4