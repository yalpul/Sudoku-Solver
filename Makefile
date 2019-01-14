CC=g++
FLAGS=-std=c++11 -O3
OUT=solver

main:
	$(CC) -o $(OUT) $(FLAGS) main.cpp io.cpp utils.cpp
