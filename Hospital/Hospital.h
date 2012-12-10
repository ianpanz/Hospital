//
//  Hospital.h
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#ifndef Hospital_Hospital_h
#define Hospital_Hospital_h
#include "Room.h"
#include "Doctor.h"
class Hospital
{
public:
    Hospital(Doctor, Room[]);
    void play();
    bool done();
    void displayStatus();
    void displayHelp();
    int cured();
    void move( char );
    void quit();
    void treat();
    //void processCommand( std::string );
    void processCommand( char );
   // int findIndex(LinkedList<Room>, Room);
    int findIndex(Room[], Room);
    //LinkedList<Room> roomList;
    Room roomList[10];
   
    Doctor doctor;
    Room firstRoom;
};


#endif
