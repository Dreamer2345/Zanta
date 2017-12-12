#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
#include "Bitmaps.h"
#include "Game.h"

enum class GameState { MainMenu, Game , Dead, InitGame};
GameState gameState = GameState::MainMenu;





void setup() {
  ard.begin();
  ard.clear();
}



void loop() {
  if(!ard.nextFrame())
    return;

  ard.pollButtons();
  ard.clear();
  
  switch(gameState)
  {
    case GameState::MainMenu: UpdateMainMenu(); break;
    case GameState::InitGame: InitGameState(); break;
    case GameState::Game: UpdateGame(); break;
    case GameState::Dead: Death(); break;
  }

  ard.display();
}
