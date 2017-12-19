#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
uint32_t Points = 0;

enum class GameState { MainMenu, Game , Dead, InitGame};
GameState gameState = GameState::MainMenu;


#include "Bitmaps.h"
#include "Map.h"
#include "Player.h"
PlayerClass playerobj;
#include "Sprite.h"
SpriteClass Objects[MAXOBJECT];
#include "Game.h"






void setup() {
  ard.begin();
  ard.clear();
  ard.initRandomSeed();
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
