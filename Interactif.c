#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main()
{
char str[20];
int x=0;
int y=0;
char ecran[80][24];
char avion[6][6];
int positionX=37;
int positionY=19;
FILE *image;
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
    initscr();
    cbreak();

    char c=getchar();
    printf("%c", c);
if(c!='\0'){
printf("X");
switch(c){
case 'z':
image = fopen("H.pbm" , "r");
fgets(str, 20, image);
fgets(str, 20, image);
for(y=0;y<6;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<13;x++)
        {
            if(str[x]!=' ')
            avion[x][y]=str[x];
        }}

y=0;
x=0;
while(c!='\0'){
for(y=0;y<24;y++)
{
    for(x=0;x<80;x++)
    {
    if (ecran[x][y] == '1')
    ecran[x][y-1]=ecran[x][y];
    positionY--;
    }
}
y=0;
x=0;
while (y<6)
{

	while (x < 12)
	{
    ecran[positionX+x][positionY+y]=avion[x][y];

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
system("clear");
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
x=0;}
sleep(1);
}
break;
case 'q':
image = fopen("G.pbm" , "r");
fgets(str, 20, image);
fgets(str, 20, image);
for(y=0;y<12;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<13;x++)
        {
            if(str[x]!=' ')
            avion[positionX+x][positionY+y]=str[x];
        }}

y=0;
x=0;
while(c!='\0'){
for(y=0;y<24;y++)
{
    for(x=0;x<80;x++)
    {
    if (ecran[x][y] == '1')
    ecran[x-1][y]=ecran[x][y];
    positionX--;
    }
}
y=0;
x=0;
while (y<6)
{

	while (x < 12)
	{
    ecran[positionX+x][positionY+y]=avion[x][y];

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
system("clear");
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
x=0;}
sleep(1);
}
break;
case 's':
image = fopen("B.pbm" , "r");
fgets(str, 20, image);
fgets(str, 20, image);
for(y=0;y<12;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<13;x++)
        {
            if(str[x]!=' ')
            avion[positionX+x][positionY+y]=str[x];
        }}

y=0;
x=0;
while(c!='\0'){
for(y=0;y<24;y++)
{
    for(x=0;x<80;x++)
    {
    if (ecran[x][y] == '1')
    ecran[x][y+1]=ecran[x][y];
    positionY++;
    }
}
y=0;
x=0;
while (y<6)
{

	while (x < 12)
	{
    ecran[positionX+x][positionY+y]=avion[x][y];

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
system("clear");
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
x=0;}
sleep(1);
}
break;
case 'd':
image = fopen("D.pbm" , "r");
fgets(str, 20, image);
fgets(str, 20, image);
for(y=0;y<12;y++)
    {
    fgets(str, 200, image);
        for(x=0;x<13;x++)
        {
            if(str[x]!=' ')
            avion[positionX+x][positionY+y]=str[x];
        }}

y=0;
x=0;
while(c!='\0'){
for(y=0;y<24;y++)
{
    for(x=0;x<80;x++)
    {
    if (ecran[x][y] == '1')
    ecran[x+1][y]=ecran[x][y];
    positionX++;
    }
}
y=0;
x=0;
while (y<6)
{

	while (x < 12)
	{
    ecran[positionX+x][positionY+y]=avion[x][y];

	x++;

	}
y++;
x=0;
}
y=0;
x=0;
system("clear");
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
x=0;}
sleep(1);
}
break;
case '0':
return(0);
endwin();
fclose(image);
system("clear");
}}
}
