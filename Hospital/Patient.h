//
//  Patient.h
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#ifndef Hospital_Patient_h
#define Hospital_Patient_h
#include <string>

class Patient
{
public:
    Patient();
    bool cured();
    bool died();
    bool treatable();
    void treat();
    void untreated();
    char consonant();
    char vowel();
    std::string genName();
    
    void setName( std::string );
    void setAge( int );
    void setHealth(int);
    
    int getAge();
    int getHealth();
    std::string getName();
    
    
    bool operator==(Patient &other);
    void operator=(Patient &other);

private:
    int age;
    int health;
    std::string name;
    
      
};
#endif
