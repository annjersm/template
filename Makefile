BIN = bin
EXE = $(BIN)/chess
#LIB = $(BIN)/lib
RES = $(BIN)/res

CC = clang
CFLAGS = -Isrc -Iinclude
CLIB = -Llib -Wl,-rpath,lib

CFLAGS += -O0
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -std=c17

OBJ = main.o \
      $(OBJ_SRC)
OBJ_SRC =

all: compile_commands.json run

$(BIN):
	mkdir $@

$(LIB): $(BIN)
	cp -r lib $(BIN)/.

$(RES): $(BIN)
	cp -r res $(BIN)/.

main.o: src/main.c
	$(CC) -c $(CFLAGS) $<

$(OBJ_SRC): %.o: src/%.c src/%.h
	$(CC) -c $(CFLAGS) $<

.PHONY : compile
compile: $(BIN) $(OBJ) $(LIB) $(RES)
	$(CC) $(OBJ) -o $(EXE) $(CLIB)
	ctags -R src/

.PHONY : run
run:
	./$(EXE)

.PHONY : clean
clean:
	rm -r $(BIN) $(OBJ) tags compile_commands.json

compile_commands.json:
	bear -- make compile
