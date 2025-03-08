# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

SRC_DIR := .
OUT_DIR := .

.PHONY: build clean

build: servere colorare compresie oferta

run-p1:
	./servere
run-p2:
	./colorare
run-p3:
	./compresie
run-p5:
	./oferta

servere: servere.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
colorare: colorare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
compresie: compresie.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
oferta: oferta.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f servere colorare compresie criptat oferta
