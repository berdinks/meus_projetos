include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item
{
    string nome;
    int quantidade;
    float valor;
};

vector<Item> inventario;
float valorTotal = 0.0f;

void CadastrarItem()
{
    Item item;

    cout << "Digite o nome do item: ";
    cin.ignore();
    getline(cin, item.nome);

    cout << "Digite a quantidade: ";
    cin >> item.quantidade;

    cout << "Digite o valor: ";
    cin >> item.valor;

    // Adiciona o valor total do item ao inventario
    valorTotal += item.valor * item.quantidade;

    inventario.push_back(item);

    cout << "Item cadastrado com sucesso!" << endl;
}

void ListarItens()
{
    if (inventario.empty())
    {
        cout << "O inventario esta vazio!" << endl;
        return;
    }

    for (int i = 0; i < inventario.size(); i++)
    {
        cout << "Nome: " << inventario[i].nome << endl;
        cout << "Quantidade: " << inventario[i].quantidade << endl;
        cout << "Valor: " << inventario[i].valor << endl;
        cout << "====================================" << endl;
    }
}

void UsarItem()
{
    bool itemEncontrado = false;
    string itemUsavel;

    cout << "Digite o item que deseja usar: ";
    cin.ignore();
    getline(cin, itemUsavel);

    for (int i = 0; i < inventario.size(); i++)
    {
        if (inventario[i].nome == itemUsavel)
        {
            itemEncontrado = true;

            // Retira o valor de uma unidade do valor total
            valorTotal -= inventario[i].valor;

            inventario[i].quantidade--;

            if (inventario[i].quantidade <= 0)
            {
                inventario.erase(inventario.begin() + i);
                cout << "Item usado e removido do inventario!" << endl;
            }
            else
            {
                cout << "Item usado!" << endl;
                cout << "Quantidade restante: "
                     << inventario[i].quantidade << endl;
            }

            break;
        }
    }

    if (!itemEncontrado)
    {
        cout << "Item nao encontrado!" << endl;
    }
}

void ProcurarItem()
{
    string nomeItem;
    bool itemEncontrado = false;

    cout << "Digite o item que deseja procurar: ";
    cin.ignore();
    getline(cin, nomeItem);

    for (Item item : inventario)
    {
        if (item.nome == nomeItem)
        {
            itemEncontrado = true;

            cout << "Item encontrado!" << endl;
            cout << "Nome: " << item.nome << endl;
            cout << "Quantidade: " << item.quantidade << endl;
            cout << "Valor: " << item.valor << endl;

            break;
        }
    }

    if (!itemEncontrado)
    {
        cout << "Item nao encontrado!" << endl;
    }
}

void calcularValorTotal()
{
    cout << "Valor total do inventario: R$ "
         << valorTotal << endl;
}

int main()
{
    int menu;

    while (true)
    {
        bool menuCorreto = true;

        cout << endl;
        cout << "========== Inventario ===========" << endl;
        cout << "Escolha 1 das opcoes abaixo" << endl;
        cout << "1 - Adicionar item" << endl;
        cout << "2 - Listar itens" << endl;
        cout << "3 - Procurar item" << endl;
        cout << "4 - Usar item" << endl;
        cout << "5 - Calcular valor total" << endl;
        cout << "Escolha apenas 1: ";

        cin >> menu;

        if (
            menu != 1 &&
            menu != 2 &&
            menu != 3 &&
            menu != 4 &&
            menu != 5
        )
        {
            menuCorreto = false;
            cout << "Escolha apenas as opcoes numeradas acima!!!" << endl;
        }

        if (menuCorreto == true)
        {
            switch (menu)
            {
                case 1:
                    CadastrarItem();
                    break;

                case 2:
                    ListarItens();
                    break;

                case 3:
                    ProcurarItem();
                    break;

                case 4:
                    UsarItem();
                    break;

                case 5:
                    calcularValorTotal();
                    break;
            }
        }
    }

    return 0;
}
