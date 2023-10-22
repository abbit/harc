CC = gcc
CFLAGS = -std=c11
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
EXE = $(BIN_DIR)/harc

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

