#include <stdio.h>
#include <string.h>
#include <ncurses.h>


int main(int argc, char *argv[])
{
char nombre=argv[1][0];
FILE *image;
char str[200];
int a=0;
int b;
int y=0;
int x;
int xInitial;
int yInitial;
char tableau[100][30];
char ecran[80][24];
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
if(image == NULL)
{
perror("Error opening file");
return(-1);
}

if( fgets (str, 200, image)!=NULL )
{
   if(str[0]=='P' && str[1]=='1')
    {
    fgets(str, 200, image);
    while(str[0]=='#')
    fgets(str, 200, image);
    fseek( image, 3, SEEK_SET );
fscanf(image,"%d %d", &a, &b);
    a=a*2;
    fgets(str, 200, image);

    for(y=0;y<b;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<a;x++)
        {
            if(str[x]!=' ')
            tableau[x][y]=str[x];
        }}
y=0;
x=0;
        xInitial=40-a/4;
        yInitial=12-b/2;
   system("clear");
while (y<24)
{

	while (x < 80)
	{
    ecran[x][y]='0';

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
    ecran[xInitial+x][yInitial+y]=tableau[x][y];

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

		if (ecran[x][y] == '1')
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
endwin();
fclose(image);
system("clear");
return(0);
}}
