bin/main: src/main.cpp obj/bloqueLed.o
	g++ src/main.cpp obj/bloqueLed.o -o bin/main -Iinclude/

obj/bloqueLed.o: src/bloqueLed.cpp include/bloqueLed.h
	g++ -c src/bloqueLed.cpp -o obj/bloqueLed.o -Iinclude/

clean:
	echo "Limpiando..."
	rm obj/*.o

mrproper: clean
	rm bin/main
