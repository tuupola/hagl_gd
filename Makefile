all: mandelbroot.c
	gcc -o mandelbroot mandelbroot.c hagl_hal.c ../hagl/src/hagl.c ../hagl/src/rgb565.c ../hagl/src/fontx2.c ../hagl/src/clip.c ../hagl/src/bitmap.c ../hagl/src/tjpgd.c -I. -I../hagl/include -lgd -lpng -lz -ljpeg -lfreetype -lm -DNO_MENUCONFIG

clean:
	$(RM) *.o
	$(RM) test
