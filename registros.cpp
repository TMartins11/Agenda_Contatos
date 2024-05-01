/* 
 * File:   Registros (Struct) - Variável Composta Heterogênea
 * 
 * Projeto para armazenar informações em registors de dados.
 * 
 * (typdef) => declaração de tipo (Não aloca memória até declarada no main)
 * 
 * As operações podem ser realizadas pelo usuário quantas vezes forem necessárias e devem ser:
 *  1- Busca pelo nome do amigo;
 *  2- Excluir um amigo;
 *  3- Inserir um amigo.
 * 
 *
 * Created on 29 de abril de 2024, 16:09
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int TAM = 1000;

typedef struct{
    bool valido = true;
    string nome;
    string celular;
    string cidade;
    string email;
} Pessoa; //Padrão que a struct seja nomeada com inicial Maiúscula

int main(){
    Pessoa agenda[TAM];
    int qtd = 0, contatos = 0, opcao = 0, i = 0, excluir = 0;
    
    //Abrir arquivo que fornecerá os dados iniciais da agenda
    ifstream arquivo("bancodedados.txt");
    if(!arquivo.is_open()){
        cout << endl << "Erro, arquivo não existe";
        return 1;
    }
    
    arquivo >> agenda[qtd].nome;
     
    //Gerar Lista inicial de contatos
    while(agenda[qtd].nome != "FIM"){
        arquivo >> agenda[qtd].celular;
        arquivo >> agenda[qtd].cidade;
        arquivo >> agenda[qtd].email;
        contatos++;
        qtd++;
        arquivo >> agenda[qtd].nome;
    }
    
    //Menu que fornece ao usuário as opções do programa, juntamente com uma repetição que impede a inserção de opções inválidas
    cout << "Agenda de Contatos" << endl;
    cout << endl << "Opções disponíveis:" << endl << "1 - Exibir Agenda" << endl << "2 - Adicionar Contato" << endl << "3 - Excluir Contato";
    cout << endl << "4 - Alterar contato" << endl << "5 - Buscar Contato" << endl << "6 - Sair" << endl;
    cout << endl << "Escolha a opção desejada: ";
    cin >> opcao;
    while(opcao > 6 || opcao <= 0){
        cout << endl << "Opção inválida! Insira novamente: ";
        cin >> opcao;
    }
    
    //Loop com switch case para que o usuário possa acessar todas as opções do programa e sair conforme sua vontade
    while(opcao != 6){
        switch(opcao){
            case 1:
                for( i = 0; i < contatos;i++){
                    if(agenda[i].valido == true){
                        cout << endl << i + 1 << "- Nome:" << agenda[i].nome;
                        cout << endl << "Telefone:" << agenda[i].celular;
                        cout << endl << "Cidade onde mora:" << agenda[i].cidade;
                        cout << endl << "Email:" << agenda[i].email;
                        cout << endl;
                    }
                }
                
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 6 || opcao < 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;     
            case 2:
                cout << endl << "Insira o nome do contato: ";
                cin >> agenda[qtd].nome;
                cout << endl << "Telefone: ";
                cin >> agenda[qtd].celular;
                cout << endl << "Cidade onde mora: ";
                cin >> agenda[qtd].cidade;
                cout << endl << "Email: ";
                cin >> agenda[qtd].email;
                contatos++;
                qtd++;
                
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 6 || opcao < 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;  
            case 3:
                cout << endl << "Insira o contato que deseja excluir: ";
                cin >> excluir;
                excluir -= 1;
                
                agenda[excluir].valido = false;
                
                cout << endl << "Escolha a opção desejada: ";
                cin >> opcao;
                while(opcao > 6 || opcao < 0){
                    cout << endl << "Opção inválida! Insira novamente: ";
                    cin >> opcao;
                }
                break;
                
        }
    }
         
    return 0;
}