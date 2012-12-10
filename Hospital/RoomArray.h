//
//  RoomArray.h
//  Hospital
//
//  Created by Ian Panzica on 12/10/12.
//

#ifndef Hospital_RoomArray_h
#define Hospital_RoomArray_h

template <typename T>
class RoomArray
{
    class ArrayException
    {
        
    };

    
public:
    //defualt constructor initializes array with no length or data
    RoomArray()
    {
        length = 0;
        data = 0;
    }
    //constructor takes int for length
    RoomArray(int n)
    {
        data= new T[n];
        length = n;
    }
    
    ~RoomArray()
    {
        delete[] data;
    }
    //check the index to make sure it isn't bad
    T& operator[](int index)
    {
        //index is bad if it exceeds or equals length or if it is less than 0
        if (index < 0 || index >= length){
            throw ArrayException();
        }
        return data[index];
    }
    
    // The length of the array is always an integer
    // It does not depend on the data type of the array
    //int getLength(); // templated getLength() function defined below-returns length of array
    int length; //array length
private:
    
    T *data; //data in array
    
};
//define the getLength() function

#endif


