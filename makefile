compile: executor.c
	gcc executor.c

run: compile
	./a.out
