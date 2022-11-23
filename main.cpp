#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>


int main()
{
    int gd = DETECT,gm,key_dir,foodX,foodY,snakeX[200],snakeY[200];   // DETECT = 0; gm = graph mode ; gd =graph diver
    initgraph(&gd,&gm,(char*)" ");

    //initialization

    int  delayTime = 200;
    int food = 0;        // snake food
    int body= 500;   // snake body
    int p_dir = 1;     //p_dir = previous direction;
    int length = 1;   // snake game;
    bool game = true;  // declaration a bool variable for the loop

    // snake array or creating snake;

    for(int i = 0; i < 200; i++)
    {
        snakeX[i] = 0;
        snakeY[i] = 0;
    }

    // initialization for dis[play snake ;

    snakeX[0] = 200,snakeY[0] = 200;
    foodX = 200, foodY = 200;
    key_dir = 1;


    // drawing game panel

    while(game)
    {
        setfillstyle(SOLID_FILL,WHITE); // initialization back ground color
        bar(0,0,630,470);  //  initializing background size or wide

        setfillstyle(SOLID_FILL,YELLOW);  // initializing boarder color

        bar(0,0,630,10); // upper boarder width,length

        bar(0,0,10,470); // right boarder width,length

        bar(0,470,630,460); // lower boarder width,length

        bar(620,10,630,470); // upper boarder width,length

        setfillstyle(SOLID_FILL,BLACK); // initialization food color

        if(snakeX[0] == foodX && snakeY[0] == foodY) // checking snake and food is in the same position or not
        {
            length = length + 1;
            food = food +1 ;
            delayTime = delayTime - 2;  // food consumed by snake then the delay time reduced and snake spread increase

            bar(foodX,foodY,foodX + 10 , foodY + 10 ); // food poosition

            do{
                foodX = (10 + rand() % 600);
                foodY = (10 + rand() % 450);
            }while(getpixel(foodX,foodY) != 0 && foodX > 10 && foodY>10); //condition for food visualization

            // condition for not overlaping food or snake

            foodX = foodX / 10;
            foodX = foodX * 10;
            foodY = foodY / 10;
            foodY = foodY * 10;

            // condition for food coordinate can't be 10, if so then the food will situated beside the boarder line every time

            if(foodX == 10){
                foodX = rand() % 10 + 5;
                foodX = food * 10;
            }
            else if(foodY == 10)
            {
                foodY = rand() % 10 + 5;
                foodY = foodY * 10;
            }

        }

        bar(foodX,foodY,foodX + 10, foodY + 10); // final  food position for display

        setfillstyle(SOLID_FILL,RED); // initialize snake color

        // condition for key direction

        if(GetAsyncKeyState(VK_RIGHT)){
            key_dir = 1;
        }
        else if(GetAsyncKeyState(VK_LEFT)){
            key_dir = 2;
        }
        else if(GetAsyncKeyState(VK_UP)){
            key_dir = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN)){
            key_dir = 4;
        }
        else {
                key_dir = 0;
        }

        // condition for moving snake according to key direction

        switch(key_dir)
        {
        case 0:
            if(p_dir == 1){
                snakeX[0] = snakeX[0] + 10;
            }
            else if(p_dir == 2){
                snakeX[0] = snakeX[0] - 10;
            }
            else if(p_dir == 3){
                snakeY[0] = snakeY[0] - 10;
            }
            else if(p_dir == 4){
                snakeY[0] = snakeY[0] + 10;
            }
            else{
                key_dir = 0;
            }
            break;

        case 1:
            snakeX[0] = snakeX[0] + 10;
            p_dir = 1;
            break;
        case 2:
            snakeX[0] = snakeX[0] - 10;
            p_dir = 2;
            break;
        case 3:
            snakeY[0] = snakeY[0] - 10;
            p_dir = 3;
            break;
        case 4:
            snakeY[0] = snakeY[0] + 10;
            p_dir = 4;
            break;

        }

       // displaying snake

       for(int i =0; i < length; i++)
       {
           bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
       }

       // body of snake

       for(int i = 199; i > 0; i--)
       {
           snakeX[i] = snakeX[i - 1];
           snakeY[i] = snakeY[i - 1];
       }

    // checking bumping into body

    for(int i = 2; i < length; i++)
    {
        if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            body = i;
            break;
        }
    }

    delay(delayTime);

    // checking bumping in to boundary;

    if(snakeX[0] >= 615 || snakeX[0] <=5 || snakeY[0] <= 5|| snakeY[0] >= 455){
        std::cout<<"Snake bumped into the wall !!\n\n";
        game = false;
    }

    // checking bumping into body

    if(snakeX[0] == snakeX[body] && snakeY[0] ==  snakeY[body] ){
        std::cout<<"Snake bumped into itself !!!\n\n";
        game = false;
    }

    } 
    
    // game result
    
    std::cout<<"Your score is : " <<(food-1)*10<<"\n\n";
    std::cout<<"Game Over !!!\n\n";
    getch();
    return 0;
}

// another code for snake game

/*

#include <conio.h>
#include <vector>
#include <graphics.h>
#include <dos.h>       // libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int lenght = 2;
int lenghtmax = 2; // controls snake's lenght

int x1 = 30;
int y1 = 170; // snake's location

char direc = '-';
char last = '-'; // direction

bool playing = true; // if you are alive

int fruitx;
int fruity;
bool eaten = false; // fruit position

vector<int> snakex;
vector<int> snakey; // where your tail needs to go

int i = 1;
int imax = 0; // some basic for() things

char score[50];
int score1; // your score

void fruit();
void graphic();
void move();
void start();
void update(); // all voids

int main()
{
	start();


	while (playing == true)
	{
		update();

		if (x1 >= 340 || x1 < 0 || y1 >= 340 || y1 < 10) // check if you are inside the map
		{
			playing = false; // you die :P
		}

		if (lenghtmax > 3 || direc != '-' && direc != 'w' && direc != 'a' && direc != 's' && direc != 'd' && direc != 'W' && direc != 'A' && direc != 'S' && direc != 'D')
		{
			for (lenght = lenghtmax; lenght >= 0; lenght--)
			{
				if (x1 == snakex[i] && y1 == snakey[i])
				{
					playing = false; // check if you head hits your tail
				}

				i--;
			}

			i = imax;
		}
	}

	if (playing == false)
	{
		cleardevice();
		outtextxy(70, 170, "YOU LOST, YOUR ");
		outtextxy(188, 170, score);
		getch();
		getch();
		return 0; // game over things
	}
}

void start() // execute at the start of the game
{
	sprintf(score, "SCORE : %d ", score1);

	srand(time(NULL));
	initwindow(350, 354, "SnakeGame");

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(0, 0, 340, 10);
	floodfill(5, 5, GREEN);

	setcolor(WHITE);
	outtextxy(10, 0, score);

	fruitx = rand() % 34;
	fruity = rand() % 34;
	fruity = fruity * 10;
	fruitx = fruitx * 10;

	if(fruity == 0){
		fruity = fruity+10;
	}


	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx, fruity, fruitx + 10, fruity + 10);
	floodfill(fruitx + 5, fruity + 5, RED);
}

void update() // execute every frame
{
	sprintf(score, "SCORE : %d ", score1);

	delay(150);

	snakex.push_back(x1);
	snakey.push_back(y1); // makes your tail know the way to your head

	fruit();

	move();

	graphic();

}

void move() // all move related things
{
	if (kbhit())
	{
		direc = getch();
	}

	if (direc == 'w' && last == 's' || direc == 'W' && last == 'S')
	{
		direc = last;
	}

	if (direc == 'a' && last == 'd' || direc == 'A' && last == 'D')
	{
		direc = last;
	}

	if (direc == 's' && last == 'w' || direc == 'S' && last == 'W')
	{
		direc = last;
	}

	if (direc == 'd' && last == 'a' || direc == 'D' && last == 'A')
	{
		direc = last;
	}

	last = direc;

	if (direc == 's' || direc == 'S')
	{
		y1 = y1 + 10;
	}

	if (direc == 'a' || direc == 'A')
	{
		x1 = x1 - 10;
	}

	if (direc == 'w' || direc == 'W')
	{
		y1 = y1 - 10;
	}

	if (direc == 'd' || direc == 'D')
	{
		x1 = x1 + 10;
	}
}

void graphic() // the graphic
{
	cleardevice();

	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	rectangle(0,0, 350, 10);			// green line
	floodfill(5, 5, GREEN);

	setcolor(WHITE);
	outtextxy(10, 0, score); // score

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(fruitx, fruity, fruitx + 10, fruity + 10); // fruit
	floodfill(fruitx + 5, fruity + 5, RED);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	rectangle(x1, y1, x1 + 10, y1 + 10); // head
	floodfill(x1 + 5, y1 + 5, WHITE);

	for (int lenght = lenghtmax; lenght > 0; lenght--)
	{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		rectangle(snakex[i], snakey[i], snakex[i] + 10, snakey[i] + 10); // tail
		floodfill(snakex[i] + 5, snakey[i] + 5, WHITE);
		i--;
	}

	imax++;
	i = imax;

}

void fruit() // fruit things
{
	if (x1 == fruitx && y1 == fruity)
	{
		eaten = true;

	}

	if (eaten == true)
	{
		eaten = false;
		lenghtmax++;
		score1++;
		lenght = lenghtmax;
		fruitx = rand() % 34;
		fruity = rand() % 34;
		fruity = fruity * 10;
		fruitx = fruitx * 10; // random location

		for (lenght = lenghtmax; lenght >= 0; lenght--)
		{
			if (fruitx == snakex[i] && fruity == snakey[i])
			{
				fruitx = rand() % 34;
				fruity = rand() % 34;
				fruity = fruity * 10;
				fruitx = fruitx * 10; // don't spawn the fruit on the snake
			}

			i--;
		}

		if (fruity == 0)
		{
			fruity = 10;
		}

		i = imax;

		setcolor(RED);
		setfillstyle(SOLID_FILL, RED);
		rectangle(fruitx, fruity, fruitx + 10, fruity + 10); // makes fruit
		//asdfloodfill(fruitx + 5, fruitx + 5, RED);
	}

}

*/

