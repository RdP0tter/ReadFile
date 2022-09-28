all:
	gcc -Wall -o readfile readfile.c -L./lib -ltestrf -lrsrc

clean:
	rm -f readfile
