.PHONY: data

data:
	rm -rf data
	mkdir -p data
	curl -L "https://www.dropbox.com/scl/fi/a5ron8w0cmizw3rdms511/pa4_dataset.csv?rlkey=v70qjo33775cxu3fach91nfnf&st=4luay4qe&dl=1" -o dataset.csv
	mv dataset.csv data

preprocess:
	make build
	./main --preprocess

build:
	g++ src/*.cpp -g -Wall -std=c++14 -o main

exec:
	@./main

debug:
	@gdb ./main
