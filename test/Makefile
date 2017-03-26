.PHONY:	all clean

all: hw_test.elf

clean:
	rm -vf *.o *.elf

%.elf: %.o
	$(CC) $(LDLIBS) -o $@ $<

LDLIBS=`sdl2-config --cflags --static-libs` -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_net
.PRECIOUS: %.o
