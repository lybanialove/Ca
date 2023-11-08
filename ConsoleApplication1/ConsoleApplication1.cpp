#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char* function(char* destination, const char* sourseOne, const char* sourseTwo)
{
    int i = 0;
    int j;
    int o = 0;
    while (sourseOne[i] != '\0')
    {
        j = 0;
        while (sourseTwo[j] != '\0')
        {
            if (sourseOne[i] == sourseTwo[j])
            {
                destination[o] = sourseOne[i];
                o++;
            }
            j++;
        }
        i++;
    }
    return destination;
}

int Str_lenght( const char* sourseOne, const char* sourseTwo)
{
    int i = 0;
    int j;
    int o = 0;
    while (sourseOne[i] != '\0')
    {
        j = 0;
        while (sourseTwo[j] != '\0')
        {
            if (sourseOne[i] == sourseTwo[j])
            {
                o++;
            }
            j++;
        }
        i++;
    }
    return o;
}
int main()
{
    setlocale(LC_ALL, "rus");
    FILE* result = fopen("result.txt", "w");
    FILE* in = fopen("input.txt", "r"); //файл находится в папке main (папка main находится в папке с проектом)
    //  параметр "r", то есть reed - позволит нам только считать информацию.
    if (in == NULL)                     //если in(файл) равен NULL,значит он не может открыться.Либо путь не тот.
    {
        cout << "Ошибка в открытии файла input.txt" << endl;
    }
    else
    {
        try 
        {
            int iteration = 1;
            int sizeFirstSourse, sizeSecondSourse;
            while (!feof(in))
            {
                fscanf(in, "%d %d", &sizeFirstSourse, &sizeSecondSourse);
                cout << sizeFirstSourse << " " << sizeSecondSourse << endl;
                const char* firstSourse(new char[sizeFirstSourse]);
                const char* secondSourse(new char[sizeSecondSourse]);
                fscanf(in, "%s %s", firstSourse, secondSourse);
                cout << firstSourse << " " << secondSourse << endl;
                int i = Str_lenght(firstSourse, secondSourse) + 1;
                char* a = new char[i];
                a[i - 1] = '\0';
                fprintf(result, "result for %d iteration: %s\n", iteration, function(a, firstSourse, secondSourse));
                cout << endl << endl << a << endl << endl;
                delete firstSourse, secondSourse, a;
                iteration++;
            }
            fclose(result);
            fclose(in);         //закрываем открытые файлы.
        }
        catch(...)
        {
            cout << "Список тестовых данных пуст!";
        }
    }
}