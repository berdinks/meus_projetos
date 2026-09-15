#include <iostream>
#include <vector>
#include <string>
using namespace std;



void cadastrar(vector<string>& nomes)
{
    string desejo;

    while (true)
    {
        string nome;

        cout << "Diga seu nome: ";
        cin.ignore(1000, '\n');
        getline(cin, nome);

        nomes.push_back(nome);

        cout << "Quer continuar? s/n: ";
        cin >> desejo;

        if (desejo == "n" || desejo == "N")
        {
            break;
        }
    }
}



void verLista(vector<string>& nomes)
{
    cout << "----------------" << endl;
    cout << "Pessoas cadastradas: " << nomes.size() << endl;

    for (int i = 0; i < nomes.size(); i++)
    {
        cout << i + 1 << " - " << nomes[i] << endl;
    }

    cout << "----------------" << endl;
}



void pesquisar(vector<string>& nomes)
{
    string pesquisa;
    bool encontrado = false;

    cout << "Digite o nome que deseja pesquisar: ";
    cin.ignore(1000, '\n');
    getline(cin, pesquisa);

    for (string nome : nomes)
    {
        if (nome == pesquisa)
        {
            encontrado = true;
            break;
        }
    }

    if (encontrado)
    {
        cout << "Nome encontrado!" << endl;
    }
    else
    {
        cout << "Nome nao encontrado!" << endl;
    }
}



void remover(vector<string>& nomes)
{
    string alvo;
    bool alvoEncontrado = false;

    cout << "Digite o nome que deseja remover: ";
    cin.ignore(1000, '\n');
    getline(cin, alvo);

    for (int i = 0; i < nomes.size(); i++)
    {
        if (nomes[i] == alvo)
        {
            nomes.erase(nomes.begin() + i);

            alvoEncontrado = true;

            break;
        }
    }

    if (alvoEncontrado)
    {
        cout << "Nome removido!" << endl;
    }
    else
    {
        cout << "Usuario nao encontrado!" << endl;
    }
}


int main()
{
    int escolha;
    vector<string> nomes;

    while (true)
    {
        cout << endl;
        cout << "SISTEMA DE CADASTRO" << endl;
        cout << "-------------------" << endl;

        cout << "Escolha uma das opcoes abaixo:" << endl;
        cout << "1 - CADASTRAR" << endl;
        cout << "2 - VER LISTA" << endl;
        cout << "3 - PESQUISAR" << endl;
        cout << "4 - REMOVER" << endl;
        cout << "5 - SAIR" << endl;

        cout << "Sua escolha: ";
        cin >> escolha;


        
        if (escolha != 1 &&
            escolha != 2 &&
            escolha != 3 &&
            escolha != 4 &&
            escolha != 5)
        {
            cout << "Escolha apenas as opcoes listadas!" << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }


        switch (escolha)
        {
            case 1:
                cadastrar(nomes);
                break;

            case 2:
                verLista(nomes);
                break;

            case 3:
                pesquisar(nomes);
                break;

            case 4:
                remover(nomes);
                break;

            case 5:
                cout << "Saindo..." << endl;
                return 0;
        }
    }
}
