#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "rus");

    FILE* txt1, * txt2, * txt3; 
    FILE* txtB = nullptr; //Нулевой указатель типа FILE.
    FILE* txtM = nullptr;
    char strtxt[80], str1[80], str2[80], str3[80];
    int count1 = 0, count2 = 0, count3 = 0;
    printf("Имя 1-го файла:\n");
    gets_s(str1); //Присваиваем переменной файл.
    printf("Имя 2-го файла:\n");
    gets_s(str2);
    printf("Имя 3-го файла:\n");
    gets_s(str3);
    if (!(txt1 = fopen(str1, "r"))) { //Проверяем наличие и работу файла.
        printf("Файл 1 не открывается.");
        return 0;
    }
    if (!(txt2 = fopen(str2, "r"))) {
        printf("Файл 2 не открывается.");
        return 0;
    }
    if (!(txt3 = fopen(str3, "r"))) {
        printf("Файл 3 не открывается.");
        return 0;
    }

    while (fgetc(txt1) != EOF) //Проходит весь файл.
        count1++; //Считает количество символов.
    while (fgetc(txt2) != EOF)
        count2++;
    while (fgetc(txt3) != EOF)
        count3++;
    fclose(txt1);
    fclose(txt2);
    fclose(txt3);
    if (count1 < count2 && count1 < count3) { //Находим самый короткий файл.
        txtB = fopen(str1, "r");
        if (count2 < count3) //Находим самый длинный файл.
            txtM = fopen(str3, "w");
        else
            txtM = fopen(str2, "w");
    }
    else if (count2 < count1 && count2 < count3) {
        txtB = fopen(str2, "r");
        if (count1 < count3)
            txtM = fopen(str3, "w");
        else
            txtM = fopen(str1, "w");
    }
    else if (count3 < count1 && count3 < count2) {
        txtB = fopen(str3, "r");
        if (count1 < count2)
            txtM = fopen(str2, "w");
        else
            txtM = fopen(str1, "w");
    }
    while (fgets(strtxt, 80, txtB)) //Считываем сиволы из txtB и сохраняем их в strtxt.
        fputs(strtxt, txtM); //Записываем в файл txtM strtxt.
    fclose(txtB);
    fclose(txtM);
    printf("Конец.");
    return 0;
}
