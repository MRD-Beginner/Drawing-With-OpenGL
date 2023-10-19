#include <GL/glut.h>

float housePositionX = 0.0;
float housePositionY = 0.0; // Posisi vertikal awal rumah
float houseScale = 1.0; // Skala awal rumah
float rotationAngle = 0.0; // Sudut rotasi awal
bool isReflected = false; // Menyimpan status refleksi

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix(); // Push matriks sekarang ke stack
    
    // Translasi, rotasi, dan skala objek rumah
    glTranslatef(housePositionX, housePositionY, 0.0);
    if (isReflected) {
        glScalef(-houseScale, houseScale, 1.0); // Refleksi terhadap sumbu y
    } else {
        glScalef(houseScale, houseScale, 1.0);
    }
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);
    
    // Menggambar atap
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.2, 0.0); // Mengatur warna merah
    
    glVertex2f(-0.6, 0.0);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.6, 0.0);
    
    glEnd();
    
    // Menggambar dinding
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.6, 0.2); // Mengatur warna cokelat
    
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.6, -0.6);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.6, 0.0);
    
    glEnd();
    
    // Menggambar pintu
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0); // Mengatur warna cokelat tua
    
    glVertex2f(-0.1, -0.6);
    glVertex2f(-0.1, -0.4);
    glVertex2f(0.1, -0.4);
    glVertex2f(0.1, -0.6);
    
    glEnd();
    
    // Menggambar jendela kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.8, 1.0); // Mengatur warna biru muda
    
    glVertex2f(-0.4, -0.3);
    glVertex2f(-0.4, -0.1);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.2, -0.3);
    
    glEnd();
    
    // Menggambar jendela kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.8, 0.0); // Mengatur warna biru muda
    
    glVertex2f(0.2, -0.3);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.4, -0.1);
    glVertex2f(0.4, -0.3);
    
    glEnd();
    
    glPopMatrix(); // Pop matriks sebelumnya dari stack
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 's' || key == 'S')
    {
        housePositionY -= 0.1;
    }
    else if (key == 'w' || key == 'W')
    {
        housePositionY += 0.1;
    }
    else if (key == 'a' || key == 'A')
    {
        housePositionX -= 0.1;
    }
    else if (key == 'd' || key == 'D')
    {
        housePositionX += 0.1;
    }
    else if (key == 'q' || key == 'Q')
    {
        rotationAngle += 45.0;
    }
    else if (key == 'e' || key == 'E')
    {
        rotationAngle -= 45.0;
    }
    else if (key == 'n' || key == 'N')
    {
        houseScale -= 0.1;
    }
    else if (key == 'm' || key == 'M')
    {
        houseScale += 0.1;
    }
    else if (key == 'b' || key == 'B')
    {
        isReflected = !isReflected;
    }
    else if (key == 'v' || key == 'V')
    {
        isReflected = !isReflected;
        housePositionY = -housePositionY; // Memindahkan posisi vertikal ke sisi sebaliknya
        houseScale = -houseScale; // Membalik skala secara vertikal
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Rumah");
    glClearColor(1.0, 1.0, 1.0, 1.0); // Mengatur warna latar belakang (putih)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Mengatur sistem koordinat
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Menambahkan fungsi keyboard
    glutMainLoop();
    
    return 0;
}
