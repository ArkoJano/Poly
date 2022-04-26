#include "Poly.h"
#include <iostream>
using namespace std;

/**
 * @file main.cpp
 * @brief Główny plik odpowiadający za interfejs pozwalający użytkownikowi wykorzystać funkcjonalność programu.
 * @author Arkadiusz Janus
 * 
 * @details Dostarczenie samej implementacji wymgała by od użytkownika zapozaniania
 * się z jej szczegółami. Aby maksymalnie uprościć korzystanie z programu, dostarczony
 * wraz z nim jest przejrzysty interfejs który pozwoli każdemu natychmiastowo skorzystać
 * z jego funkcjonalności. Plik zawiera kilka funkcji odpowiedzialnych za obsługę
 * działanie całej implemnetacji.  
 * 
 * @copyright Copyright (c) 2022
 */


/**
 * @brief Funkcja odpowiedzialna za wyświetlenie menu
 * 
 */
void menu(){
    cout << "Wybierz co chcesz zrobić:" << endl;
    cout << "1. Dodaj wielomiany" << endl;
    cout << "2. Odejmij wielomiany" << endl;
    cout << "3. Pomnóż wielomiany" << endl;
    cout << "4. Oblicz wartość wielomianu" << endl;
    cout << "5. Wyjdź" << endl;
}

/**
 * @brief Funkcja prowadząca użytkownika przez cały proces tworzenia 
 * nowego obiektu wielomianiu.
 * 
 * @return Poly* 
 */

Poly* create_poly(){
    
    int n, m;

    cout<< "Podaj stopien wielomianiu: ";
    cin >> n;
    int* k = new int[n+1];
    if(n >= 0){
        cout<< "Podaj wyraz wolny (x^0): ";
        cin >> m;
        k[0] = m;
    }

    if( n >= 1){
        cout<< "Podaj wspolczynnik przy x: ";
        cin >> m;
        k[1] = m;
    }

    for(int i=2; i<=n; i++){
        cout<< "Podaj wspolczynnik przy x^" << i << ": ";
        cin >> m;
        k[i] = m;
    }
    Poly *newPoly = new Poly(n+1, k);

    return newPoly;
}

/**
 * @brief Funkcja prowadząca użytkownika przez cały proces tworzenia 
 * i dodawania dwóch wielomianów do siebie.
 * 
 * Bazuje na funkcji create_poly(), które tworzy wielomiany, a następnie
 * na pierwszym z nich jest wywoływana metoda add(), z drugim z nich jako
 * argument.
 */

void add_polys(){
    Poly* newPoly1 = create_poly();
    Poly* newPoly2 = create_poly();
    cout<< "( ";
    newPoly1->print();
    cout<< " ) + ( ";
    newPoly2->print();
    cout<< " )";
    cout<< " = ";
    newPoly1->add(newPoly2);
    newPoly1->print();
}

/**
 * @brief Funkcja prowadząca użytkownika przez cały proces tworzenia 
 * i odejmowania dwóch wielomianów od siebie.
 * 
 * Bazuje na funkcji create_poly(), które tworzy wielomiany, a następnie
 * na pierwszym z nich jest wywoływana metoda substract(), z drugim z nich jako
 * argument. 
 */


void substract_polys(){
    Poly* newPoly1 = create_poly();
    Poly* newPoly2 = create_poly();
    cout<< "( ";
    newPoly1->print();
    cout<< " ) - ( ";
    newPoly2->print();
    cout<< " )";
    cout<< " = ";
    newPoly1->substract(newPoly2);
    newPoly1->print();
}

/**
 * @brief Funkcja prowadząca użytkownika przez cały proces tworzenia 
 * i mnożenia dwóch wielomianów przez siebie.
 * 
 * Bazuje na funkcji create_poly(), które tworzy wielomiany, a następnie
 * na pierwszym z nich jest wywoływana metoda multiply(), z drugim z nich jako
 * argument.
 */

void multiply_polys(){
    Poly* newPoly1 = create_poly();
    Poly* newPoly2 = create_poly();
    cout<< "( ";
    newPoly1->print();
    cout<< " ) * ( ";
    newPoly2->print();
    cout<< " )";
    cout<< " = ";
    newPoly1->multiply(newPoly2);
    newPoly1->print();
}

/**
 * @brief Funkcja prowadząca użytkownika przez cały proces tworzenia 
 * obliczania wartości wielomianu dla zadanego argumentu.
 * 
 * Bazuje na funkcji create_poly(), które tworzy wielomian, a następnie
 * prosi użytkownika o podanie argumentu dla niego według której będzie
 * obliczana wartość. Mając wszystkie dane wywoływana jest na obiekcie
 * metoda calculate(), która zwraca wynik.
 * 
 */

void calculate_poly(){
    Poly* newPoly = create_poly();
    int x;
    cout<<"Podaj x dla ktorego obliczyc wynik: ";
    cin >> x;

    cout<< "\nW(x) = (";
    newPoly->print();
    cout<< ")";
    cout<< "\nW("<< x <<") = ";
        
    cout<<newPoly->calculate(x)<<endl;
}

/**
 * @brief Główna funkcja odpowiadająca za działanie całego programu.
 * 
 * Za pomocą pętli pozwala na nieskończone działanie pozwalające na
 * wykonywanie potrzebynch nam operacji bez konieczności uruchamiania 
 * programu za każdym razem. Z każdą iteracją wypisuje menu za pomocą 
 * funkcji menu() i prosi użytkownika o wybranie funkcjonalności z 
 * której chciałby skorzystać. 
 * 
 * @return int 
 */

int main(){
    int option = 0;
    while(true){
        
        cout<<"\n";
        menu();
        cout<<"Opcja: ";
        cin >> option;
        switch (option)
        {
        case 1:
            add_polys();
            break;
        case 2:
            substract_polys();
            break;
        case 3:
            multiply_polys();
            break;
        case 4:
            calculate_poly();
            break;
        case 5:
            exit(1);
            break;
        
        default:
            break;
        }
    }

}