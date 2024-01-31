# $^ (all prerequisites): refers to whatever is after the ":"
# $@ (target): refers to whatever is before the ":"
# $< (first prerequisite): refers to the first thing that is after the ":"
# | if obj directory exists execute the code, otherwise create it in line 23
CC = gcc
CFLAGS = -Wall

OBJ = obj
# define folder

all: memory resources
# all is the default action in makefiles
memory: memory.c 
	$(CC) $(CFLAGS) $^ -o $@
# produces the executable bypassing the object file creation
resources: test_bash.c
	$(CC) $(CFLAGS) $^ -o $@
install: $(OBJ)/memory.o | $(OBJ)
	$(CC) $(CFLAGS) $^ -o test
# $^ refers to $(OBJ)/memory.o	
$(OBJ)/%.o: %.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@
# $< refers to %.c	
$(OBJ):
	mkdir -p $(OBJ)
# -p (parent): create directories that dont already exist

clean:
	rm -f memory resources $(OBJ)/*.o