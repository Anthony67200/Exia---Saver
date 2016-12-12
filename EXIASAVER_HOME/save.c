#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bibliothèque pour le Rand

int Random (int min, int max)
{
return(min + (rand ()% (max-min+1)));
}


int main(int argc, char** argv) {  

	system ("clear");

	// Lire l'heure courante
	time_t now = time (NULL);

	// Conversion de l'heure en locale
	struct tm tm_now = *localtime (&now);
	
	// Créer une chaine JJ/MM/AAAA HH:MM:SS
	char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
	strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

	
	int random;{// Système de mode aléatoire
	
		srand (time(NULL));
		random = Random (1,3);
	}
	// Condition en fonction du mode de mise en veille

	if (random == 1){
	
		printf("Mode Statique\n");

	}
	else if (random == 2){

		printf("Mode Dynamique\n");
	}
	else{
		printf("Mode Interactif\n");
	}
  
	FILE* fichier = NULL;

	fichier = fopen("historique.txt", "ar+");

	if (fichier != NULL){

		fprintf(fichier, "%s;%d;\n",s_now,random);
		fclose(fichier); // On ferme le fichier qui a été ouvert
	}

	else {
		// On affiche un message d'erreur si on veut
		printf("Impossible d'ouvrir le fichier test.txt");
	}
    return 0;
}


