
files = $(wildcard *.c struct/*.c simple/*.c simd/*.c)
objs = $(patsubst %.c, %.out, $(files))
cflags = -g -Wall -lpthread
all: $(objs)

%.out:%.c
	gcc  $< -o $@ $(cflags)

clean:
	rm $(objs)
