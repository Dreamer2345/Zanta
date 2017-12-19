bool showarrow = false;

bool Intersect(unsigned Min0, unsigned Max0, unsigned Min1, unsigned Max1){return ((Max0 > Min1) && (Min0 < Max1));}

bool Collision(unsigned x, unsigned y, unsigned x1, unsigned y1) {return (Intersect(x-8,x+8,x1-8,x1+8)&&Intersect(y-8,y+8,y1-8,y1+8));}

uint8_t Objects = 0;



void InitGameState(){
    playerobj.x = 16*8;
    playerobj.y = 16*9; 
    playerobj.H = 100;
    playerobj.Bullets = 50;
}

void DisplayPlayer(){	
	const uint8_t PlayerFrames[] = { 5, 3, 5, 4 };
  if(!playerobj.Moving)
  {
    sprites.drawExternalMask(CENTERX - 8, CENTERY - 8, Items,ItemsMask,5,5);
  }
  else
  {
    if(ard.everyXFrames(5))
    {
      ++playerobj.Frame;
      playerobj.Frame %= 4;
    }
    sprites.drawExternalMask(CENTERX - 8, CENTERY - 8, Items,ItemsMask,PlayerFrames[playerobj.Frame],PlayerFrames[playerobj.Frame]);
  }
}

void UpdateMainMenu(){
  sprites.drawSelfMasked(0,0,Logo,0);
  if (showarrow){sprites.drawOverwrite(20,55,Arrow,0);}
  if (ard.justPressed(A_BUTTON)){
    gameState = GameState::Game;
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}

void DisplayEnviroment()
{
  int tileX = GetTileX(playerobj.x);
  int tileY = GetTileY(playerobj.y);
  int offsetX = GetTileXOffset(playerobj.x);
  int offsetY = GetTileYOffset(playerobj.y);
    
  for (int i = -5; i < 5; i++)
  {
    for(int j = -3; j < 3; j++)
    {
      uint8_t block = GetBlockTrans(tileX + i, tileY + j);
      int drawX = (i * 16) + CENTERX - offsetX;
      int drawY = (j * 16) + CENTERY - offsetY;
      sprites.drawSelfMasked(drawX, drawY, Enviroment, block);
    }
  }
}

void UpdateGame(){ 
  DisplayEnviroment();
  playerobj.PlayerMovement();
  DisplayPlayer();
  ard.print(playerobj.x);
  ard.print(":");
  ard.println(playerobj.y);
}

void Death(){
}

