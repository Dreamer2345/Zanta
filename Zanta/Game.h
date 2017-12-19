bool showarrow = false;


void InitGameState(){
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
  ard.print(playerobj.x);
  ard.print(":");
  ard.println(playerobj.y);
  
  ard.print(GetTileX(playerobj.x));
  ard.print(":");
  ard.println(GetTileY(playerobj.y));

  ard.println(GetTileX(playerobj.x)+(GetTileY(playerobj.y)*MAP_WIDTH));
}

void Death(){
}

