#Makefile
CC=gcc
CFLAGS=-I/usr/local/lua/include/ -L/usr/local/lua/lib/ -llua

mytestlib: mytestlib.cpp
	$(CC) -Wall -shared -fPIC -o mytestlib.so $(CFLAGS) mytestlib.cpp
clean: mytestlib
	rm -f mytestlib.so
