CC=g++
FLAGS=-std=c++11
OUT=solver

main:
	$(CC) -o $(OUT) $(FLAGS) main.cpp
