
CC=gcc
#CFLAGS= -Wall -std=c99 -lm
CFLAGS= -Wall -std=c99 -fsanitize=address -g
CFLAFS_RELEASE= -Wall -std=c99

TEST=test.sh
SRC=tree.c main.c mainCicloDoppio.c mainHash.c mainOrginale.c mainTreeSingolo.c mainTreeDoppio.c
OBJ=$(foreach i,$(basename $(SRC)), $(i).o )
BIN=morse
ZIP=morse.zip

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BIN):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(ZIP):
	zip -r $@ $(SRC) $(TEST) Makefile tabella tree.h

.PHONY: run build clean package test
build:$(BIN)

run:build
	./$(BIN)

test:build
	./$(TEST)

clean:
	rm -fr $(BIN) $(OBJ) $(ZIP)

package:$(ZIP)
