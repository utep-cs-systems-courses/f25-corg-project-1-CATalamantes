OBJS =  uimain.o tokenizer.o history.o 

CFLAGS=-g -O3 -Wall



all:tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

clean: rm -f *.o tokenizer *~

run:tokenizer
	./tokenizer


