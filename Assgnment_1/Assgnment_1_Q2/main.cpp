#include <iostream>
using namespace std;

void removePlayer(string name, string boxName[], int boxScore[] ){
    for (int i = 0 ; i< 10 ; i++){
        if(boxName[i] == name){
            boxName[i] = "Empty";
            boxScore[i] = -1;
            return;
        }
    }
    cout << "This person not in list."<< endl;
}

bool searchPlayerScore(string name, string boxName[], int boxScore[]){
    for (int i = 0 ; i< 10 ; i++){
        if (boxName[i] == name){
            cout << boxName[i] << endl;
            cout << boxScore[i] << endl;
            return true;
        }else{
        }
    }
    return false;
}

bool addPlayer (string name, int score,string boxName[], int boxScore[]){
    for (int i = 0 ; i< 10 ; i++){
        if (boxName[i] == "Empty"){
            boxName[i] = name;
            boxScore[i] = score;
            return true;
        }
    }
    return false;

}

void print(string boxName[], int boxScore[]){
    for (int i = 0 ; i< 10 ; i++){
        if (boxName[i] != "Empty"){

            cout << boxName[i] << endl;
            cout << boxScore[i] << endl;
        }
        else{
        }
    }
}


int main() {
    string player_Name;
    string name_Box[10];
    string* name_Memory[10];

    for (int i = 0 ; i< 10 ; i++){
        name_Box[i] = "Empty";
    }

    int score;
    int score_Box[10];
    for (int i = 0 ; i< 10 ; i++){
        score_Box[i] = -1;
    }

    bool end_Function = false;
    while (!end_Function){
        int numb;
        cout << " " << endl;
        cout << "What do you want to do " << endl;
        cout << "type 1 to add player, 2 for print, 3 for search player, 4 for remove player, 0 to end function:" << endl;
        cin >> numb;
        if (numb == 0){
            cout << "Function end " << endl;
            end_Function = true;
        }
        else if(numb == 1){
            cout << "please enter player name: " << endl;
            cin >> player_Name;
            cout << "And the highest score: " << endl;
            cin >> score;

            if(addPlayer(player_Name,score,name_Box,score_Box)){
                cout << "player and score added." << endl;
            } else{
                cout<< "List full. Player can not been added." << endl;
            }
        }
        else if (numb == 2){
            print(name_Box,score_Box);
        }
        else if(numb == 3 ){
            string name;
            cout<< "Who do you want search: " << endl;
            cin >> name;
            if(!searchPlayerScore(name,name_Box,score_Box)){
                cout<< "Person not found. " << endl;
            }
        }
        else if(numb == 4 ){
            string name;
            cout<< "Who do you want to remove " << endl;
            cin >> name;
            removePlayer(name,name_Box,score_Box);
        }

    }


}
