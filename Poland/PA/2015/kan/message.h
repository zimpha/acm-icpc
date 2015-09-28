// Biblioteka message sluzy do przekazywania wiadomosci pomiedzy instancjami
// programu. Wiadomosc moze skladac sie z dowolnej liczby znakow (char) oraz
// liczb typu int i long long. Limity na liczbe wiadmosci, jakie moze
// wyslac pojedyncza instancja, oraz na ich laczny rozmiar sa podawane w tresci
// kazdego zadania.

#ifndef MESSAGE_H_
#define MESSAGE_H_

#ifdef __cplusplus
extern "C" {
#endif

// Zwraca liczbe instancji.
int NumberOfNodes();

// Zwraca ID biezacej instancji, z przedzialu {0, ..., NumberOfNodes()-1}.
int MyNodeId();

// Zachowanie kazdej z ponizszych funkcji jest niezdefiniowane, jesli
// `target` lub `source` nie nalezy do odpowiedniego przedzialu.

// Biblioteka korzysta z wewnetrznego bufora wiadomosci skierowanych do kazdej
// instancji z przedzialu {0, ..., NumberOfNodes()-1}. 
// Wiadomosci sa dopisywane do bufora za pomoca funkcji `Put*`.

// Kolejkuje `value` do wyslania do instancji `target`.
void PutChar(int target, char value);

// Kolejkuje `value` do wyslania do instancji `target`.
void PutInt(int target, int value);

// Kolejkuje `value` do wyslania do instancji `target`.
void PutLL(int target, long long value);

// Wysyla wiadomosci zakolejkowane w odpowiednim buforze do instancji `target`
// i czysci ten bufor.
//
// Ta funkcja jest nieblokująca -- nie czeka na wywolanie Receive() przez
// odbiorce, powrot nastepuje natychmiast po wyslaniu wiadomosci.
void Send(int target);

// Biblioteka posiada rowniez bufor wiadomosci odebranych od kazdej instancji.
// Po wywolaniu `Receive` i odebraniu wiadomosci od pewnej instancji,
// odpowiadajacy jej bufor zostaje nadpisany. Poszczegolne fragmenty wiadomosci
// moga zostac odczytane za pomoca funkcji `Get*`.
//
// Odbiera wiadomosc od instancji `source` (lub dowolnej, gdy `source` == -1).
// Zwraca numer instancji, od ktorej wiadomosc odebral. Receive wymaga, aby w
// momencie jego wywolania poprzednio odebrana wiadomosc od instancji `source`
// (lub wszystkie poprzednio odebrane wiadomosci, gdy `source` == -1) byla
// w calosci przeczytana.
//
// Ta funkcja jest blokujaca -- jesli nie ma wiadomosci do odbioru, bedzie
// czekac na jej przeslanie.
int Receive(int source);

// Po odebraniu wiadomosci jej zawartosc nalezy czytac w takiej kolejnosci,
// w jakiej byla kolejkowana do wyslania. Na przyklad, gdy nadawca jako pierwsza
// wartosc zakolejkowal long longa, a odbiorca sprobuje przeczytac chara,
// program zachowa sie w niezdefiniowany sposob.
//
// Niezdefiniowane zachowanie jest spowodowane rowniez przez probe odczytu
// z pustego bufora.

// Czyta char z odebranej wiadomosci od instancji `source`. Numer instancji
// musi byc liczba z przedzialu {0, ..., NumberOfNodes()-1}. W szczegolnosci
// nie moze byc rowny -1.
char GetChar(int source);

// Czyta int z odebranej wiadomosci od instancji `source`.
int GetInt(int source);

// Czyta long long z odebranej wiadomosci od instancji `source`.
long long GetLL(int source);

#ifdef __cplusplus
}
#endif

#endif  // MESSAGE_H_
