// OrelCodesChallenge.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
int currentS;
int currentL;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream server;
    ifstream local;
    ofstream output;
    ofstream missing;
    server.open("input_server.txt");
    local.open("input_local.txt");
    output.open("output_result.txt");
    missing.open("output_missing.txt");
    server >> currentS;
    local >> currentL;
    while (currentL < currentS)
    {
        output << currentL << ' ';
        local >> currentL;
    }
    output << currentS << ' ';
    if (currentL == currentS)
        local >> currentL;
    while (server >> currentS)
    {
        output << currentS << ' ';
        if (currentL == currentS)
        {
            local >> currentL;
        }
        else
        {
            missing << currentS << ' ';
        }
    }
    server.close();
    local.close();
    output.close();
    missing.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
