CC=gcc
CFLAGS= -I.
DEPS=execute.h parse.h read.h
OBJ=main.o execute_redir.o execute.o parse.o read.o

%.o: $.c $(DEPS)
	#(CC) -c -o $@ $< $(CFLAGS)

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm main.o execute.o parse.o read.o execute_redir.o
