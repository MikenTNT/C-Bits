# MAKEFILE DE PROYECTO C,  rev 6.3
# Autor: MikenTNT  13-OCT-2019.

SHELL = /bin/bash

#-----------------------------------AJUSTES-------------------------------------

# Compilador de C 'gcc'.
CC = gcc-8
# CFLAGS: depurador '-g', matematicas '-lm'.
CFLAGS = -Wall
# Nombre del archivo a principal.
MAIN = main

#----------------------------------VARIABLES------------------------------------

# SOURCES: archivos fuentes de C.
SOURCES := $(shell find . -maxdepth 1 -regex ".*\.c")
# HEADERS: archivos de cabecera de C.
HEADERS := $(shell find . -maxdepth 1 -regex ".*\.h")
# OBJECTS: archivos compilados a objeto para el linker.
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

# Phony targets.
PHONY := all run clean tar untar

#----------------------------OBJETIVOS PRINCIPALES------------------------------

# Objetivos a ejecutar con el comando make.
all: $(MAIN)


# Crear el archivo de ejecución $(MAIN).
$(MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilacion especial de archivos.
$(MAIN).o: $(MAIN).c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Compilacion general de archivos.
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

#-------------------------------OTROS OBJETIVOS---------------------------------

# Ejecutar el programa.
run: $(MAIN)
	@./$<

# Objetivo para limpieza.
clean:
	rm -rf $(OBJECTS) $(MAIN) proyecto.tar

# Objetivo para comprimir.
tar: $(SOURCES) $(HEADERS) Makefile
	tar -cvf proyecto.tar $^

# Objetivo para descomprimir.
untar: proyecto.tar
	tar -xvf $<

#-------------------------------------------------------------------------------

.PHONY: $(PHONY)
