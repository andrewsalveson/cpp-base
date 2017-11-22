CC          = g++
LD          = g++ 
CFLAG       = -Wall
PROG_NAME   = prog

SRC_DIR     = ./src
BUILD_DIR   = ./build
BIN_DIR     = ./bin
SRC_LIST = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_LIST = $(BUILD_DIR)/$(notdir $(SRC_LIST:.cpp=.o))

.PHONY: all clean $(PROG_NAME) compile

all: $(PROG_NAME) | $(BUILD_DIR)

compile:
			$(CC) -c $(CFLAG) $(SRC_LIST) -o $(OBJ_LIST)

$(BUILD_DIR):
			mkdir -p $(BUILD_DIR)

$(BIN_DIR):
			mkdir -p $(BIN_DIR)

$(PROG_NAME): compile | $(BIN_DIR)
	    $(LD) $(OBJ_LIST) -o $(BIN_DIR)/$@

clean:
	    rm -f $(BIN_DIR)/$(PROG_NAME) $(BUILD_DIR)/*.o
