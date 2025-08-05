#include <string>
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256  



//�������� ������-���� ������ ���������
//������ ���� -������� �������� (�-�)
void badCharHeuristic(string str, int size,
    int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1; //������� ������� ������� ������������� - 1

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i; //����� ��������� � ����������� ������� ������� ������ ���������� ��������� ������� � ���������.
}

//�������� ������-���� ������ ���������
//������ ����. ����� ��������� ������� ��������� ��� ��������� ������� � ��������� ����� ����� i ������� ������ � ������� ���������� ��������� ���������.
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

        while (j >= 0 && pat[j] == txt[s + j]) //�������� � ������� 0 ��� ������ s = 0 � � ���������� ������� ��������� int j = m - 1. ����� �� ���������� ������� ������ � ��������� ������ ������ :
            j--;

        if (j < 0) //���� j ������ ����, ������ �� ����� �� ����� ��������� � ����� ���������, ������� �� ����� ���������� ������ ������ :
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

//�������, ������� ���������, �������� �� ������ ������� ����� Kr.
bool IsKPeriodic(string txt, int Kr)
{
    int coun; //���������� ��������� ��������� � ������.
    string pat = txt.substr(0, Kr); //� �������� ������� substr �������� ��������� �������� ��������� (��� ���������)
    int n = txt.size(); //���������� �������� � ������
    coun = search(txt, pat); //���� ���������� �������� � ������ (���� ������ �� ������� ���������� ����� 1)

    if (n / Kr == coun && n % Kr == 0) //���� �������� ��������� ���������� ��������� �� ���������� ��������� ��������, �� ������ ��������� ���������.
    {
        cout << "������ ������ ��������� �����";
        return true;
    }

        cout << "������ �� ������ ��������� �����";
        return false;

}

int main() {
    setlocale(LC_ALL, ""); // ��� system("chcp 1251") ������ ���������� �� �������; 
    string text; //�������� ������
    int K; //�������� ���������
      
    cout << "������� ������"<< endl; 
    cin >> text;
    cout << "����� K" << endl;
    cin >> K;
    bool pr = IsKPeriodic(text, K);


    
    
    return 0;
}