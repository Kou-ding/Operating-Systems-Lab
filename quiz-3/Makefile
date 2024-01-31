# $^ (all prerequisites): refers to whatever is after the ":"
# $@ (target): refers to whatever is before the ":"
# $< (first prerequisite): refers to the first thing that is after the ":"
# | if bins directory exists execute the code, otherwise create it in line 23
CC = gcc
CFLAGS = -Wall

BINS = bins
# define folder

all: test
# all is the default action in makefiles
test: main.c waiting.c 
	$(CC) $(CFLAGS) $^ -o $@
# produces the executable bypassing the object file creation
install: $(BINS)/main.o $(BINS)/waiting.o | $(BINS)
	$(CC) $(CFLAGS) $^ -o test
# $^ refers to $(BINS)/main.o $(BINS)/waiting.o	
$(BINS)/%.o: %.c | $(BINS)
	$(CC) $(CFLAGS) -c $< -o $@
# $< refers to %.c	
$(BINS):
	mkdir -p $(BINS)
# -p (parent): create directories that dont already exist

clean:
	rm -f test $(BINS)/*.o