#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void sort_text_file(const string& path)
{
    fstream file; //исходный файл
    ofstream out; //выходной файл
    string buff; //буфер для считывания строк
    vector<string> text; //вектор строк
    file.open(path.c_str());
    if (!file)
      cerr<<"error"<<endl;
    while (file>>buff) //пока считываются строки из файла,записуем их в вектор
        text.push_back(buff);
    sort(text.begin(),text.end()); //сортируем от А до Я
    out.open(path + "_sort.txt"); 
    for (auto &i : text) //записуем новые данные в выходной файл
       out<<i<<' ';
    file.close();
    out.close();
}

int main()
{
    sort_text_file("text.txt");
    return 0;
}