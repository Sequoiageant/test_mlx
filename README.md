# test_mlx
*Simple tests to visualize how graphical mlx library works*

## Installation and uses
1. Compile using make with:
	* **no argument**: to show a simplified use of MLX which color the screen pixel by pixel (not optimized)
	* **"main=2"** as argument: to run a more optimized use of MLX which color each pixel of an image before displaying it in one time (using *mlx_new_image()*)
2. Execute the binary

ie.
```sh
$ make
$ ./test_mlx
```
or
```sh
$ make main=2
$ ./test_mlx
```