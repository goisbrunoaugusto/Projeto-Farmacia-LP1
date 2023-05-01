#include <iostream>
#include <map>
#include <fstream>


using namespace std;


int main (){
    map<string, float> medicamento;
    ofstream file;
    file.open("teste.txt");

    medicamento["ibuprofeno"] =27.5;
    medicamento["avamys"] = 40;
    medicamento["dipirona"] =20;
    medicamento["antiinflamatorio"] = 55.5;
    
    for (auto i:medicamento){
        file << i.first << " " << i.second << endl;
    }

    file.close();
    return 0;
}