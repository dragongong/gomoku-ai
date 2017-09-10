

all:
	cd gomoku-common && make
	cd mcts_alg && make
test:
	cd gomoku-common && make test
	cd mcts_alg && make test
clean:
	cd gomoku-common && make clean
	cd mcts_alg && make clean
	find . -name *.dSYM -exec rm -rf {} \;