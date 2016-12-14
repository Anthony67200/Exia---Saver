#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))


void dotLoading(int refresh) {
  int point = 0;
  int coordy = 40;
  int coordx = 23;
  system("clear");
  time_t secondes;
  struct tm instant;

  time(&secondes);
  instant=*localtime(&secondes);

  printf("\n\n\n\n\n\n\n\n\n\n                                  %d:%d:%d", instant.tm_hour, instant.tm_min, instant.tm_sec);
  printf("\n\n\n\n\n\n\n\n\n\n\n\nL'heure va s'actualiser automatiquement");
  printf("          \n");
    for (size_t i = 0; i < refresh; i++) {
      gotoxy(coordx,coordy);
      printf(".\n");
      sleep(1);
      coordy++;
    }
  coordy = 40;
  dotLoading(refresh);
  }


int main(void){
  int refresh;
  system("clear");
  printf("Quel est le temps de refresh pour l'heure ? (en secondes)\n");
  scanf("%d", &refresh);
  dotLoading(refresh);
  return 0;
}
