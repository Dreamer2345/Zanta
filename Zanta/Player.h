
class PlayerClass {
  public:
  unsigned x = 16*8;
  unsigned y = 16*9; 
  byte d;
  char H;
  char Bullets;
  bool Moving;
  uint8_t Frame;
  void PlayerMovement();
};

void PlayerClass::PlayerMovement() {
  Moving = false;
  if (ard.pressed(UP_BUTTON)){
    if (Walkable(x,y-2)){
      y-=2;
      Moving = true;
    }
    d = 0;
    }
  if (ard.pressed(DOWN_BUTTON)){
    if (Walkable(x,y+2)){
      y+=2;
      Moving = true;
    }
    d = 1;
    }
  if (ard.pressed(RIGHT_BUTTON)){
    if (Walkable(x+2,y)){
      x+=2;
      Moving = true;
    }
    d = 2;
    }
  if (ard.pressed(LEFT_BUTTON)){
    if (Walkable(x-2,y)){
      x-=2;
      Moving = true;
    }
    d = 3;
    }      
}
