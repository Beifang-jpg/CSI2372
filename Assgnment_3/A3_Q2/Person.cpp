
#include "Person.h"
#include "Organization.h"



//Person::Person(std::string n, int a) {
//    name = n;
//
//};

    // copy from the Q1
    int Person:: getAge(){
        return age;
    }
    string Person:: getName(){
        return name;
    }
    Person:: Person(basic_string<char> basicString, int i){
        age = i;
        name = basicString;

    }
    Person:: Person(){
        age = -1;
        name = "Default";
        int size = 0;
        Organization** organizations[5] = {};
        int dim = 0;
    };


    //Q2 part
    Person:: Person (string s){
        name = s;
        age = -1;
        int size = 0;
        Organization** organizations[5] = {};
        int dim = 0;
    }


    int Person:: getSize(){
        return size;
    }


    void Person:: addOrganization(Organization organization){
        if (size <= 5){
            organizations.push_back(organization);
        }
    }

//    void Person:: addOrganization(Organization *organization){
//        if (size <= 5){
//            organizations[size] = organization;
//        }
//    }

//    void registering(Organization* o, Person* p) {
//        o->addPerson(p);
//        p->addOrganization(o);
//    }

    string Person:: getOrgNames(){
        string S = "";
        for (int i=0; i<size ; i++){
            Organization temp = organizations[i];
            S = S + "," + temp.getName();
        }
        return S ;
    }

    float Person:: getTotalTuition(){
        float fee = 0;
        for (int i=0; i<size ; i++){
            Organization temp = organizations[i];
            if (temp.isSchool()){
                fee = fee + temp.getTuition();

            }
        }
        return fee;

    }
    string Person:: printSchools(){
        string S = "";
        for (int i=0; i<size ; i++){
            Organization temp = organizations[i];
            if (temp.isSchool()){
                S = S +" , "+ temp.getName();
            }
        }
        return S;
    }


//Person::Person(string s) {
//
//}





