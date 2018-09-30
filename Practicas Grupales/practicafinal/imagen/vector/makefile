SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC) -ansi -std=c++11
	

all: $(BIN)/testimagen $(BIN)/arteASCII2 $(BIN)/suma

# ************ arteASCII2 *******
$(BIN)/arteASCII2 : $(OBJ)/arteASCII2.o $(LIB)/libimagen.a
	g++ -o $(BIN)/arteASCII2 $(OBJ)/arteASCII2.o -Llib/ -limagen

$(OBJ)/arteASCII2.o : $(SRC)/arteASCII2.cpp
	g++ $(CPPFLAGS) $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o -Iinclude

# ************ testimagen *******
$(BIN)/testimagen : $(OBJ)/testimagen.o $(LIB)/libimagen.a
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o -Llib/ -limagen

$(OBJ)/testimagen.o : $(SRC)/testimagen.cpp
	g++ $(CPPFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude

# ************ suma *******
$(BIN)/suma : $(OBJ)/suma.o $(LIB)/libimagen.a
	g++ -o $(BIN)/suma $(OBJ)/suma.o -Llib/ -limagen

$(OBJ)/suma.o : $(SRC)/suma.cpp
	g++ $(CPPFLAGS) $(SRC)/suma.cpp -o $(OBJ)/suma.o -Iinclude	


# ************ libreria *******
$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o 
	ar rsv lib/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(OBJ)/lista.o: $(INC)/lista.h $(SRC)/lista.cpp 
	g++ $(CPPFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o -Iinclude/

$(OBJ)/imagen.o: $(INC)/imagen.h $(SRC)/imagen.cpp 
	g++ $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o -Iinclude/	

# ************ documentación *******
documentacion:
	doxygen doc/doxys/Doxyfile
# ************ Limpieza ************
clean:
	echo "Limpiando..."
	rm obj/*.o lib/lib*.a

mrproper: clean
	rm bin/*

	
