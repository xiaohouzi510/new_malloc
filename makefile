all : new_malloc

new_malloc : new_malloc.cpp jemalloc/lib/libjemalloc_pic.a
	g++ -g -o $@ $^ -Ijemalloc/include/jemalloc -Ljemalloc/lib -lpthread -ldl -lrt

clean :
	rm -rf new_malloc *~
