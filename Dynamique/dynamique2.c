#include <stdlib.h>		//Bibliothèque fondamentales
#include <stdio.h>		//Contenant printf, scanf, ...
#include <ncurses.h>		//Bibliothèque pour quitter le processus sur commande de touches
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define LARGEUR_CONSOLE 80

int InitTime()
{
	time_t secondes; //structure prééexistante
	struct tm instant; //permettant d'avoir des variables avec l'heure donnée
	time(&secondes); //par le PC
	instant=*localtime(&secondes);
	int Seconde1 = (instant.tm_sec)/10; //Série de calculs permettant de diviser l'heure en 2 chiffres
	int Seconde2 = (instant.tm_sec)-(Seconde1*10);
	int Minute1 = (instant.tm_min)/10;
	int Minute2 = (instant.tm_min)-(Minute1*10);
	int Heure1 = (instant.tm_hour)/10;
	int Heure2 = (instant.tm_hour)-(Heure1*10);

	int Tableau[8]; //ce tableau contient chaque caractère de l'heure, dans l'ordre
	Tableau[0]=Heure1;
	Tableau[1]=Heure2;
	Tableau[2]=42;
	Tableau[3]=Minute1;
	Tableau[4]=Minute2;
	Tableau[5]=42;
	Tableau[6]=Seconde1;
	Tableau[7]=Seconde2;

	int z = 0;
	int TailleFich = 1;

	int y=12, x=9;
	FILE* fichier1 = NULL;     		//Initialisation de pointeur
	char chaine[1000];         //On donne la taille maximum du fichier
	int chaine2[2];
        int i=0, j=0;				//Deux nouvelles variables qui serviront pour les boucles de lecture de fichier
        int n,m;						//Variables servant pour le parcout des lignes du PBM

	fichier1 = (FILE*)malloc(sizeof(int));	//Allocation de mémoire au pointeur fichier1

	for (z=0;z<8;z++) //Boucle qui va parcourir tout le tableau contenant l'heure
	{
		switch (Tableau[z]) //Switch parcourant tout le tableau contenant l'heure

		{
			case 0: //IL EST IMPORTANT DE PLACER LES FICHIERS DU PROGRAMME DANS UN ENDROIT GERE PAR LE $PATH, OU ALORS DE LE MODIFIER AVEC "export PATH=$PATH:/home/user/mes_prog" par exemple
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/0.pbm", "r"); //la console ouvre un fichier en fonction de l'heure dans le tableau
				break;
			case 1:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/1.pbm", "r");
				break;
			case 2:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/2.pbm", "r");
				break;
			case 3:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/3.pbm", "r");
				break;
			case 4:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/4.pbm", "r");
				break;
			case 5:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/5.pbm", "r");
				break;
			case 6:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/6.pbm", "r");
				break;
			case 7:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/7.pbm", "r");
				break;
			case 8:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/8.pbm", "r");
				break;
			case 9:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/9.pbm", "r");
				break;
			case 42:
				fichier1 = fopen("$PATH/EXIASAVER_HOMER/EXIASAVER2_PBM/doublepoints.pbm", "r");
				break;
		}

//Partie concernant l'affichage de l'image

 		if (fichier1 != NULL) 							//Permet de lire le fichier
        	    {
        	        fseek(fichier1, 3, SEEK_SET);
        	        fscanf(fichier1, "%d %d", &chaine2[0], &chaine2[1]);
        	        n = chaine2[0];
        	        m = chaine2[1];
        	        n = (n*2)-1;

			fseek(fichier1, 1, SEEK_CUR);
        	      	for(i=0; i<m; i++)                   			//Cette boucle va parcourir les lignes du pbm
        	            {
				gotoxy(x,y);
				fgets(chaine, 1000, fichier1);		//On récupère la ligne du pbm
        	                for(j=0; j<n; j++)               		//Cette boucle va parcourir ladite ligne
        	                    {
					gotoxy(x,y);
					if (chaine[j] == '0')
        	                            chaine[j] = ' ';        		//On définit qu'un 0 affiche un espace
        	       			else if (chaine[j] == '1')
        	                            	chaine[j] = '@'; //On définit qu'un 1 affiche un @
        	                    }
				x=x+1;
				printf("%s", chaine);				//L'image est ensuite affiché ligne par ligne
        	            }
				fclose(fichier1);   				//Le fichier ouvert est fermée, très important
				fichier1 = NULL;
				free(fichier1);					//La mémoire allouée est libérée
        	    }
		x=x-5;
		y=y+7;
	}

}

int dotLoading(int refresh)
{
	system("clear");
	int i = 0;
	int coordy = 40; //Il s'agit des coordonnées où devront s'afficher le premier point
	int coordx = 23;
	gotoxy(20,30);
	InitTime();
	gotoxy(23,0);
	printf("L'heure va s'actualiser automatiquement");
	for (size_t i = 0; i < refresh; i++) { //boucle for qui permet d'afficher un point par seconde après la phrase
		gotoxy(coordx,coordy); //et ce jusqu'à que l'heure s'actualise
		printf(".\n");
		sleep(1);
		coordy++;
	}
coordy = 40;
dotLoading(refresh); //une fois que la période d'actualisation est atteinte la fonction d'affichage se relance pour actualiser
return 0;
}

int main()
{

	int refresh;				//Temps en seconde avant actualisation
	system("clear");				//Nettoiement de la console
	printf("Veuillez rentrer le temps de réactualisation de l'heure ? (en secondes)\n"); //Question à l'user
	scanf("%d", &refresh);
	system("clear");
	dotLoading(refresh);
	return 0;
}
