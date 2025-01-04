all:
	g++ -Isrc/Include -Lsrc/Lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2