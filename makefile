CC = gcc
CFLAGS = -Wall 

SRC_DIR = ./src/
INC_DIR = ./include/

SRC_FILES = $(SRC_DIR)*.c
INC_FILES = $(INC_DIR)
TARGET = chess

all: build run clean

build:
	$(CC) -I$(INC_FILES) $(SRC_FILES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)
