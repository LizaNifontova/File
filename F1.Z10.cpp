#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "rus");

    FILE* txt;
    char strtxt[80];
    int count = 0;
    if (!(txt = fopen("p10.txt", "r+"))) { //Проверяем наличие файла.
        printf("Файл не открывается");
        return 0;
    }
    while (fgets(strtxt, 80, txt)) //Пока не пройдёт все строки.
        if (strtxt[0] == strtxt[strlen(strtxt) - 2]) //Сравниваем первый и последний символ.
            count++; //Считаем количество строк.
    printf("Количество строк: %d", count);
    fclose(txt);
    return 0;
}
