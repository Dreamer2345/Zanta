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
  0 ,0 ,0 ,0 ,1 ,1 ,2 ,2 ,2 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,3 ,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,0 ,0 ,0 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,4 ,4 ,4 ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,2 ,2 ,2 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,3 ,3 ,
  0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,3 ,3 ,3 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,4 ,0 ,0 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,3 ,3 ,3 ,3 ,
  3 ,0 ,0 ,4 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,
  3 ,3 ,3 ,3 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,
};


int GetTileX(int x)
{
  if(x < 0)
      return (x / TILE_SIZE) - 1;
    else
      return (x / TILE_SIZE);
}

int GetTileY(int y)
{
  if(y < 0)
      return (y / TILE_SIZE) - 1;
    else
      return (y / TILE_SIZE);
}

int GetTileXOffset(int x)
{
  if(x < 0)
      return (TILE_SIZE + (x % TILE_SIZE));
    else
      return (x % TILE_SIZE);
}

int GetTileYOffset(int y)
{
  if(y < 0)
      return (TILE_SIZE + (y % TILE_SIZE));
    else
      return (y % TILE_SIZE);
}

uint8_t GetBlock(int x, int y) {
  if ((x < 0) || (y < 0) || (x >= MAP_WIDTH) || (y >= MAP_HEIGHT)) {
    return 0;
  }
  uint8_t Block =  pgm_read_byte(&Map[(x + (y * MAP_WIDTH))]);

  return Block;
}

bool Walkable(int x, int y) {
  uint8_t p[4];
  bool Walk = true; 
  p[0] = (GetBlock(GetTileX(x-8), GetTileY(y-16)));
  p[1] = (GetBlock(GetTileX(x+7), GetTileY(y-16)));
  p[2] = (GetBlock(GetTileX(x-8), GetTileY(y+15)));
  p[3] = (GetBlock(GetTileX(x+7), GetTileY(y+16)));
  for (byte i=0; i<4;i++){
    if (!(p[i] == 0)){
        Walk = false;
        break;
      }
  }
  return Walk;
}





