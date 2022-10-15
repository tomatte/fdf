#!/bin/bash
gcc $1 ./minilibx-linux/libmlx_Linux.a -L. -lXext -L. -lX11
