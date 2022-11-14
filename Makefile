make all:
	g++ src/*.cpp -o build/Output
	
make for_valgrind:
	g++ src/*.cpp -o build/Output -g