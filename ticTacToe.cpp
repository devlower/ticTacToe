#include <GL/freeglut.h>
#include <math.h>

#define PI 3.14

int a = 1; //'a' verifica qual jogador: se impar jogador 'X', se par jogador 'O'
int quadrante = 0; //guarda as coordenadas da tela
int mx, my; //mx = coluna e my = linha
int i, j; //percorrer a matriz
char vencedor = 0; //identifica o vencedor
char matriz[3][3] = {         //indica a posição da jogada de cada player
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}
                    };

void desenha(void); //função de desenho

void DesenhaTextoStroke(void *font, char *string)
{
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}

void mouse (int button, int state, int mousex, int mousey)
{
    if ( (button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN) )
    {
        mx = mousex;
        my = 720 - mousey;

//_______ Definição da área de interação com o usuário _______

        if (mx > 690 && mx < 790 && my > 210 && my < 310)
            quadrante = 9;

        if(mx > 690 && mx < 790 && my > 310 && my < 410)
            quadrante = 6;

        if (mx > 690 && mx < 790 && my > 410 && my < 510)
            quadrante = 3;

        if (mx > 590 && mx < 690 && my > 210 && my < 310)
            quadrante = 8;

        if (mx > 590 && mx < 690 && my > 310 && my < 410)
            quadrante = 5;

        if (mx > 590 && mx < 690 && my > 410 && my < 510)
            quadrante = 2;

        if (mx > 490 && mx < 590 && my > 210 && my < 310)
            quadrante = 7;

        if (mx > 490 && mx < 590 && my > 310 && my < 410)
            quadrante = 4;

        if (mx > 490 && mx < 590 && my > 410 && my < 510)
            quadrante = 1;

        if(mx > 615 && mx < 655 && my > 100 && my < 120)
            quadrante = 10;

        if(mx > 530 && mx < 745 && my > 150 && my < 173)
            quadrante = 11;

        if(quadrante == 11) //condição de jogar novamente
        {
            if(vencedor == 'o' || vencedor == 'x' || a > 9)
            {
                glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
                for (i = 0; i < 3; i++)
                {
                    for(j = 0; j < 3; j++)
                    {
                        matriz[i][j] = 0;
                    }
                }
                a = 1;
                vencedor = 0;
            }
        }

        if(quadrante == 10) //condição de saída
        {
            if(vencedor == 'o' || vencedor == 'x' || a > 9)
                exit(0);
        }
    }
}

void texto (void)
{
	desenha();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720);

//____________________________ Identificação ____________________________

    glColor3f(1,1,1); //define cor do texto (BRANCO)
	glPushMatrix();
	glTranslatef(25,25,0); //define a posição do texto na tela
	glScalef(0.17, 0.17, 0.17); // diminui o tamanho da fonte
	glLineWidth(2); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Autora : Tuanne Assenco");

//________________________ Mensagem para vencedor ________________________

	if (vencedor == 'x')
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(840,450,0); //define a posição do texto na tela
        glScalef(0.3, 0.3, 0.3); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' X ' venceu!");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(530,150,0); //define a posição do texto na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Jogar novamente");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1, 0.85, 0.71);
        glPushMatrix();
        glTranslatef(615,100,0); //define a posição do texto na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Sair");
    }

    if (vencedor == 'o')
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(840,450,0); //define a posição do texto na tela
        glScalef(0.3, 0.3, 0.3); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' O ' venceu!");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(530,150,0); //define a posição do texto na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Jogar novamente");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1, 0.85, 0.71);
        glPushMatrix();
        glTranslatef(615,100,0); //define a posição do texto na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Sair");
    }

//____________________ Mensagem para identificar player _____________________

    if (a%2 != 0)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(0.44, 0.50, 0.56);
        glPushMatrix();
        glTranslatef(560,590,0); //define a posição do texto na tela
        glScalef(0.25, 0.25, 0.25); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' O '");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(560,590,0); // define a posição do texto na tela
        glScalef(0.25, 0.25, 0.25); // diminui o tamanho do fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' X '");
    }

    if (a%2 == 0)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(0.44, 0.50, 0.56);
        glPushMatrix();
        glTranslatef(560,590,0); // define a posição do texto na tela
        glScalef(0.25, 0.25, 0.25); // diminui o tamanho do fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' X '");

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 1280, 0, 720);
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(560,590,0); //define a posição do texto na tela
        glScalef(0.25, 0.25, 0.25); // diminui o tamanho da fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Player ' O '");

    }

//___________________________ Mensagem para empate ____________________________

    if (vencedor != 'x' && vencedor != 'o' && a > 9)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0, 1280, 0, 720);
            glColor3f(1,1,1);
            glPushMatrix();
            glTranslatef(840,450,0); //define a posição do texto na tela
            glScalef(0.3, 0.3, 0.3); // diminui o tamanho da fonte
            glLineWidth(2); // define a espessura da linha
            DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Ixe... Deu velha!");

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0, 1280, 0, 720);
            glColor3f(1,1,1);
            glPushMatrix();
            glTranslatef(530,150,0); //define a posição do texto na tela
            glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
            glLineWidth(2); // define a espessura da linha
            DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Jogar novamente");

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0, 1280, 0, 720);
            glColor3f(1, 0.85, 0.71);
            glPushMatrix();
            glTranslatef(615,100,0); //define a posição do texto na tela
            glScalef(0.2, 0.2, 0.2); // diminui o tamanho da fonte
            glLineWidth(2); // define a espessura da linha
            DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Sair");
        }
	glFlush();
}

void desenha(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1280, 0, 720);

//___________ Tabuleiro ___________

    glLineWidth(3);
    glColor3f(1, 0.85, 0.71);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin (GL_LINES);
    //barras eixo x
    //eixo x 1
    glVertex2f(790, 310);
    glVertex2f(490, 310);
    //eixo x 2
    glVertex2f(790, 410);
    glVertex2f(490, 410);
    //barras eixo y
    //eixo y 1
    glVertex2f(590, 210);
    glVertex2f(590, 510);
    //eixo y 2
    glVertex2f(690, 210);
    glVertex2f(690, 510);


//___________ Registro de jogadas ___________

    if (quadrante == 9 && vencedor == 0)
    {
        if (matriz[2][2] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 9 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(710, 290);
                glVertex2f(770, 230);

                glVertex2f(770, 290);
                glVertex2f(710, 230);

                matriz[2][2] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 9 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5;
                glLineWidth(2.0);

                x = 740;
                y = 260;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioX*10)+y);
                }
                matriz[2][2] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 6 && vencedor == 0)
    {
        if (matriz[2][1] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 6 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(710, 390);
                glVertex2f(770, 330);

                glVertex2f(770, 390);
                glVertex2f(710, 330);

                matriz[2][1] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 6 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 740;
                y = 360;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[2][1] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 3 && vencedor == 0)
    {
        if (matriz[2][0] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 3 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(710, 490);
                glVertex2f(770, 430);

                glVertex2f(770, 490);
                glVertex2f(710, 430);

                matriz[2][0] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 3 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 740;
                y = 460;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[2][0] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 8 && vencedor == 0)
    {
        if (matriz[1][2] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 8 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(610, 290);
                glVertex2f(670, 230);

                glVertex2f(670, 290);
                glVertex2f(610, 230);

                matriz[1][2] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 8 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 640;
                y = 260;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[1][2] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 5 && vencedor == 0)
    {
        if (matriz[1][1] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 5 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(610, 390);
                glVertex2f(670, 330);

                glVertex2f(670, 390);
                glVertex2f(610, 330);

                matriz[1][1] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 5 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 640;
                y = 360;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[1][1] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 2 && vencedor == 0)
    {
        if (matriz[1][0] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 2 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(610, 490);
                glVertex2f(670, 430);

                glVertex2f(670, 490);
                glVertex2f(610, 430);

                matriz[1][0] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 2 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 640;
                y = 460;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[1][0] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 7 && vencedor == 0)
    {
        if (matriz[0][2] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 7 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(510, 290);
                glVertex2f(570, 230);

                glVertex2f(570, 290);
                glVertex2f(510, 230);

                matriz[0][2] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 7 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 540;
                y = 260;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[0][2] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 4 && vencedor == 0)
    {
        if (matriz[0][1] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 4 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(510, 390);
                glVertex2f(570, 330);

                glVertex2f(570, 390);
                glVertex2f(510, 330);

                matriz[0][1] = 'x';
            }

            if(a%2 == 0 && vencedor == 0)
            {
                //quadrante 4 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 540;
                y = 360;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[0][1] = 'o';
            }
            a++;
        }
    }

    if (quadrante == 1 && vencedor == 0)
    {
        if (matriz[0][0] == 0)
        {
            if(a%2 != 0)
            {
                //quadrante 1 para 'X'
                glLineWidth(2);
                glColor3f(0.66, 0.66, 0.66);

                glBegin(GL_LINES);

                glVertex2f(510, 490);
                glVertex2f(570, 430);

                glVertex2f(570, 490);
                glVertex2f(510, 430);

                matriz[0][0] = 'x';
            }

            if(a%2 == 0)
            {
                //quadrante 1 para 'O'
                int x, y;
                glColor3f(1, 1, 1);
                GLfloat circle_points = 100;
                GLfloat angle;
                float raioX=3.5, raioY=3.5;
                glLineWidth(2.0);

                x = 540;
                y = 460;

                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < circle_points; i++)
                {
                    angle = 2*PI*i/circle_points;
                    glVertex2i((cos(angle)*raioX*10)+x, (sin(angle)*raioY*10)+y);
                }

                matriz[0][0] = 'o';
            }
            a++;
        }
    }

//___________________________ Condições para ganhar ___________________________

    if (matriz[2][0] == 'x' && matriz[2][1] == 'x' && matriz[2][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(740, 220);
        glVertex2f(740, 500);
    }

    if (matriz[1][0] == 'x' && matriz[1][1] == 'x' && matriz[1][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(640, 220);
        glVertex2f(640, 500);
    }

    if (matriz[0][0] == 'x' && matriz[0][1] == 'x' && matriz[0][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(540, 220);
        glVertex2f(540, 500);
    }

    if (matriz[0][0] == 'x' && matriz[1][0] == 'x' && matriz[2][0] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(500, 460);
        glVertex2f(780, 460);
    }

    if (matriz[0][1] == 'x' && matriz[1][1] == 'x' && matriz[2][1] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(500, 360);
        glVertex2f(780, 360);
    }

     if (matriz[0][2] == 'x' && matriz[1][2] == 'x' && matriz[2][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(500, 260);
        glVertex2f(780, 260);
    }

     if (matriz[0][0] == 'x' && matriz[1][1] == 'x' && matriz[2][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(500, 500);
        glVertex2f(780, 220);
    }

    if (matriz[2][0] == 'x' && matriz[1][1] == 'x' && matriz[0][2] == 'x')
    {
        vencedor = 'x';

        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex2f(500, 220);
        glVertex2f(780, 500);
    }

    if (matriz[2][0] == 'o' && matriz[2][1] == 'o' && matriz[2][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(740, 215);
        glVertex2f(740, 505);
    }

    if (matriz[1][0] == 'o' && matriz[1][1] == 'o' && matriz[1][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(640, 215);
        glVertex2f(640, 505);
    }

    if (matriz[0][0] == 'o' && matriz[0][1] == 'o' && matriz[0][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(540, 215);
        glVertex2f(540, 505);
    }

    if (matriz[0][0] == 'o' && matriz[1][0] == 'o' && matriz[2][0] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(495, 460);
        glVertex2f(785, 460);
    }

    if (matriz[0][1] == 'o' && matriz[1][1] == 'o' && matriz[2][1] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(495, 360);
        glVertex2f(785, 360);
    }

     if (matriz[0][2] == 'o' && matriz[1][2] == 'o' && matriz[2][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(495, 260);
        glVertex2f(785, 260);
    }

     if (matriz[0][0] == 'o' && matriz[1][1] == 'o' && matriz[2][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(500, 500);
        glVertex2f(780, 220);
    }

    if (matriz[2][0] == 'o' && matriz[1][1] == 'o' && matriz[0][2] == 'o')
    {
        vencedor = 'o';

        glLineWidth(10);
        glColor3f(0.66, 0.66, 0.66);
        glBegin(GL_LINES);
        glVertex2f(500, 220);
        glVertex2f(780, 500);
    }

    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1280,720);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Jogo da Velha");
    glutMouseFunc(mouse);
    //glutDisplayFunc(desenha);
    glutDisplayFunc(texto);
    glClearColor(0.44, 0.50, 0.56,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();
    return EXIT_SUCCESS;
}
