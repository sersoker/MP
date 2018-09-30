SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)
	

all: $(BIN)/testimagen $(BIN)/testplano $(BIN)/testarteASCII $(BIN)/arteASCII

# ************ arteASCII *******
$(BIN)/arteASCII : $(OBJ)/arteASCII.o $(LIB)/libimagen.a
	g++ -o $(BIN)/arteASCII $(OBJ)/arteASCII.o -Llib/ -limagen

$(OBJ)/arteASCII.o : $(SRC)/arteASCII.cpp
	g++ -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -Iinclude


# ************ testarteASCII *******
$(BIN)/testarteASCII : $(OBJ)/testarteASCII.o $(LIB)/libimagen.a
	g++ -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o -Llib/ -limagen

$(OBJ)/testarteASCII.o : $(SRC)/testarteASCII.cpp
	g++ -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -Iinclude


# ************ testplano *******
$(BIN)/testplano : $(OBJ)/testplano.o $(LIB)/libimagen.a
	g++ -o $(BIN)/testplano $(OBJ)/testplano.o  -Llib/ -limagen

$(OBJ)/testplano.o : $(SRC)/testplano.cpp
	g++ -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -Iinclude


# ************ testimagen *******
$(BIN)/testimagen : $(OBJ)/testimagen.o $(LIB)/libimagen.a
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o -Llib/ -limagen

$(OBJ)/testimagen.o : $(SRC)/testimagen.cpp
	g++ -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -Iinclude

# ************ libreria *******
$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	ar rsv lib/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o

$(OBJ)/imagen.o: $(INC)/imagen.h $(SRC)/imagen.cpp 
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -Iinclude/	

# ************ documentación *******
documentacion:
	doxygen doc/doxys/Doxyfile
# ************ Limpieza ************
clean:
	echo "Limpiando..."
	rm obj/*.o lib/lib*.a bin/*

	
