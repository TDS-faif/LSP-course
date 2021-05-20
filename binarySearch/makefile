bin_search: bin_search.o
	gcc -o bin_search bin_search.o
	
bin_search.o: bin_search.c
	gcc -c bin_search.c
	
bin_search_with_realloc: bin_search_with_realloc.o
	gcc -o bin_search_with_realloc bin_search_with_realloc.o
	
bin_search_with_realloc.o: bin_search_with_realloc.c
	gcc -c bin_search_with_realloc.c
	
bin_search_bad_realloc: bin_search_bad_realloc.o
	gcc -o bin_search_bad_realloc bin_search_bad_realloc.o
	
bin_search_bad_realloc.o: bin_search_bad_realloc.c
	gcc -c bin_search_bad_realloc.c

clean:
	rm *.o
