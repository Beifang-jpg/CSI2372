#include <iostream>
using namespace std;

struct Player{
    string name;
    double score;

};

void addPlayer(string newName , double newScore, Player data[10]){
    Player temp;
    temp.name = newName;
    temp.score = newScore;
    for (int i = 0; i < 10 ; i++){
        if (data[i].score < 0){
            data[i].name = newName;
            data[i].score = newScore;
            return;
        }
    }
}

void removePlayer(string removeName , Player data[10], int end){

    for (int i = 0; i < 10 ; i++){
        if (data[i].name == removeName){
            data[i].name = data[end].name;
            data[i].score = data[end].score;
            data[end].score = -1;
            data[end].name = "A";
        }
    }
}


void AAA(Player data[10]){
    Player P;
    P.name = "A";
    P.score = -1;

    for (int i = 0; i < 10 ; i++){
        data[i] = P;
    }
}


int main() {
    Player oldData[10];
    AAA(oldData);

    bool endFunction = false;

    int input;
    int size = 0;

    string name;
    double score = -1 ;

    while (!endFunction){
        cout << "What do you want to do? (Assume user always enter right thing)" << endl;
        cout << "Type 1 for add player, 2 for remove player, 3 for print player, 4 to search player, 0 to end function" << endl;
        cin >> input;
        if (input == 0){
            endFunction = true;
        }
        else if (input == 1 && size <= 10){
            cout << "Type in the name: " << endl;
            cin >> name;
            score = -1;
            while ( score < 0){
                cout << "Type in the score(need >0): " << endl;
                cin >> score;
            }
            size ++ ;
            addPlayer(name,score,oldData);
            Player* Dynamic = new Player[size];
            for (int i =0 ; i < size ; i++ ){
                Dynamic[i] = oldData[i];
            }

        }
        else if(input == 1 && size >= 10){
            cout << "Maximum have 10 players." << endl;
        }
        else if (input == 2){
            string removeName;
            cout << "Type in the player you want to remove: " << endl;
            cin >> removeName;
            removePlayer(removeName,oldData,(size-1));
            size--;
            Player* Dynamic = new Player[size];
            for (int i =0 ; i < size ; i++ ){
                Dynamic[i] = oldData[i];
            }

        }
        else if(input == 3){
            cout << "We have " << size << " players." << endl;
            Player* Dynamic = new Player[size];
            for (int i =0 ; i < size ; i++ ){
                Dynamic[i] = oldData[i];
            }

            for (int i = 0; i < size ;i ++ ){
                if ( Dynamic[i].score > 0){
                    cout << Dynamic[i].name << "   " << Dynamic[i].score << endl;
                }
            }
        }
        else if(input == 4){
            string find;
            bool foundIt = false;
            cout << "Who you want find?" << endl;
            cin >> find;



            Player* Dynamic = new Player[size];
            for (int i =0 ; i < size ; i++ ){
                Dynamic[i] = oldData[i];
            }
            for (int j =0 ; j < size ; j++ ){
                if (Dynamic[j].name == find){
                    cout << Dynamic[j].name << "  " << Dynamic[j].score << endl;
                    foundIt = true;
                }
            }
            if (!foundIt){
                cout << "Can not find this person." << endl;
            }

        }
    }

}
