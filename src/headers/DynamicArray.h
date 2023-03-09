/* Klasa przedstawiająca tablicę dynamiczną */

class DynamicArray{

    /* POLA */
    private: int* array_address;        // adres pierwszej komórki w tablicy
    private: unsigned int length;       // aktualna długość tablicy

    /* MEOTDY */

    // Konstruktor
    public: DynamicArray();

    // Destruktor
    public: ~DynamicArray();

    //-----------------------------------------------------------------------
    // Zwraca element tablicy zawarty w komórce o zadanym indeksie. W wypadku
    // podanie niepoprawnego indesu zwraca wartość NULL.
    // 
    // Parametry:
    // index - indeks elementu, który chcemy uzyskać
    //-----------------------------------------------------------------------
    public: int operator[](int index);


    //-----------------------------------------------------------------------
    // Dodaje nowy element do tablicy.
    // 
    // Parametry:
    // new_element - nowa wartość, która ma zostać dodana do tablicy
    //-----------------------------------------------------------------------
    public: void add(int new_element);

    // Usunięcie elementu o podanym indeksie
    public: void remove(int index);

};