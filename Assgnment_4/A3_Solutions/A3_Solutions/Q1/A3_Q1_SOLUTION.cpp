#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


class Person {

    std::string name;   // person’s name
    int age;            // person’s age


public:

    Person(std::string n = "default", int a = rand()% 30 +16) : name(n), age(a){};
    
    int getAge(){ return age;}
    std::string getName() {return name;}
};

class Organization {

    std::string name; // name of the org
    Person* members; // list of members
    int size;  // actual size of the org
    int dim;  // max size of the org


public:

    Organization(std::string n = "default") : name(n), size(0), dim(100)
    {
        members = new Person[dim];
    };


    Organization(const Organization& organization) : name(organization.name), size(organization.size), dim(organization.dim)
    {
        members = new Person[dim];
        for (int i = 0; i < size; i++) {

            members[i] = organization.members[i];
        }

    }

    ~Organization()
    {
        delete[] members;
    }

    // return the name of all members enrolled in the organization
    // all members written in one string separated by semi-colons
    // returns empty string if no member is enrolled in the organization
    std::string getMemberNames()
	{
	    std::string name ="";
	    for (int i = 0; i<size;i++)
	    {
	        name = name + members[i].getName()+ ":"+ std::to_string(members[i].getAge()) + "; ";
	    }
	    return name;
    }

    // adds a Person to the members array of the organization
    // Should double the members array size if array is full
    void addPerson(Person person)
    {
        if( size>= dim)
        {
            Person *tmp= new Person[dim*2];
            for (int i=0; i<size; i++) 
            {
                tmp[i]= members[i];
            }
            delete[] members;
            members=tmp;
            dim*= 2;
        }
        
        members[size++] = person;
    }
};


void printMembers( Organization organization)// pass by value, so copy constructor is called.
{
    cout << organization.getMemberNames()<< endl;
}// after the function scope, the destructor will be called on organization.Will cause a dangling pointer if no copy constructor was defined


int main()
{
    Person p; //create a Person instance
    Organization org; //create an Organization instance
    
    org.addPerson(p); // add p to org
    cout<< "org includes: "<<endl;
    printMembers(org); // copy constructor called here: That's why we need to define our copy constructor. Otherwise we will have a shallow copy.
    
    //here we will add 250 persons to org
    for (int i =0 ; i<250; i++)
    {
        Person person("Person"+std::to_string(i), rand()% 30 +16); // create  a Person instance with the name "Person+i" and a random age
        org.addPerson(person);
    }
    cout<<endl<< "org includes: "<<endl;
    printMembers(org);
    
    Organization org1 = org;
    cout<<endl<< "org1 includes: "<<endl;
    printMembers(org1);

    return 0;
}







