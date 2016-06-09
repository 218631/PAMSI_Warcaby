CPPFLAGS= -c -g -Iinc -std=c++11

__start__: prog
	./prog

prog: obj/main.o obj/warcaby.o
	g++ -o prog obj/main.o obj/warcaby.o

obj/main.o: src/main.cpp inc/warcaby.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/warcaby.o: src/warcaby.cpp inc/warcaby.hh
	g++ ${CPPFLAGS} -o obj/warcaby.o src/warcaby.cpp

clean:
	rm -f obj/*.o prog

