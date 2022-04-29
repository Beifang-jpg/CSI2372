
#include "Person.h"
#include "Organization.h"
#include "university.h"


//add a person to an organization and an organization to a person  
void registering(Organization* o, Person* p) {
    o->addPerson(*p);
    p->addOrganization(*o);
}
void registering(University* o, Person* p) {
    o->addPerson(*p);
    p->addOrganization(*o);
}

//prints the name of the person, the number of organizations of the person and the name list of the organizations of the person 
void printMembers(Person& person)
{

    cout << person.getName() << " is part of " << person.getSize() << " organisations: " << endl;
    cout << person.getOrgNames() << endl;

}


//main: to test program 
int main() {
    Organization* o0 = new Organization("SAMSUNG");
    Organization* o1 = new Organization("Test");
    Organization* o2 = new Organization("Subway");
    Organization* o3 = new Organization("IBM");
    Organization* o4 = new Organization("Microsoft");
    Organization* o5 = new Organization("Google");



    University* o6 = new University("UofO");
    University* o7 = new University("UofT");
    o6->setTuition(10);
    o7->setTuition(30);

    Person* p1 = new Person("Amir");
    Person* p2 = new Person("John");

    registering(o0, p1);
    registering(o1, p1);
    registering(o6, p1);
    registering(o3, p1);
    registering(o7, p1);
    //registering(o5, p1); //throws error 

    registering(o1, p2);
    registering(o6, p2);
    registering(o5, p2);

    printMembers(*p1);

    cout << "Univeristy Organization: \n" << p1->printSchools() << endl;
    cout << "With Total tution fees of " << p1->getTotalTuition() << " $" << endl << endl;



    return 0;

}