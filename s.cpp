#include<bits/stdc++.h>
#include<conio.h>
#include <Windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y , foodX ,foodY,score;
int tailX[100] ,tailY[100];
int nTail;   //length of the tail

enum eDirection {stop = 0,LEFT,RIGHT,up,down};
eDirection dir;
void setUp()
{
        gameOver = false;
        dir = stop;
        x= width/2;
        y=height/2;
        foodX = rand()%width;
        foodY = rand()%height;
        score = 0;

}
void draw()
{
        system("cls");
        for(int i=0;i<width;i++)
        {
                cout<<"*";
        }
        cout<<endl;
        for(int i=0;i<height;i++)
        {
                for(int j=0;j<width;j++)
                {
                    if(j==0 || j==width -1)
                    cout<<"*";
                    else
                    {
                            if(i==y && j==x)
                            {
                                    cout<<"O";
                            }
                            else if(i==foodY && j==foodX)
                            cout<<"+";
                            else
                            {
                                bool print = false;
                                for(int k=0;k<nTail;k++)
                                {
                                    if(tailX[k]==j && tailY[k] == i)
                                    {
                                        cout<<"O";
                                        print = true;
                                    }

                                }
                                if(!print)
                                cout<<" ";
                            }
                    }

                }
            cout<<endl;
        }
    for(int i=0;i<width;i++)
        {
                cout<<"*";
        }
        cout<<endl;
        cout<<"score: "<<score<<endl;;
}
void input()
{
        if(_kbhit())
        {

                switch(_getch())
                {
                        case 'a':
                                dir=LEFT;
                           break;
                        case 's':
                                dir=down;
                           break;
                        case 'w':
                                dir=up;
                           break;
                        case 'd':
                                dir=RIGHT;
                           break;
                        case 'x':
                                gameOver=true;
                            break;

                }
        }
}

void logic()
{
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0]=x;
        tailY[0]=y;
        for(int i=1;i<nTail;i++)
            {
                prev2X = tailX[i];
                prev2Y = tailY[i];
                tailX[i] = prevX;
                tailY[i] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }

                switch(dir)
                {
                        // case stop:
                        //         dir=left;
                        //    break;
                        case LEFT:
                                x--;
                           break;
                        case RIGHT:
                                x++;
                           break;
                        case up:
                               y--;
                           break;
                        case down:
                                y++;
                            break;
                }
//                if(x > width-1 || x < 0 ||y > height-1|| y < 0)
//                {
//                                gameOver = true;
//                }
                for(int i=0;i<nTail;i++)
                {

                    if(tailX[i]==x && tailY[i]==y)
                        gameOver=true;
                }
                if(x == foodX && y == foodY)
                {

                        score += 10;
                        foodX = rand()%width;
                        foodY = rand()%height;
                        nTail++;
                }


}
int main(){
    setUp();
    while(!gameOver)
    {
            draw();
            input();
            logic();
            Sleep(100);

    }
    return 0;
}
