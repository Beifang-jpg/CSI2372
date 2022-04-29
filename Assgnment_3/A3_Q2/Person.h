
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Organization;

/**
Class Person:  Create  Person, used to add organizations to a person
Private variable: name, age and others to define


Add all missing methods
*/
class Person{
    int dim;
    string name;
    int age;
    int size = 0;
//    Organization** organizations[5] = {};
    vector <Organization> organizations;
public:
    // copy from the Q1
    int getAge();
//    {
//        return age;
//    }
    string getName();
//    {
//        return name;
//    }
    Person(basic_string<char> basicString, int i);
//    {
//        age = i;
//        name = basicString;

//    }
    Person();
//    {
//        age = -1;
//        name = "Default";
//        int size = 0;
//        Organization** organizations[5] = {};
//        int dim = 0;
//    };


    //Q2 part
    Person(string s);
//    {
//        name = s;
//        age = -1;
//        int size = 0;
//        Organization** organizations[5] = {};
//        int dim = 0;
//    }


    int getSize();
//    {
//        return size;
//    }


    void addOrganization(Organization organization);
//    {
//        if (size <= 5){
//            organizations[size] = &organization;
//        }
//    }

//    void addOrganization(Organization ***organization);
//    {
//        if (size <= 5){
//            organizations[size] = &organization;
//        }
//    }

//    void registering(Organization* o, Person* p) {
//        o->addPerson(p);
//        p->addOrganization(o);
//    }

    string getOrgNames();
//    {
//        string S = "";
//        for (int i=0; i<size ; i++){
//            cout << organizations[i] << endl;
//        }
//        return S ;
//    }

    float getTotalTuition();
//    {
//        float fee = 0;
//        for (int i=0; i<size ; i++){
//            if (organizations[i].isSchool == true){
//                fee = fee + organizations[i].getTuition;
//            }
//        }
//        return fee;
//
//    }
    string printSchools();
//    {
//        string S = "";
//        for (int i=0; i<size ; i++){
//            if (organizations[i].isSchool == true){
//                S = S +" , "+ organizations[i].getName;
//            }
//        }
//        return S;
//    }

};



#endif