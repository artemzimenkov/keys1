#include <iostream>
#include <string>

using namespace std;

string bin(int chislo, string stroka){
    char digit;                        //char - simvol
    int i = stroka.size() -1;      //schitaem skolko simvolov v stroke
    while (i >= 0 && chislo > 0) {
        digit = chislo % 2 + '0';       // prevrashaem simvol v stroku
        stroka[i] = digit;             //((((perevod v bin))))
        i--;                           // i-- potomu chto idem s konca
        chislo /= 2;
    }
    return stroka;
}

string obratniy(string stroka){
    int a = stroka.size() -1;             //schitaem skolko simvolov v stroke
    for (int i = 1; i <= a; i++){
        if (stroka[i] == '1') {            //esli 1 to menyaem na 0
            stroka[i] = '0';
        }
        else {
            stroka[i] = '1';
        }
    }
    return stroka;
}

int dopolnit(string stroka){
    int a = 1, b = 0;
    char digit;              //char - simvol
    int i = stroka.size() -1;          //schitaem skolko simvolov v stroke
    while (i >= 0) {
        digit = stroka[i] - '0';        //perevodim v int
        b += digit * a;
        a *= 2;                     //stepen dvoyki 1 2 4 8
        i--;
    }
    b++;
    return b;
}

string dopolnit2(int b, string st){
    char digit;               //char - simvol
    int i = st.size() -1;                //schitaem skolko simvolov v stroke
    while (i >= 0 && b > 0) {
        digit = b % 2 + '0';
        st[i] = digit;
        i--;
        b = b / 2;
    }
    return st;
}



int main()
{
    int ch, tip, bit, b;
    bool znak = false;
    cin >> ch >> bit >> tip;
    if (ch < 0)
    {
        if (ch < 0)
        {
            ch = ch * -1;
            znak = true;
        }
        string st(bit, '0');
        st = dvoichka(ch, st);
        if (znak)
        {
            st[0] = '1';
        }
        if (tip == 1)
        cout << dvoichka(ch, st) << endl;
        if (tip == 2)
        cout << zamen(st) << endl;
        if (tip == 3){
        string dv(bit, '0');
        dv = dvoichka(ch, st);
        st = zamen(st);
        b = dop(st);
        cout << dop1(b, dv);
        }
    }
    else
    {
        string st(bit, '0');
        st = dvoichka(ch, st);
        cout << dvoichka(ch, st);
    }
}
