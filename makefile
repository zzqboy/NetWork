main: main.cc server.o
	g++ -o main main.cc	server.o

server.o:server.h server.cc
	g++ -c -o server.o server.cc
