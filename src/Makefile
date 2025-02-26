# cc -O3 -c uimain.c
OBJS = uimain.o tokenize.o history.o

CFLAGS = -g -O3

all: tokenizer
Tokenizer: $(OBJS)
    cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
    rm -f *.o tokenizer

run: tokenizer
    ./tokenizer

#cc  -g -O3 -o tokenizer uimain.o
