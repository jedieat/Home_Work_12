#include <string>
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256  



//Алгоритм Бойера-Мура поиска подстроки
//Первый этап -таблица смещений (Б-М)
void badCharHeuristic(string str, int size,
    int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1; //Вначале каждому символу присваивается - 1

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i; //Далее заполняем и присваиваем каждому символу индекс последнего вхождения символа в подстроку.
}

//Алгоритм Бойера-Мура поиска подстроки
//Второй этап. Поиск подстроки функция фиксирует что подстрока найдена и указывает номер номер i массива строки с которой начинается найденная подстрока.
int search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];
    int counter=0;

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m)) 
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j]) //Начинаем с позиций 0 для строки s = 0 и с последнего символа подстроки int j = m - 1. Далее мы сравниваем символы строки и подстроки справа налево :
            j--;

        if (j < 0) //Если j меньше нуля, значит мы дошли до конца подстроки и нашли подстроку, поэтому мы сразу перемещаем индекс строки :
        {
            cout << "pattern occurs at shift = " << s << endl;
            if (s % m == 0 || s == 0)
            {
                counter++;
            }

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

        }
        else
        {
            int bc = badchar[txt[s + j]];
            s += max(1, j - bc);
        }
    }

    return counter;
}

//Функция, которая проверяет, является ли строка кратной числу Kr.
bool IsKPeriodic(string txt, int Kr)
{
    int coun; //Количество вхождений подстроки в строку.
    string pat = txt.substr(0, Kr); //С посмощью функции substr выделяем подстроку заданной кратности (Это подстрока)
    int n = txt.size(); //Количество символов в строке
    coun = search(txt, pat); //Ищем количество подстрок в строке (если строка не найдена количество будет 1)

    if (n / Kr == coun && n % Kr == 0) //Если поделить суммарное количество симоволов на количиство найденных подстрок, то должна получится кратность.
    {
        cout << "Строка кратна заданному числу";
        return true;
    }

        cout << "Строка не кратна заданному числу";
        return false;

}

int main() {
    setlocale(LC_ALL, ""); // или system("chcp 1251") меняем кракозябры на русский; 
    string text; //заданная строка
    int K; //заданная кратность
      
    cout << "Введите строку"<< endl; 
    cin >> text;
    cout << "Число K" << endl;
    cin >> K;
    bool pr = IsKPeriodic(text, K);


    
    
    return 0;
}