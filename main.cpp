#include <iostream>
#include <fstream>
using namespace std;

string powrot; //zmienna globalna do czyszczenia ekranu po wykonaniu opcji

int czyPoprawnaOpcja(string opcja)
{

    int opcjaInt;

    if (opcja.length() > 1)
    {
        opcjaInt = 0;
        cout << "nie poprawna opcja, wpisz ponownie:";
    }
    else
    {
        char znak = opcja[0];
        if (znak <= '5' && znak > '0')
        {
            opcjaInt = znak - 48;
        }
        else
        {
            opcjaInt = 0;
            cout << "nie poprawna opcja, wpisz ponownie:";
        }
    }
    return opcjaInt;
}
void wyswietlJednostki()
{
    fstream plik;
    string linia;

    plik.open("jednostki.txt");

    cout << endl
         << "Oto twoje dostepne jednostki:" << endl
         << endl;

    while (!plik.eof())
    {
        plik >> linia;
        cout << "   " << linia << endl;
    }
    cout << endl;
    plik.close();

    cout << "Wpisz jakikolwiek znak aby wrocic: ";
    cin >> powrot;
    system("cls");
}
void dodajJednostke()
{
    fstream plik;
    ofstream zapis;
    string linia;
    string jednostka;
    bool czyJestJuzTakaJednostka = false;
    cout << "Wpisz nazwe jednostki:";
    cin >> jednostka;

    plik.open("jednostki.txt");
    zapis.open("jednostki.txt", ios_base::app);

    while (!plik.eof())
    {
        plik >> linia;
        if (linia == jednostka)
        {
            czyJestJuzTakaJednostka = true;
            break;
        }
    }
    if (czyJestJuzTakaJednostka)
    {
        cout << endl
             << "Taka jednostka zostala juz zapisana wczesniej" << endl
             << endl;
    }
    else
    {
        zapis << endl
              << jednostka;
        cout << "Jednostka dodana!" << endl
             << endl;
    }

    plik.close();
    zapis.close();

    cout << "Wpisz jakikolwiek znak aby wrocic: ";
    cin >> powrot;
    system("cls");
}
void edytujJednostke()
{
    string jednostka;
    string nowaJednostka;
    fstream plik;
    ofstream zapis;
    string linia;
    int licznik = 0;

    cout << "Podaj nazwe jednostki: ";
    cin >> jednostka;

    system("cls");

    cout << "Podaj nowa nazwe jednostki: ";
    cin >> nowaJednostka;

    plik.open("jednostki.txt", ios::in);
    zapis.open("jednostkiPomoc.txt");

    while (!plik.eof())
    {

        plik >> linia;
        if (linia != jednostka)
        {
            zapis << endl
                  << linia;
        }
        else
        {
            zapis << endl
                  << nowaJednostka;
            licznik++;
        }
    }
    cout << endl;
    plik.close();
    zapis.close();

    plik.open("jednostkiPomoc.txt", ios::in);
    zapis.open("jednostki.txt");

    while (!plik.eof())
    {

        plik >> linia;
        zapis << endl
              << linia;
    }

    plik.close();
    zapis.close();

    if (licznik > 0)
    {
        cout << "Udalo sie zmienic nazwe!" << endl
             << endl;
    }
    else
    {
        cout << "Nie ma takiej jednostki :( " << endl
             << endl;
    }

    cout << "Wpisz jakikolwiek znak aby wrocic: ";
    cin >> powrot;
    system("cls");
}
void usunJednostke()
{
    string jednostka;
    fstream plik;
    ofstream zapis;
    string linia;

    cout << "Podaj nazwe jednostki ktora chcesz usunac: ";
    cin >> jednostka;

    system("cls");

    plik.open("jednostki.txt", ios::in);
    zapis.open("jednostkiPomoc.txt");

    while (!plik.eof())
    {

        plik >> linia;
        if (linia != jednostka)
        {
            zapis << endl
                  << linia;
        }
    }
    cout << endl;
    plik.close();
    zapis.close();

    plik.open("jednostkiPomoc.txt", ios::in);
    zapis.open("jednostki.txt");

    while (!plik.eof())
    {

        plik >> linia;
        zapis << endl
              << linia;
    }

    plik.close();
    zapis.close();

    cout << "Udalo sie usunac jednostke!" << endl
         << endl;
    cout << "Wpisz jakikolwiek znak aby wrocic: ";
    cin >> powrot;
    system("cls");
}

int main()
{
    //menu
    while (1 == 1)
    {
        string opcja;
        cout << "----------------------------------------" << endl;
        cout << "             SYSTEM BITEWNY" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Opcje:" << endl
             << endl;
        cout << "   1. Wyswietl liste jednostek" << endl;
        cout << "   2. Dodaj jednostke" << endl;
        cout << "   3. Edytuj jednostke" << endl;
        cout << "   4. Usun jednostke" << endl;
        cout << "   5. Wyjdz z systemu" << endl
             << endl;
        cout << "Podaj opcje: ";

        //sprawdza czy haslo jest liczba z przedzialu <1;5>
        do
        {
            cin >> opcja;

        } while (czyPoprawnaOpcja(opcja) == 0);
        system("cls");

        //wybiera opcje
        switch (czyPoprawnaOpcja(opcja))
        {
        case 1:
        {
            wyswietlJednostki();
            break;
        }
        case 2:
        {
            dodajJednostke();
            break;
        }
        case 3:
        {
            edytujJednostke();
            break;
        }
        case 4:
        {
            usunJednostke();
            break;
        }
        case 5:
        {
            return 0;
            break;
        }
        }
    }

    return 0;
}