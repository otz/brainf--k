#include <stdio.h>
#define TAPESIZE 30000
static char tape[TAPESIZE];
static char data[TAPESIZE];

char *backward(char *p)
{
	if (*p == ']')
		while (*--p != '[')
			if (*p == ']')
				p = backward(p);
	return p;
}

char * forward(char *p)
{
	if (*p == '[')
		while (*++p != ']')
			if (*p == '[')
				p = forward(p);
	return p;
}

int bf()
{
	char *p = tape;
	char *d = data;
	while ( d < data + sizeof(data) )
		*(d++) = 0;
	d = data + sizeof(data) / 2;
	while ( p < tape + sizeof(tape) && *p) {
		switch (*p) {
			case ',': *d=getchar(); break;
			case '.': putchar(*d); break;
			case '+': (*d)++; break;
			case '-': (*d)--; break;
			case '<': d--; break;
			case '>': d++; break;
			case '[': if (!(*d)) p = forward(p); break;
			case ']': if (*d) p = backward(p); break;
			default:
				break;
		}
		p++;
	}
}

int main(int argc, char **argv)
{
	int c;
	char *p = tape;
	FILE *ftape = fopen(argv[1], "r");
	while (EOF != (c = fgetc(ftape)))
		*p++ = c;
	*p = 0;
	fclose(ftape);
	return bf();
}

