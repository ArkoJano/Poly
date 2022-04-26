#include "Poly.h"
#include <iostream>
using namespace std;

/**
 * @file test_poly.cpp
 * @author Arkadiusz Janus
 * @brief Plik odpowiadający za testy wszystkich funkcjonalności klasy Poly()
 * 
 * Do testowania funkcjonalności podszedłem w następujący sposób.
 * Dla każdej z nich zaimplementowałem te same operacje które znajdują się
 * w klasie, lecz operując tylko na tablicach i następnie porównując
 * wyniki za pomocą funkcji pomocniczej compare_arrays(int*, int*, int)
 * i porównań.
 * 
 * @copyright Copyright (c) 2022
 */



/**
 * @brief Funkcja testujaca wypisywanie wieomianów
 * dla różnych przypadków.
 * 
 */


void test_print(){

    int n = 5;
    int* k = new int[n+1];
    k[0] = 0;
    for (int i=1; i<n; i++){
        if (i % 2 == 0)
            k[i] = i;
        else 
            k[i] = -i; 
    }
    k[n] = 0;
    // cout<<"[";
    // for (int i=0; i<=n; i++){
    //     cout<<k[i]<<", ";
    // }
    // cout<<"]"<<endl;
    
    Poly *newPoly = new Poly(n+1, k);
    newPoly->print();
    cout<<endl;

    k[0] = -1;
    k[1] = -1;
    k[2] = -1;
    k[3] = -1;
    k[4] = -1;
    k[5] = -1;
    
    newPoly = new Poly(n+1, k);
    newPoly->print();
    cout<<endl;

    k[0] = 0;
    k[1] = 0;
    k[2] = 0;
    k[3] = 0;
    k[4] = 0;
    k[5] = 0;
    
    newPoly = new Poly(n+1, k);
    newPoly->print();
    cout<<endl;


    k[0] = -1;
    k[1] = 0;
    k[2] = -1;
    k[3] = 0;
    k[4] = -1;
    k[5] = 0;
    
    newPoly = new Poly(n+1, k);
    newPoly->print();
    cout<<endl;

    k[0] = 0;
    k[1] = -1;
    k[2] = 0;
    k[3] = -1;
    k[4] = 0;
    k[5] = -1;
    
    newPoly = new Poly(n+1, k);
    newPoly->print();
    cout<<endl;
}

/**
 * @brief Funkcja typu assert porównująca dwie tablice
 * 
 * @param[in]  array1 pierwsza tablica do porównania
 * @param[in]  array2 druga tablica do porównania
 * @param[in]  size wielkość obu tablic (nie mogą być różne)
 */

bool compare_arrays(int* array1, int* array2, int size){

    for(int i=0; i<size; i++){
        // cout<<"array1["<<i<<"]: "<<array1[i]<< " == " << array2[i] << ":array2["<<i<<"]"<<endl; 
        if(array1[i] != array2[i]) return false;
    }
    return true;
}

void test_add(){

    /**
     * @brief Funkcja testująca dodawanie wielomianów dla przypadków:
     *  - n = m
     *  - n > m
     *  - n < m
     *  - n = m = 0
     * gdzie n i m to stopnie wielomianów
     * 
     */

    int n = 5;
    int m = 5;
    int size = (m > n) ? m : n;
    int limit = (m > n) ? m : n;
    int* k_n = new int[n+1];
    int* k_m = new int[m+1];
    int* k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    Poly *newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    Poly *newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] + k_m[i];
    
    Poly *result = new Poly(size+1, k_r);
    newPoly1->add(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 2;
    m = 5;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] + k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->add(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n<m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 5;
    m = 2;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] + k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->add(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n>m]ok"<<endl;

    // -------------------------------------------------------------------------

    n = 0;
    m = 0;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] + k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->add(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m=0]ok"<<endl;
    // -------------------------------------------------------------------------


}

void test_substract(){

    /**
     * @brief Funkcja testująca odejmowanie wielomianów dla przypadków:
     *  - n = m
     *  - n > m
     *  - n < m
     *  - n = m = 0
     * gdzie n i m to stopnie wielomianów
     * 
     */

    int n = 5;
    int m = 5;
    int size = (m > n) ? m : n;
    int limit = (m > n) ? m : n;
    int* k_n = new int[n+1];
    int* k_m = new int[m+1];
    int* k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    Poly *newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    Poly *newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] - k_m[i];
    
    Poly *result = new Poly(size+1, k_r);
    newPoly1->substract(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 2;
    m = 5;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] - k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->substract(newPoly2);

    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n<m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 5;
    m = 2;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] - k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->substract(newPoly2);
        
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n>m]ok"<<endl;

    // -------------------------------------------------------------------------

    n = 0;
    m = 0;
    
    size = (m > n) ? m : n;
    limit = (m > n) ? m : n;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i = 0; i<limit; i++)
        k_r[i] = k_n[i] - k_m[i];
    
    result = new Poly(size+1, k_r);
    newPoly1->substract(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m=0]ok"<<endl;
    // -------------------------------------------------------------------------


}

void test_multiply(){

    /**
     * @brief Funkcja testująca mnożenie wielomianów dla przypadków:
     *  - n = m
     *  - n > m
     *  - n < m
     *  - n = m = 0
     * gdzie n i m to stopnie wielomianów
     * 
     */

    int n = 5;
    int m = 5;
    int size = n+m-1;
    int limit = n+m-1;
    int* k_n = new int[n+1];
    int* k_m = new int[m+1];
    int* k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    Poly *newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    Poly *newPoly2 = new Poly(m+1, k_m);
    
    for(int i=0; i<limit; i++){
        k_r[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            k_r[i+j] += k_n[i]*k_m[j];
    }
    
    Poly *result = new Poly(size+1, k_r);
    newPoly1->multiply(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 2;
    m = 5;
    
    size = n+m-1;
    limit = n+m-1;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i=0; i<limit; i++){
        k_r[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            k_r[i+j] += k_n[i]*k_m[j];
    }
    
    result = new Poly(size+1, k_r);
    newPoly1->multiply(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n<m]ok"<<endl;
    // -------------------------------------------------------------------------

    n = 5;
    m = 2;
    
    size = n+m-1;
    limit = n+m-1;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i=0; i<limit; i++){
        k_r[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            k_r[i+j] += k_n[i]*k_m[j];
    }
    
    result = new Poly(size+1, k_r);
    newPoly1->multiply(newPoly2);
        
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n>m]ok"<<endl;

    // -------------------------------------------------------------------------

    n = 0;
    m = 0;
    
    size = n+m-1;
    limit = n+m-1;
    k_n = new int[n+1];
    k_m = new int[m+1];
    k_r = new int[size+1];
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    
    newPoly1 = new Poly(n+1, k_n);

    for(int i = 0; i<m; i++)
        k_m[i] = -1;

    newPoly2 = new Poly(m+1, k_m);
    
    for(int i=0; i<limit; i++){
        k_r[i] = 0;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            k_r[i+j] += k_n[i]*k_m[j];
    }
    
    result = new Poly(size+1, k_r);
    newPoly1->multiply(newPoly2);
    
    if(compare_arrays(newPoly1->get_coefficients(), result->get_coefficients(), size+1))
        cout<<"[n=m=0]ok"<<endl;
    // -------------------------------------------------------------------------


}

void test_calculate(){

/**
 * @brief Funkcja testująca obliczanie wartości wielomianu dla zadanego argumentu.
 * 
 */

    int n = 5;
    int* k_n = new int[n+1];
    int result = 0;
    
    for(int i = 0; i<n; i++)
        k_n[i] = -1;

    result = k_n[n];
    
    Poly *newPoly1 = new Poly(n+1, k_n);


    for (int i=n-1; i>=0; i--) {
        result = result*n + k_n[i];
    }
    
    
    if(newPoly1->calculate(n), result)
        cout<<"ok"<<endl;
    // -------------------------------------------------------------------------

}

int main(){
    cout<< "TEST PRINT"<<endl;
    test_print();
    cout<< "TEST ADD"<<endl;
    test_add();
    cout<< "TEST SUBSTRACT"<<endl;
    test_substract();
    cout<< "TEST MULTIPLY"<<endl;
    test_multiply();
    cout<< "TEST CALCULATE"<<endl;
    test_calculate();
}