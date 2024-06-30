####################################################################|#########
######################################### PROJECT DIR ##############|# (¬_¬) #
####################################################################|#########
PROJECT_NAME = app

BIN = bin
EXE = $(BIN)/$(PROJECT_NAME)
#LIB = $(BIN)/lib
RES = $(BIN)/res


####################################################################|#########
######################################### CFLAGS AND CLIB ##########|# (¬_¬) #
####################################################################|#########
CC = clang
CFLAGS = -Isrc -Iinclude
CLIB = -Llib -Wl,-rpath,lib

CFLAGS += -O0
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -std=c17
CLIB += -lm
#CLIB += -lSDL3


####################################################################|#########
######################################### OBJECT FILES #############|# (¬_¬) #
####################################################################|#########
OBJ = main.o \
      $(OBJ_SRC) \
      $(OBJ_UTIL) \
      $(OBJ_STB)
OBJ_SRC =
OBJ_UTIL = math.o
#OBJ_STB = stb_image.o


####################################################################|#########
######################################### Colors ###################|# (¬_¬) #
####################################################################|#########
COLOR_GREEN = \033[0;32m
COLOR_RED   = \033[0;31m
COLOR_BLUE  = \033[0;34m
END_COLOR   = \033[0m

LOG_COMPILE = @echo "${COLOR_GREEN}Compile: ${COLOR_BLUE}"$<"$(END_COLOR)"


####################################################################|#########
######################################### Rules ####################|# (¬_¬) #
####################################################################|#########

all: compile_commands.json compile run

$(BIN):
	@mkdir $@
	@echo "${COLOR_GREEN}Creating dir: $(BIN)${END_COLOR}"

$(LIB): $(BIN)
	@cp -r lib $(BIN)/.
	@echo "${COLOR_GREEN}Yanking dir: $(LIB)${END_COLOR}"

$(RES): $(BIN)
	@cp -r res $(BIN)/.
	@echo "${COLOR_GREEN}Yanking dir: $(RES)${END_COLOR}"

main.o: src/main.c
	@$(CC) -c $(CFLAGS) $<
	$(LOG_COMPILE)

$(OBJ_SRC): %.o: src/%.c src/%.h
	@$(CC) -c $(CFLAGS) $<
	$(LOG_COMPILE)

$(OBJ_UTIL): %.o: src/utils/%.c src/utils/%.h
	@$(CC) -c $(CFLAGS) $<
	$(LOG_COMPILE)

$(OBJ_STB): %.o: include/stb/%.c include/stb/%.h
	@$(CC) -c -O0 $<
	$(LOG_COMPILE)

.PHONY : help
help:
	@echo "Local Makefile help args/rules"
	@echo
	@echo "make <rules>"
	@echo "    all        'default' compile and run"
	@echo "    help       Show this  message"
	@echo "    clean      clean the dir for all *.o and bin dir"
	@echo "    cleanAll   Cleam everything but the 'src' files"
	@echo "    cloc       Prints lines of src code"
	@echo "    compile    Compile the code"
	@echo "    run        Run the code"
	@echo "    recompile  Recompile the cede"
	@echo "    rc         same as recompile" 

.PHONY : deps
deps:
	@echo "Dependencies:"
	@echo "  - libSDL3"
	@echo

.PHONY : recompile
recompile: clean compile

.PHONY : rc
rc: recompile

.PHONY : compile
compile: $(BIN) $(OBJ) $(LIB) $(RES)
	@$(CC) $(OBJ) -o $(EXE) $(CLIB) 
	@echo "${COLOR_GREEN}Linking: $(OBJ)\nTarget: $(EXE)${END_COLOR}"
	@ctags -R src/
	@echo "${COLOR_GREEN}Creating ctags${END_COLOR}"

.PHONY : run
run:
	./$(EXE)

.PHONY : clean
clean:
	@echo "$(COLOR_RED)"
	rm -r $(BIN) $(OBJ)
	@echo "$(END_COLOR)"

.PHONY : cleanAll
cleanAll:
	@echo "$(COLOR_RED)"
	rm -r $(BIN) $(OBJ) tags compile_commands.json
	@echo "$(END_COLOR)"

.PHONY : cloc
cloc:
	@cloc src Makefile res

compile_commands.json:
	bear -- make compile
