//
//  Room.cpp
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#include "Room.h"
#include "Patient.h"

/* Room::Room(int n)
 {
     setRoomNumber(n);
     Patient patient();
 }*/

Room::Room()
: patient()
{
    counter++;
    setRoomNumber(counter);
}

Room::Room(int n)
: patient() , roomNumber(n)
{
   // setRoomNumber(n);
}
LinkedList<Room> Room::createRooms() {
    //create rooms up until ROOMS is reached
    LinkedList<Room> roomList;
    for(int i= 1; i < 11; i++){
        Room room(i+100);
        roomList.push(room);
    }
    return roomList;
    
}

void Room::setRoomNumber(int num)
{
    roomNumber= num;
}

int Room::getRoomNumber() 
{
    return this->roomNumber;
}
//Overload ==
bool Room::operator==(Room other)
{
    //compare each room's room number field
    return (getRoomNumber() == other.getRoomNumber()); //check for patient?
    
}

void Room::setPatient(Patient p)
{
    patient= p;
}

Patient Room::getPatient()
{
    return patient;
}
//Overload !=
bool Room::operator!=(Room other){
    return !(*this == other);
}

void Room::operator=(Room other){
    this->setPatient(other.getPatient());
    this->setRoomNumber(other.getRoomNumber());
}
