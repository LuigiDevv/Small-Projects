#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <list>
#include <numbers>
#include <algorithm>
static bool check(char a) {
    if (a != '+' && a != '-' && a != '*' && a != '/' && a != '(' && a != ')') {
        return true;
    }
    else {
        return false;
    }
}

static std::string checkS(std::string skill) {
        std::string cur = "";
        std::string SkillVal = "";
        for (char e : skill) {
            if (std::isdigit(e) || e == '^') { SkillVal += e; }
        }
        for (char e : skill) { // taking skill name
            if (!std::isdigit(e) && e != '^') { cur += e; }
        }
        // DON'T FORGET TO REMOVE EXPONENT FROM SkillVal
        // AND CREATE A FUNCTION WHICH POWERS THE NUBMER AND USE IT FOR REGULAR NUMBERS TOO
        if (cur == "sin") { return sin(stoi(SkillVal)); }
        else if (cur == "cos") { return cos(stoi(SkillVal)); }
        else if (cur == "log") { return log(stoi(SkillVal)); }
        else if (cur == "sqrt") { return sqrt(stoi(SkillVal)); }
        else if (cur == "cosh") { return cosh(stoi(SkillVal)); }
        else if (cur == "sinh") { return sinh(stoi(SkillVal)); }
        else if (cur == "tan") { return tan(stoi(SkillVal)); }
        
        
    }
int main() {
    double pi = std::numbers::pi;
    double e = std::numbers::e;
    std::string INP;
    std::getline(std::cin, INP);
    size_t length(std::size(INP));
    std::vector<std::string> dyded = {};


    std::string word("");

    for (int i = 0; i < length; i++) {
        if (check(INP[i])) {
            if (INP[i] != ' ') {  
                word += INP[i];   
            }
        }
        else {  
            if (!word.empty()) {
                dyded.push_back(word);  
                word = "";  
            }
            dyded.push_back(std::string(1, INP[i]));  
        }
    }

    if (!word.empty()) {  
        dyded.push_back(word);
    }
/* --------------------------------------------------SOLVING
    for (int i = 0; i < dyded.size();i++) {
        if (!std::isdigit(dyded[i][0] & std::isdigit(dyded[i][-1]))) {
            dyded[i] = checkS(dyded[i]);
        }
    } */
    for (std::string FFF : dyded) {
        std::cout << FFF << ' ';
    }
    return 0;
}