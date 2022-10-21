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

bfsForest1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map BFS 80 200 4 204
idsForest1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map IDS 80 200 4 204
ucsForest1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map UCS 80 200 4 204
greedyForest1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Greedy 80 200 4 204
astarForest1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Astar 80 200 4 204

bfsForest2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map BFS 3 20 253 3
idsForest2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map IDS 3 20 253 3
ucsForest2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map UCS 3 20 253 3
greedyForest2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Greedy 3 20 253 3
astarForest2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Astar 3 20 253 3

bfsForest3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map BFS 161 120 19 212
idsForest3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map IDS 161 120 19 212
ucsForest3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map UCS 161 120 19 212
greedyForest3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Greedy 161 120 19 212
astarForest3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Astar 161 120 19 212

bfsForest4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map BFS 21 244 2 104
idsForest4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map IDS 21 244 2 104
ucsForest4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map UCS 21 244 2 104
greedyForest4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Greedy 21 244 2 104
astarForest4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/floresta.map Astar 21 244 2 104

bfsCity1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map BFS 130 1 192 166
idsCity1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map IDS 130 1 192 166
ucsCity1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map UCS 130 1 192 166
greedyCity1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Greedy 130 1 192 166
astarCity1:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Astar 130 1 192 166

bfsCity2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map BFS 1 94 205 117
idsCity2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map IDS 1 94 205 117
ucsCity2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map UCS 1 94 205 117
greedyCity2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Greedy 1 94 205 117
astarCity2:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Astar 1 94 205 117

bfsCity3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map BFS 16 121 5 253
idsCity3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map IDS 16 121 5 253
ucsCity3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map UCS 16 121 5 253
greedyCity3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Greedy 16 121 5 253
astarCity3:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Astar 16 121 5 253

bfsCity4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map BFS 95 75 65 152
idsCity4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map IDS 95 75 65 152
ucsCity4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map UCS 95 75 65 152
greedyCity4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Greedy 95 75 65 152
astarCity4:
	cd src && g++ -o main main.cpp InputFile.cpp BFS.cpp IDS.cpp UCS.cpp Greedy.cpp AStar.cpp Node.cpp && ./main ../maps/cidade.map Astar 95 75 65 152