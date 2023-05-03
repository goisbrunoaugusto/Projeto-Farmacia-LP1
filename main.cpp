#include <iostream>
#include <fstream>
#include <map>
#include "header.hpp"

using namespace std;

int main()
{
    int perfilId;
    string admin = "admin";

    adicionarArquivoNoMapa();

    // Seleção do perfil a ser utilizado
    cout << "Qual perfil deseja usar?" << endl;
    cout << "1 -- Cliente" << endl;
    cout << "2 -- Gerente" << endl;
    cin >> perfilId;

    // Funcionalidades do perfil do Cliente
    if (perfilId == 1)
    {
        while (true)
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
            else if (funcaoID == 2)
            {
                verificarRemedio();
            }
            // Funcao 3
            else if (funcaoID == 3)
            {
                selecionarRemedio();
            }
            // Funcao 4
            else if (funcaoID == 4)
            {
                calculoCompra();
            }
            // Funcao 5
            else if (funcaoID == 5)
            {
                apagar();
            }
            else if (funcaoID == 6)
            {
                salvarMapNoArquivo();
                break;
            }
            else
            {
                salvarMapNoArquivo();
                cout << "Opção inválida.";
                break;
            }
        }
    }
    // Funcionalidade do perfil do Gerente
    else if (perfilId == 2)
    {
        string string;
        // Requisição de senha
        cout << "Digite a senha: " << endl;
        cin.ignore();
        getline(cin, string);
        // Se a senha for a certa
        if (string == admin)
        {

            while (true)
            {
                int funcaoID;
                // Seleçao da funcionalidade desejada
                cout << "Digite o Id da função desejada: " << endl;
                cout << "1-- Listar todos os remédios cadastrados e seus respectivos preços " << endl;
                cout << "2-- Buscar um remédio por nome" << endl;
                cout << "3-- Adicionar um novo medicamento" << endl;
                cout << "4-- Atualizar o preço de um determinado remédio" << endl;
                cout << "5-- Excluir um remédio (buscando pelo nome) " << endl;
                cout << "6-- Para sair" << endl;
                cin >> funcaoID;
                // Funcao 1
                if (funcaoID == 1)
                {
                    imprimirArquivoGerente();
                }
                // Funcao 2
                else if (funcaoID == 2)
                {
                    verificarRemedio();
                }
                // Funcao 3
                else if (funcaoID == 3)
                {
                    adicionarMedicamento();
                }
                // Funcao 4
                else if (funcaoID == 4)
                {
                    atualizarPreco();
                }
                // Funcao 5
                else if (funcaoID == 5)
                {
                    excluirMedicamento();
                }
                // Funcao 6
                else if (funcaoID == 6)
                {
                    salvarMapNoArquivo();
                    break;
                }
                else
                {
                    salvarMapNoArquivo();
                    cout << "Opção inválida.";
                    break;
                }
            }
        }
        // Se a senha não for certa
        else
        {
            cout << "Senha errada!" << endl;
        }
    }
    // Caso seja digitado um numero de perfil diferente
    else
    {
        cout << "Perfil invalido" << endl;
    }

    return 0;
}