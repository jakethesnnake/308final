//  login.c
//  Authentication, initialization, encryption and file I/O

#include <stdlib.h>
#include "login.h"

// Parses
Account read_one_account(char * line)
{
	Account a;
	if(line == NULL) return a;
	const char delim[2] = "~";
	char * token = strtok(line, delim);
	a.username = token;
	token = strtok(NULL, delim);
	a.password = token;
	return a;
}

// Evaluates equality iteratively through file
Account tryLogin(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "r");
	Account AccArr[100];
	char line[10000];
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		if(strcmp(uname,AccArr[i].username) == 0 && strcmp(psw,AccArr[i].password) == 0) 
		{
			fclose(reader);
			return AccArr[i];
		}
	}
	fclose(reader);
	Account a;
	return a;
}

// May creates account upon successful equality testing (referential)
Account tryCreateAccount(char * uname, char * psw)
{
	FILE * reader = fopen("AllLoginData.txt", "w");
	Account AccArr[100];
	Account a;
	char line[10000];
	for(int i = 0; fscanf(reader, "%s\n", line) != EOF; i++)
	{
		AccArr[i] = read_one_account(line);
		if(strcmp(uname,AccArr[i].username) == 0) 
		{
			fclose(reader);
			return a;
		}
	}
	Account a;
	a.username = uname;
	a.password = psw;
	fprintf("%s~%s", uname, psw);
	fclose(reader);
	return a;
}

void encrypt_one_password(char * psw)
{
	
}

void decrypt_one_password(char * psw)
{
	
}
