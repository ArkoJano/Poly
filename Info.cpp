/**
 * @file Info.cpp
 * @author Arkadiusz Janus
 * @brief Plik stron informacyjnych dokumentacji
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// ***********************************************************************
/// @page page1 Informacje o projekcie
/// 
/// Projektem który chciałbym tutaj zaprezentować jest implementacja 
/// operacji na wielomianach z wykorzystaniem tablic. 
/// 
/// W podsekcjach znajduje się szczegółowy opis własności samej implementacji
/// takich jak:
/// - @subpage zlozonosc
/// - @subpage uruchomienie
/// - @subpage obsluga
///
// ***********************************************************************

// ***********************************************************************
/// @page zlozonosc Złożoność
/// 
/// Złożoność poszczególnych operacji możemy podzielić na:
/// - @subpage czasowa "Czasową"
/// - @subpage pamieciowa "Pamięciową"
/// 
// ***********************************************************************

// ***********************************************************************
/// @page czasowa Czasowa
/// Złożoność czasowa poszczególnych operacji:
/// 
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">add()</span>
///     - <b>O(N)</b> - ponieważ musimy przejść przez wszystkie współczynniki magazynowane
/// w tablicy mniejszego wielomianiu
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">substract()</span>
///     - <b>O(N)</b> - ponieważ musimy przejść przez wszystkie współczynniki magazynowane
/// w tablicy mniejszego wielomianiu
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">muliply()</span>
///     - <b>O(N*M)</b> - ponieważ musimy przejść przez wszystkie współczynniki magazynowane
/// w tablicach obu wielomianów 
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">calculate()</span>
///     - <b>O(N)</b> - ponieważ musimy przejść przez wszystkie współczynniki wielomianu 
/// magazynowane w tablicy 
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">print()</span>
///     - <b>O(N)</b> - ponieważ musimy przejść przez wszystkie współczynniki wielomianu 
/// magazynowane w tablicy
/// 
/// Gdzie <b>N</b> i <b>M</b> to liczba współczynników pierwszego i drugiego wielomianu.
// ***********************************************************************

// ***********************************************************************
/// @page pamieciowa Pamięciowa
/// Złożoność pamięciowa poszczególnych operacji:
///
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">add()</span>
///     - <b>O(N+M)</b> - ponieważ przechowujemy wszystkie elementy w już wykorzystywanej
/// tablicy większego z wielomianów, ale istnieje druga tablica przechowująca wartości 
/// mniejszgo z nich 
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">substract()</span>
///     - <b>O(N+M)</b> - ponieważ przechowujemy wszystkie elementy w już wykorzystywanej
/// tablicy większego z wielomianów, ale istnieje druga tablica przechowująca wartości 
/// mniejszgo z nich
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">muliply()</span>
///     - <b>O(N+M)</b> - musimy zaalokować nową tablicę będąca sumą rozmiarów obu tablic 
/// minus jeden, ale nadal istnieją dwie poprzednie tablice o rozmiarach <b>N</b> i <b>M</b>, więc
/// całkowita pamięć potrzebna na funkcję wynosi 2(n+m), gdzie dla definicji dużego O, pomijamy
/// stałą
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">calculate()</span>
///     - <b>O(1)</b> - wykorzystujemy do zapisywania wyniku tylko jedną zmienną typu int
/// - <span style="color:#3D578C; font-size:18px; font-weight: bold;">print()</span>
///     - Nie wykorzystuje pamięci
///
/// Gdzie <b>N</b> i <b>M</b> to liczba współczynników pierwszego i drugiego wielomianu.
// ***********************************************************************


// ***********************************************************************
/// @page uruchomienie Uruchomienie
/// Do programu dołączony został plik <b>MakeFile</b> dzięki któremu
/// uruchomienie programu sprowadza się do wywołania prostej komendy w
/// wierszu poleceń. Wymaganym jest aby ją wywoływać znajdując się w folderze
/// zawierającym wszystkie niezbędne pliki potrzebne do działania programu. 
/// 
/// @note Do skorzystania z tej możliwości wymagane jest również posiadanie 
/// zainstalowanej aplikacji MakeFile o której informacje można znaleźć 
/// na oficjalnej stronie: https://www.gnu.org/software/make/manual/make.html
/// 
/// @section run Uruchomienie programu
/// @code  
/// make run
/// @endcode 
/// 
/// @section test Uruchomienie testów
/// @code  
/// make test
/// @endcode
// ***********************************************************************

// ***********************************************************************
/// @page obsluga Obsługa
/// 
/// Po uruchomieniu programu zostajemy przywitani przez następujący ekran:
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 
/// @endcode
/// 
/// @note (Po każdej wykonanej operacji będzie on wyświetlany ponownie aż do 
/// zakończenia działania programu)
///
/// Który pozwala nam skorzystać z następujących funkcjonalności programu:
///
/// <hr>
/// @section add Dodawanie
///
/// Po wybraniu opcji numer 1 i zatwierdzeniu enterem jesteśmy poproszeni o podanie
/// stopnia pierwszego wielomianiu:
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 1
/// Podaj stopien wielomianiu: 
/// @endcode 
/// A następnie jego współczynników przy odpowiednich potęgach x'a: 
///
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 1
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
///@endcode  
/// 
/// Po zebraniu wszystkich elementów program poprosi o stworzenie drugiego wielomianu
/// w dokładnie taki sam sposób.
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 1
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
/// @endcode 
///
/// Gdzie po zatwierdzeniu zostaną one utworzone i do siebie dodane co zostanie
/// zasyngnalizowane wypisaniem całego równania wraz ich wynikiem.
/// 
/// @code 
/// ( 1 + x + x^2 ) + ( 1 + x + x^2 ) = 2 + 2x + 2x^2
/// @endcode 
/// <hr>
/// @section sub Odejmowanie
/// Po wybraniu opcji numer 2 i zatwierdzeniu enterem jesteśmy poproszeni o podanie
/// stopnia pierwszego wielomianiu:
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 2
/// Podaj stopien wielomianiu: 
/// @endcode 
/// A następnie jego współczynników przy odpowiednich potęgach x'a: 
///
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 2
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 2
/// Podaj wspolczynnik przy x^2: 3
///@endcode  
/// 
/// Po zebraniu wszystkich elementów program poprosi o stworzenie drugiego wielomianu
/// w dokładnie taki sam sposób.
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 2
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 2
/// Podaj wspolczynnik przy x^2: 3
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
/// @endcode 
///
/// Gdzie po zatwierdzeniu zostaną one utworzone i od siebie odjęte co zostanie
/// zasyngnalizowane wypisaniem całego równania wraz ich wynikiem.
/// 
/// @code 
/// ( 1 + 2x + 3x^2 ) - ( 1 + x + x^2 ) =  + x + 2x^2
/// @endcode 
/// <hr>
/// @section mul Mnożenie
///
/// Po wybraniu opcji numer 3 i zatwierdzeniu enterem jesteśmy poproszeni o podanie
/// stopnia pierwszego wielomianiu:
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 3
/// Podaj stopien wielomianiu: 
/// @endcode 
/// A następnie jego współczynników przy odpowiednich potęgach x'a: 
///
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 3
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
///@endcode  
/// 
/// Po zebraniu wszystkich elementów program poprosi o stworzenie drugiego wielomianu
/// w dokładnie taki sam sposób.
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 3
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
/// Podaj stopien wielomianiu: 2
/// Podaj wyraz wolny (x^0): 1
/// Podaj wspolczynnik przy x: 1
/// Podaj wspolczynnik przy x^2: 1
/// @endcode 
///
/// Gdzie po zatwierdzeniu zostaną one utworzone i przez siebie pomnożone co zostanie
/// zasyngnalizowane wypisaniem całego równania wraz ich wynikiem.
/// 
/// @code 
/// ( 1 + x + x^2 ) * ( 1 + x + x^2 ) = 1 + 2x + 3x^2 + 2x^3 + x^4
/// @endcode 
/// <hr>
/// @section calc Obliczanie wartości
///
/// Po wybraniu opcji numer 4 i zatwierdzeniu enterem jesteśmy poproszeni o podanie
/// stopnia wielomianiu który chcemy policzyć:
/// 
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 4
/// Podaj stopien wielomianiu: 
/// @endcode 
/// A następnie jego współczynników przy odpowiednich potęgach x'a: 
///
/// @code
/// Wybierz co chcesz zrobić:
/// 1. Dodaj wielomiany
/// 2. Odejmij wielomiany
/// 3. Pomnóż wielomiany
/// 4. Oblicz wartość wielomianu
/// 5. Wyjdź
/// Opcja: 4
/// Podaj stopien wielomianiu: 3
/// Podaj wyraz wolny (x^0): 2
/// Podaj wspolczynnik przy x: 3
/// Podaj wspolczynnik przy x^2: 5
/// Podaj wspolczynnik przy x^3: -4
/// Podaj x dla ktorego obliczyc wynik: 3
///@endcode  
/// Gdzie po zatwierdzeniu wielomian zostanie utworzony, a wynik dla danej
/// wartości obliczony co zostanie zasyngnalizowane wypisaniem całego 
/// wielomianiu i jego wielkości dla podanego argumentu.
/// 
/// @code 
/// W(x) = (2 + 3x + 4x^2 - 4x^3)
/// W(3) = -61
/// @endcode 
/// 
// ***********************************************************************