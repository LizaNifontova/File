#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* txt;
    char strtxt[100][100], d[1];
    int i, j, k, count = 0, len, max = 0;

    if (!(txt = fopen("p3.txt", "r"))) { //Проверяем открывается ли файл.
        printf("Error opening file!");
        return 0;
    }

    while (fgets(strtxt[count], 100, txt)) count++; //Считаем количество строк в файле.

    txt = fopen("p3.txt", "w");

    for (k = 0; k < count; k++)  //Пока не for не пройдёт все строки.
    {
        len = strlen(strtxt[k]) - 1; //Без -1 появляется пробел, с -2 удаляется первый символ.

        for (i = 0; i < len; i++) //Пока не пройдёт все символы в строке.
        {
            for (j = 0; j < len - i; j++)

                if ((int)strtxt[k][j] > (int)strtxt[k][max]) //Если max значение меньше j, то присваиваем max значение j.
                    max = j; //Находим максимальное значение.

            d[0] = strtxt[k][max];
            strtxt[k][max] = strtxt[k][len - i - 1];
            strtxt[k][len - i - 1] = d[0];
            max = 0; //Сортируем "массив" символов в строке по возростанию.
        }
        fputs(strtxt[k], txt); //Записываем ответ.
    }
    printf("OK!");
    fclose(txt);
    return 0;
}
