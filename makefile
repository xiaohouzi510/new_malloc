all : new_malloc

new_malloc : new_malloc.cpp
	g++ -g -o $@ $^

clean :
	rm -rf new_malloc *~
