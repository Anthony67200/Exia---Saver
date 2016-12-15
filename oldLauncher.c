#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Bibliothèque pour le Rand
#include <sys/stat.h>
#include "launcher.h"

int main(int argc, char** argv)
{

    if(argv[1] != NULL)
    {
    system("clear");
    int nombre;
    printf("            ------            Menu Statistique            ------\n\n");
    printf("1.Trier par Date\n");
    printf("2.Trier par Type\n");
    printf("3.Trier par Extension\n");

    printf("Choissisez le menu que vous souhaitez afficher\n");

    scanf("%d", &nombre);

        switch (nombre)
        {
          case 1:
          {
printf("");
FILE *historique = NULL;
historique = fopen("historique.txt", "r");
char *line=malloc(512*sizeof(char));
int k=fscanf(historique, "#%s\n", line);

printf("%s", line);
          }


/*
int type;
char date[21], image[20];



          printf("");
            FILE* stat = NULL;
            int caractere = 0;
            stat = fopen("historique.txt", "r");
            if (stat != NULL)
            {
              do
              {
                caractere = fgetc(stat);
                printf("%c", caractere);
              } while (caractere != EOF);
              fclose(stat);
            }*/
          break;
          case 2:
            printf("MENU 2");
          break;
          case 3:
            printf("MENU 3");
          break;
        }

    return 0;
    }

    system("clear"); // Permet de nettoyer la console
/*char *getenv(const char *name)*/
printf("HOME : %s\n", getenv("HOME"));
printf("PATH : %s\n", getenv("PATH"));
printf("ROOT : %s\n", getenv("ROOT"));





    /*--------Nombre Random--------*/
    srand (time(NULL));
    int choix=rand()%3+1;

    printf("%d", choix);

    int ch_image;
    ch_image = rand()%4+1;

    /*--------Condition en fonction du mode choisis--------*/

    /*
ouvrir
lister
choisir aléa
executer exec avec argument))
*/

    if (choix == 1)
    {



      printf("Lancement du type statique ! \n");



      switch (ch_image)
      {
        case 1:
        printf("");
          FILE* fichier = NULL;
          int caractereActuel = 0;
          fichier = fopen("EXIASAVER1_PBM/1.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel = fgetc(fichier);
              printf("%c", caractereActuel);
            } while (caractereActuel != EOF);
            fclose(fichier);
          }
        break;
        case 2:
        printf("");
          FILE* fichier2 = NULL;
          int caractereActuel2 = 0;
          fichier2 = fopen("EXIASAVER1_PBM/2.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel2 = fgetc(fichier2);
              printf("%c", caractereActuel2);
            } while (caractereActuel2 != EOF);
            fclose(fichier2);
          }
        break;
        case 3:
        printf("");
          FILE* fichier3 = NULL;
          int caractereActuel3 = 0;
          fichier3 = fopen("EXIASAVER1_PBM/3.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel3 = fgetc(fichier3);
              printf("%c", caractereActuel3);
            } while (caractereActuel3 != EOF);
            fclose(fichier3);
          }
        break;
        case 4:
        printf("");
          FILE* fichier4 = NULL;
          int caractereActuel4 = 0;
          fichier4 = fopen("EXIASAVER1_PBM/4.pbm", "r");
          if (fichier != NULL)
          {
            do
            {
              caractereActuel4 = fgetc(fichier4);
              printf("%c", caractereActuel4);
            } while (caractereActuel4 != EOF);
            fclose(fichier4);
          }
        break;
      }
    }
    else if (choix == 2)
    {
      printf("Lancement du type dynamique ! \n");
    }
    else if (choix == 3)
    {
      printf("Lancement du type intéractif ! \n");
    }
sauvegarde(choix,ch_image);

return 0;

}

void sauvegarde(int fichier, int image)
{
  FILE* historique = NULL; // Initialise le pointeur à NULL
  historique = fopen("historique.txt", "r+"); // Ouvre le fichier historique

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

    /*Permet d'écrire la date dans le bon format dans l'historique
    fseek 25 permet d'éviter de lire les 25 premiers caractères*/

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
   else if (fichier == 2)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d\n",s_Date,fichier);
   }
   else if (fichier == 3)
   {
     fseek(historique,0, SEEK_END);
     fprintf(historique, "%s;%d\n",s_Date,fichier);
   }

  }
  return 0;
}
