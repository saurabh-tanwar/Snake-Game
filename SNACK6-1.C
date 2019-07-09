#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<bios.h>
void food();
void check();
unsigned int getonech();
void win();
void level2();
void level3();
void check2();
void check3();
void lose();
void grade();

#define UP 372
#define DOWN 380
#define LEFT 375
#define RIGHT 377
int p,q,r,n[500],m[500],con=10;

void main()
{

	int gd=DETECT,gm,i=0,j,ch,k=0,f,spd=100,temp,fl=0;
	int x=11,y=11;
	initgraph(&gd,&gm,"c://TC//bgi");
	p=9;
	q=random(getmaxx());
	temp=q/11;
	q=((temp*11)+77);
	r=random(getmaxy());
	temp=r/11;
	r=((temp*11)+88);
	while(1)
	{
		setcolor(WHITE);
		setfillstyle(1,p);
		circle(q,r,5);
		floodfill(q,r,WHITE);
	if(kbhit())
	{
		ch=getonech();
		if(ch==DOWN)
		{
		k=1;
		}
		else if(ch==RIGHT)
		{
		k=2;
		}
		else if(ch==LEFT)
		{
		k=3;
		}
		else if(ch==UP)
		{
		k=4;
		}
		else
		{
		printf("bruuppp!!!");
		break;
		}
	}

		  HERE: while(i<10)
		   {
		   m[i]=x;
		   n[i]=y;
		   i++;
		   }

		 if(i>=10){
			  for(j=con;j>=0;j--){
				  m[1+j]=m[j];
				  n[1+j]=n[j];
					     }
		   m[0]=x;
		   n[0]=y;

		   setcolor(WHITE);
		   setfillstyle(SOLID_FILL,4);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<con;j++){
		   setfillstyle(SOLID_FILL,random(15));
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
				      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		  circle(m[0],n[0],8);
		  floodfill(m[0],n[0],BLACK);
		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);
		   }
		 if(k==1)
		   {
		   y+=11;

	/*sound(10*random(100));
	delay(75);
	nosound();*/
	check();
	if(fl==1)
	check2();
	if(fl==2)
	check3();

		   if(y>getmaxy())
			{
			y=0;
			}
		    //check();
		   }
		   //if(k==2)

       /*	sound(10*random(100));
	delay(75);
	nosound();*/
		if(k==2)
		{x+=11;
		check();
		if(fl==1)
	check2();
	if(fl==2)
	check3();


			if(x>getmaxx())
			{
			x=0;
			}
		}
		   if(k==3)
		   {
		   x-=11;

	/*sound(10*random(100));
	delay(75);
	nosound();*/
		check();
		if(fl==1)
	check2();
	if(fl==2)
	check3();


			if(x<0)
			{
			temp=getmaxx();
			x=temp/11;
			x=x*11;
			}
		   }
		   if(k==4)
		   {
		   y-=11;

	/*sound(10*random(100));
	delay(75);
	nosound();*/
		check();
		if(fl==1)
	check2();
	if(fl==2)
	check3();

			if(y<0)
			{
			temp=getmaxy();
			y=temp/11;
			y=y*11;
			}

		   }
	if(k==0)
	{
       //	x+=11;
	y+=11;
	}
		   if(q==x&&r==y)
		   {
		   con+=5;
		   spd-=5;
		   if(spd==5)
		   {spd=5;}
		   sound(800);
		   sound(10*random(100));
	delay(75);
	nosound();
	if(con==30)
	{
	cleardevice();
	delay(300);
	setcolor(random(15));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	outtextxy(90,170,"level 1 complited");
	delay(2000);
	cleardevice();
	setcolor(14);
	outtextxy(240,170,"level 2");
	delay(1500);
	cleardevice();
	level2();
	k=0;
	fl=1;
	i=0;
	x=11;y=11;
	for(i=0;i<con;i++){m[i]=0;n[i]=0;}
	goto HERE;
	}
	if(con==40)
	{//win();}
	cleardevice();
	delay(300);
	setcolor(random(15));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	outtextxy(90,170,"level 2 complited");
	delay(2000);
	cleardevice();
	setcolor(14);
	outtextxy(240,170,"level 3");
	delay(1500);
	cleardevice();
	level3();
	k=0;
	fl=2;
	i=0;
	for(i=0;i<con;i++){m[i]=0;n[i]=0;}
	x=22;y=33;
	goto HERE;
	}
	if(con==50)
	{win();
	grade();}



       //	sound(120);
	//nosound();

		   setcolor(BLACK);
		   setfillstyle(SOLID_FILL,BLACK);
		   circle(m[x],n[y],5);
		   floodfill(m[x],n[y],BLACK);
		   food();
		   }}




		//fl=1;
		//nosound();
	closegraph();
	getch();
	}
	void food()
	{
	     int temp;
		p=random(15);
		q=random(getmaxx());
	temp=q/11;
	q=temp*11;
	r=random(getmaxy());
	temp=r/11;
	r=temp*11;
	if((q>=121&&q<=363)&&(r>=99&&r<=121))
	{q=110;r=88;}
	else if((q>=308&&q<=550)&&r>=286&&r<=308)
	{q=286;r=319;}
	else{
		setcolor(WHITE);
		setfillstyle(1,p);
		circle(q,r,5);
		floodfill(q,r,WHITE);}


	}
     unsigned int getonech()
	{
		unsigned int ch;
		int hi,lo;
		ch=bioskey(0);
		hi=ch>>8;
		lo=ch & 0x00ff;
		if(lo==0)
		{
		ch=300+hi;
		return ch;
		}
		else
		{
		ch=hi;
		return ch;
		}
	}
	void check()
	{
	int f,i;
	for(f=1;f<con;f++)
	{
		   if(n[0]==n[f]&&m[0]==m[f])
		   {
		   cleardevice();
		   i=1;
		   break;
		   }
	}
			if(i==1)
			{lose();
			}
	}
	void win()
	{
	int i,f;
	cleardevice();
	for(i=0;i<3;i++)
	{
		for(f=con;f>0;f--)
		{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,random(15));
		circle(m[f],n[f],5);
		floodfill(m[f],n[f],WHITE);
	setcolor(random(15));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
	outtextxy((getmaxx()/4),(getmaxy()/4),"CONGO..!!");
	if(i==0)
	delay(40);
		}
	delay(500);
	cleardevice();
	delay(500);
	}
	cleardevice();
	setcolor(random(15));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,7);
	outtextxy((getmaxx()/4),(getmaxy()/4),"YOU WON  :)");
	getch();
	}
     void level2()
	{
	setcolor(WHITE);
	setfillstyle(1,4);
	rectangle(121,99,363,121);
	floodfill(125,105,WHITE);
	rectangle(308,286,550,308);
	floodfill(320,295,WHITE);
	}
     void check2()
     {
     int i;
     //down
     for(i=121;i<=363;i++){
     if(m[0]==i&&n[0]==99){
     lose();}}
     //left
     for(i=99;i<=121;i++){
     if(n[0]==i&&m[0]==363)
     {lose();}}
     //down
     for(i=121;i<363;i++){
     if(m[0]==i&&n[0]==121)
     {lose();}}
     //right
     for(i=99;i<=121;i++){
     if(n[0]==i&&m[0]==121)
     {lose();}}
     for(i=121;i<=363;i++){
     if(m[0]==i&&n[0]==121){
     lose();}}

     for(i=308;i<=550;i++){
     if(m[0]==i&&n[0]==286){
     lose();}}
     for(i=286;i<=308;i++){
     if(n[0]==i&&m[0]==550)
     {lose();}}
     for(i=308;i<550;i++){
     if(m[0]==i&&n[0]==308)
     {lose();}}
     for(i=308;i<=550;i++){
     if(m[0]==i&&n[0]==308){
     lose();}}
     }

void lose()
{
int i,f;


			  for(i=0;i<4;i++)
			  {
			    for(f=1;f<con;f++)
			    {
				setcolor(WHITE);
				setfillstyle(SOLID_FILL,4);
				circle(m[f],n[f],7);
				floodfill(m[f],n[f],WHITE);
				setcolor(random(15));
				settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
				outtextxy((getmaxx()/4),(getmaxy()/4),"OOPSS..!!");
				if(i==0)
				delay(50);

			    }
				delay(500);
				cleardevice();
				delay(500);
			  }
				setcolor(random(15));
				settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
				outtextxy((getmaxx()/4),(getmaxy()/4),"GAME OVER");
				getch();
				cleardevice();
				closegraph();
}
void level3()
{
setfillstyle(1,4);
rectangle(11,11,627,462);
floodfill(1,1,14);
setcolor(15);
setfillstyle(1,4);
rectangle(99,121,121,363);
	floodfill(105,125,15);
	rectangle(308,286,550,308);
	setfillstyle(1,4);
	floodfill(320,295,15);
}
void check3()
{ int i;
for(i=308;i<=550;i++){
     if(m[0]==i&&n[0]==286){
     lose();}}
     for(i=286;i<=308;i++){
     if(n[0]==i&&m[0]==550)
     {lose();}}
     for(i=308;i<550;i++){       //308,286,550,308
     if(m[0]==i&&n[0]==308)
     {lose();}}
     for(i=308;i<=550;i++){
     if(m[0]==i&&n[0]==308){
     lose();}}

     //up
     for(i=99;i<=121;i++){
     if(m[0]==i&&n[0]==121){
     lose();}}
     //right
     for(i=121;i<=363;i++){
     if(n[0]==i&&m[0]==121)
     {lose();}}
     //down               //99,121,121,363
     for(i=99;i<121;i++){
     if(m[0]==i&&n[0]==363)
     {lose();}}
     //left
     for(i=99;i<=363;i++){
     if(n[0]==i&&m[0]==99){
     lose();}}

for(i=11;i<=627;i++)
{
if(m[0]==i&&n[0]==11){
cleardevice();
delay(1000);                //11,11,627,462
lose();
}}
for(i=11;i<=462;i++)
{
if(m[0]==627&&n[0]==i){
lose();
}}
for(i=11;i<=462;i++)
{
if(m[0]==11&&n[0]==i){
lose();
}}
for(i=11;i<=627;i++)
{
if(m[0]==i&&n[0]==462){
lose();
}}
}
void grade()
{
int i, ch[100];
for(i=0;i<=con;i++)
{
	setcolor(random(15));
	settextstyle(1,0,i/10);
	sprintf(ch,"%d",i);
	outtextxy((getmaxx()/2)-i,(getmaxy()/2)-i,ch);
	delay(20);
	setcolor(BLACK);
	outtextxy((getmaxx()/2)-i,(getmaxy()/2)-i,ch);
	sound(20*i);//random(100));
	delay(30);
	nosound();

}
setcolor(WHITE);
outtextxy((getmaxx()/2)-i,(getmaxy()/2)-i,ch);
closegraph();
getch();}

