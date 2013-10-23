#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif
#define PI 3.1415926535898
#define NENDS 2           /* number of end "points" to draw */
GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
int ends[NENDS][2];       /* array of 2D points */
void hammer(int,int,int,int);
/* Program initialization NOT OpenGL/GLUT dependent,
   as we haven't created a GLUT window yet */
void circle(float,float,int);
void basicSetup();
void rope(int);
void waterJug(float);
void dominoes(float,float,float,float,float,float,float,float);
float newPathx(float,float,float,float,float);
float newPathy(float,float,float,float,float);
void myButton(float);
void waterflow(float);
void init(void)
{
  width  = 1280.0;                 /* initial window width and height, */
  height = 800.0;                  /* within which we draw. */
  ends[0][0] = (int)(0.25*width);  /* (0,0) is the lower left corner */
  ends[0][1] = (int)(0.75*height);
  ends[1][0] = (int)(0.75*width);
  ends[1][1] = (int)(0.25*height);
}

/* Callback functions for GLUT */

/* Draw the window - this is where all the GL actions are */
void
display(void)
{
  int i;

  
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 0.5, 0.0);
  glBegin(GL_POLYGON);
  glVertex2i(683,384);
  glVertex2i(683+20,384);
  glVertex2i(683+20,384-20);
  glVertex2i(683,384-20);
  glVertex2i(683,384);
  glEnd();
  basicSetup();
   circle(683+380,384+146,18);
	hammer((683+380)+18,(384+148)+6,(683+380+18)+40,(384+148)-6);
	int rea,reb,rec,red,rope_y;
	float xc,yc;
	rea=683+380+18;
	reb=384+148+6;
	rec=683+380+18+40;
	red=384+148-6;
	rope_y=0;
	xc=683+380;yc=384+146;
float da1,db1,dc1,dd1,de1,df1,dg1,dh1;//dominoe1
float da2,db2,dc2,dd2,de2,df2,dg2,dh2;//dominoe2
float da3,db3,dc3,dd3,de3,df3,dg3,dh3;//dominoe3
float da4,db4,dc4,dd4,de4,df4,dg4,dh4;//dominoe4
da1=720;db1=285;dc1=720+5;dd1=db1;de1=dc1;df1=205;dg1=da1;dh1=df1;
da2=720+50;db2=285;dc2=da2+5;dd2=db2;de2=dc2;df2=205;dg2=da2;dh2=df2;
da3=da2+50;db3=285;dc3=da3+5;dd3=db3;de3=dc3;df3=205;dg3=da3;dh3=df3;
da4=da3+50;db4=285;dc4=da4+5;dd4=db4;de4=dc4;df4=205;dg4=da4;dh4=df4;
int bctr=0,waterLevel=30;
//hammer swinging and rope being pulled
	for(int i=0;i<10;i++)
	{ 
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		waterJug(waterLevel);
	    circle(683+380,384+146,18);
		/*dominoes(720,205+80,725,205);
		dominoes(720+30,205+80,725+5,205);
		dominoes(720+60,205+80,725+10,205);
		dominoes(720+90,205+80,725+15,205);*/
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		if(i<5)
		{
			rea+=4;reb+=1;rec+=4;red+=1;rope_y-=5;
			hammer(rea,reb,rec,red);
			rope(rope_y);
		}
		else
		{//1103->1063=2,266->532=19  in 14steps
			rea-=4;reb-=1;rec-=4;red-=1;rope_y+=5;
			hammer(rea,reb,rec,red);
			rope(rope_y);
		}
		_sleep(80);//300
	}
	//hammer's effect
	for(i=0;i<14;i++)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		waterJug(waterLevel);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope_y+=5;
		rope(rope_y);
		xc-=5;rea-=2.8;rec-=2.8;
		circle(xc,yc,18);
		hammer(rea,reb,rec,red);
		_sleep(80);//200
		
	}
	//now circle from 993,532 to 433,404 so line tracing must be circle's centre
	xc=683+310;yc=384+128+20;
	float m;
	//m=1/(532-404)/(993-433);
	m=1/2;
	for(i=0;i<209;i++)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		glColor3f(1, 0.5, 0.0);
		basicSetup();
		myButton(bctr);
		waterJug(waterLevel);
		rope(rope_y);
		hammer(rea,reb,rec,red);
		xc-=2;yc-=1;
		/*glBegin(GL_LINE_LOOP);
		glVertex2f(xc,yc);
		glVertex2f(993,518+20);
		glEnd();
		glFlush();	*/	
	circle(xc,yc,18);
		_sleep(50);//60
	}//ball roles on 1st plank
	
	
	while(yc>278)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
		yc-=2;
		circle(xc,yc,18);
		_sleep(40);//50
	}//ball falls
	for(i=0;i<54;i++)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		myButton(bctr);
		hammer(rea,reb,rec,red);
		xc+=2;yc-=1;
		circle(xc,yc,18);
		_sleep(50);//60
	}//roll slope on 2nd plank
for(i=0;i<10;i++)//centre must move 22px to touch dominoes so 2x11.
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
		xc+=2;
		circle(xc,yc,18);
		_sleep(40);//60
	}
for(i=0;i<3;i++)
{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
		xc-=1;
		circle(xc,yc,18);
		_sleep(50);//60
	}//bounce back
// glRecti(100,100,500,500);
int h=0,h2=0,h3=0,h4=0;float t1,t2,t3,t4,t5,t6;
//1st fall
for(i=0;i<8;i++)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		t1=da1;t2=db1;t3=dc1;t4=dd1;t5=dg1;t6=dh1;
		da1=newPathx(t1,t2,-h,de1,df1);
		db1=newPathy(t1,t2,-h,de1,df1);
		dc1=newPathx(t3,t4,-h,de1,df1);
		dd1=newPathy(t3,t4,-h,de1,df1);
		dg1=newPathx(t5,t6,-h,de1,df1);
		dh1=newPathy(t5,t6,-h,de1,df1);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);		
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
		circle(xc,yc,18);
		_sleep(60);//60
		h-=1;
}
float s1,s2,s3,s4,s5,s6;
//2nd fall
for(i=0;i<8;i++)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		waterJug(waterLevel);
		t1=da1;t2=db1;t3=dc1;t4=dd1;t5=dg1;t6=dh1;
		s1=da2;s2=db2;s3=dc2;s4=dd2;s5=dg2;s6=dh2;
		da2=newPathx(s1,s2,-h2,de2,df2);
		db2=newPathy(s1,s2,-h2,de2,df2);
		dc2=newPathx(s3,s4,-h2,de2,df2);
		dd2=newPathy(s3,s4,-h2,de2,df2);
		dg2=newPathx(s5,s6,-h2,de2,df2);
		dh2=newPathy(s5,s6,-h2,de2,df2);
		da1=newPathx(t1,t2,-h,de1,df1);
		db1=newPathy(t1,t2,-h,de1,df1);
		dc1=newPathx(t3,t4,-h,de1,df1);
		dd1=newPathy(t3,t4,-h,de1,df1);
		dg1=newPathx(t5,t6,-h,de1,df1);
		dh1=newPathy(t5,t6,-h,de1,df1);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		rope(rope_y);
		hammer(rea,reb,rec,red);
		circle(xc,yc,18);
		_sleep(60);//60
		h2-=1;
		h-=3;
		h/=2.5;
}
float q1,q2,q3,q4,q5,q6,u1,u2,u3,u4,u5,u6;
//3rd fall
for(i=0;i<8;i++)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		t1=da1;t2=db1;t3=dc1;t4=dd1;t5=dg1;t6=dh1;
		s1=da2;s2=db2;s3=dc2;s4=dd2;s5=dg2;s6=dh2;
		q1=da3;q2=db3;q3=dc3;q4=dd3;q5=dg3;q6=dh3;
		da3=newPathx(q1,q2,-h3,de3,df3);
		db3=newPathy(q1,q2,-h3,de3,df3);
		dc3=newPathx(q3,q4,-h3,de3,df3);
		dd3=newPathy(q3,q4,-h3,de3,df3);
		dg3=newPathx(q5,q6,-h3,de3,df3);
		dh3=newPathy(q5,q6,-h3,de3,df3);
		da2=newPathx(s1,s2,-h2,de2,df2);
		db2=newPathy(s1,s2,-h2,de2,df2);
		dc2=newPathx(s3,s4,-h2,de2,df2);
		dd2=newPathy(s3,s4,-h2,de2,df2);
		dg2=newPathx(s5,s6,-h2,de2,df2);
		dh2=newPathy(s5,s6,-h2,de2,df2);
		da1=newPathx(t1,t2,-h,de1,df1);
		db1=newPathy(t1,t2,-h,de1,df1);
		dc1=newPathx(t3,t4,-h,de1,df1);
		dd1=newPathy(t3,t4,-h,de1,df1);
		dg1=newPathx(t5,t6,-h,de1,df1);
		dh1=newPathy(t5,t6,-h,de1,df1);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
		circle(xc,yc,18);
		_sleep(60);//60
		h3-=1;h2-=3.8;
		h-=2;
		h2/=2.1;
		h/=2.1;
}
//4th fall
for(i=0;i<14;i++)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		waterJug(waterLevel);
		t1=da1;t2=db1;t3=dc1;t4=dd1;t5=dg1;t6=dh1;
		s1=da2;s2=db2;s3=dc2;s4=dd2;s5=dg2;s6=dh2;
		q1=da3;q2=db3;q3=dc3;q4=dd3;q5=dg3;q6=dh3;
		u1=da4;u2=db4;u3=dc4;u4=dd4;u5=dg4;u6=dh4;
		da4=newPathx(u1,u2,-h4,de4,df4);
		db4=newPathy(u1,u2,-h4,de4,df4);
		dc4=newPathx(u3,u4,-h4,de4,df4);
		dd4=newPathy(u3,u4,-h4,de4,df4);
		dg4=newPathx(u5,u6,-h4,de4,df4);
		dh4=newPathy(u5,u6,-h4,de4,df4);
		da3=newPathx(q1,q2,-h3/1.5,de3,df3);
		db3=newPathy(q1,q2,-h3/1.5,de3,df3);
		dc3=newPathx(q3,q4,-h3/1.5,de3,df3);
		dd3=newPathy(q3,q4,-h3/1.5,de3,df3);
		dg3=newPathx(q5,q6,-h3/1.5,de3,df3);
		dh3=newPathy(q5,q6,-h3/1.5,de3,df3);
		da2=newPathx(s1,s2,-h2,de2,df2);
		db2=newPathy(s1,s2,-h2,de2,df2);
		dc2=newPathx(s3,s4,-h2,de2,df2);
		dd2=newPathy(s3,s4,-h2,de2,df2);
		dg2=newPathx(s5,s6,-h2,de2,df2);
		dh2=newPathy(s5,s6,-h2,de2,df2);
		da1=newPathx(t1,t2,-h,de1,df1);
		db1=newPathy(t1,t2,-h,de1,df1);
		dc1=newPathx(t3,t4,-h,de1,df1);
		dd1=newPathy(t3,t4,-h,de1,df1);
		dg1=newPathx(t5,t6,-h,de1,df1);
		dh1=newPathy(t5,t6,-h,de1,df1);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		rope(rope_y);
		hammer(rea,reb,rec,red);
		circle(xc,yc,18);
		_sleep(60);//60
		h4-=1;h2-=2.9;h-=2;
		h3-=3;
		h2/=1.4;
		h3/=1.5;
		h/=1.5;
}
for(i=0;i<5;i++)
{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr++);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
			circle(xc,yc,18);
		_sleep(80);//60
}//button pushed
float k=0;
for(i=0;i<8;i++)
{glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		bctr-=2;
		myButton(bctr);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
			circle(xc,yc,18);
			glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(1008,205);
glVertex2f(1010,205);
glVertex2f(1010,160);
glVertex2f(1008,159);
glVertex2f(1008,205);
glEnd();
//k+=13.5;8
//waterflow(k);
/*if(i<3)
{
glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1008,159);
	glVertex2f(954,186);
	/*glVertex2f(1008,132);
	glVertex2f(954,186);
	glVertex2f(1008,159);
	glEnd();
	glFlush();
}*/
if(i<7 && i>3)
{
glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1008,159);
	glVertex2f(900,100);
	glVertex2f(1008,159);
	glEnd();
	glFlush();
}
glFlush();
  glColor3f(1, 0.5, 0.0);
_sleep(60);
}//water spills
k=0;
for(i=0;i<30;i++)
{
	k+=0.5;
	glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		basicSetup();
		myButton(bctr);
		dominoes(da1,db1,dc1,dd1,de1,df1,dg1,dh1);
		dominoes(da2,db2,dc2,dd2,de2,df2,dg2,dh2);
		dominoes(da3,db3,dc3,dd3,de3,df3,dg3,dh3);
		dominoes(da4,db4,dc4,dd4,de4,df4,dg4,dh4);
		rope(rope_y);
		waterJug(waterLevel);
		hammer(rea,reb,rec,red);
			circle(xc,yc,18);
	if(i<10)
	{
		glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1008,159);
	glVertex2f(900,100);
	glVertex2f(900,69);
	glVertex2f(900,100);
	glVertex2f(1008,159);
	glEnd();
	}
	/*else if(i<20)
	{
		glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(954,186);
	glVertex2f(900,100);
	glVertex2f(900,69);
	glVertex2f(900,100);
	glVertex2f(954,186);
	glEnd();
	}*/
	glBegin(GL_POLYGON);
	glVertex2f(900,80);
	glVertex2f(881,71);
	glVertex2f(920,71);
	glVertex2f(900,80);
	glEnd();//flow triangle*/
	glBegin(GL_POLYGON);
	glVertex2f(920,71);
	glVertex2f(881,71);
	glVertex2f(881,71+k);
	glVertex2f(920,71+k);
	glEnd();//filled glass
	glFlush();
	glColor3f(0,0,1);
	_sleep(60);
}//water fills
  glFlush();
}

/* Called when window is resized,
   also when window is first created,
   before the first call to display(). */
void
reshape(int w, int h)
{
  /* save new screen dimensions */
  width = (GLdouble) w;
  height = (GLdouble) h;

  /* tell OpenGL to use the whole window for drawing */
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  /* do an orthographic parallel projection with the coordinate
     system set to first quadrant, limited by screen/window size */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char *argv[])
{
  /* perform initialization NOT OpenGL/GLUT dependent,
     as we haven't created a GLUT window yet */
  init();

  /* initialize GLUT, let it extract command-line 
     GLUT options that you may provide 
     - NOTE THE '&' BEFORE argc */
  glutInit(&argc, argv);

  /* specify the display to be single 
     buffered and color as RGBA values */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  /* set the initial window size */
  glutInitWindowSize((int) width, (int) height);

  /* create the window and store the handle to it */
  wd = glutCreateWindow("Experiment with line drawing" /* title */ );

  /* --- register callbacks with GLUT --- */

  /* register function to handle window resizes */
  glutReshapeFunc(reshape);

  /* register function that draws in the window */
  glutDisplayFunc(display);

  /* start the GLUT main loop */
  glutMainLoop();

  return 0;
}
void circle(float x,float y,int rad)
{
	glColor3f(1,0.5,0);
	GLint circ=100;
  GLfloat angle;
  glBegin(GL_LINE_LOOP);
for (int i = 0; i < circ; i++) {
angle = 2*PI*i/circ;
glVertex2f(x+rad*cos(angle), y+rad*sin(angle));
}
glEnd();
glFlush();
}
void basicSetup()
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1366,384+128);
	glVertex2i(683+310,384+128);
	glVertex2i(683+310,384+128);
	glVertex2i(683-90,312);
	glVertex2i(683+310,384+128);
	glEnd();glFlush();//1st plank
	glBegin(GL_LINE_LOOP);
	glVertex2i(680-150,280);
	glVertex2i(680,205);                                        //595,312  530,280 -->-247.5=>circle goes down by 312-247.5=64.5
	glVertex2i(680,205);
	glVertex2i(1000,205);
	glVertex2i(680,205);
	glEnd();//2nd plank
	glBegin(GL_LINE_LOOP);
	glVertex2i(1100,205);
	glVertex2i(900,100);                                        //595,312  530,280 -->-247.5=>circle goes down by 312-247.5=64.5
	glVertex2i(1100,205);
	glEnd();//3rd vplank
	glFlush();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(880,90);
	glVertex2i(920,90);                                        //595,312  530,280 -->-247.5=>circle goes down by 312-247.5=64.5
	glVertex2i(920,70);
	glVertex2i(880,70);
	glVertex2i(880,90);
	glEnd();//glass
	glColor3f(1, 0.5, 0.0);
	glFlush();
	  
}//993,518  433,390
void hammer(int xa,int ya,int xb,int yb)
{
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i((xa+xb)/2,(ya+yb)/2);
	glVertex2i(683+380,600);
	glEnd();
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2i(xa,ya);
	glVertex2i(xb,ya);
	glVertex2i(xb,yb);
	glVertex2i(xa,yb);
	glVertex2i(xa,ya);
	glEnd();
	glFlush();
	glColor3f(0,0,1);
}
void rope(int ey)
{
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(683+380,600);
	glVertex2i(683-580,600);
	glEnd();
	glColor3f(1,0.2,0.3);
	circle(683-580,600-4,5);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(683-580-5,600-4);
	glVertex2i(683-580-5,600-380+ey);
	glEnd();
	glColor3f(1,0,0.6);
	circle(683-580-5,600-380+ey-4,4);
	glFlush();
	glColor3f(0,0,1);
}
void dominoes(float a,float b,float c,float d,float e,float f,float g,float h)
{//x between 680 1000 y 205(lower)
	glColor3f(0.5,0,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(a,b);
	glVertex2f(c,d);
	glVertex2f(e,f);
	glVertex2f(g,h);
	glVertex2f(a,b);
	glEnd();
	glFlush();
	glColor3f(1,0.5,0);
}
float newPathx(float x,float y,float angle,float tx,float ty)
{
	//x'=xcos0-ysin0
	float temp;
	angle = angle*PI/180;
	x=x-tx;y=y-ty;
	temp=x*cos(-angle)-y*sin(-angle);
	temp=temp+tx;
	return temp;
}
float newPathy(float x,float y,float angle,float tx,float ty)
{
	//y'=xsin0+ycos0
	float temp;
	angle = angle*PI/180;
	x=x-tx;y=y-ty;
	temp=x*sin(-angle)+y*cos(-angle);
	temp+=ty;
	return temp;
}
void myButton(float a)
{
	//875,205
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(874+80-10,198-a);
	glVertex2f(874+80,198-a);
	glVertex2f(874+80,205);
	glVertex2f(874+80-10,205);
	glVertex2f(874+80-10,198-a);
	glEnd();
	glFlush();
	glColor3f(1, 0.5, 0.0);
}
void waterJug(float l)
{
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINE_LOOP);
	glVertex2f(874+90,205);
	glVertex2f(874+90,245);
	glVertex2f(1000,245);
	glVertex2f(1000,205);
	glVertex2f(870+90,205);
	glEnd();
	glFlush();
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000,206);
	glVertex2f(1000,209);
	glVertex2f(1010,209);
	glVertex2f(1010,206);
	glVertex2f(1000,206);
	glEnd();//tap opening
	glFlush();
	glBegin(GL_LINE_LOOP);
	glVertex2f(1002,209);
	glVertex2f(1002,212);
	glVertex2f(1007,212);
	glVertex2f(1007,209);
	glVertex2f(1002,209);
	glEnd();
	glFlush();
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
	glVertex2f(874+90,206);
	glVertex2f(874+90,206+l);
	glVertex2f(1000,206+l);
	glVertex2f(1000,206);
	glVertex2f(870+90,206);
	glEnd();
	glFlush();

	glColor3f(1, 0.5, 0.0);
}
void waterflow(float a)
{
	float y;
	y=abs(100-(1008-a-900)/2);
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1008,159);
	glVertex2f(1008-a,y);
	glVertex2f(1008,159);
	glEnd();
	glColor3f(1,0.5,0);
}