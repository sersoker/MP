bin/test : obj/test.o
	g++ -o  bin/test obj/test.o -Llib/ 

obj/test.o: src/test.cpp obj/bloqueLed.o
	g++ -c src/test.cpp -o obj/test.o -Iinclude/

obj/bloqueLed.o: src/bloqueLed.cpp include/bloqueLed.h
	g++ -c src/bloqueLed.cpp -o obj/bloqueLed.o -Iinclude/

