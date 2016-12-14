#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y)) //Cette ligne permet d'utiliser la fonction gotoxy par la suite


void dotLoading(int refresh) { //La fonction dotLoading s'occupe de l'affichage de l'heure et du texte de chargement
  int coordy = 40; //Il s'agit des coordonnées où devront s'afficher le premier point
  int coordx = 23; //

  system("clear"); //La console s'efface pour enlever ce qui a été affiché par le main

  time_t secondes; //Lignes de codes qui permettent d'activer une
  struct tm instant; // structure prééxistante et qui contient
  time(&secondes); //des variables avec l'heure donnée
  instant=*localtime(&secondes); //par le pc

  if (instant.tm_hour < 10 && instant.tm_min > 9 && instant.tm_sec > 9) { //Séries de if qui permet de mettre des 0 devant les chiffres, pour afficher 09 aulieu de 9 par exemple
    printf("\n\n\n\n\n\n\n\n\n\n                                  0%d:%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  } else if (instant.tm_min < 10 && instant.tm_hour > 9 && instant.tm_sec > 9) {
    printf("\n\n\n\n\n\n\n\n\n\n                                  %d:0%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  } else if (instant.tm_sec < 10 && instant.tm_min > 9 && instant.tm_hour > 9){
    printf("\n\n\n\n\n\n\n\n\n\n                                  %d:%d:0%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  } else if (instant.tm_hour < 10 && instant.tm_min < 10 && instant.tm_sec > 9) {
    printf("\n\n\n\n\n\n\n\n\n\n                                  0%d:0%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  } else if (instant.tm_min < 10 && instant.tm_sec < 10 && instant.tm_hour > 9){
    printf("\n\n\n\n\n\n\n\n\n\n                                  %d:0%d:0%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  }  else if (instant.tm_hour < 10 && instant.tm_min < 10 && instant.tm_sec < 10){
    printf("\n\n\n\n\n\n\n\n\n\n                                  0%d:0%d:0%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  } else {
    printf("\n\n\n\n\n\n\n\n\n\n                                  %d:%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\nL'heure va s'actualiser automatiquement"); //Affichage de la phrase d'actualisation
    for (size_t i = 0; i < refresh; i++) { //boucle for qui permet d'afficher un point par seconde après la phrase
      gotoxy(coordx,coordy); //et ce jusqu'à que l'heure s'actualise
      printf(".\n");
      sleep(1);
      coordy++;
    }
  coordy = 40;
  dotLoading(refresh); //une fois que la période d'actualisation est atteinte la fonction d'affichage se relance pour actualiser
  }


int main(void){
  int refresh; //Creation de la variable d'actualisation
  system("clear"); //La console s'efface, au cas où il y a eu des commandes précédentes.
  printf("Quel est le temps de refresh pour l'heure ? (en secondes)\n"); //Question à l'user
  scanf("%d", &refresh); //Reponse de l'user
  dotLoading(refresh); //On appelle la fonction dotLoading qui a pour paramètre ce qu'a répondu l'user
  return 0;
}
