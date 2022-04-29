#include <iostream>
using namespace std;
struct Stat
{
    float min;
    float ave;
    float max;
};


//prototypes
void printMonth(Stat& tableTemp, int month) {
    string calendar[12] = { "January" , "February" , "March" , "April" , "May" , "June" , "July", "August" ,"September" , "October" , "November", "December"};
    cout<< "For the month of " << calendar[month-1] << endl;
    cout<< "The minimum temperature was =" << tableTemp.min <<endl;
    cout<< "The average temperature was =" << tableTemp.ave <<endl;
    cout<< "The maximum temperature was =" << tableTemp.max <<endl;
}

Stat statMonth(Stat** tableTemp, int month, int nYears){
    Stat AAA;
    // Max part
    float Max = tableTemp[0][month].max;

    for (int i=1 ; i<nYears ;i++){

        if ((tableTemp[i][month].max) > Max){
            Max = tableTemp[i][month].max;
        }else{

        }

    }
    AAA.max = Max;


    // Ave part
    float Ave = 0;
    float year = (nYears + 1);
    for (int i=0 ; i<year ;i++){

        Ave = Ave + tableTemp[i][month].ave;


    }
    Ave = Ave/year;

    AAA.ave = Ave;


    // Min part
    float Min = tableTemp[0][month].min;
    for (int i=1 ; i<year ;i++){
        if ((tableTemp[i][month].min) < Min){
            Min = tableTemp[i][month].min;
        }else{

        }

    }
    AAA.min = Min;


    return AAA;
}



int main()
{
    float year19[12][3] = { {-15,-12,-9},{-12,-9,-6},{-8,-4,-1},{1,5,9},{7,11,15},{12,17,22},{17,22,27},{14,19,24},{10,15,20},{5,9,13},{-5,-2,2},{-7,-4,-1} };
    float year18[12][3] = { {-13,-9,-5},{-9,-5,0},{-4,-1,2},{-1,3,7},{8,15,21},{12,17,23},{17,22,28},{17,21,26},{12,17,21},{3,7,11},{-4,-1,2},{-8,-5,-2} };
    float year17[12][3] = { {-11,-7,-3},{-11,-6,-2},{-9,-6,-2},{3,7,11},{7,11,16},{12,17,22},{15,20,25},{13,19,24},{13,18,23},{9,13,17},{-3,1,5},{-11,-9,-6} };
    float year16[12][3] = { {-11,-7,-4},{-13,-9,-4},{-6,-2,1},{-1,3,8},{8,13,18},{12,17,22},{15,20,25},{16,21,26},{11,17,22},{6,9,13},{0,4,7},{-9,-6,-2} };
    float year15[12][3] = { {-18,-13,-8},{-22,-17,-12},{-10,-6,-2},{1,5,10},{9,15,22},{11,17,22},{14,20,26},{15,20,25},{12,17,22},{4,8,12},{2,5,8},{-1,1,4} };
    float year14[12][3] = { {-17,-12,-8},{-16,-11,-7},{-12,-8,-3},{0,4,8},{7,13,18},{12,17,23},{13,18,24},{13,18,24},{10,15,20},{6,10,14},{-2,1,4},{-6,-4,-1} };
    float year13[12][3] = { {-15,-10,-5},{-14,-10,-5},{-6,-3,0},{0,4,9},{8,13,19},{11,16,21},{15,20,26},{13,19,25},{8,14,19},{6,9,13},{-5,-1,3},{-13,-9,-6} };
    float year12[12][3] = { {-14,-9,-5},{-12,-7,-2},{-1,3,7},{1,6,10},{9,14,20},{12,18,23},{14,20,25},{15,19,24},{9,14,19},{6,10,14},{-2,1,4},{-8,-5,-1} };
    float year11[12][3] = { {-14,-11,-7},{-13,-9,-4},{-7,-4,0},{1,5,10},{7,12,17},{12,17,22},{15,21,26},{14,19,23},{11,16,20},{6,10,13},{1,5,9},{-6,-3,0} };
    float year10[12][3] = { {-10,-7,-4},{-7,-5,-3},{-1,3,6},{4,9,14},{8,14,20},{12,17,22},{16,21,26},{14,19,24},{10,15,19},{4,8,11},{-2,2,5},{-8,-6,-3} };



    //Create 10x12 dynamic array with struct stat
    Stat** tableTemp = new Stat*[10];
    for (int i = 0; i < 10; i++){
        tableTemp[i] = new Stat[12];
    }

    float allData [10][12][3] ;
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[0][i][j] = year10[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[1][i][j] = year11[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[2][i][j] = year12[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[3][i][j] = year13[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[4][i][j] = year14[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[5][i][j] = year15[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[6][i][j] = year16[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[7][i][j] = year17[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[8][i][j] = year18[i][j];
        }
    }
    for (int i = 0 ; i < 12 ; i++){
        for (int j = 0 ; j < 3; j++){
            allData[9][i][j] = year19[i][j];
        }
    }
    // All 10 years are in one 3d array
    for (int i = 0; i< 10 ;i ++){
        for (int j = 0; j < 12; j++){
            tableTemp[i][j].min = allData[i][j][0];
            tableTemp[i][j].ave = allData[i][j][1];
            tableTemp[i][j].max = allData[i][j][2];
        }
    }




    int month;
    int year;

    //Month


    cout << "Please type in how long you would like to check since 2010: "<< endl;
    cin >> year ;
    while (year< 0 || year > 9){
        cout << "Out of range! "<< endl;
        cout << "Please type in how long you would like to check since 2010: "<< endl;
        cin >> year ;
    }

    Stat data[12];
    for (int i = 0; i<12; i++){
        data[i] = statMonth(tableTemp,i,year);
    }


    cout << "Enter the number of the month (between 1 and 12):  " << endl;
    cin >> month;
    while (month < 0 || month > 12){
        cout << "Month out of range!" << endl;
        cout << "Enter the number of the month (between 1 and 12):  " << endl;
        cin >> month;
    }

    cout << "From 2010 to 201"<< year << endl;
    printMonth(data[month-1],month);










    return 0;
}
