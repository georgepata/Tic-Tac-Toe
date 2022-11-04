#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char a[4][4];
int command, scorep1, scorep2;

void interface (char p1[], char p2[]){
    cout << endl << endl;
    cout << setw(60) << right << " ";
    cout << "Welcome to X & O" << endl << endl;
    cout << setw(56) << right << " ";
    cout << "Enter Player 1's name: ";
    cin >>p1;
    cout << endl;
    cout << setw(56) << right << " ";
    cout << "Enter Player 2's name: ";
    cin >>p2;
    cout << endl;
    cout << setw(59) << right << " ";
    cout << "Choose your command:" << endl;
    cout << setw(62) << right << " ";
    cout << "1. Play" << endl;
    cout << setw(62) << right << " ";
    cout << "2. Instructions" << endl;
    cout << setw(62) << right << " ";
    cout << "3. Leave" << endl << endl;
}

void instructions (){
    cout << setw(56) << right << " ";
    cout << "-----Instructions-----" << endl;
    cout << setw(46) << right << " ";
    cout << "Choose a number from 1-9 that is not taken" << endl;
    cout << setw(62) << right << " ";
    cout << "Have fun!" << endl;
}

void game_continue(){
    cout << setw(59) << right << " ";
    cout << "Choose your command:" << endl;
    cout << setw(62) << right << " ";
    cout << "1. Play" << endl;
    cout << setw(62) << right << " ";
    cout << "2. Instructions" << endl;
    cout << setw(62) << right << " ";
    cout << "3. Leave" << endl << endl;
}

void citire_matrice (char a[][4], char &litera, int &i, int &j){
    for (i=1; i<=3; i++){
        for (j=1; j<=3; j++){
            a[i][j]=litera;
            litera++;
        }
    } 
}

void gameplay (char a[][4], int n, int m, int &ok, char player1, char player2){
    int i,j,cnt;
    for (i=1; i<=3; i++){
        cnt=0;
        for (j=1; j<=3; j++){
            if (i==n && j==m){
                if (ok) {a[i][j]=player1; ok=0;}
                else {a[i][j]=player2; ok=1;}
            }
            if (j==1) cout << setw(60) << right << " ";
            cout << setw(3) << left << "|" << setw(3) << left << a[i][j];
            if (j==3) cout << "|";
        }
        cout << endl;
        cout << setw(60) << right << " ";
        while (cnt!=19) {cout << "-"; cnt++;}
        cout << endl;
    }
}

bool winner (char a[][4], char player1, char player2, char &c){
    int i;
    for (i=1; i<=3; i++){
        if (a[i][1]==player1 && a[i][2]==player1 && a[i][3]==player1) {c=player1; return true;}
        else if (a[i][1]==player2 && a[i][2]==player2 && a[i][3]==player2) {c=player2; return true;}
        if (a[1][i]==player1 && a[2][i]==player1 && a[3][i]==player1) {c=player1; return true;}
        else if (a[1][i]==player2 && a[2][i]==player2 && a[3][i]==player2) {c=player2; return true;}
    }
    if (a[1][1]==player1 && a[2][2]==player1 && a[3][3]==player1) {c=player1; return true;}
    else if (a[1][1]==player2 && a[2][2]==player2 && a[3][3]==player2) {c=player2; return true;}
    if (a[1][3]==player1 && a[2][2]==player1 && a[3][1]==player1) {c=player1; return true;}
    else if (a[1][3]==player2 && a[2][2]==player2 && a[3][1]==player2) {c=player2; return true;} 
    return false;
} 

bool game_over (char a[][4]){
    int i=1,j=1,ok=1;
    for (i=1; i<=3 && ok; i++){
        for (j=1; j<=3; j++){
            if (a[i][j]>='1' && a[i][j]<='9') ok=0;
        }
    }
    if (ok==0) return false;
    else return true;
}

bool number_exist (char a[][4], int x){
    int i,j;
    int c;
    for (i=1; i<=3; i++){
        for (j=1; j<=3; j++){
            c=a[i][j]-'0';
            if (c==x) return true;
        }
    }
    return false;
} 

void choosing_number (char a[][4], int &done, int x, char player1, char player2, int &ok){
    int i,j;
    for (i=1; i<=3 && done; i++){
            for (j=1; j<=3 && done; j++){
                if (x%3==0){
                    if (1*j==x){gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (i*j==x && i+j+1==x) {gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (i*j==x && 2*i+j==x) {gameplay(a,i,j,ok,player1,player2); done=0;}
                } else if (x%2==0){
                    if (1*j==x && i<j) {gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (i+j+1==x && 3*i-2*j==x && i>j) {gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (2*i+j==x && i+j+x%(i+j)==x && i>j) {gameplay(a,i,j,ok,player1,player2); done=0;}
                }  else if (x%2==1){
                    if (1*j==x) {gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (i+j+1==x && i==j && i+j+x%(i+j)==x) {gameplay(a,i,j,ok,player1,player2); done=0;}
                    else if (2*i+j==x && i>j && 3*i-2*j==x) {gameplay(a,i,j,ok,player1,player2); done=0;}
                }
            }
        }
}

void scoreboard (int scorep1, int scorep2, char p1[], char p2[]) {
    int cnt=0;
    cout << setw(60) << right << p1;
    cout << setw(15) << left << " ";
    cout << setw(15) << right << p2;
    cout << endl;
    cout << setw(52) << right << " ";
    while (cnt!=38) {cout << "-"; cnt++;}
    cout << endl;
    cout << setw(60) << right << scorep1;
    cout << setw(15) << left << " ";
    cout << setw(15) << right << scorep2;
}

void player_turn (int ok, char p1[], char p2[], int &x){
    if (ok){
        cout << setw(67) << right << p1 << "'s turn: ";;
        cin >>x;
    } else {
        cout << setw(67) << right << p2 << "'s turn: ";
        cin >>x;
    }
}

int main (){
    int i=1, j=1, x, ok=1;
    char litera='1', player1='X', player2='O',c;
    char p1[10], p2[10];
    citire_matrice(a,litera,i,j); 
    interface(p1,p2);
    do{
        cout << setw(57) << right << " ";
        cout << "You chose command: ";
        cin >>command;
        cout << endl << endl;
        switch(command){
            case 1:
                gameplay(a,i,j,ok,player1,player2);
                while (game_over(a)==false && winner(a,player1,player2,c)==false){
                    int done=1;
                    player_turn(ok,p1,p2,x);
                    if (x>9){
                        while (x>9){
                            cout << setw(56) << right << " ";
                            cout << "Enter a number between 1-9: ";
                            cin >>x;
                        }
                    }
                    if (number_exist(a,x)==false){
                        while (number_exist(a,x)==false){
                            cout << setw(52) << right << " ";
                            cout << "Enter another number that is not taken: ";
                            cin >>x;
                            if (x>9){
                                while (x>9){
                                    cout << setw(56) << right << " ";
                                    cout << "Enter a number between 1-9: ";
                                    cin >>x;
                                }
                            }
                        }
                    }
                    cout << endl;
                    choosing_number(a,done,x,player1,player2,ok);
                    cout << endl << endl << endl;
                    gameplay(a,i,j,ok,player1,player2);
                    cout << endl;
                    if (winner(a,player1,player2,c)==true){
                        if (c==player1) {cout << setw(70) <<"Winner is: " << player1 << " -> " << p1 << endl << endl; scorep1+=10;}
                        else {cout << setw(70) << "Winner is: " << player2 << " -> " << p2 << endl << endl; scorep2+=10;}
                    }
                }
                cout << endl;
                scoreboard(scorep1,scorep2,p1,p2);
                cout << endl;
                break;
            case 2:
                instructions();
                break;
            case 3:
                cout << setw(47) << right << " ";
                cout << "Thanks for playing X & O, this is the scoreboard" << endl << endl;
                scoreboard(scorep1,scorep2,p1,p2);
                cout << endl << endl;
                cout << setw(60) << right << " ";
                if (scorep1>scorep2) cout << "The winner is: " << p1;
                else if (scorep1<scorep2) cout << "The winner is: " << p2;
                else cout << "Game ended in a tie";
                break;
        }
        cout << endl;
        litera='1'; i=1; j=1; ok=1;
        citire_matrice(a,litera,i,j); 
        if (command!=3) game_continue();
    } while (command!=3); 
}