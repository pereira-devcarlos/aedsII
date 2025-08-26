
# Makefile com output

OUTPUT = output
TARGET = $(OUTPUT)/hello
MAIN_OBJ = $(OUTPUT)/main.o
HW_OBJ = $(OUTPUT)/helloWorld.o

all: $(OUTPUT) $(TARGET)

$(OUTPUT):
	mkdir -p $(OUTPUT)

$(TARGET): $(MAIN_OBJ) $(HW_OBJ)
	gcc -o $(TARGET) $(MAIN_OBJ) $(HW_OBJ)

$(MAIN_OBJ): main.c helloWorld.h | $(OUTPUT)
	gcc -o $(MAIN_OBJ) main.c -c -W -Wall -ansi -pedantic

$(HW_OBJ): helloWorld.c helloWorld.h | $(OUTPUT)
	gcc -o $(HW_OBJ) helloWorld.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf $(OUTPUT) *~
	