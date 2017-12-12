bool showarrow = false;


void InitGameState(){
}

void UpdateMainMenu(){
  sprites.drawSelfMasked(0,0,Logo,0);
  if (showarrow){sprites.drawOverwrite(20,55,Arrow,0);}
  if (ard.justPressed(A_BUTTON)){
    //gameState = GameState::InitGame;
  }
  if (ard.everyXFrames(30)) {
      showarrow = !showarrow;
      }
}

void UpdateGame(){  
}

void Death(){
}

