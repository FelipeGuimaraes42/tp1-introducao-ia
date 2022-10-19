compile:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp

run:
	cd src && ./main ../maps/mapa_teste.map UCS 1 2 2 3

bfsTest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/test.map BFS 1 2 1 4
idsTest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/test.map IDS 1 2 1 4
ucsTest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/test.map UCS 1 2 1 4
greedyTest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/test.map Greedy 1 2 1 4
astarTest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/test.map Astar 1 2 1 4

bfsForest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map BFS 13 7 90 0
idsForest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map IDS 13 7 90 0
ucsForest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map UCS 13 7 90 0
greedyForest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Greedy 13 7 90 0
astarForest:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Astar 13 7 90 0

bfsCity:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map BFS 0 0 79 0
idsCity:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map IDS 0 0 79 0
ucsCity:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map UCS 0 0 79 0
greedyCity:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Greedy 0 0 79 0
astarCity:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Astar 0 0 79 0