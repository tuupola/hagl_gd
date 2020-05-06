CC = gcc
CFLAGS = -Wall -I../ -I../../hagl/include -DNO_MENUCONFIG
GDFLAGS = -lgd -lpng -lz -ljpeg -lfreetype -lm

src = $(wildcard *.c) \
      $(wildcard ../*.c) \
      $(wildcard ../../hagl/src/*.c)

obj = $(src:.c=.o)

mandelbroot: $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(GDFLAGS)


.PHONY: clean
clean:
	rm -f $(obj) mandelbroot hagl.png
