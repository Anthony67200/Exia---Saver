#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int affichage(void)
{
    time_t secondes;
    struct tm instant;

    time(&secondes);
    instant=*localtime(&secondes);

    printf("%d:%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  }

int main(void){

  int refresh = 0;
  int point = 0;
  int actualisation = 0;
  system("clear");
  printf("Quel est le temps de refresh pour l'heure ? (en secondes)\n");
  scanf("%d", &refresh);
  system("clear");
  affichage();
  while(1){
    if (actualisation >= refresh) {
      system("clear");
      affichage();
      printf("\n\n\nL'heure va s'actualiser automatiquement");
      actualisation = 0;
    }
      while(1){
        sleep(1);
        printf("\n.");
        point++;
        actualisation++;
      if(point == refresh){
        point = 0;
        break;
      }
    }
  }
  return 0;
}
