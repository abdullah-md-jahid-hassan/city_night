#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

void star(double x, double y, double s){

        double x1 = s*4.9 +x, y1 = y;
        double x2 = s*10+x, y2 = s*15.3+y;
        double x3 = s*12+x, y3 = s*9.4+y;
        double x4 = s*18.1+x, y4 = s*9.4+y;
        double x5 = s*15.1+x, y5 = y;
        double x6 = s*1.9+x, y6 = s*9.4+y;
        double x7 = s*12+x, y7 = s*9.4+y;

    /// Half triangle for a star
    {
        glColor3ub(255,215,0);
        glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
        glEnd();
    }
    /// Second Half of the star triangle
    {
        glColor3ub(255,215,0);
        glBegin(GL_POLYGON);
        glVertex2f(x5,y5);
        glVertex2f(x6,y6);
        glVertex2f(x7,y7);
        glEnd();
    }

}

void blockL(double x, double y, double s)
{
    //room
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
        glVertex2f((1*s+x), (0*s+y));
        glVertex2f((11*s+x),(0*s+y));
        glVertex2f((11*s+x),(10*s+y));
        glVertex2f((1*s+x),(10*s+y));
    glEnd();
    //side line
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f((1*s+x), (0*s+y));
        glVertex2f((1*s+x),(10*s+y));
    glEnd();
    //roof
    glColor3ub(150,150,150);
    glBegin(GL_POLYGON);
        glVertex2f((0*s+x), (10*s+y));
        glVertex2f((12*s+x),(10*s+y));
        glVertex2f((12*s+x),(9*s+y));
        glVertex2f((0*s+x),(9*s+y));
    glEnd();
    //window
    int t = rand()%2;
    if (t==0) glColor3ub(255,255,0);
    else glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f((5*s+x), (3*s+y));
        glVertex2f((9*s+x),(3*s+y));
        glVertex2f((9*s+x),(7*s+y));
        glVertex2f((5*s+x),(7*s+y));
    glEnd();
}

void blockR(double x, double y, double s)
{
    //room
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
        glVertex2f((1*s+x), (0*s+y));
        glVertex2f((11*s+x),(0*s+y));
        glVertex2f((11*s+x),(10*s+y));
        glVertex2f((1*s+x),(10*s+y));
    glEnd();
    //side line
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
        glVertex2f((11*s+x),(0*s+y));
        glVertex2f((11*s+x),(10*s+y));
    glEnd();
    //roof
    glColor3ub(150,150,150);
    glBegin(GL_POLYGON);
        glVertex2f((0*s+x), (10*s+y));
        glVertex2f((12*s+x),(10*s+y));
        glVertex2f((12*s+x),(9*s+y));
        glVertex2f((0*s+x),(9*s+y));
    glEnd();
    //window
    int t = rand()%2;
    if (t==0) glColor3ub(255,255,0);
    else glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f((5*s+x), (3*s+y));
        glVertex2f((9*s+x),(3*s+y));
        glVertex2f((9*s+x),(7*s+y));
        glVertex2f((5*s+x),(7*s+y));
    glEnd();
}

void blockM(double x, double y, double s)
{
    //room
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
        glVertex2f((1*s+x), (0*s+y));
        glVertex2f((11*s+x),(0*s+y));
        glVertex2f((11*s+x),(10*s+y));
        glVertex2f((1*s+x),(10*s+y));
    glEnd();
    //roof
    glColor3ub(150,150,150);
    glBegin(GL_POLYGON);
        glVertex2f((0*s+x), (10*s+y));
        glVertex2f((12*s+x),(10*s+y));
        glVertex2f((12*s+x),(9*s+y));
        glVertex2f((0*s+x),(9*s+y));
    glEnd();
    //window
    int t = rand()%2;
    if (t==0) glColor3ub(255,255,0);
    else glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f((5*s+x), (3*s+y));
        glVertex2f((9*s+x),(3*s+y));
        glVertex2f((9*s+x),(7*s+y));
        glVertex2f((5*s+x),(7*s+y));
    glEnd();
}

void bulding (double x, double y, double s, int f)
{
   for (int i=0; i<f; i++)
   {
       blockL(x,y,s);
       blockM(x+(10*s),y,s);
       blockM(x+(20*s),y,s);
       blockR(x+(30*s),y,s);
       y+=(s*10);
   }


}

void moon (double x, double y, double r)
{
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (int i=0; i<=r; i++) glVertex2f(x+i, (sqrt ((r*r)-(i*i)))+y);
    for (int i=0; i<=r; i++) glVertex2f((sqrt ((r*r)-(i*i)))+x, y-i);
    for (int i=0; i<=r; i++) glVertex2f((-1*(sqrt ((r*r)-(i*i)))+x), y-i);
    for (int i=0; i<=r; i++) glVertex2f(x-i, ((sqrt ((r*r)-(i*i)))+y));
    glEnd();
}

void sun (double x, double y, double r)
{
    glColor3ub(255,215,0);
    glBegin(GL_POLYGON);
    for (int i=0; i<=r; i++) glVertex2f(x+i, (sqrt ((r*r)-(i*i)))+y);
    for (int i=0; i<=r; i++) glVertex2f((sqrt ((r*r)-(i*i)))+x, y-i);
    for (int i=0; i<=r; i++) glVertex2f((-1*(sqrt ((r*r)-(i*i)))+x), y-i);
    for (int i=0; i<=r; i++) glVertex2f(x-i, ((sqrt ((r*r)-(i*i)))+y));
    glEnd();
}

void city()
{
    int i;
    double r,g;
    for (r=0, i=-50;0==0;i+=80)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //Sky
        glClear(GL_COLOR_BUFFER_BIT);
        if (i>=960) r+=0.125;
        glClearColor(r, r, r, 0);

        //sky(c);

        //Stars
        if (i<1120)
            for (int i=0; i<150; i++)
                star (rand()%1500, rand()%800, 0.5+((rand()%6)/10.0));

        //Moon
        moon (i, 720, 50);

        //Sun
        sun (i-1010, 740, 60);

        //Buldings
        bulding(600,0,2,8);
        bulding(650,0,2,8);

        bulding(500,0,3,8);
        bulding(700,0,3,8);

        bulding(400,0,4,8);
        bulding(800,0,4,8);

        bulding(300,0,5,8);
        bulding(900,0,5,8);

        bulding(200,0,6,8);
        bulding(1000,0,6,8);

        bulding(100,0,7,8);
        bulding(1100,0,7,8);

        bulding(0,0,8,8);
        bulding(1200,0,8,8);

        if (i>=1500)
        {
            i=-50;
            r=0.001;
        }
        Sleep(1000);
        glFlush();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    double w=1500, h=800;
    glutInitWindowSize(w,h);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

    glutCreateWindow("City Night");
    glOrtho(0,w,0,h,-1,1);
    glutDisplayFunc(city);
    glutMainLoop();

    return EXIT_SUCCESS;
}
