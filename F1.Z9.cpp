#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    FILE* txt1;
    FILE* txt2 = fopen("p.txt", "wt");
    ifstream inp("p9.txt");

    if (!(txt1 = fopen("p9.txt", "r+"))) { //Проверяем наличие файла.
        printf("Файл не открывается.");
        return 0;
    }
    while (inp.peek() != EOF) { //Проходит через каждый символ в файле.

        int t;
        inp >> t; //Значение симвала в файле  присваивается переменной t.

        if (t > 0 || t == 0) { //Если t больше 0 или равно ему, то просто записываем значение в файл.
            fprintf(txt2, "%d \n ", t);
        }

        if (t < 0) { //Если t меньше нуля, то присваиваем t значение 0 и записываем в файл.
            t = 0;
            fprintf(txt2, "%d \n ", t);
        }
    }

    return 0;
}
