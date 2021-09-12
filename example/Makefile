CC = gcc
GDFLAGS = -lgd -lpng -lz -ljpeg -lfreetype -lm
mandelbroot: CFLAGS = -Wall -I../ -I../../hagl/include
palette: CFLAGS = -Wall -I../ -I../../hagl/include -DDISPLAY_WIDTH=4080 -DDISPLAY_HEIGHT=4080

PALETTEFLAGS =

src = $(wildcard ../*.c) \
      $(wildcard ../../hagl/src/*.c)

obj = $(src:.c=.o)

all: palette mandelbroot

mandelbroot: mandelbroot.c $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)

palette: palette.c $(obj)
	$(CC) $(PALETTEFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)


.PHONY: clean
clean:
	rm -f $(obj) mandelbroot palette *.png *.o
