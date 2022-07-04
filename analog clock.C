#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
struct cord
{
	float xcord, ycord;
};
struct cord rotate(float x, float y, float a)
{
	struct cord c;
	float d=a*3.14/180;
	x-=200;
	y-=200;
	c.xcord=x*cos(d)-y*sin(d);
	c.ycord=x*sin(d)+y*cos(d);
	c.xcord+=200;
	c.ycord+=200;
	return c;
}
void dial()
{
	float dx=200, dy=85, da=30;
	struct cord d;
	outtextxy(dx,dy,"12");
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"1");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"2");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"3");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"4");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"5");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"6");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"7");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"8");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"9");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"10");
	da+=30;
	d=rotate(dx,dy,da);
	outtextxy(d.xcord,d.ycord,"11");
	da+=30;
}
void main()
{
	int i, gd=DETECT, gm, sa=0, ma=0, ha=0, h, m, s;
	float sx,sy,mx,my,hx,hy;
	struct cord p;
	printf("Set time (HH:MM:SS)");
	scanf("%d %d %d",&h,&m,&s);
	initgraph(&gd,&gm,"C://TurboC3//BGI");
	circle(200,200,100);
	sx=200;
	sy=110;
	mx=200;
	my=125;
	hx=200;
	hy=150;
	setcolor(GREEN);
	line(200,200,sx,sy);
	setcolor(RED);
	line(200,200,mx,my);
	sa=s*6;
	ma=m*6;
	ha=h*30;
	while(!kbhit())
	{
		clrscr();
		setcolor(WHITE);
		circle(200,200,100);
		circle(200,200,125);
		dial();
		p=rotate(sx,sy,sa);
		line(200,200,p.xcord,p.ycord);
		sa+=6;
		if(sa>360)
		{
			ma+=6;
			sa=6;
		}		
		if(ma>=360)
		{
			ma=0;
			ha+=30;
		}
		if(ha>360)
			ha=30;
		setcolor(GREEN);
		p=rotate(mx,my,ma);
		line(200,200,p.xcord,p.ycord);
		setcolor(RED);
		p=rotate(hx,hy,ha);
		line(200,200,p.xcord,p.ycord);
		delay(1000);
	}
}
