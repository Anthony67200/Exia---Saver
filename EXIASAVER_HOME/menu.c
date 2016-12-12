#include <stdio.h>
#include <time.h> // Bibliothèque pour le Rand
#include <stdlib.h>
 
int affichageMenu(void) /* pas d'entree donc void */
{
    int choixMenu; /* il manquait un point virgule */
 
    printf("---Menu---\n\n");
    printf("1.Date\n");
    printf("2.Type\n");
    printf("3.Tailles utilisés\n");
    printf("\nVotre choix?\n\n");
    scanf("%d", &choixMenu);
    return choixMenu; /* c'est ici qu'on retourne une valeur*/

}

int main(void)
{

    switch (affichageMenu()) 
    {
    case 1:
        printf("Les dates de lancement des fichiers\n");
		
        break;
    case 2:
        printf("Voilà les derniers modes utilisés\n");
        break;
    case 3:
        printf("La taillé utilisé sur le système");
        break;
	 default:
        printf("Vous ne ferez rien du tout!");
        break;
    }
    return 0;
}

