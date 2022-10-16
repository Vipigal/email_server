#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CPP = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/email.o $(OBJ)/inbox.o $(OBJ)/user.o $(OBJ)/main.o
HDRS = $(INC)/email.hpp $(INC)/user.hpp $(INC)/inbox.hpp
CPFLAGS = -Wall -c -I$(INC)
CXXFLAGS = -std=c++11 -g -Wall

EXE = $(BIN)/email_server


all:  $(EXE)

test: $(TEST)



$(BIN)/email_server: $(OBJS)
	$(CPP) $(CXXFLAGS) -pg -I$(INC) -o $(BIN)/email_server $(OBJS) $(LIBS) 

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/email.o: $(HDRS) $(SRC)/email.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/email.o $(SRC)/email.cpp
	
$(OBJ)/inbox.o: $(HDRS) $(SRC)/inbox.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/inbox.o $(SRC)/inbox.cpp
	
$(OBJ)/user.o: $(HDRS) $(SRC)/user.cpp
	$(CPP) $(CPFLAGS) -o $(OBJ)/user.o $(SRC)/user.cpp

	
	
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
