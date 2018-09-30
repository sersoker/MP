bin/central : obj/central.o lib/libformas.a
	g++ -o bin/central obj/central.o -Llib/ -lformas

obj/central.o: src/central.cpp 
	g++ -c src/central.cpp -o obj/central.o -Iinclude/

lib/libformas.a: obj/punto.o obj/circulo.o
	ar rsv lib/libformas.a obj/punto.o obj/circulo.o

obj/circulo.o: src/circulo.cpp include/circulo.h include/punto.h src/punto.cpp
	g++ -c src/circulo.cpp -o obj/circulo.o -Iinclude/

obj/punto.o: src/punto.cpp include/punto.h
	g++ -c src/punto.cpp -o obj/punto.o -Iinclude/

clean:
	echo "Limpiando..."
	rm obj/*.o lib/lib*.a

mrproper: clean
	rm bin/central bin/main2