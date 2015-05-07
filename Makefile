CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -O2
OBJS = $(patsubst %.c,%.o, $(wildcard *.c))

prot : $(OBJS)
	$(CC) $(CFLAGS) -o Batalha_Naval $(OBJS)

limpar :
	rm Batalha_Naval *.o
	
