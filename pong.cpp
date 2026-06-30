#include <iostream>
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

        void changeDirection(eDir d){
            directions = d;
        }

        void randomDirection(){
            directions = (eDir) ((rand() % 6) + 1);
        }

        // From here, we have our getters
        int getX(){ return x; }

        int getY(){ return y; }

        eDir getDirection(){ return directions; }

};

int main(){


    return 0;
}
