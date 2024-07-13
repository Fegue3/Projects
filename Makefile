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

.PHONY: all execute clean

# Identifica o alvo a ser executado
EXECUTABLES = $(filter-out $@,$(MAKECMDGOALS))

# Regras de compilação e execução

# Regra para Python
run-python: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			echo "Executando $$script"; \
			$(PYTHON) $$script; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

# Regra para Bash
run-bash: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			echo "Executando $$script"; \
			$(BASH) $$script; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

# Regra para C++
run-cpp: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			$(CXX) -o $${script:.cpp=.exe} $$script; \
			echo "$$script compilado para $${script:.cpp=.exe}"; \
			./$${script:.cpp=.exe}; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

# Regra para C
run-c: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			$(CC) -o $${script:.c=.exe} $$script; \
			echo "$$script compilado para $${script:.c=.exe}"; \
			./$${script:.c=.exe}; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

# Regra para Java
run-java: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			$(JAVA) $$script; \
			echo "$$script compilado"; \
			$(JAVARUN) $${script:.java=}; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

# Regra para OCaml
run-ocaml: 
	@for script in $(EXECUTABLES); do \
		if [ -f $$script ]; then \
			$(OCAMLC) -o $${script:.ml=.exe} $$script; \
			echo "$$script compilado para $${script:.ml=.exe}"; \
			./$${script:.ml=.exe}; \
		else \
			echo "Arquivo $$script não encontrado"; \
			exit 1; \
		fi \
	done

execute: 
	@for exe in $(EXECUTABLES); do \
		if [ -f $$exe ]; then \
			case $$exe in \
				*.py) $(MAKE) run-python EXECUTABLES=$$exe;; \
				*.sh) $(MAKE) run-bash EXECUTABLES=$$exe;; \
				*.cpp) $(MAKE) run-cpp EXECUTABLES=$$exe;; \
				*.c) $(MAKE) run-c EXECUTABLES=$$exe;; \
				*.java) $(MAKE) run-java EXECUTABLES=$$exe;; \
				*.ml) $(MAKE) run-ocaml EXECUTABLES=$$exe;; \
				*) echo "Tipo de arquivo não suportado: $$exe"; exit 1;; \
			esac \
		else \
			echo "Arquivo $$exe não encontrado"; \
			exit 1; \
		fi \
	done

clean:
	@$(RM) *.exe *.class *.cmi *.cmo
	@echo "Ficheiros removidos"

# Prevents make from considering these as file targets
%:
	@:
