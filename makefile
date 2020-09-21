hotelFinder: main.cpp myfunctions.o 
	g++ -o $@ main.cpp myfunctions.o
myfunctions.o: header.h myfunctions.h myfunctions.cpp
	g++ -c myfunctions.cpp -o $@
clean:
	rm hotelFinder
	rm *.o