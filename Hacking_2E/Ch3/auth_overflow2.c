#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_auth(char *pwd)
{
	char pwd_buf[16];
	int auth_flag = 0;

	strcpy(pwd_buf, pwd);

	if(strcmp(pwd_buf, "brilling") == 0)
		auth_flag = 1;
	
	if(strcmp(pwd_buf, "outgrabe") == 0)
		auth_flag = 1;

	return auth_flag;
}

int main(int argc, char *argv[]) 
{
	if(argc < 2) {
		printf("usage: %s <password>\n", argv[0]);
		exit(0);
	}
	printf("Hello peasant, welcome to the portal!\n");

	if(check_auth(argv[1]))
		printf("Congratz, you are in dawg\n");
	else
		printf("Err, you gon have to try again...\n");
}
