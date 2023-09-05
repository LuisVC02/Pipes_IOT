#include <stdio.h>
#include <unistd.h>

#define LEN 50

int main(int argc, char *argv[])
{
	int fds[2];
	char buffer[LEN];
	char out[LEN];
	int retval = pipe(fds);
	char * str = fgets(buffer, LEN, stdin);

	write(fds[1], buffer, LEN);
	read(fds[0], out, LEN);
	printf("%s\n", out);
	return 0;
}
