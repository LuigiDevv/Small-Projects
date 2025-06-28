#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
// all code ideas I just found
// game tools section
vector<string> list = {};
const string albet{"abcdefghijklmnopqrstuvwxyz"};
vector<vector<string>> grid = {{"[ ]","[ ]","[ ]"},
                               {"[ ]","[ ]","[ ]"},
                               {"[ ]","[ ]","[ ]"}};
void displaygrid(vector<vector<string>> g){
    for (vector row : g){
        for (string elem : row){
            cout << elem;
        }
        cout << '\n';
    }
}
int AlbIndex(char c){
for(int i = 0;i < 26;i++){
    if (tolower((unsigned char)c) == albet[i]){
        return i;
    }
}
}
string reverse(string a){
    string reversed = "";
    for (int i = size(a)-1;i >= 0; i--){
        reversed += a[i];
    }
    return reversed;
}
bool wincheck(char s){
    return (grid[0][0][1] == s && grid[1][0][1] == s && grid[2][0][1] == s)
        || (grid[0][0][1] == s && grid[1][1][1] == s && grid[2][2][1] == s)
        || (grid[0][2][1] == s && grid[1][1][1] == s && grid[2][0][1] == s)
        || (grid[0][0][1] == s && grid[0][1][1] == s && grid[0][2][1] == s)
        || (grid[2][0][1] == s && grid[2][1][1] == s && grid[2][2][1] == s)
        || (grid[0][2][1] == s && grid[1][2][1] == s && grid[2][2][1] == s)
        || (grid[1][0][1] == s && grid[1][1][1] == s && grid[1][2][1] == s);
}
char rpsChoiceChecker(){
srand(time(0));
string choice;
cout << "Rock paper or scissors?: ";
cin >> choice;
//uppering
for(char&c:choice){
    c=toupper((unsigned char)c);
}
//upper ended
if (choice != "ROCK" && choice != "SCISSORS" && choice != "PAPER"){
    rpsChoiceChecker();
}
return choice[0];
}
// games section
void numberguessr(){
unsigned short randomnumber = rand()%100;
int f;
srand(time(0));
cin >> f;
if (f == randomnumber) {
    cout << "Awesome\n";
} else if (f > randomnumber && f <= 100) {
    cout << "Hold your horses! :";
    cin >> f;
    numberguessr();
} else if (f < randomnumber && f >= 0) {
    cout << "Slacker! :";
    cin >> f;
    numberguessr();
} else if (f < 0 || f > 100){
    cout << "You dum?:";
    cin >> f;
    numberguessr();
} else {
    cout << "Oh, come on!:";
    cin >> f;
    numberguessr();
}
}
void FizzBuzz() {
    grid = {{"[ ]","[ ]","[ ]"},
            {"[ ]","[ ]","[ ]"},
            {"[ ]","[ ]","[ ]"}};
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (i%3==0 && i%5!=0){
         cout << "Fizz\n";   
        } else if (i%3!=0 && i%5==0) {
         cout << "Buzz\n";
        } else if (i%3==0 && i%5==0) {
         cout << "FizzBuzz\n";
        } else {
            cout << i << '\n';
        }
    }
}
void rps(){
unsigned int cpuch = rand()%3;
char plch = rpsChoiceChecker();
switch (cpuch){
    case 0:
    if (plch == 'P'){
        cout << "You win!\n";
    } else if (plch == 'S') {
        cout << "You lose!\n";
    } else {
        cout << "It's tie!\n";
    }
    break;
    case 1:
    if (plch == 'S'){
        cout << "You win!\n";
    } else if (plch == 'R') {
        cout << "You lose!\n";
    } else {
        cout << "It's tie!\n";
    }
    break;
    case 2:
    if (plch == 'R'){
        cout << "You win!\n";
    } else if (plch == 'P') {
        cout << "You lose!\n";
    } else {
        cout << "It's tie!\n";
    }
    break;
}
}
void cipher(){
string mes;
bool ch;
cout << "Type a message: ";
cin >> mes;
cout << "Encrypt(0),Decrypt(1): ";
cin >> ch;
if (ch) {
for (char&a:mes){
a = albet[(26+AlbIndex(a) - 3)%26];
}} else {
for (char&a:mes){
a = albet[(26+AlbIndex(a) + 3)%26];
}}
cout << mes << '\n';
}
void todo(){
    int n,rem,listsize;
    listsize = 0;
    string business;
    cout << "________________LIST_______________\n";
    for (int i = 0;i < listsize;i++){
        cout << i+1 << '.' << list[i] << '\n';
    }
    cout << "___________________________________\n";
    cout << "Index action[add,remove,quit]: ";
    cin >> n;
    cin.ignore();
    switch (n){
        case 0:
            cout << "Add: ";
            listsize++;
            getline(cin,business);
            list.push_back(business);
            todo();
            break;
        case 1:
            cout << "Number in order: ";
            listsize--;
            cin >> rem;
            list.erase(list.begin()+rem-1);
            todo();
            break;
        case 2:
        break;
        default:
        todo();
        break;
    }
}
void PalindromeChecker(){
    string word;
    cout << "Type word to check if it is palindrome: ";
    cin >> word;
    word == reverse(word)? cout << "Yeah baby\n" : cout << "Hell nah\n";
}
void TicTacToe(){
    int i{0};
    string p1,p2;
    displaygrid(grid);
    cout << "Index your move as | row[no_symbol]column <--> 0-2[no_symbol]0-2\n";
    for (i; i < 9;i++){
        if (i%2 == 0){
            cout << "P1: ";
            cin >> p1;
            int a = p1[0] - '0';
            int b = p1[1] - '0';
            if (grid[a][b][1] == ' '){
            grid[a][b][1] = 'X';
            } else {
                cout << "Taken\n";
                i--;
            }
            displaygrid(grid);
            if (wincheck('X')) {i += 9;cout << "P2 is a looser\n";};
        } else {
            cout << "P2: ";
            cin >> p2;
            int a = p2[0] - '0';
            int b = p2[1] - '0';
            if (grid[a][b][1] == ' '){
            grid[a][b][1] = 'O';
            } else {
                cout << "Taken\n";
                i--;
            }
            displaygrid(grid);
            if (wincheck('O')) {i += 9;cout << "P1 is a looser\n";}
        }
    }
    if (i <= 9) {cout << "both are suckers\n";}
}
// gameplay section
int main(){ // [CHOOSE THE GAME]
    int n;
    cout << "[NumberGuesser,FizzBuzz,PalindromeCheck,TicTacToe,ToDoList,RockPaperScissors,Cipher[Shifting to 4]]\n";
    cout << "Choose the game (0 to quit): ";
    cin  >> n;
    switch (n) {
        case 0:
        break;
        case 1:
cout << "Enternumber from 0 to 100: ";
        numberguessr();
        cout << "______________________________\n"; // I don't fancy to look up much enough to clear the screen so I will just leave this cause yk
        main();
        break;
        case 2:
        FizzBuzz();
        cout << "______________________________\n"; 
        main();
        break;
        case 3:
        PalindromeChecker();
        cout << "______________________________\n"; 
        main();
        break;
        case 4:
        TicTacToe();
        cout << "______________________________\n"; 
        main();
        break;
        case 5:
        todo();
        cout << "______________________________\n"; 
        main();
        break;
        case 6:
        rps();
        cout << "______________________________\n"; 
        main();
        break;
        case 7:
        cipher();
        cout << "______________________________\n"; 
        main();
        break;
        default:
        main();
        break;
    }
    return 0;
}
