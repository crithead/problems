# Generated Makefile for Problems
all: array nearest-power-of-two poweroftwo series-approx sizeof square-root three-bits markov primes trajectory

markov: markov.cpp
	g++ -Wall -pedantic --std=c++11 -o markov markov.cpp -lm

primes: primes.cpp
	g++ -Wall -pedantic --std=c++11 -o primes primes.cpp -lm

trajectory: trajectory.cpp
	g++ -Wall -pedantic --std=c++11 -o trajectory trajectory.cpp -lm

array: array.c
	gcc -Wall -pedantic --std=c99 -o array array.c -lm

nearest-power-of-two: nearest-power-of-two.c
	gcc -Wall -pedantic --std=c99 -o nearest-power-of-two nearest-power-of-two.c -lm

poweroftwo: poweroftwo.c
	gcc -Wall -pedantic --std=c99 -o poweroftwo poweroftwo.c -lm

series-approx: series-approx.c
	gcc -Wall -pedantic --std=c99 -o series-approx series-approx.c -lm

sizeof: sizeof.c
	gcc -Wall -pedantic --std=c99 -o sizeof sizeof.c -lm

square-root: square-root.c
	gcc -Wall -pedantic --std=c99 -o square-root square-root.c -lm

three-bits: three-bits.c
	gcc -Wall -pedantic --std=c99 -o three-bits three-bits.c -lm

.PHONY: clean
clean:
	rm -f  array nearest-power-of-two poweroftwo series-approx sizeof square-root three-bits markov primes trajectory

