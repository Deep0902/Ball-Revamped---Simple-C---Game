#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<math.h>
int life=3;
int colour=1,lcolour=28;
int c=0,i=40,j=80,x=0,y=0,virtualRadius=17,Radius=15;  // i & j are the coordinates of the circle, x and y are to update the coordinates
float p=0,q=0,t=0,LINE=0;
void lifeDisplay();     //displays the number of lives left
void gameOverFun();     //Displays Game over
void levelOne();        //Level 1 code
void levelTwo();        //Level 2 code
void levelThree();      //Level 3 code
void introAndRules();   //graphical description about rules of the game
void horizontaLineTouch(int, int, int);   //Check weather the circle touches the horizontal line
void verticalLineTouch(int, int, int);    //Check weather the circle touches the vertical line
void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

   introAndRules();
   levelOne();
   levelTwo();
   levelThree();
}//main

void horizontaLineTouch(int xh1,int yh,int xh2)   //horizontal line
{
   if(c==72 && j<yh+virtualRadius && j>yh-virtualRadius && i>xh1-virtualRadius && i<xh2+virtualRadius) //up
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==75 && i<xh2+virtualRadius && i>xh1-virtualRadius && j<yh+virtualRadius && j>yh-virtualRadius) //left
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==77 && i>xh1-virtualRadius && i<xh2+virtualRadius && j<yh+virtualRadius && j>yh-virtualRadius) //right
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==80 && j<yh+virtualRadius && j>yh-virtualRadius && i>xh1-virtualRadius && i<xh2+virtualRadius) //down
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   if(life<1)
      gameOverFun();
}
void verticalLineTouch(int vx, int vy1, int vy2)  // vertical line
{
   if(c==72 && i>vx-virtualRadius && i<vx+virtualRadius && j>vy1-virtualRadius && j<vy2+virtualRadius) //up
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==75 && i>vx-virtualRadius && i<vx+virtualRadius && j>vy1-virtualRadius && j<vy2+virtualRadius)//left
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==77 && i>vx-virtualRadius && i<vx+virtualRadius && j>vy1-virtualRadius && j<vy2+virtualRadius) //right
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   else if(c==80 && i>vx-virtualRadius && i<vx+virtualRadius) //down
      {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); life--; i=40; j=80;   }
   if(life<1)
      gameOverFun();
}
void lifeDisplay()
{
 if(life==3)
  outtextxy(400,20,"Lives left:   ");
 if(life==2)
  outtextxy(400,20,"Lives left:  ");
 if(life==1)
  outtextxy(400,20,"Lives left: ");
}
void gameOverFun()
{ 
  cleardevice();
  setcolor(YELLOW);
  settextstyle(0,0,2);
  outtextxy(200,240,"Game Over ! :(");
  delay(2000);
  cleardevice();
  exit(0);
}
void levelOne()
{
  while(life>0)
 {
  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,Radius);  //draw the circle
  floodfill(i,j,colour);
  setcolor(lcolour);
  line(10 ,120,500,120);    horizontaLineTouch(10 ,120,500); 
  line(150,230,600,230);    horizontaLineTouch(150,230,600); 
  line(10 ,340,450,340);    horizontaLineTouch(10 ,340,450); 

  setcolor(GREEN);
  lifeDisplay();
  setfillstyle(1,colour+1);
  circle(100,400,15);
 // floodfill(100,400,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
      {  x=0; y=-1;   }
   else if(c==75)//left
      {  x=-1; y=0;   }
   else if(c==77)//right
      {  x=1; y=0;    }
   else if(c==80)//down
      {  x=0; y=1;    }
   else if(c==113 || c==81)
      { cleardevice(); exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
      {  x=0; y=0;    }
   else if(c==75&&i<30)//left
      {  x=0; y=0;   }
   else if(c==77&&i>580)//right
      {  x=0; y=0;   }
   else if(c==80&&j>430)//down
      {  x=0; y=0;   }

   }//if
    i=i+(5*x);    //increment the coordinates of circle
    j=j+(5*y);
    x=0;y=0;
    delay(20);
    cleardevice();

    if(pow(pow((100-i),2)+pow((400-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 1 Clear"); delay(1500); return;  }

    rectangle(610,50,615,300);      //timer
    line(610,p+50,615,p+50);
    p=p+0.05;
    if(p>250)
      {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); exit(0); }
 }//while level 1
}
void levelTwo()
{
 int linetop[3]={130,200,280};      
 int linever[3]={350,430,490};
 int linebot[3]={210,270,350};
 int linepos[3]={0,1,0};
 setcolor(WHITE);
 i=40,j=80;
 cleardevice();
 settextstyle(0,0,3);
 outtextxy(220,240,"Level 2");
 delay(1500);
 cleardevice();
 while(life>0)
 {
  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,Radius);
  floodfill(i,j,colour);
  setcolor(lcolour);
	     line(295,49,295,380);      verticalLineTouch(295,50,380);
	     line(100,51,100,350);      verticalLineTouch(100,50,350);
	     line(200,120,200,449);     verticalLineTouch(200,120,449);
	     line(295,380,530,380);	  horizontaLineTouch(295,380,530);
	     line(360,290,599,290);	  horizontaLineTouch(360,290,599);
	     line(295,200,530,200);	  horizontaLineTouch(295,200,530);
	     line(360,120,599,120);     horizontaLineTouch(360,120,599);
  setcolor(GREEN);
  lifeDisplay(); 	                        // green circle
  setfillstyle(1,colour+1);
  circle(560,90,15);
  //floodfill(560,90,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
      {  x=0; y=-1;   }
   else if(c==75)//left
      {  x=-1; y=0;   }
   else if(c==77)//right
      {  x=1; y=0;    }
   else if(c==80)//down
      {  x=0; y=1;    }
   else if(c==113 || c==81)
      { cleardevice(); exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
      {  x=0; y=0;    }
   else if(c==75&&i<30)//left
      {  x=0; y=0;   }
   else if(c==77&&i>580)//right
      {  x=0; y=0;   }
   else if(c==80&&j>430)//down
      {  x=0; y=0;   }
   }//if

   setcolor(RED);                  // moving red lines
   for(int I=0; I<3; I++)
   {
	  if(linepos[I]==0)
	      {   line(linever[I],linetop[I],linever[I],linebot[I]); verticalLineTouch(linever[I],linetop[I],linebot[I]); linetop[I]++; linebot[I]++;   }
	  else if(linepos[I]==1)
	      {   line(linever[I],linetop[I],linever[I],linebot[I]); verticalLineTouch(linever[I],linetop[I],linebot[I]); linetop[I]--; linebot[I]--;   }

	  if(linetop[I]==52)
	     linepos[I]=0;
	  else if(linebot[I]==449)
	     linepos[I]=1;
   }
   setcolor(WHITE);
   i=i+(4*x);     //increment coordinates of the circle
   j=j+(4*y);
   x=0;y=0;
   delay(20);
   cleardevice();

   if(pow(pow((560-i),2)+pow((90-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 2 Clear"); delay(1500); return;}

   rectangle(610,50,615,300);       //timer
   line(610,q+50,615,q+50);
   q=q+0.03;
   if(q>250)
      {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); exit(0); }

 }// while level2
}
void levelThree()
{
 int Linetop[5]={130,200,280,80,350};
 int Linever[5]={330,380,430,480,530};
 int Linebot[5]={210,270,350,150,430};
 int Linepos[5]={0,1,0,1,1};
 setcolor(WHITE);

 i=40,j=80;
 cleardevice();
 settextstyle(0,0,3);
 outtextxy(220,240,"Level 3");
 delay(1500);
 cleardevice();
 while(life>0)
 {
  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,Radius);
  floodfill(i,j,colour);
  setcolor(lcolour);
	     line(295,49,295,380);      verticalLineTouch(295,49,380);
	     line(10,120,190,120);      horizontaLineTouch(10,120,190);
	     line(250,120,295,120);     horizontaLineTouch(250,120,295);
	     line(10,190,50,190);       horizontaLineTouch(10,190,50);
	     line(110,190,295,190);     horizontaLineTouch(110,190,295);
	     line(10,250,230,250);      horizontaLineTouch(10,250,230);
	     line(100,310,295,310);     horizontaLineTouch(100,310,295);
	     line(100,310,100,390);     verticalLineTouch(100,310,390);
	     line(190,370,190,449);     verticalLineTouch(190,370,449);
	     line(295,380,530,380);	  horizontaLineTouch(295,380,530);
	     line(360,290,599,290);	  horizontaLineTouch(360,290,599);
	     line(295,200,530,200);	  horizontaLineTouch(295,200,530);
	     line(360,120,599,120);     horizontaLineTouch(360,120,599);
  setcolor(GREEN);
  lifeDisplay(); 	                        // green circle
  setfillstyle(1,colour+1);
  circle(560,90,15);
//  floodfill(560,90,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
      {  x=0; y=-1;   }
   if(c==75)//left
      {  x=-1; y=0;   }
   if(c==77)//right
      {  x=1; y=0;    }
   if(c==80)//down
      {  x=0; y=1;    }
   if(c==113 || c==81)
      { cleardevice(); exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
      {  x=0; y=0;    }
   if(c==75&&i<30)//left
      {  x=0; y=0;   }
   if(c==77&&i>580)//right
      {  x=0; y=0;   }
   if(c==80&&j>430)//down
      {  x=0; y=0;   }
   }//if

   setcolor(RED);                  // moving red lines
   for(int I=0; I<5; I++)
   {
	    if(Linepos[I]==0)
	        {   line(Linever[I],Linetop[I],Linever[I],Linebot[I]); verticalLineTouch(Linever[I],Linetop[I],Linebot[I]); Linetop[I]++; Linebot[I]++;   }
	    if(Linepos[I]==1)
	        {   line(Linever[I],Linetop[I],Linever[I],Linebot[I]); verticalLineTouch(Linever[I],Linetop[I],Linebot[I]); Linetop[I]--; Linebot[I]--;   }

	    if(Linetop[I]==52)
	     Linepos[I]=0;
	    else if(Linebot[I]==449)
	     Linepos[I]=1;
   }
   setcolor(WHITE);

   i=i+(4*x);     //incerment coordinates of the circle 
   j=j+(4*y);
   x=0;y=0;
   delay(20);
   cleardevice();

   if(pow(pow((560-i),2)+pow((90-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 3 Clear"); cleardevice(); outtextxy(178,240,"You've reached the end!"); delay(1500); return;}

   rectangle(610,50,615,300);       //timer
   line(610,t+50,615,t+50);
   t=t+0.03;
   if(t>250)
      {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); exit(0); }

 }// while level3
}
void introAndRules()
{
    settextstyle(1,0,5);
    setpalette(7,24);
    setpalette(11,15);
    int a,b,z;
    a=0;
    b=0;
	// getting maximum width
    int we=getmaxx();
	//getting maximum height
    z=getmaxy();
    setcolor(11);
    rectangle(a+80,b+80,we-100,z-80);
    setfillstyle(1,7);
    bar(a+81,b+81,we-101,z-81);
    setlinestyle(3,0,0);
    setcolor(14);
    rectangle(a+83,b+83,we-103,z-83);
    setlinestyle(0,0,0);
    setcolor(0);
    rectangle(a+86,b+86,we-106,z-86);
    // Finish drawingthe splash window
    putpixel(303,98,0);
    setfillstyle(5,2);

    setcolor(14);
    settextstyle(0,0,3);
    outtextxy(100,100,"Blue Ball Journey");
    setcolor(9);
    setfillstyle(1,9);
    circle(300,184,38);
      floodfill(300,184,9);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(120,250,"C.S Investigatory Project ");
    setcolor(11);
    settextstyle(0,0,2);
    outtextxy(95,300," By: Deep, Santosh & Kunal");
     setcolor(19);
    settextstyle(0,0,2);
     delay(2500);
    cleardevice();
    settextstyle(0,0,2);
    outtextxy(260,16,"RULES");   delay(1000);
    setcolor(BLUE);
    setfillstyle(1,colour);
    circle(100,100,15);  floodfill(100,100,BLUE);    delay(1000);
    setcolor(GREEN);
    setfillstyle(1,colour+1);
    circle(100,170,15);     delay(1000);
    setcolor(RED);	 line(100,230,100,310);      delay(1000);
    setcolor(WHITE);
    outtextxy(150,95,"- You");                      delay(1000);
    outtextxy(150,163,"- Destination");              delay(1000);
    outtextxy(150,270,"- Do not touch any RED lines");  delay(1500);
    settextstyle(0,0,0);
    outtextxy(170,390,"Use Arrow Keys to move the Blue Ball"); delay(2500);
    outtextxy(70,420,"Reach the Destination before the time slider reaches the bottom"); delay(3000);
    cleardevice();
    settextstyle(0,0,2);
    setcolor(YELLOW);
    outtextxy(220,240,"Good Luck !");   delay(1000);

    setcolor(WHITE);
    cleardevice();
    settextstyle(0,0,3);
    outtextxy(220,240,"Level 1");
     delay(2000);
}
