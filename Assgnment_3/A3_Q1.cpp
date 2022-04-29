#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


// define your classes here


// prints all members of an organization to std::cout
void printMembers( Organization organization)
{
    // to implement
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

