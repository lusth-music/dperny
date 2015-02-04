#Place the names of all your tracks here (as RRA filenames)

RRA = song.rra
SRRA = s-song.rra
INCLUDE=/usr/local/include/songlib/
LIB=/usr/local/lib/

all : $(RRA)

%.rra	: %.x
		./$<

%.x	: %.c
		gcc -Wall -g -o $@ -I$(INCLUDE) $< -L$(LIB) -lsong -lm 

mix.rra		: $(RRA)
		rrafastmixer $(RRA) > mix.rra

play	: $(RRA)
		rplay $(RRA)

mix :
		rrafastmixer $(RRA) | rplay

playmix : mix.rra
		rplay mix.rra

s-song.rra : song.rra
		rrastereo -r song.rra s-song.rra

playmaster:  $(SRRA)
	rrafastmixer $(SRRA) | rramaster ! rplay

master.rra :  $(SRRA)
	rrafastmixer $(SRRA) | rramaster > master.rra

master.mp3 : master.rra
	rra2mp3 master.rra

.PHONY : clean

clean :
		rm -f $(RRA) $(SRRA) master.rra mix.rra master.mp3
