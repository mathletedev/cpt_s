build:
	g++ src/*.cpp -g -Wall -std=c++11 -o main
	mkdir -p target
	cp -nr data/. target

exec:
	@read -p "Enter variant to test: " VARIANT; \
	./main $$VARIANT

test:
	@./main --test

debug:
	@gdb ./main
