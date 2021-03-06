
#include "Person.h"
#include "Organization.h"
#include "University.h"
using namespace std;


Person::Person(std::string n, int a) {
    name = n;
    age = a;
    size = 0;
    dim = 5;
    organizations = new Organization *  [dim];
};


Person::Person(const Person& registered) {
    size = 0;
    name = registered.name;
    age = registered.age;
    dim = registered.dim;
    organizations = new Organization *  [dim];

    for (int i = 0; i < size; i++) {
        organizations[i] = registered.organizations[i];
    }
}


float Person::getTotalTuition() {
    float total = 0;
    for (int i = 0; i < size; i++) {
        Organization* ptr = organizations[i];
       University* op = dynamic_cast<University*>(ptr);

        if (op != nullptr) {
            total += op->getTuition();
        }
    }
    return total;
}


std::string Person::printSchools() {
    string name = "";

    for (int i = 0; i < size; i++) {

        Organization* ptr = organizations[i];
        University* op = dynamic_cast<University*>(ptr);
        if (op != nullptr) {
            name = name + op->getName() + ": " + to_string(op->getTuition()) + "; ";

        }
    }
    return name;
}


std::string Person::getOrgNames() {
    std::string name = "";
    for (int i = 0; i < size; i++)
    {
        name = name + (*organizations[i]).getName() + ", ";
    }
    return name;
}

 void Person::addOrganization(Organization* organization) {
    if (size == dim) {
        throw std::out_of_range(getName() + " has already 5 organization");
    }
    else {
        organizations[size++] = organization;
    }
}

void Person::removeOrganization(Organization* organization){
    bool find = false;
    for(int i =0 ; i<=5; i++){
        if (organizations[i] == organization){
            find = true;
        }
    }
    if (find){
        organizations[size--] = organization;
    }else{
        throw std::out_of_range(getName() + " is not in this organization");
    }


}