#include<iostream>

/**
 * @file Poly.h
 * @brief Plik nagłówkowy odpowiadający za implementację wielomianów
 * @author Arkadiusz Janus
 * @details  Wielomiany są zaimplementowane za pomocą tablicy w której są 
 * przechowywane jego współczynniki. Każde miejsce odpowiada odpowiedniemu
 * współczynnikowi dla danej potęgi wielomianu. Ilośc potęg jest wyznaczana
 * na podstawie stopnia wielomianu który jest podawany przy tworzeniu. 
 * 
 * Klasa zawiera dwa konstruktory i destruktor, a także funkcje które 
 * pozwalają wykonywać operacje na wielomianach:
 * - dodawanie
 * - odejmowanie
 * - mnożenie
 * - oblicznie dla danej wartości
 * 
 * @copyright Copyright (c) 2022
 */

class Poly{
    private:
        int *coefficients;  
        int exponent;       


    public:
        Poly(); 
        Poly(int exponent, int* _coefficients);
        ~Poly();
        void add(Poly* other);
        void substract(Poly* other);
        void multiply(Poly* other);
        int calculate(int x);
        void print();
        int* get_coefficients();
};