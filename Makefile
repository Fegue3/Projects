# CREDITOS FG

# Variáveis
PYTHON = python3
BASH = bash
CXX = g++
CC = gcc
JAVA = javac
JAVARUN = java
OCAMLC = ocamlc
RM = rm -f

.PHONY: execute clean

# Identifica o alvo a ser executado
EXECUTABLES = $(basename $(filter-out $@,$(MAKECMDGOALS)))

all: $(EXECUTABLES) execute

# Regras de compilação e execução

# Regra para Python
%.py:
	@echo "Executando $<"
	@$(PYTHON) $<

# Regra para Bash
%.sh:
	@echo "Executando $<"
	@$(BASH) $<

# Regra para C++
%.cpp:
	@$(CXX) -o $(@:.cpp=.exe) $<
	@echo "$< compilado para $(@:.cpp=.exe)"
	@./$(@:.cpp=.exe)

# Regra para C
%.c:
	@$(CC) -o $(@:.c=.exe) $<
	@echo "$< compilado para $(@:.c=.exe)"
	@./$(@:.c=.exe)

# Regra para Java
%.java:
	@$(JAVA) $<
	@echo "$< compilado"
	@$(JAVARUN) $(@:.java=)

# Regra para OCaml
%.ml:
	@$(OCAMLC) -o $(@:.ml=.exe) $<
	@echo "$< compilado para $(@:.ml=.exe)"
	@./$(@:.ml=.exe)

# Regra para executar
execute: $(EXECUTABLES)

clean:
	@$(RM) *.exe *.class *.cmi *.cmo
	@echo "Ficheiros removidos"
