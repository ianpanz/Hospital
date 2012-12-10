//
//  Hospital.cpp
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//
#include <iostream>
#include <string>
#include <iomanip>
#include "Hospital.h"
#include "Patient.h"
#include "Doctor.h"
#include "Room.h"

using namespace std;

//constructor for hospital 
Hospital::Hospital(Doctor d, Room rList[]) 
{
    for(int i= 0; i < 10; i++)
    {
        roomList[i]= rList[i];
    }
    //roomList= Room::createRooms();
    //firstRoom= roomList.head()->value;
    //Doctor doctor(firstRoom, 120);
    //d.setMedicine(120);
    doctor= d;
}

/*//the play method for hospital to be called in main
void Hospital::play()
{
    char input;
    cout << endl;      
    cout << "*******************************************" << endl;      
    cout << "* Welcome to Krzmrgystan General Hospital *" << endl;      
    cout << "*******************************************" << endl;      
    cout << endl;      
    cout << "Type 'h' for instructions, 's' to start:" << endl;      
    //getline(cin, input); 
    //for(int i= 0; i < input.length() && !done(); i ++){
        //char c= input.at(i);
        //check the character input with each case
    cin >> input;    
    switch(input) {
			case 'h': 
				displayHelp();
				break;
			case 's': 
				displayStatus();
				break;
            case 'q': 
				quit();
				//if the character does not match any of the above cases
			default: 
				cout << "Unknown command: " << input << endl; 		
				break;
        }
   // }
    if(done())
        quit();
    while(!done()){
        //getline(cin, input); 
        char c;
        cin >> c;
       // displayStatus();
        //processCommand(c);
        //cin >> c;
        switch(c) {
			case 't': 
				treat();
				break;
			case 'p': 
				move('p');
				break;
			case 'n':
                move('n');
				break;
			case 'h': 
				displayHelp();   
				break;
			case 'q': 
				quit();
				//if the character does not match any of the above cases
			default: 
				cout << "Unknown command: " << c << endl; 		
				break;
        }
        cout << "n=next, p=prev, t=treat, h=help, q=quit? ";
        cin >> input;
        processCommand(c);
        displayStatus();
    }
    //displayStatus();
    cout << "Medicine remaining: " << doctor.getMedicine() << endl;
    cout << "Patients cured: " << cured() << endl;
}*/


void Hospital::play() {
    
          
    cout << "*******************************************" << endl;      
    cout << "* Welcome to Krzmrgystan General Hospital *" << endl;      
    cout << "*******************************************" << endl;      
    cout << "" << endl;     
    cout << "Type 'h' for instructions" << endl;      
    
    while(!done()){
        displayStatus();
        cout << "n=next, p=prev, t=treat, h=help, q=quit? " << endl;
        char input;
        cin >> input;
        processCommand(input);
    }
    displayStatus();
    cout << "Medicine remaining: " + doctor.getMedicine() << endl;
    cout << "Patients cured: " + cured() << endl;
}





int Hospital::findIndex(Room rList[], Room room){
    for(int i=0; i < 10; i++){
        if(rList[i] == room)
            return i;
    }
    return -1;
}

void Hospital::processCommand(char c){    //string cmd) {
   // for(int i= 0; i < cmd.length() && !done(); i ++){
       // char c= cmd.at(i);
        //check the character input with each case
        switch(c) {
			case 't': 
				treat();
				break;
			case 'p': 
				move('p');
				break;
			case 'n':
                move('n');
				break;
			case 'h': 
				displayHelp();   
				break;
			case 'q': 
				quit();
				//if the character does not match any of the above cases
			default: 
				cout << "Unknown command: " << c << endl; 		
				break;
        }
    }
//}
void Hospital::quit() {
    cout << "Goodbye!" << endl;
    exit(0);
}

void Hospital::treat() {
    //check for remaining medicine
    if(!doctor.medicineLeft()) return;
    doctor.getLocation().getPatient().treat();
    doctor.useMedicine();
    //account for the declining health of all the other patients
    Room room= doctor.getLocation();
    int index= findIndex(roomList, room);
    int i= index + 1;
    while (i != index){
        Room r= roomList[i];
        r.getPatient().untreated();
        if(i < 9)
            i++;
        else i=0;
    }
}

//Move in the direction of char c and account for patient status
void Hospital::move(char c) {
    Room room= doctor.getLocation();
    int i= findIndex(roomList, room);
    //check into the setting of previous room pointers 
    doctor.getLocation()= (c != 'n' ? roomList[i-1] : roomList[i+1]);
    
    //account for the patient's deteriorating health
    do {
        room.getPatient().untreated();
        int index= findIndex(roomList, room);
        room= roomList[index+1];
    }
    while(room != doctor.getLocation());
}




//count the number of cured patients
int Hospital::cured() {
    Room room = doctor.getLocation();
    int n = 0;
    do {
        if (room.getPatient().cured()) n++;
        int index= findIndex(roomList, room);
        room= roomList[index+1];
    } while(room != doctor.getLocation());
    return n;
}

bool Hospital::done() {
    if(!doctor.medicineLeft()) return true;
    Room room= doctor.getLocation();
    do {
        if(room.getPatient().treatable()) return false;
        int index= findIndex(roomList, room);
        room= roomList[index+1];
    }while(room != doctor.getLocation());
    return true;
    
}

void Hospital::displayStatus() {
    cout << "Room   " << "Patient      "<< "Age   "<< "Health   "<< endl;
    Room room = firstRoom;
    int index= 0;
    //do something other than do while 
    do {
        cout << left << setw( 6 ) << room.getRoomNumber() << room.getPatient().getName() << "    " << setw( 8 ) << room.getPatient().getAge() << fixed << right << room.getPatient().getHealth() << endl;
        index= findIndex(roomList, room);
        room= roomList[index + 1];
    } while (room != firstRoom);
    cout << "The doctor is in room " << doctor.getLocation().getRoomNumber() << " with " << doctor.getMedicine() << " units of medicine" << endl;
}


void Hospital::displayHelp() {
    cout << "-------------------------------------------------------------"<< endl;
    cout << "Krzmrgystan General Hospital Help"<< endl;
    cout << "There are 10 rooms arranged in a ring, each with 1 patient."  << endl;
    cout << "Enter a command at the prompt.  The commands are:"<< endl;
    cout << "  n  move to the next (higher-numbered) room"<< endl;
    cout << "  p  move to the previous (lower-numbered) room"<< endl;
    cout << "  t  treat the patient in this room"<< endl;
    cout << "  h  display this help screen"<< endl;
    cout << "  q  quit";
    cout << "You can enter a sequence of commands on the same line,"<< endl;
    cout << "  like this: ttttn"<< endl;
    cout << "Treating a patient uses one unit of medicine, after which the"<< endl;
    cout << "  treated patient's health improves by 10" << endl;
    cout << "Treating a patient or moving takes one unit of time, during"<< endl;
    cout << "  which all untreated patients' health deteriorates by 1" << endl;
    cout << "A patient is cured when his/her health reaches 100"<< endl;
    cout << "A patient dies when his/her health reaches 0"<< endl;
    cout << "How many patients can you save?" << endl;
    cout << "-------------------------------------------------------------"<< endl;
}
