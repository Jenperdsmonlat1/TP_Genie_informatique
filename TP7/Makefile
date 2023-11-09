
outils: outils.c
	gcc outils.c -Wall -W -std=c99 -I. -c -o outils.o
	ar cr liboutils.a outils.o

test: test.c
	gcc test.c -o test -Wall -std=c99 -loutils -L. -O3

tri: tri.c
	gcc tri.c -o tri -Wall -std=c99 -O3 -loutils -L. -O3

clean:

	rm -rf test
	rm -rf tri
	rm -rf outils.o
	rm -rf liboutils.a
