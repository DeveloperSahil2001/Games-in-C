#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int width=20,height=20;
int x,y,foodX,foodY,gameOver,score,flag;
int cTail=0;
int tailX[100];
int tailY[100];
void setup()
{
 gameOver=0;
 x=y=width/2;
 
 label1:
 foodX=rand()%20;
 if(foodX==0)
 {
  goto label1;
 }
 label2:
 foodY=rand()%20;
 if(foodY==0)
 {
  goto label2;
 }
 score=0;
}

void draw()
{
 int i,j,k;
 system("cls");
 for(i=0;i<width;i++)
 {
  for(j=0;j<height;j++)
  {
   if(i==0||i==height-1||j==0||j==width-1)
   {
   	printf("*");
   }
   else
   {
   	if(x==i && y==j)
   	{
   	 printf("O");
	}
	else if(i==foodX&&j==foodY)
	{
	 printf("o");
	}
	else
	{
	 int c=0;
	 for(k=0;k<cTail;k++)
	 {
	  c=0;
	  if(i==tailX[k]&&j==tailY[k])
	  {
	  	printf("o");
	  	c=1;
	  }
	 }
	 if(c==0)
	   printf(" ");
	}
   }
  }
  printf("\n");
 }
}

void input()
{
 if(kbhit())
 {
  switch(getch())
  {
   case 'a':
       flag=1;
       break;
   case 's':
       flag=2;
       break;
   case 'w':
       flag=3;
       break;
   case 'z':
       flag=4;
       break;
   case 'x':
       gameOver=1;
       break;
  }
 }
}

void snakeGame()
{
 int i;
 int prevX=tailX[0];
 int prevY=tailY[0];
 int prev2X,prev2Y;
 tailX[0]=x;
 tailY[0]=y;
 for(i=1;i<cTail;i++)
 {
  prev2X=tailX[i];
  prev2Y=tailY[i];
  tailX[i]=prevX;
  tailY[i]=prevY;
  prevX=prev2X;
  prevY=prev2Y;
 }
  switch(flag)
  {
   case 1:
   	   y--;
   	   break;
   case 2:
   	   y++;
   	   break;
   case 3:
   	   x--;
   	   break;
   case 4:
   	   x++;
   	   break;
   default:
   	    break;
   	
  }
  if(x<0||x>width||y<0||y>height)
  {
  	gameOver=1;
  }
  for(i=0;i<cTail;i++)
  {
  	if(x==tailX[i]&&y==tailY[i])
  	{
  	 gameOver=1;
  	 break;
	}
  }
  if(x==foodX&&y==foodY)
  {
  	label1:
     foodX=rand()%20;
     if(foodX==0)
     {
      goto label1;
     }
    label2:
     foodY=rand()%20;
     if(foodY==0)
     {
      goto label2;
     }
  	score+=10;
  	cTail++;
  }
}

int main()
{
 char ch;
 label5:
 setup();

 while(!gameOver)
 {
  draw();
  input();
  snakeGame();
  printf("Score = %d",score);
  if(score<=100)
  sleep(0.01);
  else if(score<=200)
  {
   sleep(0.008);
  }
  else if(score<=300)
  {
   sleep(0.006);
  }
  else if(score<=400)
  {
   sleep(0.004);
  }
 }
if(gameOver)
{
 score=0;
 printf("\nPress Y to restart:)");
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
  goto label5;
 }
}
 return 0;
}
