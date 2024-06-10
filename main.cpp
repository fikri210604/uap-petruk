#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cstring>
#include <queue>
#include <fstream>
template <class T, class U>
class mobil{
    T plat;
    U waktuMasuk;
    U WaktuKeluar;
    U Durasi;
    
};
int main(){
    std::ifstream inputFile("./Data/Akun.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    for (const std::string& str : lines) {
        std::cout << str << std::endl;
    }
    return 0;
}