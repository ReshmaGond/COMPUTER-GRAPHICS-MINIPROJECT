#include<stdio.h>
#include<String.h>
#include<GL/glut.h>
int slide=0;
float x=0.0;
float y=0.0;
float z=0.0;
float x1=0.0;
float y1=0.0;
float z1=0.0;
float x2=0.0;
float y2=0.0;
float x3=0.0;
float y3=0.0;
float z3=700.0;
int i;
float u=0.0;

void output(char *s)
{
        int k;
        for(k=0;k<strlen(s);k++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[k]);
}
void timer(int v){
		if(x==5)
			x=1;
		if(y==5)
			y=1;
		if(z==2)
			z=1;
			
		else{
			x+=0.5;
			y=0.5;
			z+=0.5;	
		}
		
		glutPostRedisplay();
		for(i=0;i<=99999999.99;i++);
		glutTimerFunc(999999999999,timer,0);		
	}

void timer1(int v){
		if (x1==75)
			x1=75;
		else
			x1+=0.5;	
	    if(z1==75){
	    	z1=75;
	    	x1=75;
	    }
		else
			z1+=0.5;
		glutPostRedisplay();
		glutTimerFunc(100,timer1,0);		
	}

void timer2(int v){
	if (x2==50)
		x2=50;
	else{

		x2+=0.25;
		y2+=1.0;
		//z+=0.25;
	}
	glutPostRedisplay();
	glutTimerFunc(100,timer2,0);		
}

void law3_arrow(){	
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_POLYGON);//red arrow 2
	glVertex2i(1500+z3,325);
    glVertex2i(1500+z3,275);
    glVertex2i(1800+z3,275);
    glVertex2i(1800+z3,325);
    glEnd();
    
    glColor3f(0.9,0.0,0.0);    
    glBegin(GL_TRIANGLES);//arrow 2
    glVertex2i(1400+z3,300);
    glVertex2i(1500+z3,355);
    glVertex2i(1500+z3,245);
    glEnd();
   
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(1570+z3,293,0.0);
    output("Reaction force");
    glPopMatrix();
    
    glFlush();
}

void timer3(int v){
 	if (x3==50){
	 	x3=50;
	 	z3=-400.0;
 	}
 	
	 else{
 		x3+=0.25;
 		y3+=2.0;
   }
	 glutPostRedisplay();
	 glutTimerFunc(25,timer3,0);
 }

void forcearrow(){
		
	glLineWidth(30);
	glPushMatrix();
	glTranslatef(0+x1,0,0);
	glBegin(GL_LINES);  //arrow
	glColor3f(0.3,0.0,0.5);
	glVertex2i(1030,450);
	glVertex2i(1180,450);
	glEnd();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(0+x1,0,0);
	glBegin(GL_TRIANGLES);//arrow triangle
	glColor3f(0.3,0.0,0.5);
	glVertex2i(1180,490);
	glVertex2i(1180,410);
	glVertex2i(1220,450);
	glEnd();
	glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(0+x1,0,0);
	glColor3f(1.0,1.0,1.0);
   	glRasterPos3f(1060,440,0.0);
    output("FORCE");
    glPopMatrix();
			
	glFlush();
	}

/*void law1_movement(){
	
}*/


void slider(){
    glColor3f(0.7,0.6,1.4);
	glBegin(GL_POLYGON);//slider
	glVertex2f(960+u,510);
	glVertex2f(960+u,540);
	glVertex2f(1500,540);
	glVertex2f(1500,510);
	glEnd();
}
void slider2(){
    glColor3f(0.9,0.9,1.0);
	glBegin(GL_POLYGON);//slider
	glVertex2f(960+u,630);
	glVertex2f(960+u,660);
	glVertex2f(1500,660);
	glVertex2f(1500,630);
	glEnd();
}

void slider3(){
   //	glColor3f(1,0.0,0.0);
	glColor3f(0.8,0.9,1.0);
	glBegin(GL_POLYGON);//slider
	glVertex2f(600+u,670);
	glVertex2f(600+u,700);
	glVertex2f(1040,700);
	glVertex2f(1040,670);
	glEnd();
}

void slide_timer(int v){
	if(u<540){
		u+=10.0;
	glutPostRedisplay();
	glutTimerFunc(100,slide_timer,0);
	}
}

void slide_timer3(int v){
	if(u<100){
		u+=10.0;
	glutPostRedisplay();
	glutTimerFunc(100,slide_timer,0);
	}
}

void background(){
	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	*/
	glColor3f(0.9,0.8,0.3);
	glBegin(GL_POLYGON);//BACKGROUND
	glVertex2i(0,0);
	glVertex2i(0,950);
	glVertex2i(1900,950);
	glVertex2i(1900,0);
	glEnd();
	
	glColor3f(0.9,0.7,0.1);
	glBegin(GL_TRIANGLES);//triangle top right BACKGROUND
	glVertex2i(1560,920);
	glVertex2i(1560,600);
	glVertex2i(1870,600);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//black BACKGROUND
	glVertex2i(150,150);
	glVertex2i(150,800);
	glVertex2i(1750,800);
	glVertex2i(1750,150);
	glEnd();
	
	glColor3f(0.9,0.7,0.0);
	glBegin(GL_TRIANGLES);//triangle BACKGROUND
	glVertex2i(80,400);
	glVertex2i(80,90);
	glVertex2i(370,90);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//lines black BACKGROUND left
	glVertex2i(150,500);
	glVertex2i(50,580);
	glVertex2i(50,700);
	glVertex2i(150,620);
	glEnd();
	
	glColor3f(0.9,0.7,0.0);
	glBegin(GL_POLYGON);//lines gold BACKGROUND left
	glVertex2i(150,700);
	glVertex2i(100,740);
	glVertex2i(100,800);
	glVertex2i(150,760);
	glEnd();
	
	glColor3f(0.9,0.7,0.0);
	glBegin(GL_TRIANGLES);//triangle top left BACKGROUND
	glVertex2i(420,740);
	glVertex2i(280,740);
	glVertex2i(280,900);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//top black line strip BACKGROUND
	glVertex2i(1050,800);
	glVertex2i(950,870);
	glVertex2i(950,910);
	glVertex2i(1110,800);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//lines black BACKGROUND ri8
	glVertex2i(1750,475);
	glVertex2i(1900,300);
	glVertex2i(1800,300);
	glVertex2i(1750,355);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//lines black BACKGROUND ri8 down
	glVertex2i(1550,150);
	glVertex2i(1680,40);
	glVertex2i(1740,40);
	glVertex2i(1617,150);
	glEnd();
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//line white BACKGROUND ri8 down
	glVertex2i(270,280);
	glVertex2i(550,10);
	glVertex2i(590,10);
	glVertex2i(270,320);
	glEnd();
	glFlush();
}

void intro()     
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	background();
	
	glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(480.0,750.0,0.0);
	output("MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(510.0,690.0,0.0);
	output("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glPopMatrix();
    
    glColor3f(0.9,0.7,0.4);
    glPushMatrix();
    glRasterPos3f(780.0,600.0,0.0);
	output("A MINI PROJECT ON:");
    glPopMatrix();
    
    glColor3f(0.9,0.7,0.0);
    glPushMatrix();
    glRasterPos3f(700.0,520.0,0.0);
	output("\"NEWTON'S LAWS OF MOTION\"");
    glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(400.0,440.0,0.0);
	output("BY:");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(1500.0,440.0,0.0);
	output("GUIDES:");
    glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(320.0,390.0,0.0);
	output("RACHANA H R");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(850.0,390.0,0.0);
	output("4MT18CS066");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(1400.0,390.0,0.0);
	output("Ms.AISHWARYA BHAT");
    glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(320.0,340.0,0.0);
	output("RESHMA");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(850.0,340.0,0.0);
	output("4MT18CS074");
    glPopMatrix();
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(1400.0,340.0,0.0);
	output("Ms.SUNITHA N V");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(1400.0,20.0,0.0);
	output("Press 'a' to move to next page");
    glPopMatrix();
    
	glFlush();
}

void content_page(){
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	background();
			
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glRasterPos3f(850,650.0,0.0);
	output("NAVIGATIONS");
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glRasterPos3f(400.0,520.0,0.0);
	output("NEWTON'S FIRST LAW OF MOTION");
    glPopMatrix();
	
	glColor3f(0.9,0.7,0);
    glPushMatrix();
    glRasterPos3f(1200.0,520.0,0.0);
	output("PRESS '1'");
    glPopMatrix();
    
    glColor3f(1,1,1);
    glPushMatrix();
    glRasterPos3f(400.0,450.0,0.0);
	output("NEWTON'S SECOND LAW OF MOTION");
    glPopMatrix();
	
	glColor3f(0.9,0.7,0);
    glPushMatrix();
    glRasterPos3f(1200.0,450.0,0.0);
	output("PRESS '2'");
    glPopMatrix();
    
    glColor3f(1,1,1);
    glPushMatrix();
    glRasterPos3f(400.0,380.0,0.0);
	output("NEWTON'S THIRD LAW OF MOTION");
    glPopMatrix();
	
	glColor3f(0.9,0.7,0);
    glPushMatrix();
    glRasterPos3f(1200.0,380.0,0.0);
	output("PRESS '3'");
    glPopMatrix();
    
    glFlush();
}

void law1_stmt()
{	
	//scene();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
 	
	glColor3f(1,0.9,0.6);
	glBegin(GL_POLYGON);  //WALL UP
	glVertex2i(0,251);
	glVertex2i(0,1000);
	glVertex2i(2000,1000);
	glVertex2i(2000,251);
	glEnd();
	
	glColor3f(0.5,0.8,0.8);
	glBegin(GL_POLYGON);  //WALL DOWN
	glVertex2i(0,241);
	glVertex2i(0,0);
	glVertex2i(2000,0);
	glVertex2i(2000,241);
	glEnd();
	
    glColor3f(0.0,0.4,0.1);
	glBegin(GL_POLYGON);  //BOARD
	glVertex2i(200,910);
	glVertex2i(200,410);
	glVertex2i(1220,410);
	glVertex2i(1220,910);
	glEnd();
	
	glColor3f(0.5,0.6,0.6);
	glLineWidth(8);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(200,910);	
	glVertex2i(1220,910);
	glVertex2i(200,410);	
	glVertex2i(200,915);
	glVertex2i(1220,410);	
	glVertex2i(1220,915);
	glEnd();
	
	glColor3f(0.5,0.5,0.5);
	glLineWidth(14);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(160,410);	
	glVertex2i(1260,410);
		
	glColor3f(0.4,0.6,0.6);
	glLineWidth(12);
	glBegin(GL_LINES);// back line
	glVertex2i(0,250);	
	glVertex2i(2000,250);
	glEnd();
				
	glColor3f(1,1,1);
	glLineWidth(6);
	glBegin(GL_LINES);// Chalk piece
	glVertex2i(300,423);	
	glVertex2i(345,423);
	glVertex2i(380,423);	
	glVertex2i(335,434);
	glEnd();
	
	glColor3f(1.0,1.0,1.0); 
    glPushMatrix();
    glRasterPos3f(450.0,850.0,0.0);
	output("NEWTON'S FIRST LAW OF MOTION");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,750.0,0.0);
	output("If a body is at rest or moving at a constant speed in a straight line,");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,710.0,0.0);
	output("it will remain at rest or keep moving in a straight line at constant speed");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,670.0,0.0);
	output("unless it is acted upon by a force.");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,610.0,0.0);
	output("* This law is also know as LAW OF INERTIA");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,50.0,0.0);
	output("Press 'x' for demonstration...");
    glPopMatrix();
				
    glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON);  //TABLE
	glVertex2i(1400,210);
	glVertex2i(1400,420);
	glVertex2i(1820,420);
	glVertex2i(1820,210);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE1
	glVertex2i(1410,410);
	glVertex2i(1810,410);
	glVertex2i(1810,330);
	glVertex2i(1410,330);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE2
	glVertex2i(1410,240);
	glVertex2i(1810,240);
	glVertex2i(1810,320);
	glVertex2i(1410,320);
	glEnd();
			
	glColor3f(1,0.8,0.5);
	glLineWidth(6);
	glBegin(GL_LINES);//  lines inside table
	glVertex2i(1450,260);	
	glVertex2i(1490,260);
	glVertex2i(1450,350);	
	glVertex2i(1490,350);
	glVertex2i(1770,350);	
	glVertex2i(1730,350);
	glVertex2i(1770,260);	
	glVertex2i(1730,260);
	glEnd();
				
    glColor3f(0.7,1.0,0.0);
	glBegin(GL_POLYGON);  //Pen box
	glVertex2i(1655,420);
	glVertex2i(1680,420);
	glVertex2i(1687,465);
	glVertex2i(1648,465);
	glEnd();
			
	glColor3f(0.3,0.2,1.0);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1654,465);	
	glVertex2i(1650,485);
	glEnd();
				
	glColor3f(0.9,0.5,0.1);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1679,465);	
	glVertex2i(1684,480);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);  //Pot
	glVertex2i(125,220);
	glVertex2i(175,220);
	glVertex2i(200,290);
	glVertex2i(100,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(130,290);
	glVertex2i(150,390);
	glVertex2i(170,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(160,290);
	glVertex2i(210,340);
	glVertex2i(190,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(110,290);
	glVertex2i(80,320);
	glVertex2i(160,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(120,290);
	glVertex2i(110,360);
	glVertex2i(150,320);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(140,290);
	glVertex2i(190,360);
	glVertex2i(180,290);
	glEnd();
		
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1190,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
			
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1,0.8,0.8);
	glTranslatef(1300,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
	
	//teacher skirt
    glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1310,500);
	glVertex2i(1370,190);
	glVertex2i(1300,170);
	glEnd();
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1300,170);
	glEnd();
	
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1130,190);
	glEnd();
	
	//teacher top	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1195,600);
	glVertex2i(1315,600);
	glVertex2i(1310,500);
	glEnd();
	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  //left shoulder
	glVertex2i(1240,600);
	glVertex2i(1210,630);
	glVertex2i(1140,570);
	glVertex2i(1150,540);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0+x,0+y,0);
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //left hand 
	glVertex2i(1160,550);
	glVertex2i(1135,530);
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glEnd();
	
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //left hand
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glVertex2i(1140,660);
	glVertex2i(1090,660);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glLineWidth(8);
	glBegin(GL_LINES);//fingers
	glVertex2i(1130,660);	
	glVertex2i(1120,690);
	glEnd();
	glPopMatrix();
	
	timer(0);
		
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_POLYGON); //BOOK
	glVertex2i(1230,500);
	glVertex2i(1300,540);
	glVertex2i(1350,450);
	glVertex2i(1290,410);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right shoulder 
	glVertex2i(1270,600);
	glVertex2i(1300,630);
	glVertex2i(1370,520);
	glVertex2i(1340,500);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1365,525);
	glVertex2i(1270,480);
	glVertex2i(1290,450);
	glVertex2i(1380,500);
	glEnd();
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1270,480);
	glVertex2i(1285,460);
	glVertex2i(1270,440);
	glVertex2i(1245,480);
	glEnd();
			
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck down
	glVertex2i(1230,600);
	glVertex2i(1280,600);
	glVertex2i(1300,630);
	glVertex2i(1210,630);
	glEnd();
			
	glColor3f(1,1,0.8);
	glBegin(GL_TRIANGLES); //Inner white
	glVertex2i(1220,620);
	glVertex2i(1290,620);
	glVertex2i(1256,567);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur right
	glVertex2i(1300,629);
	glVertex2i(1275,635);
	glVertex2i(1254,564);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur left
	glVertex2i(1210,629);
	glVertex2i(1235,635);
	glVertex2i(1256,565);
	glEnd();

	glColor3f(1,0.0,0.4);
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2i(1256,555);//BUTTONS
	glVertex2i(1256,530);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck up
	glVertex2i(1240,630);
	glVertex2i(1270,630);
	glVertex2i(1270,650);
	glVertex2i(1240,650);
	glEnd();
	
		
	glMatrixMode(GL_MODELVIEW);// hair semicircle
	glPushMatrix();
	glColor3f(0.6,0.3,0.1);
	glTranslatef(1250,720,0);
	glutSolidSphere(75,100,30);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);// Face
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1250,700,0);
	glutSolidSphere(60,80,10);
	glPopMatrix();
				
	glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON); //hair above
	glVertex2i(1200,720);
	glVertex2i(1220,775);
	glVertex2i(1285,775);
	glVertex2i(1300,720);
	glEnd();
		
	glColor3f(0,0.2,0.3);
	glLineWidth(1);
	glBegin(GL_LINES);// nose
	glVertex2i(1242,675);	
	glVertex2i(1247,695);
	glVertex2i(1242,675);	
	glVertex2i(1250,676);	
	glEnd();
			
	glColor3f(0,0,0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);// Eye brows LEFT
	glVertex2i(1210,710);	
	glVertex2i(1220,713);
	glVertex2i(1230,710);	
	glEnd();
	
	glBegin(GL_LINE_STRIP);//Eye brows RIGHT
	glVertex2i(1265,710);
	glVertex2i(1275,713);	
	glVertex2i(1285,710);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0,0+z,0);
	glColor3f(0.8,0,0.2);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(1235,665);  //mouth	
	glVertex2i(1237,664);
	glVertex2i(1240,663);
	glVertex2i(1245,662);
	glVertex2i(1250,662);
	glVertex2i(1255,663);
	glVertex2i(1260,664);
	glVertex2i(1265,665);
	glEnd();
	glPopMatrix();
	
	glColor3f(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(1220,700);//EYES
	glVertex2i(1275,700);
	glEnd();
	
	glFlush();

}

int law1(){
	auto void display_right();
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	void display_right(){
		glColor3f(0.7,0.2,0.0);
		glBegin(GL_POLYGON);  //horizontal table
		glVertex2i(1150,380);
		glVertex2i(1850,380);
		glVertex2i(1850,350);
		glVertex2i(1150,350);
		glVertex2i(1150,380);//ulta side
		glVertex2i(1170,400);
		glVertex2i(1870,400);
		glVertex2i(1850,380);
		glVertex2i(1850,350);//rightside
		glVertex2i(1870,370);
		glVertex2i(1870,400);
		glEnd();
		
		glBegin(GL_POLYGON);  //table leg2
		glVertex2i(1770,350);
		glVertex2i(1790,350);
		glVertex2i(1790,0);
		glVertex2i(1770,0);
		glEnd();
		
		glBegin(GL_POLYGON);  //table leg2 back
		glVertex2i(1800,350);
		glVertex2i(1820,350);
		glVertex2i(1820,20);
		glVertex2i(1800,20);
		glEnd();
		
		glBegin(GL_POLYGON);  //table leg1
		glVertex2i(1210,350);
		glVertex2i(1230,350);
		glVertex2i(1230,0);
		glVertex2i(1210,0);
		glEnd();
		
		glBegin(GL_POLYGON);  //table leg1back
		glVertex2i(1240,350);
		glVertex2i(1260,350);
		glVertex2i(1260,20);
		glVertex2i(1240,20);
		glEnd();
		
		glPushMatrix();
		glColor3f(0.3,0.0,0.5);
		glTranslatef(0+x1,0,0);
		glBegin(GL_POLYGON);  //box on table top
		glVertex2i(1220,381);
		glVertex2i(1330,381);
		glVertex2i(1330,451);
		glVertex2i(1220,451);
		glVertex2i(1220,451);//backface
		glVertex2i(1230,461);
		glVertex2i(1340,461);
		glVertex2i(1330,451);
		glVertex2i(1330,451);//side face
		glVertex2i(1330,381);
		glVertex2i(1340,391);
		glVertex2i(1340,461);
		glEnd();
		glPopMatrix();
		
		forcearrow();
		glFlush();
		
	}

	glColor3f(0.7,0.6,1.4);
	glBegin(GL_POLYGON);//wall paint top
	glVertex2f(1,200);
	glVertex2f(1,949);
	glVertex2f(1899,949);
	glVertex2f(1899,200);
	glEnd();
	
	glColor3f(1.0,0.5,0.6);
	glBegin(GL_POLYGON);//wall paint down
	glVertex2f(1,199);
	glVertex2f(1,0);
	glVertex2f(1899,0);
	glVertex2f(1899,199);
	glEnd();
	
	glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1000.0,520.0,0.0);
	output("Press 'm' to apply force...");
    glPopMatrix();
	
	glColor3f(0.7,0.6,1.4);
	glBegin(GL_POLYGON);   //side cut1
	glVertex2i(0,0);
	glVertex2i(0,200);
	glVertex2i(30,200);
	glVertex2i(0,0);
	glEnd();
	
	glColor3f(0.7,0.6,1.4);
	glBegin(GL_POLYGON);//side cut2
	glVertex2i(1900,0);
	glVertex2i(1900,200);
	glVertex2i(1870,200);
	glVertex2i(1900,0);
	glEnd();
	
	
	glColor3f(1.0,0.5,0.6);
	glLineWidth(2);
	glBegin(GL_POLYGON);  //window border
	glVertex2i(90,640);
	glVertex2i(90,860);
	glVertex2i(310,860);
	glVertex2i(310,640);
	glEnd();
	
	glColor3f(0.9,0.9,1.0);
	glBegin(GL_POLYGON);  //window
	glVertex2i(100,650);
	glVertex2i(100,850);
	glVertex2i(300,850);
	glVertex2i(300,650);
	glEnd();
	
	glMatrixMode(GL_MODELVIEW);//sun
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(160,790,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINES);  //window rod
	glVertex2i(200,650);
	glVertex2i(200,850);
	glVertex2i(100,750);
	glVertex2i(300,750);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);  //crow
	glVertex2i(220,780);
	glVertex2i(230,770);
	glVertex2i(240,783);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);  //crow
	glVertex2i(240,790);
	glVertex2i(250,780);
	glVertex2i(260,792);
	glEnd();
	
	glColor3f(0.7,0.2,0.0);
	glBegin(GL_POLYGON);  //horizontal table
	glVertex2i(50,380);
	glVertex2i(750,380);
	glVertex2i(750,350);
	glVertex2i(50,350);
	glVertex2i(50,380);//ulta side
	glVertex2i(70,400);
	glVertex2i(770,400);
	glVertex2i(750,380);
	glVertex2i(750,350);//rightside
	glVertex2i(770,370);
	glVertex2i(770,400);
	glEnd();
	
	glBegin(GL_POLYGON);  //table leg2
	glVertex2i(670,350);
	glVertex2i(690,350);
	glVertex2i(690,0);
	glVertex2i(670,0);
	glEnd();
	
	glBegin(GL_POLYGON);  //table leg2 back
	glVertex2i(700,350);
	glVertex2i(720,350);
	glVertex2i(720,20);
	glVertex2i(700,20);
	glEnd();
	
	glBegin(GL_POLYGON);  //table leg1
	glVertex2i(110,350);
	glVertex2i(130,350);
	glVertex2i(130,0);
	glVertex2i(110,0);
	glEnd();
	
	glBegin(GL_POLYGON);  //table leg1back
	glVertex2i(140,350);
	glVertex2i(160,350);
	glVertex2i(160,20);
	glVertex2i(140,20);
	glEnd();
	
	glColor3f(0.3,0.0,0.5);
	glBegin(GL_POLYGON);  //box on table top
	glVertex2i(120,381);
	glVertex2i(230,381);
	glVertex2i(230,451);
	glVertex2i(120,451);
	glVertex2i(120,451);//box back
	glVertex2i(130,461);
	glVertex2i(240,461);
	glVertex2i(230,451);//side face
	glVertex2i(230,381);
	glVertex2i(240,391);
	glVertex2i(240,461);
	glEnd();
	
	glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,40.0,0.0);
	output("Press '2' to move to next page...");
    glPopMatrix();
	
	display_right();
    
	glFlush();
}

void law_stmt2(){
	
	//SECOND LAW DISPLAY
 
 	//scene();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
 	
	glColor3f(1,0.9,0.6);
	glBegin(GL_POLYGON);  //WALL UP
	glVertex2i(0,251);
	glVertex2i(0,1000);
	glVertex2i(2000,1000);
	glVertex2i(2000,251);
	glEnd();
	
	glColor3f(0.5,0.8,0.8);
	glBegin(GL_POLYGON);  //WALL DOWN
	glVertex2i(0,241);
	glVertex2i(0,0);
	glVertex2i(2000,0);
	glVertex2i(2000,241);
	glEnd();
	
    glColor3f(0.0,0.4,0.1);
	glBegin(GL_POLYGON);  //BOARD
	glVertex2i(200,910);
	glVertex2i(200,410);
	glVertex2i(1220,410);
	glVertex2i(1220,910);
	glEnd();
	
	glColor3f(0.5,0.6,0.6);
	glLineWidth(8);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(200,910);	
	glVertex2i(1220,910);
	glVertex2i(200,410);	
	glVertex2i(200,915);
	glVertex2i(1220,410);	
	glVertex2i(1220,915);
	glEnd();
	
	glColor3f(0.5,0.5,0.5);
	glLineWidth(14);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(160,410);	
	glVertex2i(1260,410);
		
	glColor3f(0.4,0.6,0.6);
	glLineWidth(12);
	glBegin(GL_LINES);// back line
	glVertex2i(0,250);	
	glVertex2i(2000,250);
	glEnd();
				
	glColor3f(1,1,1);
	glLineWidth(6);
	glBegin(GL_LINES);// Chalk piece
	glVertex2i(300,423);	
	glVertex2i(345,423);
	glVertex2i(380,423);	
	glVertex2i(335,434);
	glEnd();
	
	//statements
	glColor3f(1.0,1.0,1.0); 
    glPushMatrix();
    glRasterPos3f(450.0,850.0,0.0);
	output("NEWTON'S SECOND LAW OF MOTION");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,750.0,0.0);
	output("The acceleration of an object as product by a net force is directly");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,710.0,0.0);
	output("proportional to the magnitude of the net force,in the same direction as");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(280.0,670.0,0.0);
	output("the net force and inversely proportional to the mass of the object.");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(290.0,610.0,0.0);
	output(" i.e,  F = MA ");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,40.0,0.0);
	output("Press 'y' for demonstration...");
    glPopMatrix();
	
	glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON);  //TABLE
	glVertex2i(1400,210);
	glVertex2i(1400,420);
	glVertex2i(1820,420);
	glVertex2i(1820,210);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE1
	glVertex2i(1410,410);
	glVertex2i(1810,410);
	glVertex2i(1810,330);
	glVertex2i(1410,330);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE2
	glVertex2i(1410,240);
	glVertex2i(1810,240);
	glVertex2i(1810,320);
	glVertex2i(1410,320);
	glEnd();
			
	glColor3f(1,0.8,0.5);
	glLineWidth(6);
	glBegin(GL_LINES);//  lines inside table
	glVertex2i(1450,260);	
	glVertex2i(1490,260);
	glVertex2i(1450,350);	
	glVertex2i(1490,350);
	glVertex2i(1770,350);	
	glVertex2i(1730,350);
	glVertex2i(1770,260);	
	glVertex2i(1730,260);
	glEnd();
				
    glColor3f(0.7,1.0,0.0);
	glBegin(GL_POLYGON);  //Pen box
	glVertex2i(1655,420);
	glVertex2i(1680,420);
	glVertex2i(1687,465);
	glVertex2i(1648,465);
	glEnd();
			
	glColor3f(0.3,0.2,1.0);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1654,465);	
	glVertex2i(1650,485);
	glEnd();
				
	glColor3f(0.9,0.5,0.1);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1679,465);	
	glVertex2i(1684,480);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);  //Pot
	glVertex2i(125,220);
	glVertex2i(175,220);
	glVertex2i(200,290);
	glVertex2i(100,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(130,290);
	glVertex2i(150,390);
	glVertex2i(170,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(160,290);
	glVertex2i(210,340);
	glVertex2i(190,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(110,290);
	glVertex2i(80,320);
	glVertex2i(160,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(120,290);
	glVertex2i(110,360);
	glVertex2i(150,320);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(140,290);
	glVertex2i(190,360);
	glVertex2i(180,290);
	glEnd();
		
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1190,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
			
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1,0.8,0.8);
	glTranslatef(1300,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
	
	//teacher skirt
    glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1310,500);
	glVertex2i(1370,190);
	glVertex2i(1300,170);
	glEnd();
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1300,170);
	glEnd();
	
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1130,190);
	glEnd();
	
	//teacher top	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1195,600);
	glVertex2i(1315,600);
	glVertex2i(1310,500);
	glEnd();
	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  //left shoulder
	glVertex2i(1240,600);
	glVertex2i(1210,630);
	glVertex2i(1140,570);
	glVertex2i(1150,540);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0+x,0+y,0);
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //left hand 
	glVertex2i(1160,550);
	glVertex2i(1135,530);
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glEnd();
	
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //left hand
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glVertex2i(1140,660);
	glVertex2i(1090,660);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glLineWidth(8);
	glBegin(GL_LINES);//fingers
	glVertex2i(1130,660);	
	glVertex2i(1120,690);
	glEnd();
	glPopMatrix();
	
	timer(0);
		
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_POLYGON); //BOOK
	glVertex2i(1230,500);
	glVertex2i(1300,540);
	glVertex2i(1350,450);
	glVertex2i(1290,410);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right shoulder 
	glVertex2i(1270,600);
	glVertex2i(1300,630);
	glVertex2i(1370,520);
	glVertex2i(1340,500);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1365,525);
	glVertex2i(1270,480);
	glVertex2i(1290,450);
	glVertex2i(1380,500);
	glEnd();
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1270,480);
	glVertex2i(1285,460);
	glVertex2i(1270,440);
	glVertex2i(1245,480);
	glEnd();
			
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck down
	glVertex2i(1230,600);
	glVertex2i(1280,600);
	glVertex2i(1300,630);
	glVertex2i(1210,630);
	glEnd();
			
	glColor3f(1,1,0.8);
	glBegin(GL_TRIANGLES); //Inner white
	glVertex2i(1220,620);
	glVertex2i(1290,620);
	glVertex2i(1256,567);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur right
	glVertex2i(1300,629);
	glVertex2i(1275,635);
	glVertex2i(1254,564);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur left
	glVertex2i(1210,629);
	glVertex2i(1235,635);
	glVertex2i(1256,565);
	glEnd();

	glColor3f(1,0.0,0.4);
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2i(1256,555);//BUTTONS
	glVertex2i(1256,530);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck up
	glVertex2i(1240,630);
	glVertex2i(1270,630);
	glVertex2i(1270,650);
	glVertex2i(1240,650);
	glEnd();
	
		
	glMatrixMode(GL_MODELVIEW);// hair semicircle
	glPushMatrix();
	glColor3f(0.6,0.3,0.1);
	glTranslatef(1250,720,0);
	glutSolidSphere(75,100,30);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);// Face
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1250,700,0);
	glutSolidSphere(60,80,10);
	glPopMatrix();
				
	glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON); //hair above
	glVertex2i(1200,720);
	glVertex2i(1220,775);
	glVertex2i(1285,775);
	glVertex2i(1300,720);
	glEnd();
		
	glColor3f(0,0.2,0.3);
	glLineWidth(1);
	glBegin(GL_LINES);// nose
	glVertex2i(1242,675);	
	glVertex2i(1247,695);
	glVertex2i(1242,675);	
	glVertex2i(1250,676);	
	glEnd();
			
	glColor3f(0,0,0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);// Eye brows LEFT
	glVertex2i(1210,710);	
	glVertex2i(1220,713);
	glVertex2i(1230,710);	
	glEnd();
	
	glBegin(GL_LINE_STRIP);//Eye brows RIGHT
	glVertex2i(1265,710);
	glVertex2i(1275,713);	
	glVertex2i(1285,710);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0,0+z,0);
	glColor3f(0.8,0,0.2);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(1235,665);  //mouth	
	glVertex2i(1237,664);
	glVertex2i(1240,663);
	glVertex2i(1245,662);
	glVertex2i(1250,662);
	glVertex2i(1255,663);
	glVertex2i(1260,664);
	glVertex2i(1265,665);
	glEnd();
	glPopMatrix();
	
	glColor3f(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(1220,700);//EYES
	glVertex2i(1275,700);
	glEnd();
	
	glFlush();
}

void law2(){

	auto void display_right();
	auto void display_left();
	auto void word_left();
	//auto void word_right();
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	void display_right(){	/////////////////////////////////////display_right
		glMatrixMode(GL_MODELVIEW);//wheel1
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(1070,400,0);
		glutSolidSphere(50,100,10);
		glPopMatrix();
		
		glColor3f(0.0,0.0,0.0);
		glLineWidth(10);
		glBegin(GL_LINES);  // rod_left
		glVertex2i(1070,480);
		glVertex2i(1070,400);
		glVertex2i(1070,400);
		glVertex2i(1170,490);
		glEnd();
		
		glMatrixMode(GL_MODELVIEW);//wheel1_inside
		glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(1070,400,0);
		glutSolidSphere(35,100,10);
		glPopMatrix();
	
		glMatrixMode(GL_MODELVIEW);//wheel1_center
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(1070,400,0);
		glutSolidSphere(10,100,10);
		glPopMatrix();
		
		glMatrixMode(GL_MODELVIEW);//wheel2
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(1370,400,0);
		glutSolidSphere(50,100,10);
		glPopMatrix();
		
		glBegin(GL_LINES);  // rod_right
		glVertex2i(1370,480);
		glVertex2i(1370,400);
		glVertex2i(1370,400);
		glVertex2i(1270,490);
		glEnd();
		
		glMatrixMode(GL_MODELVIEW);//wheel2_inside
		glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(1370,400,0);
		glutSolidSphere(35,100,10);
		glPopMatrix();
		
		glMatrixMode(GL_MODELVIEW);//wheel2_center
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(1370,400,0);
		glutSolidSphere(10,100,10);
		glPopMatrix();
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//horz.table
		glVertex2f(970,520);
		glVertex2f(970,480);
		glVertex2f(1470,480);
		glVertex2f(1470,520);
		glEnd();
		
		glColor3f(0.0,0.0,0.0);
		glLineWidth(7);
		glBegin(GL_LINES);  //vehicle rod
		glVertex2i(1370,477);
		glVertex2i(1500,477);
		glVertex2i(1499,477);
		glVertex2i(1650,590);
		glEnd();
		
		glLineWidth(10);
		glBegin(GL_LINES);  //force arrow
		glColor3f(0.0,0.0,0.0);	
		glVertex2i(1655,590);
		glVertex2i(1700,590);
		glEnd();
		
		glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(1700,580);
		glVertex2i(1700,600);
		glVertex2i(1715,590);
		glEnd();
		
		glColor3f(0.5,0.5,0.6);
		glBegin(GL_POLYGON);//box
		glVertex2f(1020,520);
		glVertex2f(1020,600);
		glVertex2f(1200,600);
		glVertex2f(1200,520);
		glEnd();
		
		//word_right();
		
		glLineWidth(40);
		glBegin(GL_LINES);  //arrow_rod
		glColor3f(1.0,0.0,0.0);	
		glVertex2i(1550,460);
		glVertex2i(1630,460);
		glEnd();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0+x2,0,0);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2i(1630,410);
		glVertex2i(1630,510);
		glVertex2i(1670,460);
		glEnd();
		glPopMatrix();
		
		glColor3f(0.0,0.0,1.0);
		glPushMatrix();
		glTranslatef(0+x2,0,0);
	    glRasterPos3f(1095,550,0.0);
	    output("m");
	    glPopMatrix();
	    
	    glColor3f(0.0,0.0,0.0);
		glPushMatrix();
		glTranslatef(0+x2,0,0);
	    glRasterPos3f(1590,455,0.0);
	    output("a");
	    glPopMatrix();
	    
	    glColor3f(0.0,0.0,0.0);
		glPushMatrix();
		glTranslatef(0+x2,0,0);
	    glRasterPos3f(1655,610,0.0);
	    output("force");
	    glPopMatrix();
		
		glFlush();
		
	}

	void display_left(){ //////////////////////////////////////////////display_left
		glMatrixMode(GL_MODELVIEW);//wheel1
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(100,400,0);
		glutSolidSphere(50,100,10);
		glPopMatrix();
		
		glColor3f(0.0,0.0,0.0);
		glLineWidth(10);
		glBegin(GL_LINES);  // rod_left
		glVertex2i(100,480);
		glVertex2i(100,400);
		glVertex2i(100,400);
		glVertex2i(200,490);
		glEnd();
		
		glMatrixMode(GL_MODELVIEW);//wheel1_inside
		glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(100,400,0);
		glutSolidSphere(35,100,10);
		glPopMatrix();
		
		glMatrixMode(GL_MODELVIEW);//wheel1_center
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(100,400,0);
		glutSolidSphere(10,100,10);
		glPopMatrix();
		
		glMatrixMode(GL_MODELVIEW);//wheel2
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(430,400,0);
		glutSolidSphere(50,100,10);
		glPopMatrix();
		
		glBegin(GL_LINES);  // rod_right
		glVertex2i(430,480);
		glVertex2i(430,400);
		glVertex2i(430,400);
		glVertex2i(330,490);
		glEnd();
		
		glMatrixMode(GL_MODELVIEW);//wheel2_inside
		glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(430,400,0);
		glutSolidSphere(35,100,10);
		glPopMatrix();
		
		glMatrixMode(GL_MODELVIEW);//wheel2_center
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		glTranslatef(430,400,0);
		glutSolidSphere(10,100,10);
		glPopMatrix();
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);//horz.table
		glVertex2f(50,520);
		glVertex2f(50,480);
		glVertex2f(490,480);
		glVertex2f(490,520);
		glEnd();
		
		glColor3f(0.0,0.0,0.0);
		glLineWidth(7);
		glBegin(GL_LINES);  //vehicle rod
		glVertex2i(430,477);
		glVertex2i(520,477);
		glVertex2i(520,477);
		glVertex2i(650,570);
		glEnd();
		
		glLineWidth(10);
		glBegin(GL_LINES);  //force arrow_left
		glColor3f(0.0,0.0,0.0);	
		glVertex2i(655,570);
		glVertex2i(700,570);
		glEnd();
		
		glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(700,560);
		glVertex2i(700,580);
		glVertex2i(715,570);
		glEnd();
		
		glColor3f(0.5,0.5,0.6);
		glBegin(GL_POLYGON);//box
		glVertex2f(200,520);
		glVertex2f(200,570);
		glVertex2f(290,570);
		glVertex2f(290,520);
		glEnd();
		
		//word_left();
		
		glLineWidth(20);
		glBegin(GL_LINES);  //arrow_rod
		glColor3f(1.0,0.0,0.0);	
		glVertex2i(630,460);
		glVertex2i(670,460);
		glEnd();
		
		glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex2i(670,430);
		glVertex2i(670,490);
		glVertex2i(700,460);
		glEnd();
		 
		word_left();
		
		glFlush();
	}
	    void word_left(){               //////////////////////////////////////////////display_word_left
	    glColor3f(0.0,0.0,1.0);
	   
	    glPushMatrix();
	    glRasterPos3f(230,540,0.0);
	    output("m");
	    glPopMatrix();
	
		glColor3f(0.0,0.0,0.0);
		glPushMatrix();
	    glRasterPos3f(650,455,0.0);
	    output("a");
	    glPopMatrix();
	    
	    glColor3f(0.0,0.0,0.0);
		glPushMatrix();
	    glRasterPos3f(655,585,0.0);
	    output("force");
	    glPopMatrix();
	
	}
    
	glColor3f(0.9,0.9,1.0);
	glBegin(GL_POLYGON);//sky
	glVertex2f(1,400);
	glVertex2f(1,949);
	glVertex2f(1899,949);
	glVertex2f(1899,400);
	glEnd();
	
	glMatrixMode(GL_MODELVIEW);//cloud1circle1
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(100,770,0);
	glutSolidSphere(50,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud1circle2
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(140,790,0);
	glutSolidSphere(50,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud1circle3
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(190,770,0);
	glutSolidSphere(50,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud1circle4
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(140,750,0);
	glutSolidSphere(50,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//sun boader
	glPushMatrix();
	glColor3f(1.0,0.6,0.0);
	glTranslatef(700,820,0);
	glutSolidSphere(73,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//sun
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(700,820,0);
	glutSolidSphere(70,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud2circle1
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(1200,870,0);
	glutSolidSphere(60,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud2circle2
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(1260,890,0);
	glutSolidSphere(60,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud2circle3
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(1240,840,0);
	glutSolidSphere(50,100,10);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);//cloud2circle4
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glTranslatef(1300,870,0);
	glutSolidSphere(60,100,10);
	glPopMatrix();
	
	glColor3f(0.0,0.7,0.1);
	glBegin(GL_POLYGON);//land
	glVertex2f(1,399);
	glVertex2f(1,0);
	glVertex2f(1899,0);
	glVertex2f(1899,399);
	glEnd();
	
	glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,40.0,0.0);
	output("Press '3' to move to next page...");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1000.0,640.0,0.0);
	output("Press 'n' to apply force on vehicles...");
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0+y2,0,0);
	display_left();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0+x2,0,0);
	display_right();
	glPopMatrix();
	
	glFlush();

}

void law_stmt3(){
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//scene();
	glColor3f(1,0.9,0.6);
	glBegin(GL_POLYGON);  //WALL UP
	glVertex2i(0,251);
	glVertex2i(0,1000);
	glVertex2i(2000,1000);
	glVertex2i(2000,251);
	glEnd();
	
	glColor3f(0.5,0.8,0.8);
	glBegin(GL_POLYGON);  //WALL DOWN
	glVertex2i(0,241);
	glVertex2i(0,0);
	glVertex2i(2000,0);
	glVertex2i(2000,241);
	glEnd();
	
    glColor3f(0.0,0.4,0.1);
	glBegin(GL_POLYGON);  //BOARD
	glVertex2i(200,910);
	glVertex2i(200,410);
	glVertex2i(1220,410);
	glVertex2i(1220,910);
	glEnd();
	
	glColor3f(0.5,0.6,0.6);
	glLineWidth(8);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(200,910);	
	glVertex2i(1220,910);
	glVertex2i(200,410);	
	glVertex2i(200,915);
	glVertex2i(1220,410);	
	glVertex2i(1220,915);
	glEnd();
	
	glColor3f(0.5,0.5,0.5);
	glLineWidth(14);
	glBegin(GL_LINES);//BOARD BORDER
	glVertex2i(160,410);	
	glVertex2i(1260,410);
		
	glColor3f(0.4,0.6,0.6);
	glLineWidth(12);
	glBegin(GL_LINES);// back line
	glVertex2i(0,250);	
	glVertex2i(2000,250);
	glEnd();
				
	glColor3f(1,1,1);
	glLineWidth(6);
	glBegin(GL_LINES);// Chalk piece
	glVertex2i(300,423);	
	glVertex2i(345,423);
	glVertex2i(380,423);	
	glVertex2i(335,434);
	glEnd();
	
	glColor3f(1.0,1.0,1.0); 
    glPushMatrix();
    glRasterPos3f(450.0,850.0,0.0);
	output("NEWTON'S THIRD LAW OF MOTION");
    glPopMatrix();
    
    glPushMatrix();
    glRasterPos3f(300.0,750.0,0.0);
	output("For every action there is equal and opposite reaction.");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,40.0,0.0);
	output("Press 'z' for demonstration...");
    glPopMatrix();
	
	glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON);  //TABLE
	glVertex2i(1400,210);
	glVertex2i(1400,420);
	glVertex2i(1820,420);
	glVertex2i(1820,210);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE1
	glVertex2i(1410,410);
	glVertex2i(1810,410);
	glVertex2i(1810,330);
	glVertex2i(1410,330);
	glEnd();
	
	glColor3f(1,0.7,0.4);
	glBegin(GL_POLYGON);  //TABLE INSIDE2
	glVertex2i(1410,240);
	glVertex2i(1810,240);
	glVertex2i(1810,320);
	glVertex2i(1410,320);
	glEnd();
			
	glColor3f(1,0.8,0.5);
	glLineWidth(6);
	glBegin(GL_LINES);//  lines inside table
	glVertex2i(1450,260);	
	glVertex2i(1490,260);
	glVertex2i(1450,350);	
	glVertex2i(1490,350);
	glVertex2i(1770,350);	
	glVertex2i(1730,350);
	glVertex2i(1770,260);	
	glVertex2i(1730,260);
	glEnd();
				
    glColor3f(0.7,1.0,0.0);
	glBegin(GL_POLYGON);  //Pen box
	glVertex2i(1655,420);
	glVertex2i(1680,420);
	glVertex2i(1687,465);
	glVertex2i(1648,465);
	glEnd();
			
	glColor3f(0.3,0.2,1.0);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1654,465);	
	glVertex2i(1650,485);
	glEnd();
				
	glColor3f(0.9,0.5,0.1);
	glLineWidth(4);
	glBegin(GL_LINES);// pens
	glVertex2i(1679,465);	
	glVertex2i(1684,480);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);  //Pot
	glVertex2i(125,220);
	glVertex2i(175,220);
	glVertex2i(200,290);
	glVertex2i(100,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(130,290);
	glVertex2i(150,390);
	glVertex2i(170,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(160,290);
	glVertex2i(210,340);
	glVertex2i(190,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(110,290);
	glVertex2i(80,320);
	glVertex2i(160,290);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(120,290);
	glVertex2i(110,360);
	glVertex2i(150,320);
	glEnd();
	
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_TRIANGLES);//Grass
	glVertex2i(140,290);
	glVertex2i(190,360);
	glVertex2i(180,290);
	glEnd();
		
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1190,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
			
	glMatrixMode(GL_MODELVIEW);// teachers leg
	glPushMatrix();
	glColor3f(1,0.8,0.8);
	glTranslatef(1300,170,0);
	glutSolidSphere(20,20,10);
	glPopMatrix();
	
	//teacher skirt
    glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1310,500);
	glVertex2i(1370,190);
	glVertex2i(1300,170);
	glEnd();
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1280,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1300,170);
	glEnd();
	
	glColor3f(0.0,0.1,0.6);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1240,500);
	glVertex2i(1200,170);
	glVertex2i(1130,190);
	glEnd();
	
	//teacher top	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  
	glVertex2i(1200,500);
	glVertex2i(1195,600);
	glVertex2i(1315,600);
	glVertex2i(1310,500);
	glEnd();
	
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON);  //left shoulder
	glVertex2i(1240,600);
	glVertex2i(1210,630);
	glVertex2i(1140,570);
	glVertex2i(1150,540);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0+x,0+y,0);
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //left hand 
	glVertex2i(1160,550);
	glVertex2i(1135,530);
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glEnd();
	
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //left hand
	glVertex2i(1100,630);
	glVertex2i(1135,630);
	glVertex2i(1140,660);
	glVertex2i(1090,660);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glLineWidth(8);
	glBegin(GL_LINES);//fingers
	glVertex2i(1130,660);	
	glVertex2i(1120,690);
	glEnd();
	glPopMatrix();
	
	timer(0);
		
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_POLYGON); //BOOK
	glVertex2i(1230,500);
	glVertex2i(1300,540);
	glVertex2i(1350,450);
	glVertex2i(1290,410);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right shoulder 
	glVertex2i(1270,600);
	glVertex2i(1300,630);
	glVertex2i(1370,520);
	glVertex2i(1340,500);
	glEnd();
		
	glColor3f(1.0,0.5,0.5);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1365,525);
	glVertex2i(1270,480);
	glVertex2i(1290,450);
	glVertex2i(1380,500);
	glEnd();
		
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //right hand
	glVertex2i(1270,480);
	glVertex2i(1285,460);
	glVertex2i(1270,440);
	glVertex2i(1245,480);
	glEnd();
			
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck down
	glVertex2i(1230,600);
	glVertex2i(1280,600);
	glVertex2i(1300,630);
	glVertex2i(1210,630);
	glEnd();
			
	glColor3f(1,1,0.8);
	glBegin(GL_TRIANGLES); //Inner white
	glVertex2i(1220,620);
	glVertex2i(1290,620);
	glVertex2i(1256,567);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur right
	glVertex2i(1300,629);
	glVertex2i(1275,635);
	glVertex2i(1254,564);
	glEnd();
		
	glColor3f(1,0,0.4);
	glBegin(GL_TRIANGLES); //Colur left
	glVertex2i(1210,629);
	glVertex2i(1235,635);
	glVertex2i(1256,565);
	glEnd();

	glColor3f(1,0.0,0.4);
	glPointSize(7);
	glBegin(GL_POINTS);
	glVertex2i(1256,555);//BUTTONS
	glVertex2i(1256,530);
	glEnd();
	
	glColor3f(1.0,0.8,0.8);
	glBegin(GL_POLYGON); //Neck up
	glVertex2i(1240,630);
	glVertex2i(1270,630);
	glVertex2i(1270,650);
	glVertex2i(1240,650);
	glEnd();
	
		
	glMatrixMode(GL_MODELVIEW);// hair semicircle
	glPushMatrix();
	glColor3f(0.6,0.3,0.1);
	glTranslatef(1250,720,0);
	glutSolidSphere(75,100,30);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);// Face
	glPushMatrix();
	glColor3f(1.0,0.8,0.8);
	glTranslatef(1250,700,0);
	glutSolidSphere(60,80,10);
	glPopMatrix();
				
	glColor3f(0.6,0.3,0.1);
	glBegin(GL_POLYGON); //hair above
	glVertex2i(1200,720);
	glVertex2i(1220,775);
	glVertex2i(1285,775);
	glVertex2i(1300,720);
	glEnd();
		
	glColor3f(0,0.2,0.3);
	glLineWidth(1);
	glBegin(GL_LINES);// nose
	glVertex2i(1242,675);	
	glVertex2i(1247,695);
	glVertex2i(1242,675);	
	glVertex2i(1250,676);	
	glEnd();
			
	glColor3f(0,0,0);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);// Eye brows LEFT
	glVertex2i(1210,710);	
	glVertex2i(1220,713);
	glVertex2i(1230,710);	
	glEnd();
	
	glBegin(GL_LINE_STRIP);//Eye brows RIGHT
	glVertex2i(1265,710);
	glVertex2i(1275,713);	
	glVertex2i(1285,710);
	glEnd();
	
	glPushMatrix();
	glTranslatef(0,0+z,0);
	glColor3f(0.8,0,0.2);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex2i(1235,665);  //mouth	
	glVertex2i(1237,664);
	glVertex2i(1240,663);
	glVertex2i(1245,662);
	glVertex2i(1250,662);
	glVertex2i(1255,663);
	glVertex2i(1260,664);
	glVertex2i(1265,665);
	glEnd();
	glPopMatrix();
	
	glColor3f(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(1220,700);//EYES
	glVertex2i(1275,700);
	glEnd();
	    
    glFlush();
}

void law3(){
	auto void display_left();
	auto void left_word();
	//auto void right_word();
	//auto void arrow();
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	

void display_left(){
	
	glColor3f(1.0,0.9,0.1);
	glBegin(GL_POLYGON);//CAR RECTANGLE
	glVertex2i(100,370);
	glVertex2i(100,230);
	glVertex2i(1000,230);
	glVertex2i(1000,370);
	glEnd();
	
	glColor3f(1.0,0.9,0.1);
	glBegin(GL_POLYGON);//CAR above
	glVertex2i(800,480);
	glVertex2i(300,480);
	glVertex2i(300,370);
	glVertex2i(800,370);
	glEnd();
	
	glColor3f(1.0,0.9,0.1);
	glBegin(GL_TRIANGLES);//car left window
	glVertex2i(300,480);
	glVertex2i(190,370);
	glVertex2i(300,370);
	glEnd();
	
	glColor3f(0.4,0.5,0.6);
	glBegin(GL_TRIANGLES);//car left window inside
	glVertex2i(290,460);
	glVertex2i(220,380);
	glVertex2i(290,380);
	glEnd();
	
	glColor3f(1.0,0.9,0.1);
	glBegin(GL_TRIANGLES);//car right window
	glVertex2i(800,480);
	glVertex2i(800,370);
	glVertex2i(910,370);
	glEnd();
		
	glColor3f(0.4,0.5,0.6);
	glBegin(GL_TRIANGLES);//car right window inside
	glVertex2i(810,460);
	glVertex2i(810,380);
	glVertex2i(880,380);
	glEnd();
	
	glColor3f(0.4,0.5,0.6);
	glBegin(GL_POLYGON);//car center window1
	glVertex2i(535,470);
	glVertex2i(310,470);
	glVertex2i(310,380);
	glVertex2i(535,380);
	glEnd();
	
	glColor3f(0.4,0.5,0.6);
	glBegin(GL_POLYGON);//car center window2
	glVertex2i(790,470);
	glVertex2i(555,470);
	glVertex2i(555,380);
	glVertex2i(790,380);
	glEnd();
	
	glMatrixMode(GL_MODELVIEW);// wheel 1
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(800,220,0);
	glutSolidSphere(70,100,30);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);// wheel 1 inside
	glPushMatrix();
	glColor3f(0.4,0.4,0.4);
	glTranslatef(800,220,0);
	glutSolidSphere(40,100,30);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);// wheel 2
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(300,220,0);
	glutSolidSphere(70,100,30);
	glPopMatrix();
	
	glMatrixMode(GL_MODELVIEW);// wheel 2 inside
	glPushMatrix();
	glColor3f(0.4,0.4,0.4);
	glTranslatef(300,220,0);
	glutSolidSphere(40,100,30);
	glPopMatrix();
			
	glColor3f(0.0,0.4,1.0);
	glBegin(GL_POLYGON);//blue arrow 1
	glVertex2i(900,600);
    glVertex2i(500,600);
    glVertex2i(500,550);
    glVertex2i(900,550);
    glEnd();
    
    glColor3f(0.0,0.4,1.0);
    glBegin(GL_TRIANGLES);//arrow 1
    glVertex2i(900,630);
    glVertex2i(900,520);
    glVertex2i(1000,575);
    glEnd();
    
	left_word();	
	glFlush();
	
}
  
void left_word(){
	glColor3f(1.0,1.0,1.0);
	
    glPushMatrix();
    glRasterPos3f(650,570,0.0);
    output("Action force");
    glPopMatrix();
    
    glFlush();
   }	
	glColor3f(0.8,0.7,0.5);
	glBegin(GL_POLYGON);  //road
	glVertex2i(1,200);
	glVertex2i(1,0);
	glVertex2i(1899,0);
	glVertex2i(1899,200);
	glEnd();
	
	glColor3f(0.8,0.9,1.0);
	glBegin(GL_POLYGON);//Sky
	glVertex2i(1,949);
	glVertex2i(1,155);
	glVertex2i(1899,155);
	glVertex2i(1899,949);
	glEnd();
	
             	
	glColor3f(0,0.7,0.1);
	glBegin(GL_POLYGON);//ground
	glVertex2i(0,155);
    glVertex2i(0,300);
    glVertex2i(1899,300);
    glVertex2i(1899,155);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);//Tree2 
    glVertex2i(350,850);
    glVertex2i(310,800);
    glVertex2i(390,800);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(350,830);
    glVertex2i(290,760);
    glVertex2i(410,760);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(350,820);
    glVertex2i(270,700);
    glVertex2i(430,700);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(350,780);
    glVertex2i(240,630);
    glVertex2i(460,630);
    glEnd();
        
    glColor3f(0.3,0.5,0.3);//Tree1
    glBegin(GL_TRIANGLES);
    glVertex2i(100,800);
    glVertex2i(0,630);
    glVertex2i(220,630);
    glEnd();
       
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,820);
    glVertex2i(10,710);
    glVertex2i(200,710);
    glEnd();
       
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,850);
    glVertex2i(30,780);
    glVertex2i(180,780);
    glEnd();
       
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,890);
    glVertex2i(50,830);
    glVertex2i(160,830);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);//Tree3 
    glVertex2i(1650,870);
    glVertex2i(1580,800);
    glVertex2i(1720,800);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(1650,830);
    glVertex2i(1560,760);
    glVertex2i(1740,760);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(1650,820);
    glVertex2i(1530,700);
    glVertex2i(1770,700);
    glEnd();
    
    glColor3f(0.3,0.5,0.3);
    glBegin(GL_TRIANGLES);
    glVertex2i(1650,780);
    glVertex2i(1500,630);
    glVertex2i(1800,630);
    glEnd();
       
    glColor3f(0.7,0.4,0.2);
	glBegin(GL_POLYGON);//compound wall
	glVertex2i(0,300);
    glVertex2i(0,640);
    glVertex2i(1899,640);
    glVertex2i(1899,300);
    glEnd();
    
            	
	glColor3f(0.9,0.7,0.5);
	glBegin(GL_POLYGON);//compound
	glVertex2i(100,300);
    glVertex2i(100,650);
    glVertex2i(230,650);
    glVertex2i(230,300);
    glEnd();
           	
	glColor3f(0.9,0.7,0.5);
	glBegin(GL_POLYGON);//compound
	glVertex2i(600,300);
    glVertex2i(600,650);
    glVertex2i(730,650);
    glVertex2i(730,300);
    glEnd();
    
    glColor3f(0.9,0.7,0.5);
	glBegin(GL_POLYGON);//compound
	glVertex2i(1150,300);
    glVertex2i(1150,650);
    glVertex2i(1280,650);
    glVertex2i(1280,300);
    glEnd();
    
    glColor3f(0.9,0.7,0.5);
	glBegin(GL_POLYGON);//compound
	glVertex2i(1700,300);
    glVertex2i(1700,650);
    glVertex2i(1830,650);
    glVertex2i(1830,300);
    glEnd();
    	
	glColor3f(0.6,0.3,0.0);
	glBegin(GL_POLYGON);//WALL
	glVertex2i(1600,780);
	glVertex2i(1400,780);
	glVertex2i(1400,155);
	glVertex2i(1600,155);
	glEnd();
	
	glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(1400.0,40.0,0.0);
	output("Press 'b' to move to next page...");
    glPopMatrix();
    
    glColor3f(0.0,0.0,0.7);
    glPushMatrix();
    glRasterPos3f(600.0,680.0,0.0);
	output("Press 'o' to move the car...");
    glPopMatrix();
	
	slider3();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINES);//lines

	glVertex2i(1400,720);	glVertex2i(1600,720);
	glVertex2i(1400,660);	glVertex2i(1600,660);
	glVertex2i(1400,600);   glVertex2i(1600,600);
	glVertex2i(1400,540);	glVertex2i(1600,540);
	glVertex2i(1400,480);	glVertex2i(1600,480);
	glVertex2i(1400,420);	glVertex2i(1600,420);
	glVertex2i(1400,360);	glVertex2i(1600,360);
	glVertex2i(1400,300);	glVertex2i(1600,300);
	glVertex2i(1400,240);	glVertex2i(1600,240);
	glVertex2i(1400,180);	glVertex2i(1600,180);
	
	
	glVertex2i(1440,720);   glVertex2i(1440,780);
	glVertex2i(1520,720);   glVertex2i(1520,780);
	glVertex2i(1470,660);   glVertex2i(1470,720);
	glVertex2i(1560,660);   glVertex2i(1560,720);
	glVertex2i(1440,600);   glVertex2i(1440,660);
	glVertex2i(1520,600);   glVertex2i(1520,660);
	glVertex2i(1470,540);   glVertex2i(1470,600);
	glVertex2i(1560,540);   glVertex2i(1560,600);
	glVertex2i(1440,480);   glVertex2i(1440,540);
	glVertex2i(1520,480);   glVertex2i(1520,540);
	glVertex2i(1470,420);   glVertex2i(1470,480);
	glVertex2i(1560,420);   glVertex2i(1560,480);
	glVertex2i(1440,360);   glVertex2i(1440,420);
	glVertex2i(1520,360);   glVertex2i(1520,420);
	glVertex2i(1470,300);   glVertex2i(1470,360);
	glVertex2i(1560,300);   glVertex2i(1560,360);
	glVertex2i(1440,240);   glVertex2i(1440,300);
	glVertex2i(1520,240);   glVertex2i(1520,300);
	glVertex2i(1470,180);   glVertex2i(1470,240);
	glVertex2i(1560,180);   glVertex2i(1560,240);
	glVertex2i(1440,180);   glVertex2i(1440,155);
	glVertex2i(1520,180);   glVertex2i(1520,155);
	glEnd();
        	    
    glPushMatrix();
    glTranslatef(0+y3,0,0);
    display_left();
    glPopMatrix();
    
	glFlush();  
	
}

void thnx_page(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1900,0,950,0,950);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	background();
	
	glColor3f(0.9,0.7,0.0);
    glPushMatrix();
    glRasterPos3f(880.0,475.0,0.0);
	output("THANK YOU...");
    glPopMatrix();
	
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glRasterPos3f(1400.0,20.0,0.0);
	output("Press 'e' to Exit...");
    glPopMatrix();
	
	glFlush();
}

void display1()
{
	if(slide==0){
		glClear(GL_COLOR_BUFFER_BIT);
		intro();
		glFlush();
 	}
	
}
void displayc(){
	if(slide==1){
		glClear(GL_COLOR_BUFFER_BIT);
		content_page();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display2(){
	if(slide==2){
		glClear(GL_COLOR_BUFFER_BIT);
		law1_stmt();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display3(){
	if(slide==3){
		glClear(GL_COLOR_BUFFER_BIT);
		law1();	
		forcearrow();
		slider();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display4(){
	if(slide==4){
		glClear(GL_COLOR_BUFFER_BIT);
		law_stmt2();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display5(){
	if(slide==5){
		glClear(GL_COLOR_BUFFER_BIT);
		law2();	
		slider2();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display6(){
	if(slide==6){
		glClear(GL_COLOR_BUFFER_BIT);
		law_stmt3();
		glFlush();
		glutSwapBuffers();
	}
	
}
void display7(){
	if(slide==7){
		glClear(GL_COLOR_BUFFER_BIT);
		law3();	
		law3_arrow();
		glFlush();
		glutSwapBuffers();
	}
	
}
void displaytq(){
	if(slide==8){
		glClear(GL_COLOR_BUFFER_BIT);
		thnx_page();
		slide=1;
		glFlush();
		glutSwapBuffers();
	}
}

void myKey(unsigned char key, int x, int y){
	if(key=='a'||key=='A'){
		slide=1;
		glutDisplayFunc(displayc);
		//glutPostRedisplay();
	}
	if(key=='1'){
		slide=2;
		timer(0);
		glutDisplayFunc(display2);
		//glutPostRedisplay();
	}
	if(key=='X'||key=='x' )
	{
		slide=3;
		slide_timer(0);
		glutDisplayFunc(display3);
		//glutPostRedisplay();
	}	
	if(key=='2'){
		slide=4;
		timer(0);
		glutDisplayFunc(display4);
		//glutPostRedisplay();
	}
	if(key=='y'||key=='Y'){
		u=0;
		slide_timer(0);
		slide=5;
		glutDisplayFunc(display5);
		//glutPostRedisplay();
		if(key=='n'||key=='N'){
			timer2(0);
		}
	}
	if(key=='3'){
		slide=6;
		timer(0);
		glutDisplayFunc(display6);
		//glutPostRedisplay();
	}
	if(key=='z'||key=='Z'){
		u=0;
		slide=7;
		slide_timer3(0);
		glutDisplayFunc(display7);
		//glutPostRedisplay();
	}
	if(key=='m'||key=='M'){
		timer1(0);
	}
	if(key=='n'||key=='N'){
		timer2(0);
	}
	if(key=='o'||key=='O'){
		timer3(0);
	}
	if(key=='b'||key=='B'){
		slide=8;
		glutDisplayFunc(displaytq);
		//glutPostRedisplay();
	}
	if(key=='e'||key=='E'){
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitWindowPosition(0.0,0.0);
	glutInitWindowSize(2000,1000);
	glutCreateWindow("NEWTON'S LAWS OF MOTION");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1900,0,950);
	//glClearColor(1.0,1.0,1.0,0.0);
	glutDisplayFunc(display1);
	glutKeyboardFunc(myKey);
	//timer(0);
	glutMainLoop();
}
