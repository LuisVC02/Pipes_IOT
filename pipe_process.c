#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define LEN 50

static void parent_process(int fd)
{
	char buffer[LEN];
	
	for(;;)
	{
		fflush(stdin);	
		char * str = fgets(buffer, LEN, stdin);
		if(NULL == str || 'h' == str[0])
		{
			break;
		}

		write(fd, buffer, LEN);
	}
	int ret = wait(NULL);
}

static void child_process(int fd)
{
	char buffer[LEN];
	for(;;)
	{
		read(fd, buffer, LEN);
		printf("From Child: %s\n", buffer);
		if('h' == buffer[0])
		{
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	int fds[2];
	
	int retval = pipe(fds);

	int ret_process = fork();

	if(0 == ret_process)
	{
		child_process(fds[0]);	
	}
	else if(0 < ret_process)
	{
		parent_process(fds[1]);
	}

	return 0;
}
