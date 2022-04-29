
#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.h"
using namespace std;


class Organization {

protected:
    std::string name; // name of the org
    Person* members; // list of members
    int size;  // actual size of the org
    int dim;  // max size of the org


public:

    Organization(std::string n = "default") : name(n), size(0), dim(20)
    {
        members = nullptr;
    };


    Organization(const Organization& organization) : 
        name(organization.name), size(organization.size), dim(organization.dim)
    {
        members = new Person[dim];
        for (int i = 0; i < size; i++) {

            members[i] = organization.members[i];
        }

    }

    virtual ~Organization()
    {
        delete[] members;
    }

    // return the name of all members enrolled in the organization
    // all members written in one string separated by semi-colons
    // returns empty string if no member is enrolled in the organization
    std::string getMemberNames()
    {
        std::string name = "";
        for (int i = 0; i < size; i++)
        {
            name = name + members[i].getName() + ":" + std::to_string(members[i].getAge()) + "; ";
        }
        return name;
    }
    virtual int paytuition() { cout << "no tuition for organization class"; return 0; }
    // adds a Person to the members array of the organization
    // Should double the members array size if array is full
    void addPerson(Person* person)
    {
        if(members == NULL)members = new Person[dim];
        if (size >= dim)
        {
            Person* tmp = new Person[dim * 2];
            for (int i = 0; i < size; i++)
            {
                tmp[i] = members[i];
            }
            delete[] members;
            members = tmp;
            dim *= 2;
        }

        members[size++] = *person;
    }

    void removePerson(Person* person){
        bool find = false;
        for (int i = 0; i< size; i++){
            if (members[i].getName() == person->getName()){
                find = true;
            }
        }
        if (find){
            members[size--] = *person;
            size--;
        }else{
            throw std::out_of_range(getName() + " does not have this person");
        }
    }



    string getName() {
        return name;
    }

    //add getters or setters if necessary 
};

#endif
