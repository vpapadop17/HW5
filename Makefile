all:
	g++ -std=c++17 -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++ -std=c++17 -Wall Graph.cpp BetterPriorityQueue.cpp BPQTestsStarter.cpp -o bpq-tests
	g++ -std=c++17 -Wall Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTestsStarter.cpp -o dijkstra

run:
	./graph-tests

try: all run

clean:
	rm -f graph-tests bpq-tests dijkstra
