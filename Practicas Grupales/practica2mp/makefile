bin/test: src/test.cpp obj/bloqueLed.o
	g++ src/test.cpp obj/bloqueLed.o -o bin/test -Iinclude/

obj/bloqueLed.o: src/bloqueLed.cpp include/bloqueLed.h
	g++ -c src/bloqueLed.cpp -o obj/bloqueLed.o -Iinclude/