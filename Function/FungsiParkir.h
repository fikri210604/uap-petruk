#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cstring>
#include <queue>
#include <fstream>
#include <bitset>
#include <functional>
void judul();
void login();
void register_();
void menu();
void lihatLokasi();
void pemesanan();
class parkir{
    public :
    std::string plat;
    int WaktuMasuk,WaktuKeluar,Durasi;
    int biaya,harga,hargaJamSelebihnya;
    void setPlat(std::string plat){
        this->plat=plat;
    }
    void setWaktuMasuk(int WaktuMasuk){
        this->WaktuMasuk=WaktuMasuk;
    }
    void setWaktuKeluar(int WaktuKeluar){
        this->WaktuKeluar=WaktuKeluar;
    }
    void setHarga(int harga,int hargaJamSelebihnya){
        this->harga=harga;
        this->hargaJamSelebihnya=hargaJamSelebihnya;
    }
    int getDurasi(){
        return Durasi;
    }
    void hitungDurasi(int WaktuMasuk,int WaktuKeluar){
        Durasi=(59+WaktuKeluar-WaktuMasuk)/60;
    }
    void bayar(){
        biaya=harga*Durasi;
    }

};
class mobil : public parkir {
    public :
    void setHargaMobil(std::string token,std::string keluar){
        setHarga(5000,3000);
        int itung = (keluar[4]-'0')*600+(keluar[5]-'0')*60+(keluar[6]-'0')*10+keluar[7]-'0';
        int itung2 = (token[4]-'0')*600+(token[5]-'0')*60+(token[6]-'0')*10+token[7]-'0';
        std::cout<<"Yang harus dibayarkan : "<<std::endl;
        std::ofstream outputFile("./Function/Data/HasilParkir.txt", std::ios::app);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file!" << std::endl;
        }
        if((59+itung-itung2)/60>1){
            std::cout<<std::to_string(5000+((59+itung-itung2)/60-1)*3000)<<std::endl;
            outputFile << std::to_string(5000+((59+itung-itung2)/60-1)*3000) << std::endl;
        }
        else{
            std::cout<<"5000"<<std::endl;
            outputFile << "5000" << std::endl;
        }
        system("pause");
        outputFile.close();
    }
};
class motor : public parkir {
    public :
    void setHargaMotor(std::string token,std::string keluar){
        setHarga(2000,1000);
        int itung = (keluar[4]-'0')*600+(keluar[5]-'0')*60+(keluar[6]-'0')*10+keluar[7]-'0';
        int itung2 = (token[4]-'0')*600+(token[5]-'0')*60+(token[6]-'0')*10+token[7]-'0';
        std::cout<<"Yang harus dibayarkan : "<<std::endl;
        std::ofstream outputFile("./Function/Data/HasilParkir.txt", std::ios::app);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file!" << std::endl;
        }
        if((59+itung-itung2)/60>1){
            std::cout<<std::to_string(2000+((59+itung-itung2)/60-1)*1000)<<std::endl;
            outputFile << std::to_string(2000+((59+itung-itung2)/60-1)*1000) << std::endl;
        }
        else{
            std::cout<<"1000"<<std::endl;
            outputFile <<"1000" << std::endl;
        }
        system("pause");
        outputFile.close();
    }
};
long long Hash(std::string object){
    std::hash<std::string> mystdhash;
    return mystdhash(object);
}
auto center = [](const std::string& text, int width) {
        int pad = (width - text.length()) / 2;
        return std::string(pad, ' ') + text + std::string(pad, ' ');
    };
void bayar(){
    std::cout<<"Masukkan Jenis Kendaraan : "<<std::endl;
    std::cout<<"1. Mobil"<<std::endl;
    std::cout<<"2. Motor"<<std::endl;
    int pilih;
    std::cin>>pilih;
    if(pilih==1){
        mobil a;
        std::cout<<"Masukkan token pelanggan:";
        char token[9];
        std::cin.ignore();
        std::cin.get(token,9);
        std::cout<<"Masukkan token keluar:";
        char keluar[9];
        std::cin.ignore();
        std::cin.get(keluar,9);
        a.setHargaMobil(token,keluar);
    }
    else if(pilih==2){
        motor a;
        std::cout<<"Masukkan token pelanggan:";
        char token[9];
        std::cin.ignore();
        std::cin.get(token,9);
        std::cout<<"Masukkan token keluar:";
        char keluar[9];
        std::cin.ignore();
        std::cin.get(keluar,9);
        a.setHargaMotor(token,keluar);
    }
}
void judul(){
    system("cls");
    int pilih;
    const int width = 90;
    std::cout << std::string(width, '=') << std::endl;
    std::cout << std::string(width, '=') << std::endl;
    std::cout << " _____        _                           _     _____          _                       \n";
    std::cout << "/ ____|      | |                         | |   |  __ \\        | |                      \n";
    std::cout << "| (___   ___ | |  __ _  _ __ ___    __ _ | |_  | |  | |  __ _ | |_  __ _  _ __    __ _ \n";
    std::cout << " \\___ \\ / _ \\| | / _` || '_ ` _ \\  / _` || __| | |  | | / _` || __|/ _` || '_ \\  / _` |\n";
    std::cout << " ____) |  __/| || (_| || | | | | || (_| || |_  | |__| || (_| || |_| (_| || | | || (_| |\n";
    std::cout << "|_____/ \\___||_| \\__,_||_| |_| |_| \\__,_| \\__| |_____/  \\__,_| \\__|\\__,_||_| |_| \\__, |\n";
    std::cout << "                                                                                  __/ |\n";
    std::cout << "                                                                                 |___/ \n";
    std::cout << center("1. Login", width) << std::endl;
    std::cout << center("2. Registrasi", width) << std::endl;
    std::cout << center("3. Bayar", width) << std::endl;
    std::cout << center("4. Keluar", width) << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << center("Masukkan Pilihan Anda: ", width);
    std::cin>>pilih;
    std::cout << std::endl << std::endl;
    std::cout << std::string(width, '=') << std::endl;
    std::cout << std::string(width, '=') << std::endl;
    if(pilih == 1){
        login();
    }
    else if(pilih == 2){
        register_();
    }
    else if(pilih == 3){
        bayar();
    }
    else if(pilih == 4){
        std::cout << "Terima Kasih" << std::endl;
    }
    system("cls");
}

int cekAkun(long long hash1, long long hash2=0){
    std::ifstream inputFile("./Function/Data/Akun.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 99;
    }
    std::string hash1Str = std::to_string(hash1);
    std::string hash2Str = std::to_string(hash2);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string username = line.substr(0, line.find(' '));
        std::string password = line.substr(line.find(' ') + 1);
        if(hash1Str == username && hash2Str == password){
            std::cout << "Login Berhasil" << std::endl;
            return 2;
        }
        else if (hash1Str == username) {
            return 1;
        }
    }
    inputFile.close();
    return 0;
}
void login(){
    system("cls");
    std::cout << "Login" << std::endl;
    std::cout << "Username : ";
    std::string username;
    std::cin >> username;
    std::cout << "Password : ";
    std::string password;
    std::cin >> password;
    if(cekAkun(Hash(username), Hash(password))==2){
        std::cout << "Login Berhasil" << std::endl;
        menu();
    }
    else{
        std::cout << "Login Gagal" << std::endl;
        judul();
    }
}
void register_(){
    system("cls");
    std::cout << "Register" << std::endl;
    std::cout << "Username : ";
    std::string username;
    std::cin >> username;
    std::cout << "Password : ";
    std::string password;
    std::cin >> password;
    if(cekAkun(Hash(username), Hash(password))==0){
        std::ofstream outputFile("./Function/Data/Akun.txt", std::ios::app);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening output file!" << std::endl;
        }
        outputFile << Hash(username) << " " << Hash(password) << std::endl;
        outputFile.close();
        std::cout << "Akun Berhasil" << std::endl;
        menu();
    }
    else if(cekAkun(Hash(username), Hash(password))==1){
        std::cout << "Akun Sudah Ada" << std::endl;
        judul();
    }
    else{
        std::cout << "Login Gagal" << std::endl;
        judul();
    }
}

void menu(){
    system("cls");
    int i = 0;
    std::cout << "1. Lihat Lokasi" << std::endl;
    std::cout << "2. Pemesanan" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cin >> i;
    if(i == 1){
        lihatLokasi();
    }
    else if(i == 2){
        pemesanan();
    }
    else if(i == 3){
        std::cout << "Terima Kasih" << std::endl;
    }
}
void tempatA(){
    system("cls");
    std::cout << "Tempat A" << std::endl;
    std::cout << "lokasi untuk : " << std::endl;
    std::cout << "1. mobil" << std::endl;
    std::cout << "2. motor" << std::endl;
    std::cout << "0. kembali" << std::endl;
    int i = 0;
    std::cin >> i;
    if(i == 1){
        std::ifstream inputFile("./Lokasi/tempat A/LahanMobil.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatA();
    }
    else if(i == 2){
       std::ifstream inputFile("./Lokasi/tempat A/LahanMotor.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatA();
    }
    else if(i == 0){
        menu();
    }
}
void tempatB(){
    system("cls");
    std::cout << "Tempat B" << std::endl;
    std::cout << "lokasi untuk : " << std::endl;
    std::cout << "1. mobil" << std::endl;
    std::cout << "2. motor" << std::endl;
    std::cout << "0. kembali" << std::endl;
    int i = 0;
    std::cin >> i;
    if(i == 1){
       std::ifstream inputFile("./Lokasi/tempat B/LahanMobil.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatB();
    }
    else if(i == 2){
       std::ifstream inputFile("./Lokasi/tempat B/LahanMotor.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatB();
    }
    else if(i == 0){
        menu();
    }
}
void tempatC(){
    system("cls");
    std::cout << "Tempat C" << std::endl;
    std::cout << "lokasi untuk : " << std::endl;
    std::cout << "1. mobil" << std::endl;
    std::cout << "2. motor" << std::endl;
    std::cout << "0. kembali" << std::endl;
    int i = 0;
    std::cin >> i;
    if(i == 1){
        std::ifstream inputFile("./Lokasi/tempat C/LahanMobil.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatC();
    }
    else if(i == 2){
        std::ifstream inputFile("./Lokasi/tempat C/LahanMotor.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening input file!" << std::endl;
        }
        std::vector<std::string> isiParkir;
        std::string line;
        while (std::getline(inputFile, line)) {
            isiParkir.push_back(line);
        }
        char awal = 'A';
        std::cout << std::endl;
        for(int i=0;i<isiParkir.size();i++){
            std::cout << char(awal+i) << " : ";
            for(int j=0;j<isiParkir[i].size();j++){
                std::cout<< isiParkir[i][j] << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
        system("pause");
        tempatC();
    }
    else if(i == 0){
        menu();
    }
}
void lihatLokasi(){
    system("cls");
    std::cout << "Lokasi yang tersedia" << std::endl;
    std::cout << "1. Tempat A" << std::endl;
    std::cout << "2. Tempat B" << std::endl;
    std::cout << "3. Tempat C" << std::endl;
    std::cout << "0. Menu" << std::endl;
    void (*arrayOfFunction[])(void) = {menu,tempatA,tempatB,tempatC};
    int i = 0;
    std::cin >> i;
    arrayOfFunction[i]();
}
void cekSlot(char tempat, char slot[], std::string kendaraan){
    if(tempat == 'A'){
        if(kendaraan == "mobil"){
            std::ifstream inputFile("./Lokasi/tempat A/LahanMobil.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat A/LahanMobil.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
        if(kendaraan == "motor"){
            std::ifstream inputFile("./Lokasi/tempat A/LahanMotor.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat A/LahanMotor.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
    }
    else if(tempat == 'B'){
        if(kendaraan == "mobil"){
            std::ifstream inputFile("./Lokasi/tempat B/LahanMobil.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat B/LahanMobil.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
        if(kendaraan == "motor"){
            std::ifstream inputFile("./Lokasi/tempat B/LahanMotor.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat B/LahanMotor.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
    }
    else if(tempat == 'C'){
        if(kendaraan == "mobil"){
            std::ifstream inputFile("./Lokasi/tempat C/LahanMobil.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat C/LahanMobil.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
        if(kendaraan == "motor"){
            std::ifstream inputFile("./Lokasi/tempat C/LahanMotor.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening input file!" << std::endl;
            }
            std::vector<std::string> isiParkir;
            std::string line;
            while (std::getline(inputFile, line)) {
                isiParkir.push_back(line);
            }
            int a = (slot[1]-'0')*20+(slot[2]-'0'-1)*2;
            if(isiParkir[slot[0]-'A'][a] == '0'){
                std::cout<<"Parkir tersedia" << std::endl;
                std::cout <<"Pesan ?"<< std::endl;
                std::cout <<"1. Ya" << std::endl;
                std::cout <<"2. Tidak" << std::endl;
                int i = 0;
                std::cin >> i;
                if(i == 1){
                    std::cout<<"Pemesan Berhasil" << std::endl;
                    std::cout<<"Kode Pemesananmu :"<< std::endl;
                    std::cout<<tempat<<slot[0]<<""<<slot[1]<<slot[2]<<"1800"<<std::endl;
                    std::cout<<"Terima Kasih" << std::endl;
                    isiParkir[slot[0]-'A'][a] = '1';
                    std::ofstream outputFile("./Lokasi/tempat C/LahanMotor.txt");
                    if (!outputFile.is_open()) {
                        std::cerr << "Error opening output file!" << std::endl;
                    }
                    for(int i=0;i<isiParkir.size();i++){
                        outputFile << isiParkir[i] << std::endl;
                    }
                    outputFile.close();
                }
                else if(i == 2){
                    menu();
                }
            }
            else{
                std::cout<<"Parkir tidak tersedia" << std::endl;
            }   
            inputFile.close();
        }
    }
}
void pemesanan(){
    system("cls");
    std::cout << "Pemesanan" << std::endl;
    std::cout << "1. Pemesanan mobil" << std::endl;
    std::cout << "2. Pemesanan motor" << std::endl;
    std::cout << "0. kembali" << std::endl;
    int i = 0;
    char slot[4];
    std::cin >> i;
    if(i == 1){
        std::cout << "Pemesanan mobil" << std::endl;
        std::cout << "lokasi untuk : " << std::endl;
        std::cout << "1. tempat A" << std::endl;
        std::cout << "2. tempat B" << std::endl;
        std::cout << "3. tempat C" << std::endl;
        std::cout << "0. kembali" << std::endl;
        int i = 0;
        std::cin >> i;
        if(i == 1){
            std::cout << "Pemesanan mobil di tempat A" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('A',slot,"mobil");
        }
        else if(i == 2){
            std::cout << "Pemesanan mobil di tempat B" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('B',slot,"mobil");
        }
        else if(i == 3){
            std::cout << "Pemesanan mobil di tempat C" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('C',slot,"mobil");
        }
        else if(i == 0){
            menu();
        }
    }
    else if(i == 2){
        std::cout << "Pemesanan motor" << std::endl;
        std::cout << "lokasi untuk : " << std::endl;
        std::cout << "1. tempat A" << std::endl;
        std::cout << "2. tempat B" << std::endl;
        std::cout << "3. tempat C" << std::endl;
        std::cout << "0. kembali" << std::endl;
        int i = 0;
        std::cin >> i;
        if(i == 1){
            std::cout << "Pemesanan motor di tempat A" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('A',slot,"motor");
        }
        else if(i == 2){
            std::cout << "Pemesanan motor di tempat B" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('B',slot,"motor");
        }
        else if(i == 3){
            std::cout << "Pemesanan motor di tempat C" << std::endl;
            std::cout << "Masukkan slot yang tersedia(cth:A11): ";
            std::cin.ignore();
            std::cin.get(slot,4);
            cekSlot('C',slot,"motor");
        }
        else if(i == 0){
            menu();
        }
    }
    else if(i == 0){
        menu();
    }
}
