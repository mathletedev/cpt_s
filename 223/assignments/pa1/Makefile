build:
	g++ src/*.cpp -g -Wall -std=c++11 -o main
	mkdir -p target
	cp -nr data/. target

exec:
	@./main

test:
	@./main --test
