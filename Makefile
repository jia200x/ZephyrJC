CC = gcc

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
CFLAGS = -g -Wall -framework OpenGL -framework GLUT
TARGET = "hello_world.elf"
else
CFLAGS = -g -Wall
TARGET = "hello_world.exe"
endif

$(TARGET): hello_world.o

all: $(TARGET)

$(TARGET): hello_world.c
	$(CC) $(CFLAGS) -o $(TARGET) hello_world.c
