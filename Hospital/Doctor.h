//
//  Doctor.h
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//  Copyright (c) 2012 Cornell University . All rights reserved.
//

#ifndef Hospital_Doctor_h
#define Hospital_Doctor_h
#include "Room.h"
class Doctor
{
public:
    Doctor();
    Doctor(int);
    void useMedicine();
    bool medicineLeft();
    void setMedicine(int);
    void setLocation(Room);
    int getMedicine();
    Room getLocation();
    
private:
    Room location;
    int medicine;
};
#endif
