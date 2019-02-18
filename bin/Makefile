compiler = gcc
flgs = -g -Wall

target = slib_test
objects = obj/test.o obj/hashtable.o obj/array.o obj/string_utils.o

$(target): $(objects)
	$(compiler) $(flgs) -o $(target) $(objects)

obj/test.o: ../src/test.c
	$(compiler) $(flgs) -c ../src/test.c -o obj/test.o

obj/hashtable.o: ../src/hashtable.c ../src/hashtable.h
	$(compiler) $(flgs) -c ../src/hashtable.c -o obj/hashtable.o

obj/array.o: ../src/array.c ../src/array.h
	$(compiler) $(flgs) -c ../src/array.c -o obj/array.o

obj/string_utils.o: ../src/string_utils.c ../src/string_utils.h
	$(compiler) $(flgs) -c ../src/string_utils.c -o obj/string_utils.o
