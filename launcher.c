#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bibliothèque pour le Rand
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "launcher.h"


int main(int argc, char** argv)
{

    if(argv[1] != NULL)
    {
    system("clear"); //Permet de vider la console au démarrage du mode stat
	    
    int nombre;
	    
    printf("            ------            Menu Statistique            ------\n\n");
    printf("Bienvenue dans le mode statistique\n\n");
    printf("Choissisez un mode de tri pour afficher l'historique parmis les choix disponible\n\n");
    printf("1.Trier par Dates\n");
    printf("2.Trier par Types\n");
    printf("3.Trier par Paramètres\n");

    scanf("%d", &nombre);

        switch (nombre)
        {
          case 1:
	    printf("-----  MENU 1  -----");
          break;
          case 2:
            printf("-----  MENU 2  -----");
          break;
          case 3:
            printf("-----  MENU 3  -----");
          break;
        }

    return 0;
    }

    system("clear"); // Permet de vider la console
    /*--------Nombre Random--------*/
    srand (time(NULL));
    int choix=rand()%3+1; // Permet de choisir un screensaver de manière aléatoire

    int ch_image;
    ch_image = rand()%5+1; // Permet de choisir un nombre entre 1 et 5 pour les images statiques.


    /*--------Condition en fonction du mode choisis--------*/
    if (choix == 1) // Permet de lancer le mode statique
    {
      printf("Lancement du type statique ! \n");

		if(ch_image == 1) //Permet de choisir l'image pbm 1 dans le fichier EXIASAVER1_PBM
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/1.pbm",NULL);
		}
		if(ch_image == 2) //Permet de choisir l'image pbm 2 dans le fichier EXIASAVER1_PBM
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/2.pbm",NULL);
		}
		if(ch_image == 3) //Permet de choisir l'image pbm 3 dans le fichier EXIASAVER1_PBM
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/3.pbm",NULL);
		}
		if(ch_image == 4) //Permet de choisir l'image pbm 4 dans le fichier EXIASAVER1_PBM
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/4.pbm",NULL);
		}
		if(ch_image == 5) //Permet de choisir l'image pbm 5 dans le fichier EXIASAVER1_PBM
		{
		execl ("Statique/statique","statique/statique","EXIASAVER1_PBM/5.pbm",NULL);
		}
    }


    else if (choix == 2) // Permet de lancer le screensaver dynamique
    {
      printf("Lancement du type dynamique ! \n");
      /*Permet d'exécuter le programme du dynamique qui se trouve dans le répertoire
      dynamique.*/
	  execl ("Dynamique/dynamique2","Dynamique/dynamique2","",NULL);
    }
    else if (choix == 3) // Permet de lancer le screensaver intéractif
    {
      printf("Lancement du type intéractif ! \n");
    }
sauvegarde(choix,ch_image); /*Permet de garder en mémoire les variables
choix, ainsi que ch_image grâce à la bibliothèque launcher.h pour nous permettre
de les utiliser dans la prochaine fonction.*/

return 0;

}

void sauvegarde(int fichier, int image) /* Fais appelle à la fonction se trouvant dans la
bibliothèque launcher.h .Pour nous permettre de récupérer les informations du choix de l'écran
mais aussi de récuperer l'image qui a été choisis pour le mode statique.
*/
{
  FILE* historique = NULL; // Initialise le pointeur à NULL
  historique = fopen("historique.txt", "r+"); // Ouvre le fichier historique.txt qui peut lire et écrire.

  if (historique != NULL) // Permet de vérifier que le fichier soit bien ouvert.
  {
    /*--------Récupération de la date et de l'heure--------*/

    // Lire l'heure courante
    time_t Date;
    Date = time(NULL);
    // Conversion de l'heure en locale
    struct tm tm_Date = *localtime (&Date);
    // Créer une chaine JJ/MM/AAAA HH:MM:SS
    char s_Date[sizeof "JJ/MM/AAAA HH:MM:SS"];
    strftime (s_Date, sizeof s_Date, "%d/%m/%Y %H:%M:%S", &tm_Date);

    //Permet d'écrire la date dans le bon format dans l'historique

    /*
    Permet d'écrire les informations concernant le mode statique directement dans le fichier historique en reprenant
    les informations dans la fonction main. Cela permet d'écrire la date , le type d'écran
    qui a été choisis , ainsi que le nom du fichier pour les images pbm pour le mode statique.
    */
    if (fichier == 1)
   {
     switch(image)
     {
       case 1:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/1.pbm\n",s_Date,fichier);
       break;
       case 2:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/2.pbm\n",s_Date,fichier);
       break;
       case 3:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/3.pbm\n",s_Date,fichier);
       break;
       case 4:
         fseek(historique, 0, SEEK_END);
         fprintf(historique, "%s;%d;EXIASAVER1_PBM/4.pbm\n",s_Date,fichier);
       break;
     }
   }
   // Permet d'écrire la date , le type d'écran qui a été choisis pour le mode dynamique.
   else if (fichier == 2)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d\n",s_Date,fichier);
   }
   // Permet d'écrire la date ainsi que le type d'écran qui a été choisis pour le mode intéractif.
   else if (fichier == 3)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d\n",s_Date,fichier);
   }

  }
  return;
}
