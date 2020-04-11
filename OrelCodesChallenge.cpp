#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>  
using namespace std;
using namespace chrono;
#define ll long long
int currentS;
int currentL;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char str[10];
    auto start = system_clock::now();
    FILE *server;
    FILE *local;
    FILE *output;
    FILE *missing;
    server = fopen("input_server.txt", "rb");
    local = fopen("input_local.txt", "rb");
    output = fopen("output_result.txt", "wb");
    missing = fopen("output_missing.txt", "wb");
    fscanf(local, "%d ", &currentL);
    fscanf(server, "%d ", &currentS);
    //server >> currentS;
    //local >> currentL;
    while (currentL < currentS)
    {
        _fwrite_nolock(&str, sprintf(str, "%d ", currentL), 1, output);
        fscanf(local, "%d ", &currentL);
        //local >> currentL;
    }
    _fwrite_nolock(&str, sprintf(str, "%d ", currentS), 1, output);
    if (currentL == currentS)
        fscanf(local, "%d ", &currentL);
        //local >> currentL;
    while (!feof(server))
    {
        fscanf(server, "%d ", &currentS);
        _fwrite_nolock(&str, sprintf(str, "%d ", currentS), 1, output);
        if (currentL == currentS)
        {
            //local >> currentL;
            if (!feof(local))
                fscanf(local, "%d ", &currentL);
            else
                currentL = 0;
        }
        else
        {
            _fwrite_nolock(&str, sprintf(str, "%d ", currentS), 1, missing);
        }
    }
    fclose(output);
    fclose(missing);
    fclose(server);
    fclose(local);
    auto end = system_clock::now();
    duration<double> span = end - start;
    cout << "Total: " << span.count() << "s\n";
}