#include <stdio.h>
#include <string.h> //bibliothèque de gestion des chaînes de caractère
#include <ncurses.h> //bibliothèque pour éviter d'appuyer sur espace avec getchar()
#include <stdlib.h>


int main(int argc, char *argv[])
{
char nombre=argv[1][0];
FILE *image; //pointeur vers l'image
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
    /*
    switch(nombre){
    case '1':
    image = fopen("1.pbm" , "r");
    break;
    case '2':
    image = fopen("2.pbm" , "r");
    break;
    case '3':
    image = fopen("3.pbm" , "r");
    break;
    case '4':
    image = fopen("4.pbm" , "r");
    break;
    case '5':
    image = fopen("5.pbm" , "r");
    break;}
    */
if(image == NULL) //messsage d'erreur si l'image n'existe pas
{
perror("Error opening file");
return(-1);
}

if( fgets (str, 200, image)!=NULL )  //on vérifie si la première ligne n'est pas rien du tout
{
   if(str[0]=='P' && str[1]=='1') //on vérifie le nombre magique pour être sur du format
    {
    fgets(str, 200, image);
    while(str[0]=='#')  //on ignore les commentaires, c a dire les lignes commencant par #
    fgets(str, 200, image);
    fseek( image, 3, SEEK_SET );
fscanf(image,"%d %d", &a, &b); //on lit les valeurs a et b qui sont la hauteur et la largeur de l'image
    a=a*2;
    fgets(str, 200, image);

    for(y=0;y<b;y++)
    {
    fgets(str, 200, image); 
        for(x=0;x<a;x++)
        {
            if(str[x]!=' ')          //pour chaque ligne (y) on mets dans notre tableau toutes les valeurs importants
            tableau[x][y]=str[x];    //c a dire pas les ' ' 
        }}
y=0;
x=0;
        xInitial=40-a/4;   //Endroit auquel on doit commencer à écrire l'image sur ecran[x][y] pour
        yInitial=12-b/2;   //quelle soit centrée
   system("clear");     //vider le shell
while (y<24)
{

	while (x < 80)
	{
    ecran[x][y]='0';  //on remplie écran de 0

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
    ecran[xInitial+x][yInitial+y]=tableau[x][y];   //on donne les valeurs de image au centre de écran

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

		if (ecran[x][y] == '1')   //on affiche écran
		{
        printf ("X");
		}

		if (ecran[x][y] == '0')
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
endwin();		//on finis le programme uniquement quand on appuie sur une touche
fclose(image);		//C à dire quand c est différent de rien
system("clear");
return(0);
}}
