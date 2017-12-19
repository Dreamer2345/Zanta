#pragma once

class SpriteClass{
  public:
    SpriteClass() { };

    void setSprite(int _x,int _y,byte _H,byte _type,byte _offset,bool _Active){x = _x;y = _y;H = _H;type = _type;Frame = 0;offset=_offset;Active = _Active;};
    void SpriteAI();
    void Display();
    void Damage();
    byte GetFrame(){return Frame;}
    byte GetType(){return type;}
    bool IsActive(){return Active;}
    void SetActive(bool _k){Active = _k;}
    byte GetX(){return x;}
    byte GetY(){return y;}
  private:
    byte offset;
    int x;
    int y;
    short int H;
    byte type;
    byte Frame;
    bool Active;
  };


void SpriteClass::Damage(){
  H -= 10;
  if (H <= 0){Active = false;}  
  }
  
void SpriteClass::SpriteAI(){
  switch(type){
    case 1: 
            if ((x < relx)&&(Walkable(x+1,y))) {x++;}
            if ((x > relx)&&(Walkable(x-1,y))) {x--;}
            if ((y < rely)&&(Walkable(x,y+1))) {y++;}
            if ((y > rely)&&(Walkable(x,y-1))) {y--;}
            if (ard.everyXFrames(24)) { ++Frame; Frame %= 2; } 
            break;
    case 2:
        switch(Frame){
            
        }
  }
}


void SpriteClass::Display(){
  int _x = (playerobj.x-x);
  int _y = (playerobj.y-y);
  sprites.drawExternalMask((CENTERX-8)-_x,(CENTERY-8)-_y,Items,ItemsMask,(Frame+offset),(Frame+offset));
}
