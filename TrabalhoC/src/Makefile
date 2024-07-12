CC = cc
EXECUTABLE = main-team-20.exe
SOURCEFILES = $(wildcard *.c) #Vai buscar todos os ficheiros .c da diretoria
OBJECTS = $(SOURCEFILES:%.c=%.o) #Lista dos ficheiros .o
CFLAGS = -Wno-builtin-declaration-mismatch -Wno-implicit-function-declaration #ignora avisos/erros de falta de declarações
CFLAGS += -DTAMANHO_VETOR=10  # define o Tamanho do vetor
LDLIBS = -lm -lrt  # Adiciona #include <math.h> e #include <time.h>

.PHONY: clean all execute help version

all: execute

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f *.o $(EXECUTABLE)

execute: $(EXECUTABLE)
	./$(EXECUTABLE)

help: 
	./$(EXECUTABLE) --help
version:
	./$(EXECUTABLE) --version
