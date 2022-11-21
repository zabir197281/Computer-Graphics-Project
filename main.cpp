#include<iostream>
using namespace std;
#include <cstdlib>
#include<windows.h>
#define PI 3.1416
#include <GL/gl.h>
#include <GL/glut.h>s
#include <vector>
#include<math.h>
#include<cstdio>

char school[] = "School";
char hotel[] = "Hotel";


GLbyte r = 242, g = 242, b = 242; /// windows color
GLbyte r1 = 242, g1 = 242, b1 = 242; /// windows color
GLbyte sr = 51, sg = 204, sb = 255; ///Sky color
GLbyte trr = 0, trg = 0, trb = 0; ///traffic  red Color
GLbyte tyr = 0, tyg = 0, tyb = 0; ///traffic  yellow Color
GLbyte tgr = 25, tgg = 255, tgb = 2; ///traffic  green Color
GLbyte slr = 202, slg = 202, slb = 202; ///Street  color
GLbyte  ldr =225  , ldg = 244 , ldb =278; /// Night Car Light


GLboolean Day = true;
GLboolean Night = false;
GLboolean Rain = false;
GLboolean TrafficGreen = true;
GLboolean TrafficRed = false;
GLboolean TrafficYellow = false;




void sound()
{

    PlaySound("rain-03.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void sound3()
{

    PlaySound("179.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

}

void TrafficRedLight()
{
    trr = 226, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 0, tyg = 0, tyb = 0; ///traffic Light yellow Color
    tgr = 0, tgg = 0, tgb = 0; ///traffic Light green Color
}


void TrafficGreenLight()
{
    trr = 0, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 0, tyg = 0, tyb = 0; ///traffic Light yellow Color
    tgr = 25, tgg = 255, tgb = 2; ///traffic Light green Color
}



void TrafficYellowLight()
{
    trr = 0, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 243, tyg = 255, tyb = 0; ///traffic Light yellow Color
    tgr = 0, tgg = 0, tgb = 0; ///traffic Light green Color
}

void NightColorChange()
{
    if(Night)
    {
        sr = 0; sg = 51; sb = 204;  ///Sky Color
        slr = 255, slg = 249, slb = 69;  ///Street Light Color
        r = 201, g = 217, b = 0;  ///Building Windows Color
        r1 = 180, g1 = 186, b1 = 181;  ///Building Windows Color
    }
}

void DayColorChange()
{
    if(Day)
    {
        sr = 51, sg = 204, sb = 255; ///Sky Color
        slr = 202, slg = 202, slb = 202; ///Street Light Color
        r = 190, g = 202, b = 200;  ///Building Windows Color
        r1 = 190, g1 = 202, b1 = 200;  ///Building Windows Color
    }
}
void RainColorChange()
{
    if(Rain)
    {
        sr = 61, sg = 92, sb = 92; ///Sky Color
    }
}



///--------------------------------------------------------------------------------

///Moving Functions

GLfloat Cloud1PositionX = 0.0f;
GLfloat Cloud1Speed = 0.002f;
GLboolean StopCloud1 = false;
int KeyC = 1;

void MoveCloud1(int value)
{
    if(StopCloud1 == false)
    {
        if(Cloud1PositionX > 1.0f)
        {
            Cloud1PositionX = -1.6f;
        }
        else
        {
            Cloud1PositionX += Cloud1Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveCloud1, 0);
    }
}


GLfloat Cloud2PositionX = 0.0f;
GLfloat Cloud2Speed = 0.0022f;
GLboolean StopCloud2 = false;
int KeyX = 1;

void MoveCloud2(int value)
{
    if(StopCloud2 == false)
    {
        if(Cloud2PositionX > 1.7f)
        {
            Cloud2PositionX = -0.7f;
        }
        else
        {
            Cloud2PositionX += Cloud2Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(22, MoveCloud2, 0);
    }
}


GLfloat Cloud3PositionX = 0.0f;
GLfloat Cloud3Speed = 0.0009f;
GLboolean StopCloud3 = false;
int KeyP = 1;

void MoveCloud3(int value)
{
    if(StopCloud3 == false)
    {
        if(Cloud3PositionX > 1.7f)
        {
            Cloud3PositionX = -0.9f;
        }
        else
        {
            Cloud3PositionX += Cloud3Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(22, MoveCloud3, 0);
    }
}



GLfloat waterPositionX1 = 0.0f;
GLfloat waterSpeed = 0.01f;

void Movewater1(int value)
    {

        if(waterPositionX1 > 2.0f)
        {
            waterPositionX1 = -2.1f;
        }
        waterPositionX1 += waterSpeed;
        glutPostRedisplay();
        glutTimerFunc(100,Movewater1,0);


    }

GLfloat waterPositionX2 = -2.1f;

void Movewater2(int value)
    {

        if(waterPositionX2 > 2.0f)
        {
            waterPositionX2 = -2.1f;
        }
        waterPositionX2 += waterSpeed;
        glutPostRedisplay();
        glutTimerFunc(100,Movewater2,0);


    }



GLfloat BirdPositionX = -0.5f;
GLfloat BirdPositionY = -0.2f;
GLfloat BirdSpeed = 0.005f;
GLboolean StopBird = false;
int KeyZ = 1;
void MoveBird(int value)
{
    if(StopBird == false)
    {
        if(BirdPositionY > .25f)
        {

            BirdPositionX = -0.5f;
            BirdPositionY = -0.2f;
        }
        else
        {
            BirdPositionX += BirdSpeed;
            BirdPositionY += (BirdSpeed/4);
        }
        glutPostRedisplay();
        glutTimerFunc(50, MoveBird, 0);
    }
}




GLfloat Boat1PositionX = 0.0f;
GLfloat Boat1Speed = 0.003f;
GLboolean StopBoat1 = false;
int KeyB = 1;
void MoveBoat1(int value)
{
    if(StopBoat1 == false)
    {
        if(Boat1PositionX > 1.7f)
        {
            Boat1PositionX = -1.1f;
        }
        else
        {
            Boat1PositionX += Boat1Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(27, MoveBoat1, 0);
    }
}


GLfloat Boat2PositionX = 0.0f;
GLfloat Boat2Speed = 0.004f;
GLboolean StopBoat2 = false;
int KeyV = 1;
void MoveBoat2(int value)
{
    if(StopBoat2 == false)
    {
        if(Boat2PositionX < -1.75f)
        {
            Boat2PositionX = 1.0f;
        }
        else
        {
            Boat2PositionX -= Boat2Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveBoat2, 0);
    }
}








GLfloat Car1PositionX = 0.0f;

GLfloat Car1Speed = 0.003f;

void MoveCar1(int value)
{
    if(TrafficGreen == true)
    {
        Car1Speed = 0.003f;
        if(Car1PositionX > 1.5f)
        {

            Car1PositionX = -0.9f;

        }
        else
        {
            Car1PositionX += Car1Speed;

        }
    }
    else if(TrafficRed == true)
    {
        if(Car1PositionX > 1.5f)
        {

            Car1PositionX = -0.9f;

        }
        if(Car1PositionX > 0.38f && Car1PositionX < 0.4f)
        {
            Car1Speed = 0.0f;
            Car1PositionX += Car1Speed;
        }
        else
        {
            Car1Speed = 0.003f;
            Car1PositionX += Car1Speed;
        }
    }
    else if(TrafficYellow == true)
    {
        if(Car1PositionX > 1.5f)
        {

            Car1PositionX = -0.9f;

        }
        if(Car1PositionX < 0.4 && Car1PositionX > 0.0f)
        {
            Car1Speed = 0.0005f;
            Car1PositionX += Car1Speed;
        }
        else
        {
            Car1Speed = 0.003f;
            Car1PositionX += Car1Speed;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, MoveCar1, 0);
}


GLfloat Car2PositionX = 0.0f;

GLfloat Car2Speed = 0.004f;

void MoveCar2(int value)
{
    if(TrafficGreen == true)
    {
        Car2Speed = 0.004f;
        if(Car2PositionX > 1.3f)
        {

            Car2PositionX = -1.3f;

        }
        else
        {
            Car2PositionX += Car2Speed;

        }
    }
    else if(TrafficRed == true)
    {
        if(Car2PositionX > 1.3f)
        {

            Car2PositionX = -1.3f;

        }
        if(Car2PositionX > -0.02f && Car2PositionX < 0.0f)
        {
            Car2Speed = 0.0f;
            Car2PositionX += Car2Speed;
        }
        else
        {
            Car2Speed = 0.004f;
            Car2PositionX += Car2Speed;
        }
    }
    else if(TrafficYellow == true)
    {
        if(Car2PositionX > 1.3f)
        {

            Car2PositionX = -1.3f;

        }
        if(Car2PositionX < 0.0 && Car2PositionX > -0.12f)
        {
            Car2Speed = 0.0006f;
            Car2PositionX += Car2Speed;
        }
        else
        {
            Car2Speed = 0.004f;
            Car2PositionX += Car2Speed;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, MoveCar2, 0);
}





GLfloat positionrainy=0.0f;
GLfloat speedrain=0.9f;
GLboolean StopRain = true;
int KeyE = 1;

void updaterain(int value)
{

if(StopRain == false)
    {

    if(positionrainy<-2.0f)
    {
        positionrainy=1.8f;
    }

    positionrainy-=speedrain;
    glutPostRedisplay();
    glutTimerFunc(100, updaterain,0);

    }
}


GLfloat positionrainy1=1.8f;

void updaterain1(int value)
{
    if(StopRain == false)

    {

        if(positionrainy1<-2.0f)
    {
        positionrainy1=1.8f;
    }


    positionrainy1-=speedrain;
    glutPostRedisplay();
    glutTimerFunc(100, updaterain1,0);

    }



}



void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
  glEnable(GL_LIGHTING);
  GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
  GLfloat light_position[] = {-0.9,.9,0, 0.0 };
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0); //enable the light after setting the properties
}










///Rain

void rain()
{
    glLineWidth(1.2);

    glPushMatrix();
    glTranslatef(0.0f,positionrainy,0.0f);

    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
        glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

        glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.95f,.7f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glPopMatrix();


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    glPushMatrix();
    glTranslatef(0.0f,positionrainy1,0.0f);

    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
        glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

        glTranslatef(-.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(-.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.001,-.25,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();

    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
        glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.95f,.7f);
    glEnd();
    glTranslatef(.1,0,0);
    glColor3ub(224, 235, 235);
    glBegin(GL_LINES);
    glVertex2f(-1.0f,.85f);
    glVertex2f(-.98f,.8f);
    glEnd();
    glPopMatrix();


}






///-----------------------------------------------------------------------------------------------------------------------

/// Normal Functions

void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); /// see how many characters are in text string.
    glColor3f(0.2,1.0,0.7);
    glRasterPos2f( x, y); /// location to start printing text
    for( i=0; i < l; i++) /// loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);
    }
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(sr, sg, sb);
	glVertex2f(-1.0f, 0.38f);
	glVertex2f(1.0f, 0.38f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}


void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void DrawCircle2(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount/4;i++)
        {
            glVertex2f(
                       x + (radius * sin(i *  twicePi / triangleAmount)),
                       y + (radius * cos(i * twicePi / triangleAmount)));
		}
	glEnd();
}

        void sun()
        {
        GLfloat x=0.3f; GLfloat y=0.9f; GLfloat radius =0.06f;
        int triangleAmount = 20;
        glColor3ub(255, 204, 0);
        DrawCircle(x,y,radius,triangleAmount);
        }





void stars()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

}

void moon()
{
    GLfloat x=-0.436f; GLfloat y=0.9f; GLfloat radius =0.06f;
    GLfloat x1=-0.442f; GLfloat y1=0.915f; GLfloat radius1 =0.06f;
    int triangleAmount = 20;

    glColor3ub(242, 242, 242);
    DrawCircle(x,y,radius,triangleAmount);

    glColor3ub(0, 51, 204);
    DrawCircle(x1,y1,radius1,triangleAmount);
}
void river()
{
    glBegin(GL_QUADS);
    glColor3ub(38, 154, 214);
	glVertex2f(-1.0f, -0.6276f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f,-0.6276f);
    glEnd();
}

void Bridge()
{

    glBegin(GL_QUADS);
	glColor3ub(131, 74, 16);
	glVertex2f(-1.0f, -0.335f);
	glVertex2f(-1.0f, -0.6276f);
	glVertex2f( 1.0f, -0.6276f);
    glVertex2f( 1.0f,-0.335f);
    glEnd();

    GLfloat x=-0.5f, y= -0.6276f, radius =0.22f;
    int triangleAmount = 20;

    glColor3ub(135, 98, 61);
    DrawCircle(x,y,radius,triangleAmount);

    glColor3ub(38, 154, 214);
    radius = 0.25f;
    y = -0.75f;
    DrawCircle(x,y,radius,triangleAmount);

    x= 0.5f, y= -0.6276f, radius = 0.22f;

    glColor3ub(135, 98, 61);
    DrawCircle(x,y,radius,triangleAmount);

    glColor3ub(38, 154, 214);
    radius = 0.25f;
    y = -0.75f;
    DrawCircle(x,y,radius,triangleAmount);
}


void boat1()
{
    //bottom part
    glBegin(GL_QUADS);
    glColor3ub(93,20,4);
	glVertex2f( -0.072f, -0.734f);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.432f, -0.8005f);
	glVertex2f( -0.112f, -0.8005f);
	glEnd();
    glBegin(GL_QUADS);
    glColor3ub(132,47,29);
    glVertex2f( -0.752f, -0.8005f);
    glVertex2f( -0.672f, -0.9335f);
    glVertex2f( -0.192f,-0.9335f);
    glVertex2f( -0.112f, -0.8005f);
    glEnd();

    //middle part
    glBegin(GL_POLYGON);
    glColor3ub(65,8,164);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.352f, -0.734f);
	glVertex2f( -0.352f, -0.6542f);
	glVertex2f( -0.672f, -0.6542f);
	glVertex2f( -0.672f, -0.8005f);
	glVertex2f( -0.432f, -0.8005f);
	glEnd();

	//middle middle part
	glBegin(GL_QUADS);
	glColor3ub(247,245,237);
    glVertex2f( -0.56f, -0.77f);
    glVertex2f( -0.56f, -0.685f);
    glVertex2f( -0.66f, -0.685f);
    glVertex2f( -0.66f, -0.77f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(247,245,237);
    glVertex2f( -0.55f, -0.77f);
    glVertex2f( -0.55f, -0.685f);
    glVertex2f( -0.455f, -0.685f);
    glVertex2f( -0.455f, -0.77f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(247,245,237);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.368f, -0.734f);
	glVertex2f( -0.368f, -0.685f);
    glVertex2f( -0.445f, -0.685f);
	glVertex2f( -0.445f, -0.77f);
	glVertex2f( -0.416f, -0.77f);
	glEnd();




    glBegin(GL_QUADS);
	glColor3ub(0, 15, 252);
    glVertex2f( -0.352f, -0.6542f);
    glVertex2f( -0.368f, -0.601f);
    glVertex2f( -0.664f, -0.601f);
    glVertex2f( -0.664f, -0.6542f);
    glEnd();

    //bottom line
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);

    glVertex2f(-0.408f, -0.7606f);
    glVertex2f(-0.088f, -0.7606f);

    glVertex2f(-0.712f, -0.867f);
    glVertex2f(-0.152f, -0.867f);
    glEnd();
}

void boat2()
{
    glBegin(GL_POLYGON);
    glColor3ub(209, 213, 208);
    glVertex2f(0.8f, -0.8803f);
    glVertex2f(0.8f, -0.8271f);
    glVertex2f(0.448f, -0.72f);
    glVertex2f(0.384f, -0.7739f);
    glVertex2f(0.448f, -0.8404f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(114, 218, 227);
    glVertex2f(0.648f, -0.78f);
    glVertex2f(0.665f, -0.69f);
    glVertex2f(0.504f, -0.681f);
    glVertex2f(0.48f, -0.73f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 245, 237);
    glVertex2f(0.57f, -0.7569f);
    glVertex2f(0.58f, -0.7f);
    glVertex2f(0.515f, -0.6943f);
    glVertex2f(0.5f, -0.7358f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 245, 237);
    glVertex2f(0.635f, -0.778f);
    glVertex2f(0.649f, -0.70f);
    glVertex2f(0.595f, -0.7f);
    glVertex2f(0.582f, -0.765f);
    glEnd();



    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.792f, -0.8803f);
    glVertex2f(0.792f, -0.8537f);


    glVertex2f(0.384f, -0.7739f);
    glVertex2f(0.792f, -0.8537f);
    glEnd();
}



void bird1()
{
	GLfloat x = -0.638f; GLfloat y= 0.801f;
	GLfloat radius = 0.01f;
	int triangleAmount = 20;

	glBegin(GL_POLYGON);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    glColor3ub(74, 74, 74);
    DrawCircle(x, y, radius, triangleAmount);
}

void bird2()
{
    GLfloat x= -0.518f; GLfloat y= 0.801f;
	GLfloat radius = 0.01f;
	int triangleAmount = 20;

    glBegin(GL_POLYGON);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    glColor3ub(74, 74, 74);
    DrawCircle(x, y, radius, triangleAmount);
}

void footpath1()
{
    glBegin(GL_QUADS);
    glColor3ub(229,153,108);
    glVertex2f( 1.0f, -0.335);
    glVertex2f( 1.0f, -0.2f);
    glVertex2f(-1.0f, -0.2);
    glVertex2f(-1.0f, -0.335);
    glEnd();

    glLineWidth(1);
    glColor3ub(77, 72, 72);
    glBegin(GL_LINES);
    glVertex2f(1.0f,-0.2685f);
    glVertex2f(-1.0f,-0.2685f);
    glEnd();
}

void footpath2()
{
    glBegin(GL_QUADS);
    glColor3ub(229,153,108);
    glVertex2f( 1.0f, 0.2261f);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f(-1.0f, 0.33f);
    glVertex2f(-1.0f, 0.2261f);
    glEnd();
}


void road()
{
    //Road//
    glBegin(GL_QUADS);
    glColor3ub(100, 99, 97);
    glVertex2f( 1.0f,-0.2286f);
    glVertex2f( 1.0f, 0.2261f);
    glVertex2f(-1.0f, 0.2261f);
    glVertex2f(-1.0f,-0.2286f);
    glEnd();



    //Divider

    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glPushMatrix();
    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();


    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();

    glTranslatef(0.2f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3ub(225, 223, 221);
    glVertex2f(-0.88f,-0.0291f);
    glVertex2f(-0.88f,-0.0025f);
    glVertex2f(-1.0f,-0.0025f);
    glVertex2f(-1.0f,-0.0291f);
    glEnd();
    glPopMatrix();



    glBegin(GL_QUADS);
    glColor3ub(100, 99, 97);
    glVertex2f(0.52f,-0.0291f);
    glVertex2f(0.52f,-0.0025f);
    glVertex2f(0.4f,-0.0025f);
    glVertex2f(0.4f,-0.0291);
    glEnd();



    //Zebra Crossing

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glTranslatef(-0.001f,-.06f,0.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();

    glPopMatrix();

}


void cloud1()
{
	GLfloat x = 0.45f; GLfloat y = 0.83f; GLfloat radius = 0.05f;
	GLfloat x1 = 0.5f; GLfloat y1 = 0.8f;
	GLfloat x2 = 0.4f; GLfloat y2 = 0.8f;
	GLfloat x3 = 0.47f; GLfloat y3 = 0.77f;
	GLfloat x4 = 0.55f; GLfloat y4 = 0.79f;
	int triangleAmount = 20;
    if(Rain==false)
    {
        glColor3ub(255, 217, 255);
    }
    if(Rain==true)
    {
        glColor3ub(  148, 184, 184);
    }


    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}


void cloud2()
{
	GLfloat x = -0.60f; GLfloat y = 0.91f; GLfloat radius = 0.05f;
    GLfloat x1 = -0.65f; GLfloat y1 = 0.88f;
	GLfloat x2 = -0.55f; GLfloat y2 = 0.88f;
	GLfloat x3 = -0.62f; GLfloat y3 = 0.85f;
	GLfloat x4 = -0.67f; GLfloat y4 = 0.87f;
	int triangleAmount = 20;
    if(Rain==false)
    {
        glColor3ub(255, 217, 255);
    }
    if(Rain==true)
    {
        glColor3ub(  148, 184, 184);
    }


    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}




void cloud3()
{
	GLfloat x = -0.10f; GLfloat y = 0.91f; GLfloat radius = 0.05f;
    GLfloat x1 = -0.15f; GLfloat y1 = 0.88f;
	GLfloat x2 = -0.05f; GLfloat y2 = 0.88f;
	GLfloat x3 = -0.12f; GLfloat y3 = 0.85f;
	GLfloat x4 = -0.17f; GLfloat y4 = 0.87f;
	int triangleAmount = 20;
	    if(Rain==false)
    {
        glColor3ub(255, 217, 255);
    }
    if(Rain==true)
    {
        glColor3ub(  148, 184, 184);
    }
    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}

void fence()
{
    GLfloat x1 = -0.944f,x2 = -0.944f,x3 = -1.0f,x4 = -1.0f,y1 = -0.335f,y2 = -0.2818f,y3 = -0.2818f,y4 = -0.335f;
    GLfloat x = 0.08f;


    for(int i =0; i<25; i++)
    {
        if(x1 <= 1.0)
        {
            glLineWidth(3);
            glColor3ub(77, 72, 72);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glVertex2f(x4,y4);
            glEnd();

            x1 += x;
            x2 += x;
            x4 += x;
            x3 += x;
        }
        else
        {
            break;
        }
    }
}


void Industry(){



    glBegin(GL_QUADS);
	glColor3ub(153, 51, 0);
    glVertex2f(.720,.330);
    glVertex2f(.970,.330);
    glVertex2f(.970,.510);
    glVertex2f(.720,.510);
    glEnd();

    glBegin(GL_QUADS);      ///left pipe
	glColor3ub(153, 51, 0);
    glVertex2f(.765, .510);
    glVertex2f(.795, .510);
    glVertex2f(.795, .590);
    glVertex2f(.765, .590);
    glEnd();

    glBegin(GL_QUADS);    ///pipe
	glColor3ub(153, 51, 0);
    glVertex2f(.905, .510);
    glVertex2f(.935, .510);
    glVertex2f(.935, .590);
    glVertex2f(.905, .590);
    glEnd();


    glColor3ub(102, 153, 153);
    DrawCircle(.779f,.602f,.01f,50);
    DrawCircle(.790f,.62f,.015f,50);
    DrawCircle(.809f,.64f,.018f,50);
    glPushMatrix();
    glTranslatef(.14f,0.0f,0.0f);
    DrawCircle(.779f,.602f,.01f,50);
    DrawCircle(.790f,.62f,.015f,50);
    DrawCircle(.809f,.64f,.018f,50);
    glPopMatrix();

    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2f(.720,.510);
    glVertex2f(.760, .560);
    glVertex2f(.80, .510);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2f(.80,.510);
    glVertex2f(.84,.560);
    glVertex2f(.88,.510);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2f(.88,.510);
    glVertex2f(.92,.560);
    glVertex2f(.96,.510);
    glEnd();


    glBegin(GL_POLYGON);  ///industry window
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glPushMatrix();
    glTranslatef(-.08,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glTranslatef(-.08,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glTranslatef(0,-.08,0);
    glBegin(GL_POLYGON);
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glTranslatef(.08,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glTranslatef(.08,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(r1 ,g1, b1);
    glVertex2f(.905,.450);
    glVertex2f(.945,.450);
    glVertex2f(.945,.490);
    glVertex2f(.905,.490);
    glEnd();

    glPopMatrix();


}

void StreetLight()
{
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.82f, -0.2486f);
    glVertex2f(-0.82f,  0.35f);

    glVertex2f(-0.89f,  0.35f);
    glVertex2f(-0.75f,  0.35f);

    glVertex2f(-0.32f, -0.2486f);
    glVertex2f(-0.32f,  0.35f);

    glVertex2f(-0.39f,  0.35f);
    glVertex2f(-0.25f,  0.35f);

    glVertex2f( 0.22f, -0.2486f);
    glVertex2f( 0.22f,  0.35f);

    glVertex2f( 0.15f,  0.35f);
    glVertex2f( 0.29f,  0.35f);

    glVertex2f( 0.78f, -0.2486f);
    glVertex2f( 0.78f,  0.35f);

    glVertex2f( 0.71f,  0.35f);
    glVertex2f( 0.85f,  0.35f);

    glVertex2f(-0.59f,  0.34f);
    glVertex2f(-0.59f,  0.24f);

    glVertex2f(-0.19f,  0.34f);
    glVertex2f(-0.19f,  0.24f);

    glVertex2f( 0.10f,  0.34f);
    glVertex2f( 0.10f,  0.24f);

    glVertex2f( 0.49f,  0.34f);
    glVertex2f( 0.49f,  0.24f);

    glVertex2f( 0.90f,  0.34f);
    glVertex2f( 0.90f,  0.24f);
    glEnd();

    GLfloat x= -0.59f; GLfloat y= 0.34f; GLfloat radius =0.02f;
	int triangleAmount = 20;

    glColor3ub(slr, slg, slb);
    DrawCircle(x,y,radius,triangleAmount);
    x = -0.19f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.10f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.49f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.90f;
    DrawCircle(x,y,radius,triangleAmount);

    glBegin(GL_QUADS);
    glColor3ub(slr, slg, slb);
    glVertex2f(-0.87f,  0.34f);
    glVertex2f(-0.87f,  0.35f);
    glVertex2f(-0.89f,  0.35f);
    glVertex2f(-0.89f,  0.34f);

    glVertex2f(-0.75f,  0.34f);
    glVertex2f(-0.75f,  0.35f);
    glVertex2f(-0.77f,  0.35f);
    glVertex2f(-0.77f,  0.34f);

    glVertex2f(-0.25f,  0.34f);
    glVertex2f(-0.25f,  0.35f);
    glVertex2f(-0.27f,  0.35f);
    glVertex2f(-0.27f,  0.34f);

    glVertex2f(-0.37f,  0.34f);
    glVertex2f(-0.37f,  0.35f);
    glVertex2f(-0.39f,  0.35f);
    glVertex2f(-0.39f,  0.34f);

    glVertex2f( 0.15f,  0.34f);
    glVertex2f( 0.15f,  0.35f);
    glVertex2f( 0.17f,  0.35f);
    glVertex2f( 0.17f,  0.34f);

    glVertex2f( 0.27f,  0.34f);
    glVertex2f( 0.27f,  0.35f);
    glVertex2f( 0.29f,  0.35f);
    glVertex2f( 0.29f,  0.34f);

    glVertex2f( 0.71f,  0.34f);
    glVertex2f( 0.71f,  0.35f);
    glVertex2f( 0.73f,  0.35f);
    glVertex2f( 0.73f,  0.34f);

    glVertex2f( 0.83f,  0.34f);
    glVertex2f( 0.83f,  0.35f);
    glVertex2f( 0.85f,  0.35f);
    glVertex2f( 0.85f,  0.34f);
    glEnd();
}

void tree1(GLfloat vx)
{
    glBegin(GL_QUADS);
    glColor3ub(80, 2, 0);
    glVertex2f((-0.91f + vx), 0.29f);
    glVertex2f((-0.91f + vx), 0.40f);
    glVertex2f((-0.92f + vx), 0.40f);
    glVertex2f((-0.92f + vx), 0.29f);
    glEnd();

    GLfloat x = (-0.915f + vx); GLfloat y = 0.42f; GLfloat radius = 0.03f;
	int triangleAmount = 20;
    glColor3ub(14, 129, 0);
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.885f + vx); y = 0.43f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.915f + vx); y = 0.44f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.945f + vx); y = 0.43f;
    DrawCircle(x,y,radius,triangleAmount);
}

void Tree()
{
    tree1(0.0f);
    tree1(0.35f);
    tree1(0.93f);
    tree1(0.06f);
    tree1(1.36f);
    tree1(1.70f);
}


///School work


void SchoolWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(r1,g1,b1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School()
{
    glPushMatrix(); ///school body
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,192);
    glVertex2i(884,192);
    glVertex2i(884,286);
    glVertex2i(643,286);
    glEnd();
    glPopMatrix();

    glPushMatrix();  ///school top
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,286);
    glVertex2i(887,286);
    glVertex2i(887,293);
    glVertex2i(640,293);
    glEnd();
    glPopMatrix();

    glPushMatrix();   ///school left lower strip
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,200);
    glVertex2i(719,200);
    glVertex2i(719,210);
    glVertex2i(648,210);
    glEnd();
    glPopMatrix();

    glPushMatrix();   ///school right lower strip
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,200);
    glVertex2i(879,200);
    glVertex2i(879,210);
    glVertex2i(808,210);
    glEnd();
    glPopMatrix();



    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,263);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,239);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,216);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,263);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,239);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,217);
    }


}
void SchoolDoor()
{
    glPushMatrix();  ///school door background
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,192);
    glVertex2i(797,192);
    glVertex2i(797,256);
    glVertex2i(728,256);
    glEnd();
    glPopMatrix();

    glPushMatrix();    ///school door triangle
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,256);
    glVertex2i(803,256);
    glVertex2i(763,282);
    glEnd();
    glPopMatrix();

    glPushMatrix();    ///school nameplate background
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,239);
    glVertex2i(792,239);
    glVertex2i(792,256);
    glVertex2i(733,256);
    glEnd();
    glPopMatrix();

    glPushMatrix();     ///school door
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,192);
    glVertex2i(782,192);
    glVertex2i(782,230);
    glVertex2i(743,230);
    glEnd();
    glPopMatrix();
}










void TotalSchool()

{

    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
    School();
    SchoolDoor();
    print(739,241,school);


}

/// Hotel Work

void HotelBelowWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(r1 ,g1, b1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();

}


void HotelAboveWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(r1 ,g1, b1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}



void Hotel()
{
    glPushMatrix();  ///////hotel lower back
    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(359,365);
    glVertex2i(504,365);
    glVertex2i(504,397);
    glVertex2i(359,397);
    glEnd();
    glPopMatrix();

    glPushMatrix();   ///////hotel top body
    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(380,397);
    glVertex2i(479,397);
    glVertex2i(479,516);
    glVertex2i(380,516);
    glEnd();
    glPopMatrix();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(386,516);
    glVertex2i(460,516);
    glVertex2i(460,531);
    glVertex2i(386,531);
    glEnd();
    glPopMatrix();

     int HotelBelowStripe1=338;
    for(int i=5;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1(HotelBelowStripe1,375);
    }

    int HotelAboveStripe1=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,485);
    }

    int HotelAboveStripe2=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,458);
    }

    int HotelAboveStripe3=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,431);
    }

    int HotelAboveStripe4=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,403);
    }
}
void HotelDoor()
{
    glColor3ub(8,32,19);
    DrawCircle(430.0f,393.0f,22.0f,50);

    glPushMatrix();     // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(407,366);
    glVertex2i(453,366);
    glVertex2i(453,389);
    glVertex2i(407,389);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(411,388);
    glVertex2i(429,388);
    glVertex2i(429,365);
    glVertex2i(411,365);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(431,365);
    glVertex2i(448,365);
    glVertex2i(448,388);
    glVertex2i(431,388);
    glEnd();
    glPopMatrix();


}



void AntinaBuilding ()   ///Building antenna
{
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);

    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
    glVertex2i(190,420);
    glVertex2i(300,420);
    glVertex2i(300,560);
    glVertex2i(190,560);
    glEnd();

    int b3y1=430,b3y2=440;
    int b3x1=200,b3x2=215;
    for(int j=1;j<21;j++){
        glBegin(GL_POLYGON);

        glColor3ub(r1,g1,b1);
        glVertex2i(b3x1,b3y1);
        glVertex2i(b3x2,b3y1);
        glVertex2i(b3x2,b3y2);
        glVertex2i(b3x1,b3y2);
        glEnd();


        b3x1=b3x1+25;
        b3x2=b3x2+25;
        if(j%4==0){
            b3x1=200;
            b3x2=215;
            b3y1=b3y1+25;
            b3y2=b3y2+25;
        }

    }

        for(int i=0;i<5;i++){
        glBegin(GL_POLYGON);
        if(i%2==0){
            glColor3ub(153, 204, 0);
        }
        else{
            glColor3ub(153,0, 0);
        }

        glVertex2i(200+(i*10),560+(i*5));
        glVertex2i(290-(i*10),560+(i*5));
        glVertex2i(290-(i*10),565+(i*5));
        glVertex2i(200+(i*10),565+(i*5));
        glEnd();


    }

    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
    glVertex2i(243,585);
    glVertex2i(247,585);
    glVertex2i(247,640);
    glVertex2i(243,640);
    glEnd();
    glPopMatrix();

}



void TotalHotel()
{
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
    Hotel();
    HotelDoor();
    print(398,518,hotel);

}


void building3()
{
    glBegin(GL_QUADS);
    glColor3ub(132, 255, 112);
    glVertex2f(-0.6f, 0.33f);
    glVertex2f(-0.6f, 0.62f);
    glVertex2f(-0.736f, 0.62f);
    glVertex2f(-0.736f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f(-0.61f, 0.62f);
    glVertex2f(-0.61f, 0.70f);
    glVertex2f(-0.73f, 0.66f);
    glVertex2f(-0.73f, 0.62f);
    glEnd();

    //Windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.54f);
    glVertex2f(-0.726f, 0.59f);
    glVertex2f(-0.67f, 0.59f);
    glVertex2f(-0.67f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.54f);
    glVertex2f(-0.61f, 0.59f);
    glVertex2f(-0.66f, 0.59f);
    glVertex2f(-0.66f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.46f);
    glVertex2f(-0.726f, 0.51f);
    glVertex2f(-0.67f, 0.51f);
    glVertex2f(-0.67f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.46f);
    glVertex2f(-0.61f, 0.51f);
    glVertex2f(-0.66f, 0.51f);
    glVertex2f(-0.66f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.37f);
    glVertex2f(-0.726f, 0.43f);
    glVertex2f(-0.67f, 0.43f);
    glVertex2f(-0.67f, 0.37f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.37f);
    glVertex2f(-0.61f, 0.43f);
    glVertex2f(-0.66f, 0.43f);
    glVertex2f(-0.66f, 0.37f);
    glEnd();
}

void building7()
{
    glBegin(GL_QUADS);
    glColor3ub(213, 200, 101);
    glVertex2f( 0.312f, 0.33f);
    glVertex2f( 0.312f, 0.58f);
    glVertex2f( 0.072f, 0.58f);
    glVertex2f( 0.072f, 0.33f);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(135, 61, 61);
    glVertex2f( 0.312f, 0.58f);
    glVertex2f( 0.292f, 0.64f);
    glVertex2f( 0.093f, 0.64f);
    glVertex2f( 0.072f, 0.58f);
    glEnd();



    //Windows
    glBegin(GL_QUADS);
    glColor3ub(r1,g1,b1);
    glVertex2f( 0.182f, 0.47f);
    glVertex2f( 0.182f, 0.55f);
    glVertex2f( 0.082f, 0.55f);
    glVertex2f( 0.082f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.302f, 0.47f);
    glVertex2f( 0.302f, 0.55f);
    glVertex2f( 0.202f, 0.55f);
    glVertex2f( 0.202f, 0.47f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f( 0.182f, 0.35f);
    glVertex2f( 0.182f, 0.43f);
    glVertex2f( 0.082f, 0.43f);
    glVertex2f( 0.082f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.302f, 0.35f);
    glVertex2f( 0.302f, 0.43f);
    glVertex2f( 0.202f, 0.43f);
    glVertex2f( 0.202f, 0.35f);
    glEnd();
}

void building8()
{
    glBegin(GL_QUADS);
    glColor3ub(152, 4, 85);
    glVertex2f( 0.568f, 0.33f);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.336f, 0.54f);
    glVertex2f( 0.336f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 216);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.578f, 0.58f);
    glVertex2f( 0.352f, 0.58f);
    glVertex2f( 0.336f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 216);
    glVertex2f( 0.578f, 0.33f);
    glVertex2f( 0.578f, 0.58f);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.568f, 0.33f);
    glEnd();

    //Windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f( 0.436f, 0.45f);
    glVertex2f( 0.436f, 0.51f);
    glVertex2f( 0.346f, 0.51f);
    glVertex2f( 0.346f, 0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.556f, 0.45f);
    glVertex2f( 0.556f, 0.51f);
    glVertex2f( 0.466f, 0.51f);
    glVertex2f( 0.466f, 0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.436f, 0.35f);
    glVertex2f( 0.436f, 0.41f);
    glVertex2f( 0.346f, 0.41f);
    glVertex2f( 0.346f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.556f, 0.35f);
    glVertex2f( 0.556f, 0.41f);
    glVertex2f( 0.466f, 0.41f);
    glVertex2f( 0.466f, 0.35f);
    glEnd();
}


void building4()
{
    glPushMatrix();
    glTranslatef(-.41,0,0);
    glBegin(GL_QUADS);
    glColor3ub(94, 65, 133);
    glVertex2f(-0.472f, 0.33f);
    glVertex2f(-0.472f, 0.64f);
    glVertex2f(-0.576f, 0.64f);
    glVertex2f(-0.576f, 0.33f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.41,0,0);

    glBegin(GL_QUADS);
    glColor3ub(99, 156, 177);
    glVertex2f(-0.48f, 0.33f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.568f, 0.62f);
    glVertex2f(-0.568f, 0.33f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.41,0,0);

    glBegin(GL_QUADS);
    glColor3ub(112, 95, 135);
    glVertex2f(-0.478f, 0.64f);
    glVertex2f(-0.478f, 0.68f);
    glVertex2f(-0.570f, 0.68f);
    glVertex2f(-0.570f, 0.64f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.41,0,0);

    glBegin(GL_QUADS);
    glColor3ub(112, 95, 135);
    glVertex2f(-0.498f, 0.68f);
    glVertex2f(-0.498f, 0.73f);
    glVertex2f(-0.550f, 0.73f);
    glVertex2f(-0.550f, 0.68f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.41,0,0);

    glBegin(GL_LINES);
    glColor3ub(11,11,11);
    glVertex2f(-0.524f, 0.73f);
    glVertex2f(-0.524f, 0.80f);

    glVertex2f(-0.508f, 0.615f);
    glVertex2f(-0.508f, 0.33f);

    glVertex2f(-0.538f, 0.615f);
    glVertex2f(-0.538f, 0.33f);
    glEnd();
    glPopMatrix();

}

void building12()
{

    glPushMatrix();
    glTranslatef(-.2,0,0);

    glBegin(GL_QUADS);
    glColor3ub(224, 0, 0);
    glVertex2f( 0.578f, 0.33f);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.478f, 0.72f);
    glVertex2f( 0.478f, 0.33f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.2,0,0);

    glBegin(GL_QUADS);
    glColor3ub(87, 0, 0);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.585f, 0.75f);
    glVertex2f( 0.485f, 0.75f);
    glVertex2f( 0.478f, 0.72f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(87, 0, 0);
    glVertex2f( 0.585f, 0.33f);
    glVertex2f( 0.585f, 0.75f);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.578f, 0.33f);
    glEnd();
    glPopMatrix();

}

void building13()
{

    glPushMatrix();
    glTranslatef(-.5,0,0);

    glBegin(GL_QUADS);
    glColor3ub(6, 145, 113);
    glVertex2f( 0.578f, 0.33f);
    glVertex2f( 0.578f, 0.75f);
    glVertex2f( 0.478f, 0.75f);
    glVertex2f( 0.478f, 0.33f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5,0,0);

    glBegin(GL_QUADS);
    glColor3ub(3, 99, 29);
    glVertex2f( 0.578f, 0.75f);
    glVertex2f( 0.585f, 0.78f);
    glVertex2f( 0.485f, 0.78f);
    glVertex2f( 0.478f, 0.75f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5,0,0);
    glBegin(GL_QUADS);
    glColor3ub(3, 99, 29);
    glVertex2f( 0.585f, 0.33f);
    glVertex2f( 0.585f, 0.78f);
    glVertex2f( 0.578f, 0.75f);
    glVertex2f( 0.578f, 0.33f);
    glEnd();

    glPopMatrix();
}

void building9()
{
    glBegin(GL_QUADS);
    glColor3ub(132, 255, 112);
    glVertex2f( 0.792f, 0.33f);
    glVertex2f( 0.792f, 0.64f);
    glVertex2f( 0.688f, 0.64f);
    glVertex2f( 0.688f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(99, 156, 177);
    glVertex2f( 0.784f, 0.33f);
    glVertex2f( 0.784f, 0.62f);
    glVertex2f( 0.696f, 0.62f);
    glVertex2f( 0.696f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f( 0.786f, 0.64f);
    glVertex2f( 0.786f, 0.68f);
    glVertex2f( 0.694f, 0.68f);
    glVertex2f( 0.694f, 0.64f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f( 0.766f, 0.68f);
    glVertex2f( 0.766f, 0.73f);
    glVertex2f( 0.714f, 0.73f);
    glVertex2f( 0.714f, 0.68f);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(11,11,11);
    glVertex2f( 0.725f, 0.615f);
    glVertex2f( 0.725f, 0.33f);

    glVertex2f( 0.754f, 0.615f);
    glVertex2f( 0.754f, 0.33f);
    glEnd();
}
void building18()
{
    glBegin(GL_QUADS);
    glColor3ub(159, 112, 194);
    glVertex2f(-0.140f, 0.33f);
    glVertex2f(-0.140f, 0.62f);
    glVertex2f( 0.112f, 0.62f);
    glVertex2f( 0.112f, 0.33f);
    glEnd();
}


void building20()
{
    glPushMatrix();
    glTranslatef(-.2,0,0);
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 0);
    glVertex2f( 0.856f, 0.33f);
    glVertex2f( 0.856f, 0.71f);
    glVertex2f( 0.766f, 0.71f);
    glVertex2f( 0.766f, 0.33f);
    glEnd();
    glPopMatrix();
}



void Buildings()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 35);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f( 1.0f, 0.38f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-1.0f, 0.33f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.04,0.0,0);
    building20();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.5,0.0,0);
    building18();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.44,0.0,0);
    building3();
    glPopMatrix();

    building13();
    building12();

    glPushMatrix();
    glTranslatef(-0.1,0.0,0);
    building9();
    glPopMatrix();

    building7();
    building8();
    building4();
    glPushMatrix();

    glScalef(1.3,1.3,0);
    glTranslatef(-0.21,-0.08,0);
    Industry();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.9,0.654,0);
    glScalef(0.75,0.75,0);
    TotalSchool();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.7,0.27,0);
    glScalef(0.85,0.85,0);
    TotalHotel();
    glPopMatrix();



    glPushMatrix();

    glTranslatef(0.3,0.145,0);
    glScalef(0.8,0.8,0);

    AntinaBuilding();
    glPopMatrix();





}

void Water()
{
    glLineWidth(0.5);

    glPushMatrix();

    glTranslatef(waterPositionX1,0,0.0f);


    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();


    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();



    glTranslatef(.1,-.1f,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.1,-.1f,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glPopMatrix();

    ///

    glPushMatrix();
    glTranslatef(waterPositionX2,0,0.0f);

    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();


    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();



    glTranslatef(.1,-.1f,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(-.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(-.1,-.1f,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.93f,-.7f);
    glEnd();

    glTranslatef(.2,0,0);
    glBegin(GL_LINES);
    glColor3ub (169, 242, 242);
    glVertex2f(-1,-.7f);
    glVertex2f(-.94f,-.7f);
    glEnd();

    glPopMatrix();


}


void car1()
{

    glBegin(GL_QUADS);
    glColor3ub(225, 229, 150);
    glVertex2f(-0.28f, -0.133f);
    glVertex2f(-0.28f,  0.03f);
    glVertex2f(-0.504f,  0.03f);
    glVertex2f(-0.504f, -0.133f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(225, 229, 150);
    glVertex2f(-0.504f, -0.133f);
    glVertex2f(-0.504f,  0.03f);
    glVertex2f(-0.520f, 0.0034f);
    glVertex2f(-0.520f, -0.1197f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(202, 174, 46);
    glVertex2f(-0.232f,  -0.133f);
    glVertex2f(-0.232f,  -0.048f);
    glVertex2f(-0.28f, -0.048f);
    glVertex2f(-0.28f, -0.133f);
    glEnd();

    GLfloat x= -0.28f; GLfloat y= -0.133f; GLfloat radius =0.085f;
    int triangleAmount = 20;

    glColor3ub(202, 174, 46);
    DrawCircle2(x,y,radius,triangleAmount);

    x = -0.28f; y = -0.048f; radius = 0.048f;
    glColor3ub(255, 228, 108);
    DrawCircle2(x,y,radius,triangleAmount);

    x = -0.27f; y = -0.133f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    x = -0.45f; y = -0.133f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    if(Night)
    {

    glColor3ub(ldr,ldg,ldb);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.15,-0.03f);
    glVertex2f(-0.15,-0.18f);
    glVertex2f(-0.2f, -0.12f);

    glEnd();

    }




}


void car2()
{
    glBegin(GL_QUADS);
    glColor3ub(171, 0, 0);
    glVertex2f( 0.22f, 0.13f);
    glVertex2f( 0.22f,  0.18f);
    glVertex2f( -0.08f, 0.18f);
    glVertex2f( -0.08f,  0.13f);

    glVertex2f( 0.17f, 0.18f);
    glVertex2f( 0.11f, 0.25f);
    glVertex2f(-0.02f, 0.25f);
    glVertex2f(-0.08f, 0.18f);


    glColor3ub(180, 218, 240);
    glVertex2f( 0.15f, 0.18f);
    glVertex2f( 0.10f, 0.23f);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.06f, 0.18f);
    glEnd();

    glColor3ub(97, 97, 97);
    glBegin(GL_LINE_LOOP);
    glVertex2f( 0.15f, 0.18f);
    glVertex2f( 0.10f, 0.23f);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.06f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.01f, 0.18f);

    glVertex2f( 0.10f, 0.23f);
    glVertex2f( 0.10f, 0.18f);

    glVertex2f( 0.05f, 0.23f);
    glVertex2f( 0.05f, 0.18f);
    glEnd();

    GLfloat x = 0.15f, y = 0.13f, radius = 0.026f;
    int triangleAmount = 20;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    x = -0.0f; y = 0.13f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    if(Night)
    {

    glColor3ub(ldr,ldg,ldb);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.22f, 0.17f);
    glVertex2f(0.27f,0.22f);
    glVertex2f(0.27f,0.1f);
    glVertex2f(0.22f,0.15f);

    glEnd();

    }


}



void TrafficLight()
{

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.365f,0.2258f);
    glVertex2f(0.365f,0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.39f,0.30f);
    glVertex2f(0.39f,0.45f);
    glVertex2f(0.34f,0.45f);
    glVertex2f(0.34f,0.30f);
    glEnd();

    GLfloat x= 0.365f; GLfloat y=0.425f; GLfloat radius =0.015f;
    int triangleAmount = 20;

    glColor3ub(trr, trg, trb);
    DrawCircle(x,y,radius,triangleAmount);

    y=0.38f;

    glColor3ub(tyr, tyg, tyb);
    DrawCircle(x,y,radius,triangleAmount);

    y=0.335f;

    glColor3ub(tgr, tgg, tgb);
    DrawCircle(x,y,radius,triangleAmount);
}




///*****************************************************************************

/// All Display Functions


void DayDisplay()
{
    if(Day)
    {

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
        glEnable(GL_COLOR_MATERIAL);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        PointLight(1,1,0, 0.8, 0.8, 0.7);


        sky();
        ///moon();
    if(Rain==false){
        sun();
    }
        glPushMatrix();
        glTranslatef(Cloud1PositionX, 0.0f, 0.0f);
        cloud1();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(Cloud2PositionX, 0.0f, 0.0f);
        cloud2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Cloud3PositionX, 0.0f, 0.0f);
        cloud3();
        glPopMatrix();


        river();

        Bridge();

        Water();


        glPushMatrix();
        glTranslatef(Boat2PositionX, 0.0f, 0.0f);
        boat2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Boat1PositionX, 0.0f, 0.0f);
        boat1();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(BirdPositionX, BirdPositionY, 0.0f);
     if(Rain==false){
        bird1();
        bird2();
     }
        glPopMatrix();

        footpath1();
        footpath2();
        fence();

        road();
        Buildings();
        Tree();
        TrafficLight();


        glPushMatrix();
        glTranslatef(Car2PositionX, 0.0f, 0.0f);
        car2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Car1PositionX, 0.0f, 0.0f);
        car1();
        glPopMatrix();

        StreetLight();

        if(Rain == true)
        {
            glPushMatrix();
            rain();
            glPopMatrix();

        }


        glFlush();




   }

}


void NightDisplay()
{
    if(Night)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
        glEnable(GL_COLOR_MATERIAL);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        PointLight(0,0,1, 0.5, 1, 1);
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);



        sky();
        if(Rain==false)
{
          moon();
          stars();
}
        ///sun();

        glPushMatrix();
        glTranslatef(Cloud1PositionX, 0.0f, 0.0f);
        cloud1();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(Cloud2PositionX, 0.0f, 0.0f);
        cloud2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Cloud3PositionX, 0.0f, 0.0f);
        cloud3();
        glPopMatrix();


        river();
        Bridge();
        Water();

        glPushMatrix();
        glTranslatef(Boat2PositionX, 0.0f, 0.0f);
        boat2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Boat1PositionX, 0.0f, 0.0f);
        boat1();
        glPopMatrix();



        footpath1();
        footpath2();
        fence();

        road();
        Buildings();
        Tree();
        TrafficLight();


        glPushMatrix();
        glTranslatef(Car2PositionX, 0.0f, 0.0f);
        car2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Car1PositionX, 0.0f, 0.0f);
        car1();
        glPopMatrix();

        StreetLight();

        if(Rain == true)
        {
            glPushMatrix();
            rain();

            glPopMatrix();

        }


        glFlush();
    }
}


void DayModePositionReset()
{
    if(Day)
    {
        BirdPositionX = -0.5f;
        BirdPositionY = -0.2f;
    }
}




void MainDisplay()
{
    if(Day)
    {
        DayDisplay();
    }

    else if(Night)
    {
        NightDisplay();
    }

}


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}



void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        /// Night
	    case 'N':
        case 'n':
            Day = false;
            Night = true;
            NightColorChange();
            sound3();
            if (Rain == true)
                    {
                    RainColorChange();
                    sound();

                    }
            MainDisplay();

            break;
        /// Day
	    case 'D':
        case 'd':
            Day = true;
            Night = false;
            DayModePositionReset();
            DayColorChange();
            sound3();
            if (Rain == true)
                    {
                        RainColorChange();
                        sound();

                    }
            MainDisplay();

            break;
        /// Boat1
        case 'B':
        case 'b':
            if(KeyB == 0)
            {
                StopBoat1 = false;
                MoveBoat1(Boat1Speed);
                KeyB = 1;
            }
            else if(KeyB == 1)
            {
                StopBoat1 = true;
                MoveBoat1(Boat1Speed);
                KeyB = 0;
            }
            break;
        /// Boat2
        case 'V':
        case 'v':
            if(KeyV == 0)
            {
                StopBoat2 = false;
                MoveBoat2(Boat2Speed);
                KeyV = 1;
            }
            else if(KeyV == 1)
            {
                StopBoat2 = true;
                MoveBoat2(Boat2Speed);
                KeyV = 0;
            }
            break;
        /// Bird
        case 'Z':
        case 'z':
            if(KeyZ == 0)
            {
                StopBird = false;
                MoveBird(BirdSpeed);
                KeyZ = 1;
            }
            else if(KeyZ == 1)
            {
                StopBird = true;
                MoveBird(BirdSpeed);
                KeyZ = 0;
            }
            break;

        ///Traffic Light
        case 'R':
        case 'r':
            TrafficGreen = false;
            TrafficRed = true;
            TrafficYellow = false;
            TrafficRedLight();
            break;
        case 'G':
        case 'g':
            TrafficGreen = true;
            TrafficRed = false;
            TrafficYellow = false;
            TrafficGreenLight();
            break;
        case 'Y':
        case 'y':
            TrafficGreen = false;
            TrafficRed = false;
            TrafficYellow = true;
            TrafficYellowLight();
            break;
        /// cloud

        case 'C':
        case 'c':
            if(KeyC == 0)
            {
                StopCloud1 = false;
                MoveCloud1(Cloud1Speed);
                KeyC = 1;
            }
            else if(KeyC == 1)
            {
                StopCloud1 = true;
                MoveCloud1(Cloud1Speed);
                KeyC = 0;
            }
            break;
        case 'X':
        case 'x':
            if(KeyX == 0)
            {
                StopCloud2 = false;
                MoveCloud2(Cloud2Speed);
                KeyX = 1;
            }
            else if(KeyX == 1)
            {
                StopCloud2 = true;
                MoveCloud2(Cloud2Speed);
                KeyX = 0;
            }
            break;

        case 'P':
        case 'p':
            if(KeyP == 0)
            {
                StopCloud3 = false;
                MoveCloud3(Cloud3Speed);
                KeyP = 1;
            }
            else if(KeyP == 1)
            {
                StopCloud3 = true;
                MoveCloud3(Cloud3Speed);
                KeyP = 0;
            }
            break;

        case 'E':
        case 'e':

            if(KeyE == 1)
            {
                Rain = true;
                StopRain = false;
                updaterain(speedrain);
                updaterain1(speedrain);
                RainColorChange();
                sound();
                KeyE = 0;
            }
            else if(KeyE == 0)
            {
                Rain = false;
                StopRain = true;
                updaterain(speedrain);
                updaterain1(speedrain);
                if (Day == true)
                    {
                DayModePositionReset();
                DayColorChange();
                sound3();
                    }
                if (Night == true)
                    {
                NightColorChange();
                sound3();
                    }
                KeyE = 1;
            }
            break;

        case 27:
            exit(0);
            break;


        glutPostRedisplay();
	}
}






int main(int argc, char** argv) {
    cout << endl << "*********** CityScape Life ********************" << endl << endl;

    cout << "Press D : For Day Mode" << endl << endl;
    cout << "Press N : For Night Mode" << endl << endl;
    cout << "Press R : For Red Traffic Light" << endl << endl;
    cout << "Press G : For Green Traffic Light" << endl << endl;
    cout << "Press Y : For Yellow Traffic Light" << endl << endl;
    cout << "Press Z : For Control Birds" << endl << endl;
    cout << "Press C : To Stop Right Side Cloud" << endl << endl;
    cout << "Press X : To Stop Left Side Cloud" << endl << endl;
    cout << "Press P : To Stop Middle Side Cloud" << endl << endl;
    cout << "Press B : For Move Left Side Boat" << endl << endl;
    cout << "Press V : For Move Right Side Boat" << endl << endl;


    glutInit(&argc, argv);
    glutInitWindowSize(1050, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Port City View");
    glutDisplayFunc(MainDisplay);
    init();
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(25, MoveBoat1, 0);
    glutTimerFunc(25, MoveBoat2, 0);
    glutTimerFunc(25, MoveCar1, 0);
    glutTimerFunc(25, MoveCar2, 0);
    glutTimerFunc(50, MoveBird, 0);
    glutTimerFunc(25, MoveCloud1, 0);
    glutTimerFunc(22, MoveCloud2, 0);
    glutTimerFunc(22, MoveCloud3, 0);
    glutTimerFunc(100, Movewater1, 0);
    glutTimerFunc(100, Movewater2, 0);

    glutTimerFunc(100, updaterain, 0);
    glutTimerFunc(100, updaterain1, 0);
    sound3();

    glutMainLoop();
    return 0;
}
