##############################################################################
######################################### PROJECT DIR ########################
##############################################################################
BIN = bin
EXE = $(BIN)/app
#LIB = $(BIN)/lib
RES = $(BIN)/res

##############################################################################
######################################### CFLAGS AND CLIB ####################
##############################################################################
CC = clang
CFLAGS = -Isrc -Iinclude
CLIB = -Llib -Wl,-rpath,lib

CFLAGS += -O0
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -std=c17
CLIB +=

##############################################################################
######################################### OBJECT FILES #######################
##############################################################################
OBJ = main.o \
      $(OBJ_SRC)
OBJ_SRC =

##############################################################################
######################################### Rules ##############################
##############################################################################

all: compile_commands.json compile run

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
	rm -r $(BIN) $(OBJ)

.PHONY : cleanAll
cleanAll:
	rm -r $(BIN) $(OBJ) tags compile_commands.json

compile_commands.json:
	bear -- make compile
