data:
	rm -rf data
	mkdir -p data
	curl "https://simplemaps.com/static/data/us-zips/1.90/basic/simplemaps_uszips_basicv1.90.zip" --output uszips.zip
	unzip uszips.zip -d tmp
	mv tmp/uszips.csv data
	rm -rf tmp
	rm uszips.zip

build:
	g++ src/*.cpp -g -Wall -std=c++11 -o main
	mkdir -p target
	cp -nr data/. target

exec:
	@./main

debug:
	@gdb ./main
