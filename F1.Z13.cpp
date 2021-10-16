#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "rus");

    FILE* txt;
    char strtxt[80];
    int i = 0, max = 0, maxLen = 0;
    if (!(txt = fopen("p13.txt", "r+"))) { //Проверяем работу и наличие файла.
        printf("Файл не открывается.");
        return 0;
    }
    while (fgets(strtxt, 80, txt)) { //Считываем сиволы из txt и записываем их в strtxt.
        if (strlen(strtxt) > maxLen) { //Сравниваем длину данной строки с максимальной.
            maxLen = strlen(strtxt); //Если данная строка больше максимальной.
            max = i + 1; //Определяем номер максимальной строки.
        }
        i++;
    }
    printf("Самая длинная строка: %d", max);
    fclose(txt);
    return 0;
}
