CC = g++

EXTRA_FLAGS = -std=c++11 -Wall -Os
INCLUDE_PATH = ./include
EXE_FILES = ./include/Application.cpp
OUT_EXE = Application.exe
#BUILD_OUTPUTS = Card.o GameState.o Player.o

rebuild: clean build

build :
	$(CC) $(EXTRA_FLAGS) -I $(INCLUDE_PATH) -o $(OUT_EXE) $(EXE_FILES)
	
clean : 
	-rm -f $(OUT_EXE)
	echo Clean done
	
#clean_o :
	#-rm -f $(BUILD_OUTPUTS)