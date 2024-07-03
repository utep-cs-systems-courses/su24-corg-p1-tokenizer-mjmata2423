CFLAGS =-g -O3
OBJS = tokenizer.o uimain.o history.o

all:tokenizer

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h

clean:
	rm -f *.o tokenizer

run:tokenizer
	./tokenizer
