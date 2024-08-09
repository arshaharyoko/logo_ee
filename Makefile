CC=gcc
LDFLAGS=`pkg-config --libs glew glfw3`

main: main.c
	$(CC) main.c -o main $(LDFLAGS) -lm