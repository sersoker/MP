SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen $(BIN)/arteASCII 

# ************ testarteASCII *******
$(BIN)/testarteASCII : $(OBJ)/testarteASCII.o
	g++ -o $(BIN)/testarteASCII $(OBJ)/testarteASCII.o

$(OBJ)/testarteASCII.o : $(SRC)/testarteASCII.cpp
	g++ -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -Iinclude

# ************ testplano *******
$(BIN)/testplano : $(OBJ)/testplano.o
	g++ -o $(BIN)/testplano $(OBJ)/testplano.o

$(OBJ)/testplano.o : $(SRC)/testplano.cpp
	g++ -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -Iinclude


# ************ arteASCII *******
$(BIN)/arteASCII : $(OBJ)/arteASCII.o
	g++ -o $(BIN)/arteASCII $(OBJ)/arteASCII.o

$(OBJ)/arteASCII.o : $(SRC)/arteASCII.cpp
	g++ -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -Iinclude

# ************ testimagen *******
$(BIN)/testimagen : $(OBJ)/testimagen.o
	g++ -o $(BIN)/testimagen $(OBJ)/testimagen.o

$(OBJ)/testimagen.o : $(SRC)/testimagen.cpp $(OBJ)/imagen.o
	g++ -c $(SRC)/testimagen.cpp $(OBJ)/imagen.o -o $(OBJ)/testimagen.o -Iinclude

$(OBJ)/imagen.o: $(INC)/imagen.h $(SRC)/imagen.cpp $(OBJ)/pgm.o
	g++ -c $(SRC)/imagen.cpp $(OBJ)/pgm.o -o $(OBJ)/imagen.o -Iinclude/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -Iinclude/	

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
