//Definition of the player Class
#include "Ship.hpp"
#include "FieldElement.hpp"
#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>
class Player {
  private:
    double Score;
  public:
    Player();
    FieldElement field [8][8];
    void Placeships();
    bool Checkplaceable(Ship s);
    void Fire(unsigned int X, unsigned int Y);
    void RecieveFire(unsigned int X, unsigned int Y);
    double GetScore();
    void InitiateField();
    unsigned int shipsplaced;
    Ship ships [4];
};
#endif
