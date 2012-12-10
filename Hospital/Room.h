//
//  Room.h
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#ifndef Hospital_Room_h
#define Hospital_Room_h
#include "Patient.h"
#include "LinkedList.h"
class Room
{
public:
    Room();
    Room(int);
    static LinkedList<Room> createRooms();
    void setRoomNumber( int );
    int getRoomNumber();
    Patient getPatient();
    int roomNumber;
    void setPatient(Patient);
    bool operator==(Room other); //overload ==
    bool operator!=(Room other); //overload !=
    void operator=(Room other); //overload =
private:
    Patient patient;
    //int roomNumber;
    int counter;
};


#endif
