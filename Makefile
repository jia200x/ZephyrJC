CC = gcc

UNAME := $(shell uname)
OBJECTS = zephyrjc.o zephyrjc_main.o graphics_sdl.o sprite.o transform.o eventdispatcher.o object.o scenario.o scenario_manager.o
CFLAGS = -Iinclude -g -Wall

SRC = $(wildcard *.c) $(wildcard game/*.c) $(wildcard game/*/*.c) $(wildcard core/*.c) $(wildcard core/*/*.c)
$(info $(SRC))

ifeq ($(UNAME), Darwin)
LDFLAGS = -framework SDL2 -framework SDL2_image
FOLDER = bin/darwin
TARGET = zephyr.elf
else
TARGET = zephyr.exe
FOLDER = bin/win
endif

$(TARGET): build 
	gcc $(CFLAGS) $(LDFLAGS) $(SRC) -o $(FOLDER)/$(TARGET)

all: $(TARGET)

build:
	mkdir -p $(FOLDER)

run:
	./$(FOLDER)/$(TARGET)

