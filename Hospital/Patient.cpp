//
//  Patient.cpp
//  Hospital
//
//  Created by Ian Panzica on 11/29/12.
//

#include <iostream>
#include "Patient.h"

using namespace std;

Patient::Patient()
{
    setAge(rand() % 81 + 10);
    setName(genName());
    setHealth(50);
}

bool Patient::cured()
{
    return health >= 100;
}

bool Patient::died()
{
    return health <= 0;
}

bool Patient::treatable()
{
    return !died() && !cured();
}

void Patient::treat()
{
    if (treatable())
        setHealth(max(health + 10, 100));
}

void Patient::untreated()
{
    if (treatable())
        setHealth(min(health - 1, 0));
}

char Patient::consonant()
{
    int index= rand() % 17;
    char CONSONANTS[] = 
    {'b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','z', '\0'};
    return CONSONANTS[index];
}

char Patient::vowel()
{
    int index= rand() % 5;
    char VOWELS[] = 
    {'a','e','i','o','u', '\0'};
    return VOWELS[index];
}
//generate a random name
string Patient::genName()
{
    string s;
    s+= toupper(consonant());
    s+= vowel();
    s+= consonant();
    s+= vowel();
    if(rand() % 3 == 0)
        s+= consonant();
    if(rand() % 3 == 0)
    {
        s+= consonant();
        s+= vowel();
    }
    s+= (' ');
    s+= toupper(consonant());
    s+= vowel();
    if (rand() % 3 == 0) 
        s+=consonant();
    s+=consonant();
    s+=vowel();
    if (rand() % 3 == 0) 
        s+=consonant();
    if (rand() % 3 == 0) {
        s+=consonant();
        s+=vowel();
    }
    return s;
}

void Patient::setAge(int a)
{
    age= a;
}

void Patient::setHealth(int h)
{
    health= h;
}


void Patient::setName(string n)
{
    name= n;
}

int Patient::getAge()
{
    return age;
}

string Patient::getName()
{
    return name;
}
int Patient::getHealth()
{
    return health;
}

//overload ==
bool Patient::operator==(Patient &other)
{
    return (this->getAge() == other.getAge() && this->getName() == other.getName());
}

//overload =
void Patient::operator=(Patient &other)
{
    setAge(other.getAge());
    setName(other.getName());
}