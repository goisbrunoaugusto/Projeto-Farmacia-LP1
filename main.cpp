#include <iostream>
#include <fstream>
#include <map>
#include "headerCliente.hpp"
#include "headerGerente.hpp"

using namespace std;

int main()
{
    int perfilId;

    ifstream lerArquivo;
    inicializarArquivo();
    adicionarArquivoNoMapa();

    lerArquivo.open("Remedios.txt");

    // Seleção do perfil a ser utilizado
    cout << "Qual perfil deseja usar?" << endl;
    cout << "1 -- Cliente" << endl;
    cout << "2 -- Gerente" << endl;
    cin >> perfilId;

    // Funcionalidades do perfil do Cliente
    if (perfilId == 1)
    {
        while(true)
        {
            int funcaoID;
            // Seleçao da funcionalidade desejada
            cout << "Digite o Id da função desejada: " << endl;
            cout << "1-- Listar todos os medicamentos cadastrados " << endl;
            cout << "2-- Buscar um remédio por nome" << endl;
            cout << "3-- Selecionar um remédio para comprá-lo" << endl;
            cout << "4-- Calcular o valor da compra" << endl;
            cout << "5-- Excluir um medicamento do carrinho " << endl;
            cout << "6-- Para sair" << endl;
            cin >> funcaoID;

            // Funcao 1
            if (funcaoID == 1)
            {
                imprimirArquivo();
            }

            // Funcao 2
            if (funcaoID == 2)
            {
                verificarRemedio();
            }
            // Funcao 3
            if (funcaoID == 3)
            {
                selecionarRemedio();
            }
            // Funcao 4
            if (funcaoID == 4)
            {
                calculoCompra();
            }
            // Funcao 5
            if (funcaoID == 5)
            {
                apagar();
            }
            if (funcaoID == 6)
            {
                break;
            }
        }
    }
    // Funcionalidade do perfil do Gerente
    else if (perfilId == 2)
    {
    }
    else
    {
        cout << "Perfil invalido" << endl;
    }

    return 0;
}