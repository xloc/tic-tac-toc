CC = gcc
CFLAGS := -Wall -W -std=gnu99 -g
PROGRAM = ttt
 
OBJS = myRand.o ttt.o
 
.PHONY: all clean
     
all: $(PROGRAM)
 
$(PROGRAM):$(OBJS)
	$(CC) $^ -o $@

.o:
	$(CC) $(CFLAGS) -c $<

clean:
	@rm -rf $(PROGRAM) $(OBJS)
