#include "Poly.h"

/**
 * @file Poly.cpp
 * @author Arkadiusz Janus
 * @brief Plik implementujący funkcjonalność obiketu Poly()
 * @copyright Copyright (c) 2022
 */



/**
 *
 *  @brief Podstawowy konstruktor klasy Poly()
 *  nie przyjmujący żadnych argumentów
 *  
 */
Poly::Poly(){
    coefficients = new int[0]; 
    exponent = 0;
}

/**
 * @brief Destruktor obiektu Poly()
 * 
 * @details Zwalniane jest zadelarowanie miejsce na listę współczynników
 */

Poly::~Poly(){
    delete[] coefficients;
}

/**
 *
 *  \brief konstruktor klasy Poly() tworzacy obiekt na podstawie podanej w argumentach listy współczynników
 *  
 * 
 *  @param _exponent Stopien wielomianu 
 *  @param coefficients Lista współczynników wielomianu 
 *  
 */ 
Poly::Poly(int _exponent, int* _coefficients){
    
    
    coefficients = _coefficients;
    exponent = _exponent;

}

/**
 * @brief Funkcja zwracająca listę współczynników 
 * (wykorzystywana do testów)
 * 
 * @return Lista współczynników 'coefficients'
 */
int* Poly::get_coefficients(){
    return coefficients;
}

/**
 *
 *  \brief Funkcja dodająca jeden wielomian do drugiego
 * 
 *  Obliczona wartość nadpisuje obiekt na którym funkcja została wywołana.
 * 
 *  @param other Obiekt typu Poly(), którego wartości zostaną dodane do wartości obiektu 
 *  
 */ 
void Poly::add(Poly* other){


    /*<! Wybór obiektu w którym będzie przechowywany wynik, wybieramy 
    wielomian o większym stopniu*/
    Poly* result = (exponent > other->exponent) ? this : other; 

    /*<! Limit w którym zatrzyma się pętla dodająca elementy do wyniku*/
    int limit = (exponent < other->exponent) ? exponent : other->exponent;

    
    for(int i=0; i<limit;i++){
        result->coefficients[i] = coefficients[i] + other->coefficients[i];
    } 
    *this = *result;
}


/**
 *
 *  \brief Funkcja odejmujaca jeden wielomian od drugiego
 * 
 *  Obliczona wartość nadpisuje obiekt na którym funkcja została wywołana.
 * 
 *  @param other Obiekt typu Poly(), którego wartości zostaną odjęte od wartości obiektu 
 *  
 */ 
void Poly::substract(Poly* other){
    
    /*<! Wybór obiektu w którym będzie przechowywany wynik, wybieramy 
    wielomian o większym stopniu*/
    Poly* result = (exponent > other->exponent) ? this : other; 

    /*<! Limit w którym zatrzyma się pętla dodająca elementy do wyniku*/
    int limit = (exponent < other->exponent) ? exponent : other->exponent;
    
    
    for(int i=0; i<limit;i++){
        result->coefficients[i] = coefficients[i] - other->coefficients[i];
    } 
    *this = *result;
}

/**
 *
 *  \brief Funkcja mnożąca jeden wielomian przez drugi
 * 
 *  Obliczona wartość nadpisuje obiekt na którym funkcja została wywołana.
 * 
 *  @param other Obiekt typu Poly(), którego wartości zostaną pomnożone przez wartości obiektu 
 *  
 */ 
void Poly::multiply(Poly* other){
    /*<! Limit w którym zatrzyma się pętla dodająca elementy do wyniku*/
    int limit = exponent + other->exponent-1;

    /*<! Nowa tablica przechowująca obliczone elementy*/
    int* newCoef = new int[limit];
    Poly* result = new Poly(limit, newCoef);

    /*<! Funkcja ustawiająca wszystkie elementy na 0*/
    for(int i=0; i<limit; i++){
        result->coefficients[i] = 0;
    }
    /*!< Pętle obliczające wymnożone współczynniki obu wielomianów*/
    for (int i=0; i<exponent; i++)
    {
        for (int j=0; j<other->exponent; j++)
            result->coefficients[i+j] += coefficients[i]*other->coefficients[j];
    }

    *this = *result;
}

/**
 *
 *  \brief Funkcja mnożąca jeden wielomian przez drugi
 * 
 *  Wykorzystywany jest do tego schemat Hornera, który zaimplementowany
 *  algorytm opiera się na wymnożeniu przy każdym kroku poprzedniego wyniku
 *  przez podany x i dodanie akutalnie rozpatrywanego współczynnika
 * 
 *  @param x Wartość dla której będzie obliczony wynik 
 *  
 *  @return Wynik działania algorytmu
 */ 
int Poly::calculate(int x){
    int result = coefficients[exponent]; 

    for (int i=exponent-1; i>=0; i--) {
        result = result*x + coefficients[i];
    }

    return result;
}


/**
 * @brief Funkcja odpowiadająca za wypisanie wielomianiu w przystępnej formie.
 * 
 */
void Poly::print(){
    for(int i = 0; i < exponent; ++i){
		if(coefficients[i] < 0){
			if(i == 0){
				std::cout << coefficients[i];
			}
			else{
				std::cout << " - ";
				if(coefficients[i] == -1){ std::cout << ""; }
				else{ std::cout << (-1 * coefficients[i]); }
				std::cout << "x";
				if(i == 1){ std::cout << ""; }
				else{ std::cout << "^"; std::cout << i; }
			}
		}
		else if(coefficients[i] == 0){ continue; }
		else{
			if(i == 0){ std::cout << coefficients[i]; }
			else{
				std::cout << " + ";
				if(coefficients[i] == 1){ std::cout << ""; }
				else{ std::cout << coefficients[i]; }
				std::cout << "x";
				if(i == 1){ std::cout << ""; }
				else{ std::cout << "^"; std::cout << i; }
			}
		}
	}
} 

