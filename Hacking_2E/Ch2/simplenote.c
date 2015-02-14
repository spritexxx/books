#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name, char *filename)
{
	printf("Usage: %s <data to add to %s>\n", prog_name, filename);
	exit(0);
}

void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[])
{
	int fd;
	char *buffer, *datafile;
	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20);
	strcpy(datafile, "/tmp/notes");
	if(argc < 2)
		usage(argv[0], datafile);
	strcpy(buffer, argv[1]);

	printf("[debug] buffer   @ %p: \'%s\'\n", buffer, buffer);
	printf("[debug] datafile @ %p: \'%s\'\n", datafile, datafile);

	strncat(buffer, "\n", 1); //add a newline

	//open the file
	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if(fd == -1)
		fatal("in main() while opening file");

	printf("[debug] file descriptor is %d\n", fd);
	
	//write data
	if(write(fd, buffer, strlen(buffer))== -1)
		fatal("in main, while writeing");
	
	if(close(fd) == -1)
		fatal("in main, while closing");

	printf("note has been saved\n");
	free(buffer);
	free(datafile);
}

void fatal(char *msg)
{
	char err_msg[100];
	strcpy(err_msg, "[!!] Fatal Error ");
	strncat(err_msg, msg, 83);
	perror(err_msg);
	exit(-1);
}

void *ec_malloc(unsigned int size)
{
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL)
		fatal("malloc fail");
	return ptr;
}
