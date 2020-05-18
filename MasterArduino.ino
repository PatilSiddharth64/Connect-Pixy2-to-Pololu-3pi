#include <Pixy2.h>
#include <SPI.h>

Pixy2 pixy;
//int Pixy_OnOff = 0;
int signature = 0;
int xblocks = 0;
int yblocks = 0;
unsigned int width = 0;
unsigned int height = 0;
unsigned int area = 0;
unsigned int newarea = 0;
int Xmin = 70;  //left
int Xmax = 200; //right
int maxArea = 0;
int minArea = 0;
static int isignature = 0;


void Pixy_scan()
{
  uint16_t blocks;
  blocks = pixy.ccc.getBlocks();
  signature = pixy.ccc.blocks[isignature].m_signature;
  xblocks = pixy.ccc.blocks[isignature].m_x;
  width = pixy.ccc.blocks[isignature].m_width;
  height = pixy.ccc.blocks[isignature].m_height;
}

void setup() {
   // Initialize serial communications at 9600 bps:
  Serial.begin(19200);


  // Initialize Pixy2
  pixy.init();

}

void loop() {
    Pixy_scan();
    area = width * height;
    maxArea = area + 1000;
    minArea = area - 1000;

  // Pixy Auto Demo
  
    if (signature == 1)
    {
      newarea = width * height;

      if (xblocks < Xmin)
      {
        Serial.write('4');
        Serial.print("TurnLeft\n");
      }
      else if (xblocks > Xmax)
      {
        Serial.write('3');
        Serial.print("TurnRight\n");
      }
      else if (newarea < minArea)
      {
        Serial.write('1');
        Serial.print("MoveForward\n");
      }
      else if (newarea > maxArea)
      {
        Serial.write('2');
        Serial.print("MoveBackward\n");
      }

      else
      {
        Serial.write('5');
        Serial.print("Stay\n");
      }
      delay(5);
    }
    else
    {
      Serial.write('5');
      Serial.print("Stay\n");
    }
  }
