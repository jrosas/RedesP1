CC = gcc
RM = rm
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

main: $(OBJS)
	$(CC) -o verific $(OBJS) -lpthread
    
%.o: %.c
	$(CC) -c  $<
    
clean:
	$(RM) *.o verific
