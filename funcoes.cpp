#include <iostream>
#include <fstream>
#include <map>
#include "header.hpp"

using namespace std;

//Struct salvando quantidade e valor do remedio colocado no carrinho de compras
struct remedioStruct
{
    int contador = 0;
    double valor = 0;
};
//Map do carrinho de compras
map<string, remedioStruct> carrinhoMap;
//Map dos medicamentos presentes no arquivo
map<string, double> medicamentos;


//Função para adicionar os remedios presentes no arquivo, no mapa
void adicionarArquivoNoMapa()
{
    ifstream file("Remedios.txt");
    string medicamento, precoString;
    double precoDouble;
    while (getline(file, medicamento))
    {
        getline(file, precoString);
        precoDouble = stod(precoString);
        medicamentos[medicamento] = precoDouble;
    }
    file.close();
}
//Função para imprimir os itens presentes no arquivo
void imprimirArquivo()
{
    for (auto i:medicamentos){
        cout << "Nome:" << i.first << "\t";
        cout << "|| Preço: " << i.second << endl;
    }    
}
//Função para verificar se o remedio está presente no arquivo
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
            cout << ">>>>> Há estoque do seu remédio <<<<<" << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << ">>>>> Não há estoque do seu remédio<<<<<" << endl;
    }
    lerArquivo.close();
}
//Função para adicionar um remedio ao map do carrinho de compras
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
//Função para calcular o valor dos itens presentes no map do carrinho de compras
void calculoCompra()
{
    double valorTotal = 0, holder;
    for (auto i : carrinhoMap)
    {
        valorTotal += carrinhoMap[i.first].valor * carrinhoMap[i.first].contador;
    }
    cout << " >>> O valor do seu carrinho é: " << valorTotal << " <<<" << endl;
}
//Função para apagar um item do map do carrinho de compras
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
//Função para imprimir os itens presentes no arquivo
void imprimirArquivoGerente()
{
    for (auto i:medicamentos){
        cout << "Nome:" << i.first << "\t";
        cout << "|| Preço: " << i.second << endl;
    }   
}
//Função para adicionar um medicamento ao map de medicamentos
void adicionarMedicamento(){
    string string;
    double valor;
    cout << "Digite o nome do medicamento" << endl;
    cin.ignore();
    getline(cin, string);
    cout << "Digite o valor do medicamento" << endl;
    cin >> valor;
    medicamentos[string] = valor;
}
//Função para atualizar o preço de um medicamento no map de medicamentos
void atualizarPreco(){
    double valor;
    string string;
    cout << "Digite o nome do medicamento que voce deseja alterar o preço: " << endl;
    cin.ignore();
    getline(cin, string);
    cout << "Digite o valor do preço novo" << endl;
    cin >> valor;
    
    for (auto i:medicamentos){
        if(i.first == string){
            medicamentos[i.first] = valor;
        }
    }
}
//Função para excluir um medicamento do map de medicamentos
void excluirMedicamento(){
    string string;
    cout <<"Digite o nome do medicamento que voce deseja excluir: " <<endl;
    cin.ignore();
    getline(cin,string);

    for (auto i:medicamentos)
    {
        if (i.first == string)
        {
            medicamentos.erase(i.first);
            break;
        }
    }
}
//Função para salvar o map medicamento, com as alterações feitas, no arquivo
void salvarMapNoArquivo(){
    ofstream arquivo;
    arquivo.open("Remedios.txt");

    for (auto i: medicamentos){
        arquivo << i.first << "\n";
        arquivo << i.second << "\n";
    }

    arquivo.close();
}