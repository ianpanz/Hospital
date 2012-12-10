//
//  Doctor.cpp
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//  Copyright (c) 2012 Cornell University . All rights reserved.
//
#include "Doctor.h"
#include "Room.h"

Doctor::Doctor(){}

Doctor::Doctor(int med) 
{
    
    //setLocation(room);
    setMedicine(med);
}



//decrease the amount of medicine left by one dose
void Doctor::useMedicine() {
    if (medicineLeft()) medicine -= 1;
}

//check if enough medicine left for one dose
bool Doctor::medicineLeft() {
    return medicine >= 1;
}

void Doctor::setMedicine(int m) {
    medicine= m;
}

void Doctor::setLocation(Room r){
    location= r;
}

Room Doctor::getLocation(){
    return location;
}

int Doctor::getMedicine(){
    return medicine;
}