make all:
	g++ src/*.cpp -o build/Output -I include
	
make for_valgrind:
	g++ src/*.cpp -o build/ValOut -g -I include
