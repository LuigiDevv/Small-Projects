#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
std::vector<std::vector<std::string>> success_list = {};
std::pair<int,int> moves[8] = {{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};// v< v> >v >^ ^> ^< <^ <v
std::vector<std::vector<bool>> chessboard = {{0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {0,0,0,0,0,0,0,0},
                                             {1,0,0,0,0,0,0,0}}; 
std::vector<std::vector<bool>> theboard = chessboard;
std::pair<int,int> cur_pos = {7,0};
void display(std::vector<std::vector<bool>> a){    
    for (auto s : a){
        for (auto g : s){
            std::cout << g << ' ';
        }
        std::cout << '\n';
    }
}
std::vector<int> available_moves(){
    std::vector<int> av_mvs = {};
    int a,b;
    a = cur_pos.first;
    b = cur_pos.second;
    for (int i = 0; i < 8; i++){
      if (!(a + moves[i].first > 7 || a + moves[i].first < 0 || b + moves[i].second > 7 || b + moves[i].second < 0 || theboard[a+moves[i].first][b + moves[i].second])){
       av_mvs.push_back(i);
      }
    }
    return av_mvs;
}
int cell_sum(std::vector<std::vector<bool>> brd){
    int cs = 0;
    for (std::vector i : brd){
        for (bool j : i){
          cs += j;}}
    return cs;
}
std::string ptoc(std::pair<int,int> p){
std::string c = "";
char a = p.second + 97;
char b = '8' - p.first;
c += a;
c += b;
return c;
}
void move_knight(unsigned int n){
    int a,b;
    a = cur_pos.first + moves[n].first;
    b = cur_pos.second + moves[n].second;
    theboard[a][b] = true;
    cur_pos = {a,b};
}
std::vector<std::string> sequence(){
   std::vector<std::string> sqn = {};
   for (int i = 0 ; i < 63 ; i++){
    std::vector<int> av_moves = available_moves();
   if (av_moves.empty()){
    cur_pos = {7,0};
    theboard = chessboard;
    i = -1;
    sqn = {};
   } else {
    int themove = std::rand()%av_moves.size();
    move_knight(av_moves[themove]);
    sqn.push_back(ptoc(cur_pos));
   }}
   return sqn;}
int main(){
std::srand(time(0));
using namespace std;
for (string f : sequence()){
    cout << f << ' ';
}
std::cout << '\n';
display(theboard);
return 0;
}