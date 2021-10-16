#include <iostream>
#include <stdio.h>

int main()
{
    FILE* txt1, * txtP, * txt2;
    char strtxt[80];
    if (!(txt1 = fopen("p12.txt", "r"))) { //Проверяем наличие и работу файла.
        printf("Файл 1 не открывается.");
        return 0;
    }
    if (!(txtP = fopen("P.txt", "w"))) {
        printf("Файл не открывается.");
        return 0;
    }
    if (!(txt2 = fopen("p21.txt", "r"))) {
        printf("Файл 2 не открывается.");
        return 0;
    }
    while (fgets(strtxt, 80, txt1)) //Считываем символы из txt1 и записываем их в strtxt.
        fputs(strtxt, txtP); //Записываем strtxtx в txtP.
    fclose(txt1);
    fclose(txtP);
    txt1 = fopen("p12.txt", "w");
    while (fgets(strtxt, 80, txt2)) //Считываем символы из txt2 и записываем их в strtxt.
        fputs(strtxt, txt1); //Записываем strtxtx в txt1.
    fclose(txt1);
    fclose(txt2);
    txtP = fopen("P.txt", "r");
    txt2 = fopen("p21.txt", "w");
    while (fgets(strtxt, 80, txtP)) //Считываем символы из txtP и записываем их в strtxt.
        fputs(strtxt, txt2); //Записываем strtxtx в txt2.
    fclose(txtP);
    fclose(txt2);
    printf("Конец.");
    return 0;
}
