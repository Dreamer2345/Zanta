#define TILE_SIZE 16
#define CENTERX 63
#define CENTERY 31
#define MAP_WIDTH 24
#define MAP_HEIGHT 17

const uint8_t PROGMEM Map[] = {
  0 ,0 ,0 ,0 ,0 ,3 ,3 ,3 ,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,0 ,3 ,4 ,4 ,4 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,1 ,2 ,2 ,2 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,3 ,3 ,3 ,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,3 ,4 ,4 ,4 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2 ,2 ,2 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,3 ,3 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,3 ,3 ,3 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,5 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,5 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,3 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,
  3 ,3 ,3 ,3 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,
};

const uint8_t PROGMEM Spawn[] = {
    7,2,
    2,14, 
    23,11,
    14,7,
};



int GetTileX(uint16_t x)
{
    return (x / TILE_SIZE);
}

int GetTileY(uint16_t y)
{
    return (y / TILE_SIZE);
}

int GetTileXOffset(uint16_t x)
{
      return (x % TILE_SIZE);
}

int GetTileYOffset(uint16_t y)
{
      return (y % TILE_SIZE);
}

uint8_t GetBlock(uint16_t x, uint16_t y) {
  uint8_t Block = 0;
  if ((x < 0) || (y < 0) || (x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
    Block = 0;
  }
  else
  {
    uint16_t Index = (x + (y * MAP_WIDTH));
    Block =  pgm_read_byte(&Map[Index]);
  }
  return Block;
}

uint8_t GetBlockTrans(uint16_t x, uint16_t y) {
  uint8_t Block = 0;
  if ((x < 0) || (y < 0) || (x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
    Block = 0;
  }
  else
  {
    uint8_t p[4];
    uint8_t Block = GetBlock(x,y);
    p[0] = GetBlock(x+1,y);
    p[1] = GetBlock(x-1,y);
    p[2] = GetBlock(x,y+1);
    p[3] = GetBlock(x,y-1);
    
    if (Block == 1){
 
        if((p[0]==1)&&(p[1]==1)&&(p[2]==1)&&(p[3]==1)){
            Block = 0;
        }
        
        if((p[0]==1)&&(p[1]==1)){
            Block = 7;
        }
        if((p[2]==1)&&(p[3]==1)){
            Block = 6;
        }
        
        if((p[0]==1)&&(p[1]==0)&&(p[2]==0)&&(p[3]==1)){
            Block = 10;
        }
        if((p[0]==1)&&(p[1]==0)&&(p[2]==1)&&(p[3]==0)){
            Block = 11;
        }
        if((p[0]==0)&&(p[1]==1)&&(p[2]==0)&&(p[3]==1)){
            Block = 9;
        }
        if((p[0]==0)&&(p[1]==1)&&(p[2]==1)&&(p[3]==0)){
            Block = 8;
        }
        return Block;
    } 
    if (Block == 2){
                
        if((p[0]==2)||(p[1]==2)||(p[0]==1)||(p[1]==1)){
            Block = 13;
        }
        if((p[2]==2)||(p[3]==2)||(p[2]==1)||(p[3]==1)){
            Block = 12;
        }
        return Block;
    }
    if (Block == 5){
        if(p[2] == 5){
            Block = 14;
        }
        if(p[3] == 5){
            Block = 15;
        }
        return Block;
    }
  }
  return Block;
}



bool Walkable(int x, int y) {  
  uint8_t p[4];
  bool Walk = true; 
  return Walk;
  p[0] = (GetBlock(GetTileX(x-8), GetTileY(y-16)));
  p[1] = (GetBlock(GetTileX(x+7), GetTileY(y-16)));
  p[2] = (GetBlock(GetTileX(x-8), GetTileY(y+15)));
  p[3] = (GetBlock(GetTileX(x+7), GetTileY(y+16)));
  for (byte i=0; i<4;i++){
    if (!((p[i] == 0)||(p[i] ==5))){
        Walk = false;
        break;
      }
  }
  return Walk;
}





