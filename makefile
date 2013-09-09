all : bf.out

bf.out : bf.c
	cc -o bf.out bf.c

clean : 
	rm bf.out

test : bf.out
	test -x ./bf.out && ./bf.out helloworld.bf | ./bf.out rot13.bf
