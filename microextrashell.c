#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char wejscie[50];
        while(1)       
	{
		int i, p;
		char kr[50];
		char uzytkownik[50];
        	char *parametr[50];
		char *komenda;
		char *gdzie;
		getcwd(kr, sizeof(kr));
		gethostname(uzytkownik, sizeof(uzytkownik));
        	printf("%s:%s>",uzytkownik, kr);
    	        fgets(wejscie, 50, stdin);
    		parametr[0] = strtok(wejscie, " \n");
    		i = 1;
    		while (parametr[i] != NULL)
    			{
        			parametr[i] = strtok(NULL," \n");
        			i = i + 1;
    			}
		komenda = parametr[0];
		gdzie = parametr[1];
		if(strcmp(komenda,"exit")==0){exit(1);}
		else if(strcmp(komenda,"cd")==0){chdir(gdzie);}
		else
		{
    			p = fork();
    			if(p == 0)
        		{execvp(parametr[0],parametr);}
    			else
    			{wait(NULL);}
		}
    	}
    		return 0;
}
