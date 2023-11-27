#include <iostream>
#include <string>
using namespace std;
bool secretcorrector (string secret){
    if (secret.length()!=4){
        return false;}
    else if (secret[0] != 'R' && secret[0] != 'G' && secret[0] != 'B' && secret[0] != 'P' && secret[0] != 'Y' && secret[0] != 'M'){
        return false;}
    else if (secret[1] != 'R' && secret[1] != 'G' && secret[1] != 'B' && secret[1] != 'P' && secret[1] != 'Y' && secret[1] != 'M'){
        return false; }
    else if (secret[2] != 'R' && secret[2] != 'G' && secret[2] != 'B' && secret[2] != 'P' && secret[2] != 'Y' && secret[2] != 'M'){
        return false;}
    else if (secret[3] != 'R' && secret[3] != 'G' && secret[3] != 'B' && secret[3] != 'P' && secret[3] != 'Y' && secret[3] != 'M'){
        return false;}
    else if (secret[0] == secret[1] || secret[0] ==secret[2] || secret[0] ==secret[3] ){
        return false; }
    else if (secret[1] == secret[0] || secret[1] == secret[2] || secret[1] == secret[3] ){
        return false;  }
    else if (secret[2] == secret[0] || secret[2] ==secret[1] || secret[2] ==secret[3] ){
        return false;}
    else if (secret[3] == secret[0] ||secret[3] == secret[1] ||secret[3] == secret[2] ){
        return false; }
    else{
        return true;   }
}
bool guesscorrector (string guess){
    if (guess.length()!=4){
        return false;
    }
    else if (guess[0] != 'R' && guess[0] != 'G' && guess[0] != 'B' && guess[0] != 'P' && guess[0] != 'Y' && guess[0] != 'M'){
        return false;
    }
    else if (guess[1] != 'R' && guess[1] != 'G' && guess[1] != 'B' && guess[1] != 'P' && guess[1] != 'Y' && guess[1] != 'M'){
        return false;
    }
    else if (guess[2] != 'R' && guess[2] != 'G' && guess[2] != 'B' && guess[2] != 'P' && guess[2] != 'Y' && guess[2] != 'M'){
        return false;
    }
    else if (guess[3] != 'R' && guess[3] != 'G' && guess[3] != 'B' && guess[3] != 'P' && guess[3] != 'Y' && guess[3] != 'M'){
        return false;
    }
    else if (guess[0] == guess[1] ||guess[0] ==guess[2] ||guess[0] == guess[3] ){
        return false;
    }
    else if (guess[1] == guess[0] || guess[1] ==guess[2] || guess[1] ==guess[3] ){
        return false;
    }
    else if (guess[2] == guess[0] || guess[2]==guess[1] ||guess[2]==guess[3] ){
        return false;
    }
    else if (guess[3] == guess[0] || guess[3] ==guess[1] ||guess[3] == guess[2] ){
        return false;
    }
    else{
        return true;
        }
}
int main(){
    string name1,name2,secret1,secret2,guess1,guess2;
    int runs,count1=0,count2=0,tur;
    cout<<"Please enter the names of the players: ";
    cin>>name1>>name2;
    cout<<"Welcome "<<name1<<" and "<<name2<<endl;
    cout<<endl;
    cout<<"Please enter the number of runs: ";
    cin>>runs;
    while ((runs<=0)|| (runs%2!=0)){
        cout<<"Invalid number of runs!"<<endl;
        cout<<"Please enter the number of runs: ";
        cin>>runs;
    }
    cout<<endl;
    tur=runs/2;
    for (int i = 0; i <tur; i=i+1){
        cout<<name1<<", it is your turn to select the secret!"<<endl;
        cout<<"Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta"<<endl;
        cout<<name1<<", please enter your secret:";
        cin>>secret1;
        while (!secretcorrector(secret1)){
            cout<<" Invalid secret!"<<endl;
            cout<<name1<<", please enter your secret:";
            cin>>secret1;
        }
        cout<<endl;
        cout<<name2<<", please enter your guess: ";
        cin>>guess2;
        for (int E=0; E<=5; E++){
            while (!guesscorrector(guess2)){
                cout<<"Invalid guess!"<<endl;
                cout<<name2<<", please enter your guess: ";
                cin>>guess2;
            }
            if (secret1==guess2){
                cout<<name2<<", you won this run!"<<endl;
                cout<<endl;
                count2++;
                break;
            }
            if (secret1.find("R")==guess2.find("R") && secret1.find("R")!=-1){
                cout<<"R";
                    }
            if (secret1.find("G")==guess2.find("G")&& secret1.find("G")!=-1){
                cout<<"R";
            }
            if (secret1.find("B")==guess2.find("B")&&secret1.find("B")!=-1){
                cout<<"R";
            }
            if (secret1.find("P")==guess2.find("P")&&secret1.find("P")!=-1){
                cout<<"R";
                    }
            if (secret1.find("Y")==guess2.find("Y")&&secret1.find("Y")!=-1){
                cout<<"R";
                    }
            if (secret1.find("M")==guess2.find("M")&&secret1.find("M")!=-1){
                cout<<"R";
                    }
            if (secret1.find("R")!=guess2.find("R") && secret1.find("R")!=-1&&guess2.find("R")!=-1){
                cout<<"W";
                    }
            if (secret1.find("G")!=guess2.find("G")&&secret1.find("G")!=-1&&guess2.find("G")!=-1){
                cout<<"W";
                    }
            if (secret1.find("B")!=guess2.find("B")&&secret1.find("B")!=-1&&guess2.find("B")!=-1){
                cout<<"W";
                    }
            if (secret1.find("P")!=guess2.find("P")&&secret1.find("P")!=-1&&guess2.find("P")!=-1){
                cout<<"W";
                    }
            if (secret1.find("Y")!=guess2.find("Y")&&secret1.find("Y")!=-1&&guess2.find("Y")!=-1){
                cout<<"W";
                    }
            if (secret1.find("M")!=guess2.find("M")&&secret1.find("M")!=-1&&guess2.find("M")!=-1){
                cout<<"W";
                    }
            count1++;
            if (E<=4){
                cout<<endl;
                cout<<name2<<", please enter your guess: ";
                cin>>guess2;
                    }
            if (E==5){
                cout<<endl;
                cout<<name2<<", you're out of chances, you lost this run!"<<endl;
                cout<<endl;
                count1++;
            }
                }
        cout<<name2<<", it is your turn to select the secret!"<<endl;
        cout<<"Valid colors: R - Red, G - Green, B - Blue, P - Purple, Y - Yellow, M - Magenta"<<endl;
        cout<<name2<<", please enter your secret:";
        cin>>secret2;
        while (!secretcorrector(secret2)){
            cout<<"Invalid secret!"<<endl;
            cout<<name2<<", please enter your secret:";
            cin>>secret2;
            cout<<endl;
            }
        cout<<endl;
        cout<<name1<<", please enter your guess: ";
        cin>>guess1;
        for (int E=0; E<6; E++){
            while (!guesscorrector(guess1)){
                cout<<"Invalid guess!"<<endl;
                cout<<name1<<", please enter your guess: ";
                cin>>guess1;
                }
            if (secret2==guess1){
                cout<<name1<<", you won this run!"<<endl;
                cout<<endl;
                count1++;
                break;
                }
            if (secret2.find("R")==guess1.find("R")&&secret2.find("R")!=-1){
                cout<<"R";
                    }
            if (secret2.find("G")==guess1.find("G")&&secret2.find("G")!=-1){
                cout<<"R";
                    }
            if (secret2.find("B")==guess1.find("B")&&secret2.find("B")!=-1){
                cout<<"R";
                    }
            if (secret2.find("P")==guess1.find("P")&&secret2.find("P")!=-1){
                cout<<"R";
                }
            if (secret2.find("Y")==guess1.find("Y")&&secret2.find("Y")!=-1){
                cout<<"R";
            }
            if (secret2.find("M")==guess1.find("M")&&secret2.find("M")!=-1){
                cout<<"R";
                    }
            if (secret2.find("R")!=guess1.find("R")&&secret2.find("R")!=-1&&guess1.find("R")!=-1){
                cout<<"W";
                    }
            if (secret2.find("G")!=guess1.find("G")&&secret2.find("G")!=-1&&guess1.find("G")!=-1){
                cout<<"W";
                    }
            if (secret2.find("B")!=guess1.find("B")&&secret2.find("B")!=-1&&guess1.find("B")!=-1){
                cout<<"W";
                        }
            if (secret2.find("P")!=guess1.find("P")&&secret2.find("P")!=-1&&guess1.find("P")!=-1){
                cout<<"W";
                        }
            if (secret2.find("Y")!=guess1.find("Y")&&secret2.find("Y")!=-1&&guess1.find("Y")!=-1){
                cout<<"W";
                    }
            if (secret2.find("M")!=guess1.find("M")&&secret2.find("M")!=-1&&guess1.find("M")!=-1){
                cout<<"W";
                        }
            count2++;
            if (E<=4){
                cout<<endl;
                cout<<name1<<", please enter your guess: ";
                cin>>guess1;
                    }
            if (E==5){
                cout<<endl;
                cout<<name1<<", you're out of chances, you lost this run!"<<endl;
                cout<<endl;
                count2++;
            }
        }
        }
    cout<<"The game has ended!"<<endl;
    cout<<name1<<": "<<count1<<" - "<<name2<<": "<<count2<<endl;
    cout<<endl;
    if (count1==count2){
        cout<<name1<<" and "<<name2<<", there is a tie!";
    }
    else if (count1>count2){
        cout<<"Congrats "<<name1<<", you have won the game!";
    }
    else{
        cout<<"Congrats "<<name2<<", you have won the game!";
    }
    return 0;
}
