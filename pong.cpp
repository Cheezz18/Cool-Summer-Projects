#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall
{
    private:
        int x, y;
        int originalX, originalY;
        eDir directions;

    public:
        // default constructor of the ball. Will default to being in the center (original position) and be at rest.
        cBall(int posX, int posY){
            originalX = posX;
            originalY = posY;
            x = posX, y = posY;
            directions = STOP;
        }

        // This resets the ball to the center position and will stop the ball 
        void reset(){
            x = originalX, y = originalY;
            directions = STOP;
        }

        // Changes direction by changing the value of the directions field
        void changeDirection(eDir d){
            directions = d;
        }

        // does the same thing as changDirection but since directions can also be represented by numbers, random can be used to change to a random direction
        void randomDirection(){
            directions = (eDir) ((rand() % 6) + 1);
        }

        // From here, we have our getters
        int getX(){ return x; }

        int getY(){ return y; }

        eDir getDirection(){ return directions; }

        // This is the move function. I could use if statements but a switch statement is better suited in this instance
        void move(){
            switch (directions){
                case STOP:
                    break;
                case LEFT:
                    --x;
                    break;
                case UPLEFT:
                    --x; ++y;
                    break;
                case DOWNLEFT:
                    --x; --y;
                    break;
                case RIGHT:
                    ++x;
                    break;
                case UPRIGHT:
                    ++x; ++y;
                    break;
                case DOWNRIGHT:
                    ++x; --y;
                    break;
                default:
                    break;
            }
        }

        // This will allow the programmer to output the object itself in main
        friend ostream & operator<<(ostream & o, cBall c){
            o << "Ball [" << c.x << "," << c.y << "][" << c.directions << "]";
            return o;
        }

};

class cPaddle{

    private:
        int x, y;
        int originalX, originalY;

    public:
        cPaddle(){
            x = y = 0; 
        }

        cPaddle(int posX, int posY) : cPaddle() {
            originalX = posX;
            originalY = posY;
            x = posX;
            y = posY;
        }

        void Reset() { x = originalX;  y = originalY; }

        int getX(){ return x; }
        int getY(){ return y; }

        void moveUp(){ y++;}
        void moveDown(){ y--;}

        friend ostream & operator<<(ostream & o, cPaddle c){
            o << "Paddle [" << c.x << "," << c.y << "]";
            return o;
        }

};

class cGameManager{

    private:
        int width, height;
        int p1Points, p2Points;
        char p1Up, p1Down, p2Up, p2Down;
        bool quit;
        cBall * ball;
        cPaddle * player1;
        cPaddle * player2;

    public:
        cGameManager(int w, int h){
            srand(time(NULL));
            quit = false;
            p1Up = 'w'; p1Down = 's';
            p2Up = 'i'; p2Down = 'k'; 
            p1Points = p2Points = 0;
            width = w; height = h;
            ball = new cBall(w / 2, h / 2);
            player1 = new cPaddle(1, h/2 - 3);
            player2 = new cPaddle(w - 2 , h/2 - 3);
        }

        ~cGameManager(){
            delete ball;
            delete player1;
            delete player2;
        }

        void ScoreUp(cPaddle * player){
            if (player == player1){
                p1Points++;
            }
            else if (player == player2){
                p2Points++;
            }

            ball->reset();
            player1->Reset();
            player2->Reset();
        }
};

int main(){

    return 0;
}
