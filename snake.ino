/*
 * Code by: Nehad younis
 * 10/10/2022
 * 
 */



#include <VGAX.h>
#define IMG_PIRATE_BWIDTH 30
#define IMG_PIRATE_HEIGHT 60
//data size=900 bytes
int counter = 1800;

VGAX vga;

char dir = 'r';
byte food_x;
byte food_y;
bool isDead = false;
byte score = 0;
bool pause = false;

struct point {
  byte x,y;
};
  
class Snake {
public:
    byte front, rear, size;
    const byte capacity = 75;
    point array[75]; //(x,y)
    
    void createEmptySnake()
    {
      front = size = 0;
      rear = capacity - 1;
    }


     void enqueue(byte x , byte y)
     {
      if (isFull())
          return;
       
      rear = (rear + 1)% capacity;
      array[rear].x = x;
      array[rear].y = y;
      size ++;
      vga.putpixel(x,y,1);
      
      if(vga.getpixel(array[rear].x, array[rear].y) == 1) isDead = true;
      
    }
    
    void dequeue()
    {
      vga.putpixel(array[front].x,array[front].y,0);
      front = (front + 1) % capacity;
      size--;
    }
    
    int isFull()
    {
      return (size == capacity);
    }



    
    void startTwoPoints(){
      enqueue(20, 20);
      grow('r');
      createFoodPoint();
      
    }
    void createFoodPoint(){
      food_x = random(0,100);
      food_y = random(0,50);
      vga.putpixel(food_x,food_y,3);
    }
    void grow(char dir){
      switch (dir){
        case 'r':
        enqueue(array[rear].x > 100?0: array[rear].x + 1,array[rear].y);
        break;
        
        case 'l':
        enqueue(array[rear].x < 1?100: array[rear].x - 1 ,array[rear].y);
        break;
        
        case 'u':
        enqueue(array[rear].x,array[rear].y < 1?50: array[rear].y - 1);
        break;
        
        case 'd':
        enqueue(array[rear].x,array[rear].y > 50?0: array[rear].y + 1);
        break;
        
        }
      
    }
    void advance(char dir){
      grow(dir);
        
      if (array[rear].x == food_x && array[rear].y == food_y){ // is food
      score++;
      vga.putpixel(food_x,food_y,1);
      createFoodPoint();
      } else {
      vga.putpixel(array[front].x,array[front].y,0);
      dequeue();
      }
    }

    void drawSnake(){
        byte current = rear;
        while (current-- != front)
          vga.putpixel(array[current].x,array[current].y,1);
      }
};



class Numbers{
  public:
  void one(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x,y+1,2);
    vga.putpixel(x,y+2,2);
    vga.putpixel(x,y+3,2);
    vga.putpixel(x,y+4,2);
}
 void two(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    vga.putpixel(x+2,y+1,2);
    vga.putpixel(x+2,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x,y+2,2);
    vga.putpixel(x,y+3,2);
    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    }
  void three(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    vga.putpixel(x+2,y+1,2);
    vga.putpixel(x+2,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x+2,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x,y+4,2);
    
    }

   void four(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x,y+1,2);
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x+2,y,2);
    vga.putpixel(x+2,y+1,2);
    vga.putpixel(x+2,y+2,2);
    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x+2,y+4,2);
    
    }
    void five(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    
    vga.putpixel(x,y+1,2);
    
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x+2,y+2,2);

    vga.putpixel(x+2,y+3,2);

    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    
    }

    void six(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    
    vga.putpixel(x,y+1,2);
    
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x+2,y+2,2);

    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x,y+3,2);

    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    
    }

    void seven(byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x,y+1,2);
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    vga.putpixel(x+2,y+1,2);
    vga.putpixel(x+2,y+2,2);
    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x+2,y+4,2);
    
    }

    void eight (byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    
    vga.putpixel(x,y+1,2);
    vga.putpixel(x+2,y+1,2);
    
    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x+2,y+2,2);

    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x,y+3,2);

    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    
    }
    void nine (byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    
    vga.putpixel(x+2,y+1,2);
    vga.putpixel(x,y+1,2);

    vga.putpixel(x,y+2,2);
    vga.putpixel(x+1,y+2,2);
    vga.putpixel(x+2,y+2,2);

    vga.putpixel(x+2,y+3,2);

    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    
    }
    void zero (byte x, byte y){
    vga.putpixel(x,y,2);
    vga.putpixel(x+1,y,2);
    vga.putpixel(x+2,y,2);
    
    vga.putpixel(x,y+1,2);
    vga.putpixel(x+2,y+1,2);

    vga.putpixel(x,y+2,2);
    vga.putpixel(x+2,y+2,2);


    vga.putpixel(x+2,y+3,2);
    vga.putpixel(x,y+3,2);

    vga.putpixel(x,y+4,2);
    vga.putpixel(x+1,y+4,2);
    vga.putpixel(x+2,y+4,2);
    
    }
    void clearScoreArea(byte x, byte y){
    vga.putpixel(x,y,0);
    vga.putpixel(x+1,y,0);
    vga.putpixel(x+2,y,0);
    vga.putpixel(x,y+1,0);
    vga.putpixel(x+2,y+1,0);
    
    vga.putpixel(x,y+2,0);
    vga.putpixel(x+1,y+2,0);
    vga.putpixel(x+2,y+2,0);

    vga.putpixel(x+2,y+3,0);
    vga.putpixel(x,y+3,0);

    vga.putpixel(x,y+4,0);
    vga.putpixel(x+1,y+4,0);
    vga.putpixel(x+2,y+4,0);
    }

    void drawScore(byte x, byte y, byte score){
      byte s1 = score/10;
      byte s2 = score%10;
      clearScoreArea(x,y);
      clearScoreArea(x+5,y);
      
      if (s1 == 0) zero(x,y);
      if (s1 == 1) one(x,y);
      if (s1 == 2) two(x,y);
      if (s1 == 3) three(x,y);
      if (s1 == 4) four(x,y);
      if (s1 == 5) five(x,y);
      if (s1 == 6) six(x,y);
      if (s1 == 7) seven(x,y);
      if (s1 == 8) eight(x,y);
      if (s1 == 9) nine(x,y);

      if (s2 == 0) zero(x+5,y);
      if (s2 == 1) one(x+5,y);
      if (s2 == 2) two(x+5,y);
      if (s2 == 3) three(x+5,y);
      if (s2 == 4) four(x+5,y);
      if (s2 == 5) five(x+5,y);
      if (s2 == 6) six(x+5,y);
      if (s2 == 7) seven(x+5,y);
      if (s2 == 8) eight(x+5,y);
      if (s2 == 9) nine(x+5,y);
    }
  
  
  };
 




Snake snake;
Numbers numbers;


void setup() {
  vga.begin();
   pinMode(A0,INPUT);
   pinMode(A1,INPUT);
   pinMode(A2,INPUT);
   pinMode(A3,INPUT);
  snake.createEmptySnake();
  snake.startTwoPoints();
}





void loop(){
  while(snake.isFull() || isDead);
  if (digitalRead(A0) && dir != 'u') dir = 'd';
  if (digitalRead(A1) && dir != 'd') dir = 'u';
  if (digitalRead(A2) && dir != 'l') dir = 'r';
  if (digitalRead(A3) && dir != 'r') dir = 'l';
  if (digitalRead(A4)) pause = !pause; //TODO: DEBOUNCEING
  
  if (!pause){
  snake.advance(dir);
  }
  vga.delay(100 - score);
  numbers.drawScore(110,4, score);


}
