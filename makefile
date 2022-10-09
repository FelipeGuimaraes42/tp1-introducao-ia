compile:
	cd src && g++ -o main main.cpp InputFile.cpp Graph.cpp BFS.cpp IDS.cpp Greedy.cpp UCs.cpp

run:
	cd src && ./main ../map.txt BFS 1 2 2 4