# GD HAL for HAGL

This is a [GD](https://libgd.github.io/) HAL for the lightweight hardware agnostic graphics library [HAGL](https://github.com/tuupola/hagl). This repository serves as an example on how to create a simple HAL.


[![Software License](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square)](LICENSE.md)

# Demo

```
$ git clone git@github.com:tuupola/hagl.git
$ git clone git@github.com:tuupola/hagl_gd.git
$ cd hagl_gd/example
$ make clean && make mandelbroot && ./mandelbroot && open hagl.png
$ make clean && make palette && ./palette && open hagl.png
```

## License

The MIT License (MIT). Please see [License File](LICENSE.txt) for more information.
