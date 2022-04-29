
#ifndef UNIVERSITY_H 
#define UNIVERSITY_H 

#include "Organization.h"



class University : public Organization {
    float tuition;
public:
    void setTuition(float i){
        tuition = i;
    }
    float getTuition(){
        return tuition;
    }

    University(string n){
        name = n;
    }

    bool isSchool(){
        return true;
    }


   
};

#endif

