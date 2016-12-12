#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fichier = NULL;
	int c;

	fichier = fopen("ex1.pbm", "r");
	if (fichier == NULL) perror ("Erreur ouverture fichier");
	fseek(fichier,38,SEEK_CUR);
		
		system ("clear");

		while(1) {
		c = fgetc(fichier);
		if (c == EOF)
		{
		break;
		}
		printf("%c",c);

		}

		fclose(fichier);
      
    return 0;
}
