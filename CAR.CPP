#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>


#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

	void  DrawBack()
	{
			 	textcolor(75);
				textbackground(125);
		int i=0,j=0;
					clrscr();
		for(i=5; i<75; i++)
		{
		      	//getch();

			for(j=5;j<40; j++)
			{ // getch();
				gotoxy(i+1,j+1);
			  	cprintf("%c",177);
          // putch(177);
			}

		}
	}
	void  DrawRoad()
	{
		gotoxy(0,0);
		textcolor(55);
		textbackground(25);

		for(int i=5; i<75; i++)
		{
	        //	getch();
			for(int j=5;j<40; j++)
			{
				if(((i>39 && i<44) || (i>5 && i<12)|| (i>68 && i<74) ||(j>5 && j<11)||(j>22 && j<28)||(j>34 && j<39))
            	&& j!=5 && j!=39 &&  i!=5 &&  i!=74)
				{
					gotoxy(i+1,j+1);
				  //	cprintf("%c",255);
              putch(255);

				}
			}


	       //	sleep(1);

		}
	}
   int TestAccident(int x,int y)
   {
   	if(((x>39 && x<44) || (x>5 && x<12)|| (x>68 && x<74) ||(y>5 && y<11)||(y>22 && y<28)||(y>34 && y<39))
      	&& y!=5 && y!=39 &&  x!=5 &&  x!=74)
      {
       	return 0;
      }
      return 1;
   }

  	int DrawCar(int x ,int y,int side)
  	{
	  	int i,j;

     	int carRight[2][7]={{255,178,178,178,178,178,178},
		{42,254,79,254,254,79,254}};

      int carLeft[2][7]={{178,178,178,178,178,178,255},
		{254,79,254,254,79,254,42}};

    switch(side)
    {
    	case UP:
      		for (i=0;i<7;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<2;j++)
               {
               	if(TestAccident(x,y+i))
                   	return 0;
						cprintf("%c",carLeft[j][i]);
               }
      		}
    			break;
    	case DOWN:
      		for (i=0;i<7;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<2;j++)
               {
               	if(TestAccident(x,y+i))
                   	return 0;
						cprintf("%c",carRight[j][i]);
               }
      		}
    			break;
    	case RIGHT:
      		for (i=0;i<2;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<7;j++)
               {
               	if(TestAccident(x,y+i))
                   	return 0;
						cprintf("%c",carRight[i][j]);
               }
      		}
      		break;
    	case LEFT:
      		for (i=0;i<2;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<7;j++)
               {
               	if(TestAccident(x,y+i))
                   	return 0;
						cprintf("%c",carLeft[i][j]);
               }
      		}
    			break;
    }

    return 1;

  }



  	void EraseCar(int x ,int y,int side)
  	{
	  	int i,j;

     	int car[2][7]={{255,255,255,255,255,255,255},
		{255,255,255,255,255,255,255}};


    switch(side)
    {
    	case UP:
      		for (i=0;i<7;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<2;j++)
					cprintf("%c",car[j][i]);
      		}
    			break;
    	case DOWN:
      		for (i=0;i<7;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<2;j++)
					cprintf("%c",car[j][i]);
      		}
    			break;
    	case RIGHT:
      		for (i=0;i<2;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<7;j++)
					cprintf("%c",car[i][j]);
      		}
      		break;
    	case LEFT:
      		for (i=0;i<2;i++)
				{
	  	  			//	cprintf("\n","\t");
        			gotoxy(x,y+i);
					for (j=0;j<7;j++)
					cprintf("%c",car[i][j]);
      		}
    			break;
    }

  }

 void Message()
 {
 	char ch=0;
   while(ch!=13)
   {
 		gotoxy(35,25);
      cprintf("Game Over");
      ch = getch();
   }
 }



void main()
{
	 int x=10,y=9;
    int old=RIGHT;
	char ch;
	clrscr();

	DrawBack();
	DrawRoad();
   DrawCar(x,y,RIGHT);
	while(1)
   {
   	if(kbhit())
      {
	   	ch=getch();
   	   if(!ch)
      		ch=getch();
      }
      switch((int)ch)
      {
      	case 72  :     //UP
               EraseCar(x,y,old);
               old=UP ;
               y--;
			     if(!DrawCar(x,y,UP))
              {
              		Message();
                  return ;
              }
               break;
      	case 80  :       //DOWN
		         EraseCar(x,y,old);
               old=DOWN;
               y++;
			     if(!DrawCar(x,y,DOWN))
              {
              		Message();
                  return;
              }
               break;
      	case 75  :        //LEFT
			            EraseCar(x,y,old);
                     old=LEFT;
               x--;
			     if(!DrawCar(x,y,LEFT))
              {
              		Message();
                  return;
              }
               break;
      	case 77  :        // RIGHT
			            EraseCar(x,y,old);
                     old=RIGHT;
               x++;
			     if(!DrawCar(x,y,RIGHT))
              {
              		Message();
                  return;
              }
               break;
      }
      sleep(1);

   }
	getch();
}