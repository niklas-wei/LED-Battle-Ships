#include <SPI.h>
#include <MFRC522.h>

#ifndef rfid_hpp
#define rfid_hpp
#include <stdio.h>
#define SS_PIN 10 // SDA an Pin 10 (bei MEGA anders)
#define RST_PIN 9 // RST an Pin 9 (bei MEGA anders)

//Rf IDs sind 1: 121254108213 und 2 : 217189057163

//TODO multiple constructors research
//TODO calling base constructor from second constructor in c++

class rfidAuthenticator {
  public:
    initializeRfid(){
      MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID-Empfänger benennen
      SPI.begin(); // SPI-Verbindung aufbauen
      mfrc522.PCD_Init();
    };
   bool authenticateID(int id); //


 private:

  //String player1_id = "";

  
   String player1_ID = "121254108213"; // int generiert OVERFLOW,daher string
   String player2_ID = "217189057163"; // int generiert OVERFLOW,daher string
   int history[20] ; //speichert die IDs als monitoring
};
#endif
