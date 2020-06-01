#include "Ship.hpp"
#include "FieldElement.hpp"
#include "Player.hpp"
#include "Pointer.hpp"

//At the beginning all the the functions will be declared according to the given class
//Valid States for the game-fields:
int Water = 0;
int Boat = 1;
int HitShip = 2;
int SunkenShip = 3;
int MissedMissle = 4;

//Definition of the possible Pointer_Orientations
unsigned int horizontal = 0;
unsigned int vertical = 1;

// Our two players- later they'll be able to contain the login data of a player

Player PlayerOne;
Player PlayerTwo;
unsigned int Currentplayer; 

//Dislpays which Koordinates the Curser is currently on and in case a ship is to be placed, it also stores the current orientation
Pointer::Pointer() {
  X = 0;
  Y = 0;
  Orientation = horizontal;
}

Pointer pointer= Pointer();

// The ship initiates with negative lives, sofield without actual ships don't interfere with the game itself
Ship::Ship() {
  lives = -1;
}

FieldElement::FieldElement() {
  Status = Water;
  Ship ship;

}

Player::Player() {
  Score = 0;
  InitiateField();
  shipsplaced = 0;
  ships[0] = Ship();
  ships[0].lives = 2;
  ships[1] = Ship();
  ships[1].lives = 3;
  ships[2] = Ship();
  ships[2].lives = 3;
  ships[3] = Ship();
  ships[3].lives = 4;

}
bool Player::Checkplaceable(Ship s) {
  //To be implemented
  for (int i = 0; i <= s.lives; i++) {
    if (pointer.Orientation == horizontal) {
      if ((field[pointer.Y][pointer.X + i]).Status != Water)
    {
      return false;
    }
  }
  if (pointer.Orientation == vertical) {
      if ((field[pointer.Y + i][pointer.X]).Status != Water)
      {
        return false;
      }
    }
  }
  return true;

}
void Player::Placeships() {
  //To be implemented
  if (Checkplaceable(ships[shipsplaced]))
{
  for (int i = 0; i <= ships[shipsplaced].lives; i++) {
      if (pointer.Orientation == horizontal) {
        (field[pointer.Y][pointer.X + i]).ship = ships[shipsplaced];
         (field[pointer.Y][pointer.X + i]).Status = Boat;
      }
      if (pointer.Orientation == vertical) {
        (field[pointer.Y + i][pointer.X]).ship = ships[shipsplaced];
         (field[pointer.Y + i][pointer.X ]).Status = Boat;
      }
    }
  }

  shipsplaced++;
}
//function that will be triggered by a player to shoot at the opponents field
void Player::Fire(unsigned int X, unsigned int Y) {
  if (Currentplayer == 1){
    PlayerTwo.RecieveFire(X,Y);
  }
  if (Currentplayer == 2){
    PlayerOne.RecieveFire(X,Y);
  }
}
// Checks if the given field has benn fired on- if not it changes its Status
void Player::RecieveFire(unsigned int X, unsigned int Y) {

  if ((field[Y][X]).Status == Water) {
    (field[Y][X]).Status = MissedMissle;
  }
  else if ((field[Y][X]).Status == Boat) {
    if ((field[Y][X]).ship.lives > 0) {
      (field[Y][X]).Status = HitShip;
    }
  }


}

void Player::InitiateField() {
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++) {
      field[a][b] = FieldElement();
    }
  }
}
double Player::GetScore() {
  return Score;
}


void updateboards() {
  Serial.println();
  for (int i = 0; i < 8; i++) {
    Serial.println();
    for (int u = 0; u < 8; u++) {
      if ((PlayerOne.field[i][u].ship.lives) == 0) {
        (PlayerOne.field[i][u]).Status = SunkenShip;
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    Serial.println();
    for (int u = 0; u < 8; u++) {
      if ((PlayerTwo.field[i][u].ship.lives) == 0) {
        (PlayerTwo.field[i][u]).Status = SunkenShip;
      }
    }
  }
  Serial.println("Player 1:");
  for (int i = 0; i < 8; i++) {
    Serial.println();
    for (int u = 0; u < 8; u++) {
      Serial.print((PlayerOne.field[i][u]).Status);
    }
  }
  Serial.println();
  Serial.println("Player 2:");
  for (int i = 0; i < 8; i++) {
    Serial.println();
    for (int u = 0; u < 8; u++) {
      Serial.print((PlayerTwo.field[i][u]).Status);
    }
  }
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Currentplayer= 1; 
}

void loop() {
  // put your main code here, to run repeatedly:
  updateboards();
  delay(5000);
}
