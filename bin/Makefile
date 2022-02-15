CPP = g++

bloom_filter: demo_main.o bloom_filter.o hash_function.o
	$(CPP) -o bloom_filter demo_main.o bloom_filter.o hash_function.o

demo_main.o:demo_main.cpp
	$(CPP) -c demo_main.cpp

bloom_filter.o:../src/bloom_filter.cpp
	$(CPP) -c ../src/bloom_filter.cpp

hash_function.o:../src/hash_function.cpp
	$(CPP) -c ../src/hash_function.cpp

clean:
	rm -f *.o bloom_filter