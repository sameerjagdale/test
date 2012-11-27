all : test

test:	test.o mysocket.o worker.o Testy.o
	gcc -o test test.o mysocket.o worker.o Testy.o
test.o: test.c worker.o Testy.o mysocket.o
	gcc -c test.c
worker.o: worker.c worker.h
	gcc -c worker.c
mysocket.o: mysocket.c mysocket.h
	gcc -c mysocket.c
Testy.o: Testy.c Testy.h
	gcc -c Testy.c
clean: 
	rm -rf *.o test 
