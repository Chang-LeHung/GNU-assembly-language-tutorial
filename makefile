dirs := $(shell bash finddir.sh)
dirs := $(patsubst %, %/*.c, $(dirs))
files := $(wildcard *.c $(dirs))
objs := $(patsubst %.c, %.out, $(files))

cflags = -g -Wall -lpthread
all: $(objs)

%.out:%.c
	gcc  $< -o $@ $(cflags)

clean:
	rm $(objs)
