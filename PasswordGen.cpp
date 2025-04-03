#include <iostream>
int main(){
    std::srand(time(0));
    unsigned int length = std::rand()%11 + 20; // 20-30 sized password
    std::string password = "";
    for (int i = 0 ; i < length ; i++){
        char s = std::rand()%128 + 1;
        while (s == 32) { s = std::rand()%128 + 1; }
        password += s;
    }
    std::cout << length << "\n";
    std::cout << "Generated Password: " << password << " ";
    return 0;
}