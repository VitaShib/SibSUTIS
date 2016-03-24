.PHONY: clean remake

all: bin/tester2 bin/QuadraticEquation

remake: clean all

bin/QuadraticEquation: obj/main.o obj/calc.o
	mkdir -p bin
	gcc obj/main.o obj/calc.o -o bin/QuadraticEquation -lm

obj/main.o: src/main.c
	mkdir -p obj
	gcc -c src/main.c -o obj/main.o

obj/calc.o: src/calc.c
	mkdir -p obj
	gcc -c src/calc.c -o obj/calc.o

obj/calc.o: src/calc.c
	mkdir -p obj
	gcc -c src/calc.c -o obj/calc.o

obj/tester.o: test/tester2.c test/mytests.c
	gcc -c test/tester2.c -o obj/tester.o

bin/tester2: obj/calc.o obj/tester.o
	gcc obj/calc.o obj/tester.o -o bin/tester2 -lm

clean:
	rm obj/*.o bin/*

