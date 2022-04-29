#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


// define your classes here
class Person{
    string name = "Default";
    int age = -1;

public:
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    Person(basic_string<char> basicString, int i){
        age = i;
        name = basicString;

    }
    Person(){
        age = -1;
        name = "Default";
    };

};

class Organization{
    string name;
    int size =0;
    Person* members;
    int dim = 100;

public:

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
};


// prints all members of an organization to std::cout
void printMembers( Organization organization)
{
    int x = organization.getSize();

    for (int i = 0; i<x ; i++ ){
        cout<< organization.getMemberNames(i) <<endl;
    }


}


int main()
{
    Person p; //create a Person instance
    Organization org; //create an Organization instance

    org.addPerson(p); // add p to org
    cout<< "org includes: "<<endl;
    printMembers(org);

    //here we will add 250 persons to org
    for (int i =0 ; i<250; i++)
    {
        Person person("Person"+std::to_string(i), rand()% 30 +16); // create  a Person instance with the name "Person+i" and a random age
        org.addPerson(person);

    }
    cout<<endl<< "organization includes: "<<endl;
    printMembers(org);

    Organization org1 = org;
    cout<<endl<< "org1 includes: "<<endl;
    printMembers(org1);

    return 0;
}

