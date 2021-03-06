CC = gcc

# all: read

reading: main.c handle_flags.c stats.c output.c
	$(CC) -o reading main.c handle_flags.c stats.c output.c
