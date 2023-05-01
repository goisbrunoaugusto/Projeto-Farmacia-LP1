#include <iostream>
#include <fstream>
#include <map>
#include "headerCliente.hpp"

using namespace std;

struct remedioStruct
{
    int contador = 0;
    double valor = 0;
};

map<string, remedioStruct> carrinhoMap;

map<string, double> medicamentos;

void inicializarArquivo()
{
    ofstream arquivo;
    arquivo.open("Remedios.txt");
    arquivo << "Ibuprofeno" << endl;
    arquivo << "10.85" << endl;
    arquivo << "Dorflex" << endl;
    arquivo << "13.33" << endl;
    arquivo << "Buscopan" << endl;
    arquivo << "15.71" << endl;
    arquivo << "Rivotril" << endl;
    arquivo << "79.90" << endl;
    arquivo << "Amoxilina" << endl;
    arquivo << "71.85" << endl;
    arquivo.close();
}

void adicionarArquivoNoMapa()
{
    ifstream file("Remedios.txt");
    string medicamento, preco;
    double precoD;
    while (getline(file, medicamento))
    {
        getline(file, preco);
        precoD = stod(preco);
        medicamentos[medicamento] = precoD;
    }
    file.close();
}

void imprimirArquivo()
{
    string linha;
    ifstream lerArquivo;
    lerArquivo.open("Remedios.txt");

    while (getline(lerArquivo, linha))
    {
        cout << linha << endl;
        getline(lerArquivo, linha);
    }
    lerArquivo.close();
}
void verificarRemedio()
{
    ifstream lerArquivo;
    lerArquivo.open("Remedios.txt");
    string nomeRemedio;
    string linha;
    int c = 0;

    cout << "Digite o nome do medicamento: " << endl;
    cin.ignore();
    getline(cin, nomeRemedio);

    while (getline(lerArquivo, linha))
    {
        if (nomeRemedio.compare(linha) == 0)
        {
            cout << "Seu remedio esta na lista" << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "Seu remedio nao esta na lista" << endl;
    }
    lerArquivo.close();
}
void selecionarRemedio()
{
    string itemCarrinho;
    int qntd;
    cout << "Digite o nome do medicamento que deseja adicionar ao carrinho: " << endl;
    cin.ignore();
    getline(cin, itemCarrinho);
    cout << "Digite a quantidade do medicamento que deseja adicionar ao carrinho: " << endl;
    cin >> qntd;
    for (auto i : medicamentos)
    {
        if (itemCarrinho == i.first)
        {
            carrinhoMap[i.first].valor = i.second;
            carrinhoMap[i.first].contador += qntd;
        }
    }
}
void calculoCompra()
{
    double valorTotal = 0, holder;
    for (auto i : carrinhoMap)
    {
        valorTotal += carrinhoMap[i.first].valor * carrinhoMap[i.first].contador;
    }
    cout << " >>> O valor do seu carrinho é: " << valorTotal << " <<<" << endl;
}
void apagar()
{
    string deletar;
    cout << "Digite o nome do medicamento que voce deseja remover do carrinho: " << endl;
    cin.ignore();
    getline(cin, deletar);
    for (auto i : carrinhoMap)
    {
        if (i.first == deletar)
        {
            carrinhoMap.erase(i.first);
            break;
        }
    }
}