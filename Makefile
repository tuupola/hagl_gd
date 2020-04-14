all: mandelbroot.c
	gcc -o mandelbroot mandelbroot.c copepod_hal.c ../copepod/copepod.c ../copepod/rgb565.c ../copepod/clip.c ../copepod/bitmap.c -I. -I../copepod -lgd -lpng -lz -ljpeg -lfreetype -lm

clean:
	$(RM) *.o
	$(RM) test
