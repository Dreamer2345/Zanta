
class PlayerClass {
  public:
  unsigned x;
  unsigned y;
  byte d;
  char H;
  bool Moving;
  uint8_t Frame;
  void PlayerMovement();
};

void PlayerClass::PlayerMovement() {
  Moving = false;
  if (ard.pressed(UP_BUTTON)){
    if (Walkable(x,y-1)){
      y-=1;
      Moving = true;
    }
    d = 0;
    }
  if (ard.pressed(DOWN_BUTTON)){
    if (Walkable(x,y+1)){
      y+=1;
      Moving = true;
    }
    d = 1;
    }
  if (ard.pressed(RIGHT_BUTTON)){
    if (Walkable(x+1,y)){
      x+=1;
      Moving = true;
    }
    d = 2;
    }
  if (ard.pressed(LEFT_BUTTON)){
    if (Walkable(x-1,y)){
      x-=1;
      Moving = true;
    }
    d = 3;
    }      
}
