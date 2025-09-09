# Automatizando o makefile

# Nome do projeto
PROJ_NAME=./build/fila

# Arquivos .c
C_SOURCE=$(wildcard *.c)

# Arquivos .h
H_SOURCE=$(wildcard *.h)

# Arquivos objeto (agora na pasta build)
OBJ=$(patsubst %.c,build/%.o,$(C_SOURCE))

# Compilador
CC=gcc

# Flags (opções) para o compilador
CC_FLAGS=-c         \
         -Wall      \
         -g         \
         -pedantic

#########################
# Compilação e linkagem #
#########################
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

build/%.o: %.c %.h | build
	$(CC) $(CC_FLAGS) -o $@ $<

build:
	mkdir -p build

clean:
	rm -rf build *.o $(PROJ_NAME) *~