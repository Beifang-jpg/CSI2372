#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;



double changeToDouble(int i){
//    if (i < 10){
//        i = i*i*i*i*i;
//    } else if(i < 100){
//        i = i*i*i;
//    }else if (i < 1000){
//        i = i*i;
//    }


    double j = 0.99999*i;
    return j;
}

bool isDead(double randomNum,double death_prob){
    if (randomNum > death_prob){
        return false;
    }else if ( randomNum <= death_prob){
        return true;
    }
}

int findAgePosition(int age){
    int i = 0;
    i = age * 3;
    return i;
}
//Quickly find which row the age is;

int simulate (int age, string gender){
    vector<double> box;
    string line;
    ifstream file ("LifeDeathProbability.txt");

    while(file >> line ){
        double num;
        stringstream ss;
        ss << line;
        ss >> num;

        box.push_back(num);
    }

    int live = age;
    int ageRow = findAgePosition(age);
    bool dead = false;
    if (gender == "M"){
        while (!dead && live<= 120){
            srand(time(0));
            int x;
            int* px = &x;
            for (int i =0 ; i < (rand()%9); i++){
                *px = rand();
            }

            double j = changeToDouble(x);

            double k = j * 0.00001;

                    while ( k > 1){
                        k = k * 0.7;
                    }
            if(isDead(k,box[ageRow+1])){
                dead = true;
            }else{
                live = live +1;
                ageRow = ageRow +3;
            }
        }
        return live;
    }else {
        while (!dead && live <=120){
            srand(time(0));
            int x;
            int* px = &x;
            for (int i =0 ; i < (rand()%9); i++){
                *px = rand();
            }

            double j = changeToDouble(x);

            double k = j * 0.00001;

            while ( k > 1){
                k = k * 0.7;
            }
            if(isDead(k,box[ageRow+2])){
                dead = true;
            }else{
                live = live +1;
                ageRow = ageRow +3;
            }
        }
        return live;
    }
}







int main() {


    bool genderPass = false;
    bool agePass = false;
    string gender;
    double age;
    srand(time(0));

    vector<double> box;
    string line;
    ifstream file ("LifeDeathProbability.txt");
    cout << "I put the LifeDeathProbability.txt in Assgnment_1\\Assgnment_1_Q1\\cmake-build-debug file" << endl;
    while(file >> line ){
        double num;
        stringstream ss;
        ss << line;
        ss >> num;

        box.push_back(num);
    }

    while(!genderPass){

        cout << "Please enter your gender, M for male and F for female: " << endl;
        cin >> gender ;
        if (gender == "M" || gender == "F"){
            genderPass = true;
        }
    }

    while(!agePass){

        cout << "Please enter your age(0-120): " << endl;
        cin >> age ;
        if (age>=0 && age<= 120){
            agePass = true;
        }
    }

    cout << "This person has lived: " <<simulate(age,gender) << endl;








    return 0;
}
