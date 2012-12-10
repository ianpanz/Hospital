//
//  main.cpp
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#include "Hospital.h"
#include "RoomArray.h"
#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    Room r0(100);
    Room r1(101);
    Room r2(102);
    Room r3(103);
    Room r4(104);
    Room r5(105);
    Room r6(106);
    Room r7(107);
    Room r8(108);
    Room r9(109);
    //RoomArray<Room> rooms[10];
    Room rooms[10];
    
    rooms[0]= r0;
    rooms[1]= r1;
    rooms[2]= r2;
    rooms[3]= r3;
    rooms[4]= r4;
    rooms[5]= r5;
    rooms[6]= r6;
    rooms[7]= r7;
    rooms[8]= r8;
    rooms[9]= r9;
 
/*
    LinkedList<Room> roomList;
    roomList.push(r0);
    roomList.push(r1);
    roomList.push(r2);
    roomList.push(r3);
    roomList.push(r4);
    roomList.push(r5);
    roomList.push(r6);
    roomList.push(r7);
    roomList.push(r8);
    roomList.push(r9);*/
    Doctor phil(120);
    Hospital hospital(phil, rooms);
   
    /*
    for (int i = 0; i < 10; i++) {
        cout << rooms[i].getRoomNumber() << endl;
        cout << rooms[i].getPatient().getName() << endl;
        cout << phil.getLocation().roomNumber << endl;
    }*/
       
    hospital.play();
    return 0;
}
