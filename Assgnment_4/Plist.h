#include <array>
using namespace std;

template <class T>
class Plist{
private:
    int capacity;
    int size = 0;
    int current = -1;
    T* myArray;

    T get(){
        return myArray[current];
    }
    void start(){
        current = 0;
    }
    void next(){
        current++;
    }
    bool isLast(){
        if(current == size -1){
            return true;
        }else{
            return false;
        }
    }
    int getCurrent(){
        return current;
    }

public:

    void add(T item){
        if(isFull()){
            throw out_of_range("It is full");
        }
        start();
        while(!isLast()){
            next();
        }
        myArray[getCurrent()] = item;
        size++;

    }
    void remove(T item){
        start();
        T temp;
        temp = myArray[getCurrent()];
        while (temp != item){
            next();
        }
        if (temp = item){
            for (int i = getCurrent(); i < size-1 ; i++){
                myArray[i] = myArray[i + 1];
            }
        }else{
            cout << " Can't find this item" << endl;
        }

    }
    int getSize(){
        return size;
    }
    bool isFull(){
        int S;
        S = sizeof(myArray) / sizeof(myArray[0]);
        if (S == size){
            return true;
        }else{
            return false;
        }
    }
    int getCapacity(){
        return capacity;
    }



};

#ifndef A4_MAIN_CPP_PLIST_H
#define A4_MAIN_CPP_PLIST_H

#endif //A4_MAIN_CPP_PLIST_H
