all:
	gcc a1q1.c -o q1
	gcc a1q2a.c -o q2a
	gcc a1q2b.c -o q2b
	gcc a1q3.c -o q3

	mkdir bin
	mv q1 bin/
	mv q2a bin/
	mv q2b bin/
	mv q3 bin/

	cd bin && mkdir Question1 && mv q1 Question1
	cd bin && mkdir Question2 && mv q2* Question2
	cd bin && mkdir Question3 && mv q3 Question3

