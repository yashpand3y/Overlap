#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<math.h>
// We purposefully misspelt "score" as "skore" because we thought it was funny
void load()	// loading screen graphics
{
	int gd=DETECT,gm;
	char w[11][34]={
			{"Looking For Reasons To Load"},
			{"ERROR 404:Reasons Not Found"},
			{"Banter!!!!"},
			{"Wait Am I Wasting Your Time?!?"},
			{"And I Was Like..."},
			{"Baby...Baby...Baby...ooo.."},
			{"ERROR : RELOADING NOW"},
			{""},
			{"Looking For Reasons To Load"},
			{"LOL...Kidding"},
			{"Lets Start"}
		       };
	double x,y;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	// setting x and y reference at the center of screen
	x=getmaxx()/2;
	y=getmaxy()/2;
	delay(2500);
	for(int i=-50;i<50;i++)
	{
		double p=(i*i)/(36);
		fillellipse(x+p,y+i,5+i/9,5+i/9);
		delay(12);
	}
	for(int v=0;v<x-200;v+=6)
	{
		for(i=-50;i<50;i++)
		{
			double p=(i*i)/(36);
			fillellipse(x+p-v,y+i,5+i/9,5+i/9);
		}
		delay(1);
		cleardevice();
		for(i=-50;i<50;i++)
		{
			double p=(i*i)/(36);
			fillellipse(x+p-v+1,y+i,5+i/9,5+i/9);
		}
	}
	settextjustify(1,1);
	settextstyle(3,0,3);
	outtextxy(x+40,y,"ALAMITY STUDIOS");
	delay(1000);
	cleardevice();
	settextstyle(0,0,1);
	for(int j=0;j<=10;j++)
	{
		setcolor(GREEN);
		settextjustify(1,1);
		outtextxy(x,y+50,w[j]);
		int m=(j+1)*2;
		setcolor(m);
		if(m==16)
			setcolor(CYAN);
		if(j==7)
		{
			cleardevice();
			setcolor(BLACK);
		}
		if(j==10)
			setcolor(BLACK);
		if(j==6)
		{
			cleardevice();
			setcolor(GREEN);
			outtextxy(x,y+25,w[6]);
			setcolor(BLACK);
		}
		for(int i=0;i<x/2;i++)
		{
			double p=sqrt((4*x*x)-(i*i));
			int s=((2*i)/x)*360;
			for(int i=0;i<5;i++)
				arc(x,y,s+90,s+98,15-i);
			delay((2*x-p)+2);
		}
		cleardevice();
		for(i=0;i<5;i++)
			arc(x,y,0,360,15-i);
	}
}
int *x=new int,*y=new int,i,skore=0,streak,j,z,hs=0;
fstream file,file1;
// Structure for storing square co-ordinates
struct sq
{
	int l;	// left
	int t;	// top
	int r;	// right
	int b;	// bottom
};
// using pointers to optimize for memory use
sq *ms=new sq;	// target square
sq *mos=new sq;	// moving square (player)
void mainscr();
void reset()	// reset highscore to zero
{
	fstream f;
	hs=0;
	f.open("high-skore.dat",ios::trunc|ios::out);
	f.write((char*)&hs,sizeof(hs));
	f.close();
}
void credit()
{
	cleardevice();
	cout<<"This program has been developed by Yash Pandey and Nitesh Sarraf with inputs    from Priyaanshu Roy. The whole of XII-C helped us by telling tips to constantly improve the program.";
	getch();
	mainscr();
}
void mainscr()
{
	while(!kbhit())
	{
		setcolor(GREEN);
		cleardevice();
		settextjustify(1,1);
		settextstyle(2,0,7);
		outtextxy(*x,*y,"C:Credits  Enter:Play  Esc:Exit");
		delay(110);
		settextstyle(2,0,40);
		outtextxy(*x,*y-50,"O     P");
		settextstyle(2,0,7);
		outtextxy(*x,*y,"C:Credits  Enter:Play  Esc:Exit");
		delay(110);
		settextstyle(2,0,40);
		outtextxy(*x,*y-50," V   A ");
		settextstyle(2,0,7);
		outtextxy(*x,*y,"C:Credits  Enter:Play  Esc:Exit");
		delay(110);
		settextstyle(2,0,40);
		outtextxy(*x,*y-50,"  E L  ");
		settextstyle(2,0,7);
		outtextxy(*x,*y,"C:Credits  Enter:Play  Esc:Exit");
		delay(110);
		settextstyle(2,0,40);
		outtextxy(*x,*y-50,"   R   ");
		settextstyle(2,0,7);
		outtextxy(*x,*y,"C:Credits  Enter:Play  Esc:Exit");
		delay(360);
		if(kbhit())
		{
			int f=getch();
			if(f==27)
				exit(0);
			else
			{
				if((f==99)||(f==67))
					credit();
				else
				{
					if(f==13)
						break;
				}
			}
		}
	}
}
void sc(int a)	// Streak Check: Check if the box co-ordinates at time of keyboard input is within 3 pixels of target
{
	if(a)
	{
		if((mos->t+i>ms->t-3)&&(mos->t+i<ms->t+3))
			streak++;
		else
			streak=0;
	}
	else
	{
		if((mos->l+i>ms->l-3)&&(mos->l+i<ms->l+3))
			streak++;
		else
			streak=0;
	}
}
void dr()	// Randomize speed of moving box
{       randomize();
	j=random((((random(10000-(ms->l+ms->r)))+(random(10000-(ms->b-ms->l))))+234))%10;
	z=random((((random(10000-(ms->l+ms->r)))+(random(10000-(ms->b-ms->l))))+234))%15;
}
void cut(int a)	// cut area of box outside of target bounds
{
	if(a==1)
	{
		if((mos->t+i>=ms->t)&&(mos->t+i<=ms->b))
		{
			sc(1);
			ms->t=mos->t+i;
			mos->t=ms->t;
			skore++;
		}
		else

		{
			if((mos->b+i>=ms->t)&&(mos->b+i<=ms->b))
			{
				sc(1);
				ms->b=mos->b+i;
				mos->b=ms->b;
				skore++;
			}
		}
	}
	if(a==2)
	{
		if((mos->l+i>=ms->l)&&(mos->l+i<=ms->r))
		{
			sc(0);
			ms->l=mos->l+i;

			mos->l=ms->l;
			skore++;
		}
		else
		{
			if((mos->r+i>=ms->l)&&(mos->r+i<=ms->r))
			{
				sc(0);
				ms->r=mos->r+i;
				mos->r=ms->r;
				skore++;
			}
		}
	}
}
int hd(int z)
{
	if(z==1)
	{
		if(((mos->t+i>=ms->t)&&(mos->t+i<=ms->b))||((mos->b+i>=ms->t)&&(mos->b+i<=ms->b)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(((mos->l+i>=ms->l)&&(mos->l+i<=ms->r))||((mos->r+i>=ms->l)&&(mos->r+i<=ms->r)))
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}
void mainframe()	// Visualize in-game UI
{
	*x=getmaxx()/2,*y=getmaxy()/2;
	char buffer[80];
	settextstyle(2,0,40);
	sprintf(buffer, "%i\n",skore);
	rectangle(*x-200,*y-200,*x+200,*y+200);
	rectangle(*x-200,0,*x+200,*y-200);
	rectangle(*x-200,*y+200,*x+200,*y*2);
	settextstyle(2,0,40);
	settextjustify(1,2);
	outtextxy(*x,*y+195,"OVERLAP");
	rectangle(*x-170,15,*x-5,25);
	bar(*x-170,15,*x-170+(55*streak),25);
	settextjustify(0,2);
	if(skore<hs)
	{
		outtextxy(*x+100,0,buffer);
	}
	else
	{
		outtextxy(*x+100,0,buffer);
		rectangle(*x+98,10,*x+145,38);
	}
}
void upd()	// up-down movement
{
	bar(mos->l,mos->t+i,mos->r,mos->b+i);
	dr();
	delay(12-j);
	cleardevice();
}
void ler()	// left-right movement
{
	bar(mos->l+i,mos->t,mos->r+i,mos->b);
	dr();
	delay(12-j);
	cleardevice();
}
void main()
{
	//Variable Declarations
	load();
	start:
	skore=0;
	file.open("high-skore.dat",ios::in);
	while(file.read((char*)&hs,sizeof(hs)));
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");	// ENSURE THIS REFERENCE IS SET CORRECTLY
	*y=getmaxy()/2;
	*x=getmaxx()/2;
	mainscr();
	//Box Size
	ms->l=*x-45;
	ms->t=*y-45;
	ms->r=*x+45;
	ms->b=*y+45;
	//Moving Box Size
	mos->l=ms->l;
	mos->t=ms->t;
	mos->r=ms->r;
	mos->b=ms->b;
	//Hit Detect
	int hdd=69;	// don't ask
	//Create Reference Rectangle
	rectangle(ms->l,ms->t,ms->r,ms->b);
	y:
	if(!z)
	z=1;
	setcolor(z);
	setfillstyle(1,z);
	if (!hdd)          //If hit is outside the box(not detected)
		goto end;
	else
	{
		if (hdd==2)       //If Hit is true
			cut(2);
	}        //cut the box
	if(streak==3)	// if streaked 3 times, increase box size by 5 pixels
	{
		streak=0;
		if((ms->r-ms->l)>(ms->b-ms->t))
		{
			ms->b+=5;
			ms->t-=5;
			mos->b+=5;
			mos->t-=5;
		}
		else
		{
			ms->l-=5;
			ms->r+=5;
			mos->l-=5;
			mos->r+=5;
		}
	}

	//UPDOWN
	while(!kbhit())
	{
		for(i=-130;i<130;i++)
		{
			mainframe();         //Main Frame
			rectangle(ms->l,ms->t,ms->r,ms->b);
			upd();
			if(kbhit())             //If keyboard is hit
			{
				if(getch()==27)	// escape key
					exit(0);
				else
				{
					hdd=hd(1);	// any other keyboard input
					goto x;
				}
			}
		}
		for(i=130;i>-130;i--)
		{
			mainframe();
			rectangle(ms->l,ms->t,ms->r,ms->b);
			upd();
			if(kbhit())
			{
				if(getch()==27)
					exit(0);
				else
				{
					hdd=hd(1);
					goto x;
				}
			}
		}
	}
	//RIGHTLEFT
	x:
	if(!z)
	z=1;
	setcolor(z);
	setfillstyle(1,z);
	if (!hdd)
		goto end;
	else
	{
		if (hdd==1)
			cut(1);
	}
	if(streak==3)
	{
		streak=0;
		if((ms->r-ms->l)>(ms->b-ms->t))
		{
			ms->b+=5;
			ms->t-=5;
			mos->b+=5;
			mos->t-=5;
		}

		else
		{
			ms->l-=5;
			ms->r+=5;
			mos->l-=5;
			mos->r+=5;
		}
	}
	while(!kbhit())	// keep moving box if no keyboard input detected
	{
		for(i=-130;i<130;i++)
		{
			mainframe();
			rectangle(ms->l,ms->t,ms->r,ms->b);
			ler();
			if(kbhit())
			{
				if(getch()==27)
					exit(0);
				else
				{
					hdd=hd(0);
					goto y;
				}
			}
		}
		for(i=130;i>-130;i--)
		{
			mainframe();
			rectangle(ms->l,ms->t,ms->r,ms->b);
			ler();
			if(kbhit())
			{
				if(getch()==27)
					exit(0);
				else
				{
					hdd=hd(0);
					goto y;
				}
			}
		}
	}
	end:
	char buffer[80];
	sprintf(buffer, "%i",skore);
	if(skore>hs)
	{
		hs=skore;
		file1.open("high-skore.dat",ios::trunc|ios::out);
		file1.write((char*)&hs,sizeof(hs));
	}
	while(file.read((char*)&hs,sizeof(hs)));
	settextjustify(1,1);
	file1.close();
	file.close();
	char buffer2[80];
	sprintf(buffer2, "%i",hs);
	outtextxy(*x,*y,buffer);
	settextstyle(2,0,7);
	outtextxy(*x,*y-50,buffer2);
	outtextxy(*x,*y+50,"Any Key:Play R:Reset Esc:Exit");
	int r=getch();
	if(r==27)
		exit(0);
	else
	{
		streak=0;
		if((r==82)||(r==114))
		{
			reset();
			goto start;
		}
		else
			goto start;
	}
	closegraph();
}
