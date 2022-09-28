all:
	gcc -c -Wall -Werror -fPIC testrf.c rsrc.c
	gcc -shared -o libtestrf.so testrf.o
	gcc -shared -o librsrc.so rsrc.o

clean:
	rm -f libtestrf.so librsrc.so testrf.o rsrc.o

install:
	install -m 0644 libtestrf.so /usr/lib/libtestrf.so
	install -m 0644 librsrc.so /usr/lib/librsrc.so

uninstall:
	rm -f /usr/lib/libtestrf.so /usr/lib/librsrc.so
