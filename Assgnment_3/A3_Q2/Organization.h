
#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.h"


using namespace std;
// define your classes here



class Organization {

protected:
    std::string name; // name of the org
    Person* members; // list of members
    int size;  // actual size of the org
    int dim;  // max size of the org
    float tuition;

public:
    // copy from the Q1

    void setTuition(float i){
        tuition = i;
    }
    float getTuition(){
        return tuition;
    }

    int getSize(){
        return size;
    }

    string getMemberNames(int i){
        string S = members[i].getName();
        return S;
    }
    void start(){
        members = new Person[dim];
    }


    void addPerson(Person person){
        int old = dim;
        if (size == 0){
            start();
        }

        if (size == dim){
            dim = dim *2;
            Person* members2 = new Person[dim];

            for(int i=0; i<old; i++ ){
                members2[i] = members[i];
            }
            members = members2;
        }
        members [size] = person;
        size ++;
    }
    Organization(string n){
    name = n;
    }

    Organization() {

    }

    bool isSchool(){
        return false;
    }
    string getName(){
        return name;
    }






};

#endif
