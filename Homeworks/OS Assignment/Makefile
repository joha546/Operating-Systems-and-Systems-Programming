CC = gcc
CFLAGS = -Wall -g
OUTPUT = scheduler

OBJS = main.o fcfs.o modified_scheduling.o utils.o

$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUTPUT)

main.o: main.c fcfs.h modified_scheduling.h
	$(CC) $(CFLAGS) -c main.c

fcfs.o: fcfs.c fcfs.h
	$(CC) $(CFLAGS) -c fcfs.c

modified_scheduling.o: modified_scheduling.c modified_scheduling.h fcfs.h
	$(CC) $(CFLAGS) -c modified_scheduling.c

utils.o: utils.c utils.h fcfs.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f $(OBJS) $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)
