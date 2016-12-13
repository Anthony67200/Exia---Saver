#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fonction ()
{
  int random;
  srand (time(NULL));
  random = rand()%3;
  random = random +1;
  printf("%d\n", random);
}


void date ()
{
  // Lire l'heure courante
	time_t now = time (NULL);
	// Conversion de l'heure en locale
	struct tm tm_now = *localtime (&now);
	// Créer une chaine JJ/MM/AAAA HH:MM:SS
	char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
	strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
}


void type ()
{
  printf("test");
}


void historique ()
{

  FILE* fichier = NULL;
	fichier = fopen("historique.txt", "ar+");

  if (fichier != NULL){
		fprintf(fichier, "%d\n",random);
		fclose(fichier); // On ferme le fichier qui a été ouvert
	}
	else {
		// On affiche un message d'erreur si on veut
		printf("Impossible d'ouvrir le fichier .txt");
	}

}
