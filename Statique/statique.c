#include <stdio.h>
#include <string.h> // Bibliothéques de gestion de chaînes de caractères
#include <ncurses.h> // Bbilothéques pour éviter d'appuyer sur espace avec getchar()
#include <stdlib.h>


int main(int argc, char *argv[])
{
char nombre=argv[1][0];
FILE *image; // Pointeur vers image
char str[200];
int a=0;
int b;
int y=0;
int x;
int xInitial;
int yInitial;
char tableau[100][30];
char ecran[80][24];
    image = fopen(argv[1],"r");

if(image == NULL) // message d'erreur si l'image n'existe pas
{
perror("Error opening file");
return(-1);
}

if( fgets (str, 200, image)!=NULL ) // On vérifie si la première ligne n'est pas rien du tous
{
   if(str[0]=='P' && str[1]=='1') // On vérifie le nombre magique pour être sur du format
    {
    fgets(str, 200, image);
    while(str[0]=='#') // On ignore les commentaires c'est à dire les lignes commencant par #
    fgets(str, 200, image);
    fseek( image, 3, SEEK_SET );
fscanf(image,"%d %d", &a, &b); // On lit les valeurs a et b qui sont la largeur et la hauteur de l'image
    a=a*2;
    fgets(str, 200, image);

    for(y=0;y<b;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<a;x++)
        {
            if(str[x]!=' ')  // pour chaque ligne (y) on met dans notre tableau toutes valeurs importants
            tableau[x][y]=str[x]; // C'est à dire pas les ' '
        }}
y=0;
x=0;
        xInitial=40-a/4; // Endroit auquel on doit commencer à écrire l'image sur l'écran [x][y] pour qu'elle puisse être centrée
        yInitial=12-b/2;
   system("clear"); // Vider le Shell
while (y<24)
{

	while (x < 80)
	{
    ecran[x][y]='0'; // on remplit l'écran de 0

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
while (y<b)
{

	while (x < a)
	{
    ecran[xInitial+x][yInitial+y]=tableau[x][y]; // On donne les valeurs de l'image au centre de l'écran

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
while (y < 24)
{

	while (x < 80)
	{

		if (ecran[x][y] == '1') // On affiche l'écran pour les valeurs 1 on les remplace par X
		{
        printf ("X");
		}

		if (ecran[x][y] == '0') // Pour les valeurs 0 on les remplace par des espace vide.
		{
		printf(" ");
		}

	x++;

	}
    printf("\n");
y++;
x=0;
}}
else
printf("Ce n'est pas le bon format, vérifiez qu'il s'agit bien d'un .pbm avec le nombre magique P1");
}

initscr();
cbreak(); 
noecho();
char c= getchar();
if(c!='\0')
{
endwin(); // On finis le programme seulement quand on appuit sur une touche du clavier
fclose(image);
system("clear");
return(0);
}}
