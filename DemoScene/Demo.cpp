#include <GL/glut.h> // Include the GLUT header file
#include <iostream>
#include <cmath>

float BoatY = 0.0f;
float SunY = 0.0f;
float SkyRed = 0.0f, SkyGreen = 0.8f, SkyBlue = 1.0f;
float cloud1X =-0.7f, cloud2X = -0.6f, cloud3X = 0.0f, cloud4X = 0.7f;
float WindowRed = 0.0f, WindowGreen = 0.0f, WindowBlue = 0.0f;
float CarX = -0.8f, BusX = 0.0f, Car2X = 0.05f;


void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, GLfloat(w) / GLfloat(h), 1.0f, 40.0);
  glMatrixMode(GL_MODELVIEW);
}
void handleKeypress(unsigned char key, int x, int y){

  switch(key){
    case 27:
      exit(0);  
    break;
  }
}
namespace Sqaure{
    void draw(float x, float y, float z, float red, float blue, float green, float scale){
        glTranslatef(x,y,z);
        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(red,blue,green);
            glVertex3f(-0.5f*scale, 1.0f*scale, 0.0f*scale);
            glVertex3f(-0.5f*scale, 0.1f*scale, 0.0f*scale);
            glVertex3f( 0.1f*scale, 0.1f*scale, 0.0f*scale);
            glVertex3f( 0.1f*scale, 1.0f*scale, 0.0f*scale);
        glEnd();
        glPopMatrix();

    }
}
namespace Sphere
{
      void draw(float red, float green, float blue, float SphereX, float SphereY,float SphereZ,float size) {

        glLoadIdentity();
        glTranslatef(SphereX,SphereY, SphereZ);
        
        glPushMatrix();
        glColor3f(red, green, blue);
        glutSolidSphere(size, 32, 32);
        glPopMatrix();
    }
}
namespace Plane{

    void draw(float x, float y, float z, float r, float g, float b){
        glLoadIdentity();
        glTranslatef(x,y,z);
        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(r,g,b);
            glVertex3f(-1.0f,0.4f,0.0f);
            glVertex3f(-1.0f,-1.0f,0.0f);
            glVertex3f(1.0f,-1.0f,0.0f);
            glVertex3f(1.0f,0.4f,0.0f);
        glEnd();
        glPopMatrix();
    }
}
namespace Road{
    void draw(float x, float y, float z){
        glLoadIdentity();
        glTranslatef(x,y,z);
        glPushMatrix();
        glBegin(GL_QUADS);
        
            //black
            glColor3f(0.0f,0.0f,0.0f);
            glVertex3f(-0.3f,0.0f,0.0f);
            glVertex3f(-0.3f,-0.3f,-0.0f);
            glVertex3f(0.22f,-0.3f,0.0f);
            glVertex3f(0.22f,0.0f,0.0f);

            //grey
            glColor3f(0.3f,0.3f,0.3f);
            glVertex3f(-0.3f,-0.017f,0.0f);
            glVertex3f(-0.3f,-0.283f,-0.0f);
            glVertex3f(0.22f,-0.283f,0.0f);
            glVertex3f(0.22f,-0.017f,0.0f);

        glEnd();

        glLineWidth(5.0f);
        glBegin(GL_LINES);
            glColor3f(1.0f,1.0f,1.0f);
            glVertex3f(-0.10f,-0.15f,0.0f);
            glVertex3f(0.03f,-0.15f,0.0f);
        glEnd();
        glPopMatrix();
    }
}
namespace Cloud{
    void draw(float x, float y, float z){
        float r = 0.8f;
        float g = 0.8f;
        float b = 0.8f; 

        glLoadIdentity();
        glTranslated(x,y,z);
        
        glPushMatrix();
        glColor3f(r,g,b);
        glTranslatef(-0.09f,0.0f,0.0f);
        glutSolidSphere(0.1,32,32);
        glPopMatrix();

        glPushMatrix();
        glColor3f(r,g,b);
        glTranslatef(0.0f,0.0f,0.0f);
        glutSolidSphere(0.1,32,32);
        glPopMatrix();

        glPushMatrix();
        glColor3f(r,g,b);
        glTranslatef(0.09f,0.0f,0.0f);
        glutSolidSphere(0.1,32,32);
        glPopMatrix();

        glPushMatrix();
        glColor3f(r,g,b);
        glTranslatef(0.0f,0.1f,0.0f);
        glutSolidSphere(0.1,32,32);
        glPopMatrix();
    }
}
namespace Building{
    void draw(float x, float y, float z){
        glLoadIdentity();
        glTranslatef(x,y,z);

        //house frame
        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.8f,0.8f,0.0f);
            glVertex3f(-0.13f, 0.2f,0.0f);
            glVertex3f(-0.13f,-0.4f,0.0f);
            glVertex3f(0.13f, -0.4f, 0.0f);
            glVertex3f(0.13f, 0.2f,0.0f);
        glEnd();
        glPopMatrix();

        //window
        float WindowX = -0.05f;
        float WindowY = 0.125f;
        for(int i=0;i<3;i++){
            WindowX = -0.05f;
            for(int j = 0; j<2;j++){
                glPushMatrix();
                glTranslatef(WindowX,WindowY,0.0f);
                glBegin(GL_QUADS);
                    glColor3f(WindowRed, WindowGreen, WindowBlue);
                    glVertex3f(-0.04f, 0.04f,0.0f);
                    glVertex3f(-0.04f,-0.06f,0.0f);
                    glVertex3f(0.03f, -0.06f, 0.0f);
                    glVertex3f(0.03f, 0.04f,0.0f);
                glEnd();
                glPopMatrix();
                WindowX += .11;
            }
            WindowY -= .15f;
        }

        //Door
        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.8f,0.4f,0.0f);
            glVertex3f(-0.05f,-0.27f, 0.0f);
            glVertex3f(-0.05f,-0.4f, 0.0f);
            glVertex3f(0.05f, -0.4f, 0.0f);
            glVertex3f(0.05f, -0.27f, 0.0f);
        glEnd();
        glPopMatrix();

        //garage
        glPushMatrix();
        Sqaure::draw(0.27f,-0.43f,0.0f,
        0.8f,0.8f,0.0f,
        0.3f);
        glLoadIdentity();
        glTranslatef(-0.42f,0.12f,0.0f);

        glPushMatrix();
        glTranslatef(-0.146f,0.029f,0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.8f,0.4f,0.0f);
            glVertex3f(0.15f,0.13f,0.0f);
            glVertex3f(0.15f,0.0f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.0f,0.13f,0.0f);
        glEnd();
        glPopMatrix();

        //garage roof
        glLoadIdentity();
        glTranslated(-0.43f,0.13f,0.0f);

        glPushMatrix();
        glTranslatef(-0.14f,0.29f,0.0f);
        glLineWidth(20.0f);
        glBegin(GL_LINES);
            glColor3f(0.20f,0.10f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glVertex3f(0.19f,0.0f,0.0f);
        glEnd();
        glPopMatrix();

        //roof
        glPushMatrix();
        glTranslatef(-0.274f,0.62f,0.0f);
        glBegin(GL_TRIANGLES);
            glColor3f(0.20f,0.10f,0.0f);
            glVertex3f(-0.18f,0.0f,0.0f);
            glVertex3f(0.0f,0.17f,0.0f);
            glVertex3f(0.18f,0.0f,0.0f);
        glEnd();
        glPopMatrix();


    }
}
namespace Building2{
    void draw(float x, float y, float z){
        glLoadIdentity();
        glTranslatef(x,y,z);

        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.2f,0.36f,0.67f);
            glVertex3f(-0.2f, 0.04f,0.0f);
            glVertex3f(-0.2f,-0.4f,0.0f);
            glVertex3f(0.2f, -0.4f, 0.0f);
            glVertex3f(0.2f, 0.04f,0.0f);
        glEnd();
        glPopMatrix();

        //window
        float WindowX = -0.14f;
        float WindowY = -0.05f;
        for(int i = 0; i<3;i++){
            glPushMatrix();
            glTranslatef(WindowX,WindowY,0.0f);
            glBegin(GL_QUADS);
                glColor3f(WindowRed, WindowGreen, WindowBlue);
                glVertex3f(-0.04f, 0.04f,0.0f);
                glVertex3f(-0.04f,-0.06f,0.0f);
                glVertex3f(0.03f, -0.06f, 0.0f);
                glVertex3f(0.03f, 0.04f,0.0f);
            glEnd();
            glPopMatrix();
            WindowY -= .13f;
        }
        WindowY = -0.05f;
        WindowX = 0.14f;
        for(int i = 0; i<3;i++){
            glPushMatrix();
            glTranslatef(WindowX,WindowY,0.0f);
            glBegin(GL_QUADS);
                glColor3f(WindowRed, WindowGreen, WindowBlue);
                glVertex3f(-0.04f, 0.04f,0.0f);
                glVertex3f(-0.04f,-0.06f,0.0f);
                glVertex3f(0.03f, -0.06f, 0.0f);
                glVertex3f(0.03f, 0.04f,0.0f);
            glEnd();
            glPopMatrix();
            WindowY -= .13f;
        }

        //roof
        glPushMatrix();
        glTranslatef(0.0f,0.03f,0.0f);
        glBegin(GL_TRIANGLES);
            glColor3f(0.16f,0.10f,0.0f);
            glVertex3f(-0.24f,0.0f,0.0f);
            glVertex3f(0.0f,0.17f,0.0f);
            glVertex3f(0.24f,0.0f,0.0f);
        glEnd();
        glPopMatrix();
        
        //Door
        glPushMatrix();
        glTranslatef(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
            glColor3f(0.36f,0.59f,0.36f);
            glVertex3f(-0.05f,-0.27f, 0.0f);
            glVertex3f(-0.05f,-0.4f, 0.0f);
            glVertex3f(0.05f, -0.4f, 0.0f);
            glVertex3f(0.05f, -0.27f, 0.0f);
        glEnd();
        glPopMatrix();

        //Cross
        glPushMatrix();
        glLineWidth(5);
        glBegin(GL_LINES);
            glColor3f(0.36f,0.16f,0.16f);
            glVertex2f(0.0f,-0.24f);
            glVertex2f(0.0f, 0.0);
            glVertex2f(-0.04,-0.07);
            glVertex2f(0.04f,-0.07);
        glEnd();
        glPopMatrix();
    }
}
namespace Car{
    void draw(float x, float y, float z, float scale){
    glColor3f(1.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glTranslatef(x,y,z);
    
    glPushMatrix();
    glBegin(GL_QUADS);
        glVertex2f(-0.8f*scale, -0.3f*scale);
        glVertex2f(-0.8f*scale, 0.3f*scale);
        glVertex2f(0.8f*scale, 0.3f*scale);
        glVertex2f(0.8f*scale, -0.3f*scale);
    glEnd();
    glPopMatrix();

    // Draw the car wheels
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
        glTranslatef(-0.5f*scale, -0.3f*scale, 0.0f*scale);
        glutSolidSphere(0.2*scale, 32, 32);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.5f*scale, -0.3f*scale, 0.0f*scale);
        glutSolidSphere(0.2*scale, 32, 32);
    glPopMatrix();

    //cockpit
    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(-0.4f*scale, 0.1f*scale);
            glVertex2f(-0.4f*scale, 0.3f*scale);
            glVertex2f(0.4f*scale, 0.3f*scale);
            glVertex2f(0.4f*scale, 0.1f*scale);
        glEnd();
    glPopMatrix(); 


    }
}
namespace Car2{
    void draw(float x, float y, float z, float scale){
        glColor3ub(120, 0, 0);
        glLoadIdentity();
            glTranslatef(x,y,z);
    glBegin(GL_QUADS);
        glVertex2f(3.0f*scale,-0.5f*scale);
        glVertex2f(4.5f*scale,-0.5f*scale);
        glVertex2f(4.5f*scale,-0.4f*scale);
        glVertex2f(3.0f*scale,-0.4f*scale);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(3.2f*scale,-0.4f*scale);
        glVertex2f(4.3f*scale,-0.4f*scale);
        glVertex2f(4.3f*scale,-0.1f*scale);
        glVertex2f(3.2f*scale,-0.1f*scale);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(4.3f*scale,-0.4f*scale);
        glVertex2f(4.5f*scale,-0.4f*scale);
        glVertex2f(4.3f*scale,-0.3f*scale);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(3.0f*scale,-0.4f*scale);
        glVertex2f(3.2f*scale,-0.4f*scale);
        glVertex2f(3.2f*scale,-0.3f*scale);
    glEnd();

    glColor3ub(0, 51, 0);
    glBegin(GL_QUADS);
        glVertex2f(3.3f*scale,-0.3f*scale);
        glVertex2f(3.6f*scale,-0.3f*scale);
        glVertex2f(3.6f*scale,-0.15f*scale);
        glVertex2f(3.3f*scale,-0.15f*scale);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(3.7f*scale,-0.3f*scale);
        glVertex2f(4.0f*scale,-0.3f*scale);
        glVertex2f(4.0f*scale,-0.15f*scale);
        glVertex2f(3.7f*scale,-0.15f*scale);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(4.1f*scale,-0.3f*scale);
        glVertex2f(4.3f*scale,-0.3f*scale);
        glVertex2f(4.3f*scale,-0.15f*scale);
        glVertex2f(4.1f*scale,-0.15f*scale);
    glEnd();

    float wheelRadius = 0.17f * scale;

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(3.8f*scale,0.1f*scale,0.0f*scale);
    glPushMatrix();
    glTranslatef(-0.4f*scale, -0.7f*scale, 0.0f*scale);
        glutSolidSphere(wheelRadius, 32, 32);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.4f*scale, -0.7f*scale, 0.0f*scale);
        glutSolidSphere(wheelRadius, 32, 32);
    glPopMatrix();

    }
}
namespace Bus{
    void draw(float x, float y, float z,float scale){

        glLoadIdentity();
        glTranslatef(x,y,z);
        glScalef(scale, scale, scale);
        ///Bus
    glPushMatrix();
    glTranslatef(0.0f,0.0, 0.0f);
  glBegin(GL_QUADS);
    glColor3ub(179, 255, 102);
    glVertex2f(3.0f,-1.8f);
    glVertex2f(4.5f,-1.8f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(3.0f,-1.6f);
    glEnd();

   glBegin(GL_QUADS);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(4.5f,-1.6f);
    glVertex2f(4.5f,-1.1f);
    glVertex2f(3.2f,-1.1f);
    glEnd();

     glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.4f,-1.6f);
    glVertex2f(3.55f,-1.6f);
    glVertex2f(3.55f,-1.3f);
    glVertex2f(3.4f,-1.3f);
    glEnd();

         glBegin(GL_QUADS);
    glVertex2f(3.6f,-1.6f);
    glVertex2f(3.8f,-1.6f);
    glVertex2f(3.8f,-1.4f);
    glVertex2f(3.6f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.6f);
    glVertex2f(4.1f,-1.6f);
    glVertex2f(4.1f,-1.4f);
    glVertex2f(3.9f,-1.4f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.6f);
    glVertex2f(4.4f,-1.6f);
    glVertex2f(4.4f,-1.4f);
    glVertex2f(4.2f,-1.4f);
    glEnd();

////

     glBegin(GL_QUADS);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.3f,-1.3f);
    glVertex2f(3.5f,-1.2f);
    glVertex2f(3.5f,-1.2f);
    glEnd();

         glBegin(GL_QUADS);
   glColor3ub(0, 51, 77);
    glVertex2f(3.6f,-1.3f);
    glVertex2f(3.8f,-1.3f);
    glVertex2f(3.8f,-1.2f);
    glVertex2f(3.6f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(3.9f,-1.3f);
    glVertex2f(4.1f,-1.3f);
    glVertex2f(4.1f,-1.2f);
    glVertex2f(3.9f,-1.2f);
    glEnd();

           glBegin(GL_QUADS);
    glVertex2f(4.2f,-1.3f);
    glVertex2f(4.4f,-1.3f);
    glVertex2f(4.4f,-1.2f);
    glVertex2f(4.2f,-1.2f);
    glEnd();

    glBegin(GL_QUADS);
   glColor3ub(230, 255, 255);
    glVertex2f(3.0f,-1.6f);
    glVertex2f(3.2f,-1.6f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.0f,-1.4f);
    glEnd();

       glBegin(GL_TRIANGLES);
    glVertex2f(3.0f,-1.4f);
    glVertex2f(3.2f,-1.4f);
    glVertex2f(3.2f,-1.1f);
   glEnd();


     glBegin(GL_QUADS);
   glColor3ub(1,0,0);
    glVertex2f(3.1f,-1.7f);
    glVertex2f(3.3f,-1.7f);
    glVertex2f(3.3f,-1.4f);
    glVertex2f(3.1f,-1.4f);
    glEnd();
    glPopMatrix();

    
    
    glPushMatrix();
    glTranslatef(3.4f,-1.9f,0.0f);
    glutSolidSphere(0.15f, 32,32);
	glPopMatrix();

    glPushMatrix();
    glTranslatef(4.3f,-1.9f,0.0f);
    glutSolidSphere(0.15f, 32,32);
	glPopMatrix();
    


    }
}
namespace Boat {
   void draw(float x, float y, float z, float scale) {
    glLoadIdentity();
    glTranslatef(x, y, z);
    glPushMatrix();
    
    glColor3ub(102, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(2.8 * scale, -3.0 * scale);
        glVertex2f(2.5 * scale, -2.8 * scale);
        glVertex2f(2.7 * scale, -3.2 * scale);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(2.8 * scale, -3.0 * scale);
        glVertex2f(2.7 * scale, -3.2 * scale);
        glVertex2f(3.6 * scale, -3.2 * scale);
        glVertex2f(3.5 * scale, -3.0 * scale);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(3.5 * scale, -3.0 * scale);
        glVertex2f(3.6 * scale, -3.2 * scale);
        glVertex2f(3.8 * scale, -2.8 * scale);
    glEnd();

    glColor3ub(12, 13, 13);
    glBegin(GL_TRIANGLES);
        glVertex2f(2.8 * scale, -3.0 * scale);
        glVertex2f(3.0 * scale, -3.0 * scale);
        glVertex2f(2.9 * scale, -2.7 * scale);
    glEnd();

    glColor3ub(12, 153, 13);
    glBegin(GL_QUADS);
        glVertex2f(2.9 * scale, -2.7 * scale);
        glVertex2f(3.0 * scale, -3.0 * scale);
        glVertex2f(3.5 * scale, -3.0 * scale);
        glVertex2f(3.4 * scale, -2.7 * scale);
    glEnd();
    glPopMatrix();
}

}
namespace Tree{
    void drawTree(float x, float y, float z, float scale){
        glLoadIdentity();
        glScalef(scale, scale, scale);
        glTranslatef(x,y,z);
        glPushMatrix();

    // Draw trunk
    glColor3f(0.54, 0.27, 0.07); // Brown
    glBegin(GL_POLYGON);
        glVertex3f(-0.1f, 0.0f, 0.0f);
        glVertex3f(-0.1f, 0.6f, 0.0f);
        glVertex3f(0.1f, 0.6f, 0.0f);
        glVertex3f(0.1f, 0.0f, 0.0f);
    glEnd();
    
    // Draw leaves
    glColor3f(0.0, 0.2, 0.0); // Green
    glTranslatef(0.0f, 0.6f, 0.0f);
    glutSolidSphere(0.4f, 20, 20);
    glTranslatef(0.0f, 0.4f, 0.0f);
    glutSolidSphere(0.3f, 20, 20);
    glTranslatef(0.0f, 0.4f, 0.0f);
    glutSolidSphere(0.2f, 20, 20);

    glPopMatrix();
    }

    void drawForest(float x, float y,float z) {
        
        
        drawTree(0.0f+x,0.0f+y,0.0f+z,0.25f);
        drawTree(6.0f+x,-5.0f+y,0.0f+z,0.1f);
        drawTree(0.5f+x,-0.07f+y,0.0f+z,0.25f);
        drawTree(-0.4f+x,-0.2f+y,0.0f+z,0.25f);
        
    }
}
namespace Hill{
    void drawHill(float x, float y, float height, float width){

    glLoadIdentity();
    glTranslatef(x, y, 0.0f);

    glPushMatrix();
    glColor3f(0.54f, 0.27f, 0.07f); 
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++)
        {
            float angle = i * (3.14159 / 180.0);
            float h = height * sin(angle);
            float w = width * cos(angle);
            glVertex3f(w, h, 0.0f);
        }
    glEnd();
    glPopMatrix();
}
}
namespace Rock{
    void draw(float x, float y, float z, float scale){

        glLoadIdentity();
        glTranslatef(x,y,z);

        glPushMatrix();
        glTranslatef(0.001f*scale,0.001f*scale,0.001f*scale);
        glColor3f(0.5f, 0.5f, 0.5f);
        glutSolidSphere(0.2f*scale, 32, 32);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.20f*scale,0.001f*scale,0.001f*scale);
        glColor3f(0.5f, 0.5f, 0.5f);
        glutSolidSphere(0.2f*scale, 32, 32);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.20f*scale,0.001f*scale,0.001f*scale);
        glColor3f(0.5f, 0.5f, 0.5f);
        glutSolidSphere(0.2f*scale, 32, 32);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.001f*scale,0.14f*scale,0.001f*scale);
        glColor3f(0.5f, 0.5f, 0.5f);
        glutSolidSphere(0.2f*scale, 32, 32);
        glPopMatrix();


    }
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT); 


    //sky
    Plane::draw(0.0f,1.0f,0.0f,
    SkyRed, SkyGreen, SkyBlue);

    //sun
    Sphere::draw(1.0f,0.5f,0.0f,
    0.9f,SunY,0.0f,
    0.25f);
    

   Hill::drawHill(0.4f,0.1f,0.6f,0.4f);
   Hill::drawHill(0.6f,0.1f,0.5f,0.4f);
    

    //grass
    Plane::draw(0.0f,0.0f,0.0f,
    0.0f,0.5f,0.25f);

    //tree at hill
    Tree::drawTree(2.0f,1.6f,0.0f,0.17f);
    Tree::drawTree(2.5f,1.9f,0.0f,0.17f);
    Tree::drawTree(3.0f,1.6f,0.0f,0.17f);
    Tree::drawTree(3.5f,1.7f,0.0f,0.17f);
    Tree::drawTree(4.0f,1.6f,0.0f,0.17f);
    
    //sand
    Sphere::draw(0.8f,0.8f,0.4f,
    -0.9f,-1.24f,0.0f,
    0.7f);

    //water
    Sphere::draw(0.0f,0.5f,1.0f, 
    -0.9f,-1.1f,0.0f,
    0.5f);

    //boat
    Boat::draw(-1.7f,BoatY,0.0f,0.3f);

    //Road
    float RoadX = -0.7f;
    for( int i=0; i<4; i++ ){
        Road::draw(RoadX, 0.14f, 0.0f);
        RoadX += 0.52f;
    }
    RoadX = -0.7f;
    for( int i=0; i<4; i++ ){
        Road::draw(RoadX, -0.18f, 0.0f);
        RoadX += 0.52f;
    }


    //cloud
    Cloud::draw(cloud1X, 0.8f, 0.0f);
    Cloud::draw(cloud2X, 0.77f, 0.0f);
    Cloud::draw(cloud3X, 0.7f, 0.0f);
    Cloud::draw(cloud4X, 0.75f, 0.0f);

    //building
    Building::draw(-0.7f,0.55f,0.0f);
    Building2::draw(0.0f,0.55f,0.0f);
    
    //cars
    Car::draw(CarX,0.10f,0.0f,0.17f);
    Car2::draw(Car2X,-0.16f,0.0f,0.2f);
    Bus::draw(BusX,0.03f,0.0f,0.23f);

    //tree    
    Tree::drawTree(-1.2f,0.6f,0.0f,0.25f);
    Tree::drawForest(2.5f,-3.7f,0.0f);

    //rock
    Rock::draw(0.46f,0.24f,0.0f,0.2f);
    Rock::draw(0.36f,-0.9f,0.0f,0.2f);


    glFlush(); 
}   

float TimeBoat = 0.0f;
void updateBoat(int v){
    TimeBoat += 0.1f;
    BoatY = 0.007f * cos(TimeBoat)+ 0.1f;
    glutPostRedisplay();
	glutTimerFunc(1, updateBoat, 0);
}

float TimeSun = 0.0f;
void updateSun(int v){
    TimeSun += 0.005f;
    SunY = 0.5f*cos(TimeSun)+0.5f;
    
    glutPostRedisplay();
	glutTimerFunc(1, updateSun, 0);
}

void updateCloud(int v){
    
    cloud1X -= 0.0026f; 
    cloud2X -= 0.0024f; 
    cloud3X -= 0.0015f; 
    cloud4X -= 0.0015f; 

    if(cloud1X < -1.4f){
        cloud1X = 1.0f;
    }
    if(cloud2X < -1.4f){
        cloud2X = 1.0f;
    }
    if(cloud3X < -1.4f){
        cloud3X = 1.0f;
    }
    if(cloud4X < -1.4f){
        cloud4X = 1.0f;
    }


    glutPostRedisplay();
	glutTimerFunc(1, updateCloud, 0);

}

void updateSky(int v){
    //-0.8 to 0.09
    if(SunY > 0.8f && SunY < 1.0f){
        //cyanid
        SkyRed = 0.0f;
        SkyGreen = 0.8f;
        SkyBlue = 1.0f;
        
    }else if(SunY > 0.5 && SunY < 0.7){
        //orange
        SkyRed = 1.0f;
        SkyGreen = 0.65f;
        SkyBlue = 0.0f;

        WindowRed = 0.0f;
        WindowGreen = 0.0f;
        WindowBlue = 0.0f;

    }else if(SunY < 0.3f && SunY > 0.1f){
        //dark Blue
        SkyRed = .14;
        SkyGreen = 0.06;
        SkyBlue = .6;

        WindowRed = 1.0f;
        WindowGreen = 1.0f;
        WindowBlue = 1.0f;
    }
    glutPostRedisplay();
	glutTimerFunc(1, updateSky, 0);
}

void updateCar(int v){

    CarX += 0.006f;
    Car2X -= 0.004f;
    BusX -= 0.003f;
    
    if(CarX > 1.3){
        CarX =  -1.3f;
    }
    if(Car2X < -2.3){
        Car2X = 0.3f;
    }
    if(BusX < -2.2){
        BusX = 0.0f;
    }
    
    glutPostRedisplay();
    glutTimerFunc(1,updateCar,0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1200, 800); 
    glutCreateWindow("My OpenGL Program");
    glutDisplayFunc(display); 
//timerfunc
    glutTimerFunc(1,updateBoat,0);
    glutTimerFunc(1,updateSun,0);
    glutTimerFunc(1,updateSky,0);
    glutTimerFunc(1,updateCar,0);
    glutTimerFunc(1,updateCloud,0);

    glutKeyboardFunc(handleKeypress);
    glutMainLoop(); 
    return 0;
}