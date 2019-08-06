.PHONY:	all
all:	print_stars print_stars2

print_stars:	print_stars_func.o print_stars_main.o all.c
	gcc -o $@ $^

print_stars2:	print_stars_func.o print_stars_main2.o
	gcc -o $@ $^
