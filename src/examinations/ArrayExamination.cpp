#include "examinations/ArrayExamination.h"
#include "app/utility/Timer.h"
#include "app/utility/RandomNumberGenerator.h"

ExaminationRecord ArrayExamination::push_front(DynamicArray* array){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    array->push_front(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        PUSH_FRONT,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::push_back(DynamicArray* array){

    // Generuję nowy element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    array->push_back(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        PUSH_BACK,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::add_element(DynamicArray* array){

    // Generuję nowy element oraz indeks
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();
    unsigned index = RandomNumberGenerator::getIntegers(1, 0, UINT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    array->add(new_element,index);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        ADD,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::pop_front(DynamicArray* array){

    // Mierzę czas dodawnia elementu na początek
    Timer timer;
    timer.start();
    array->pop_front();
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        POP_FRONT,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::pop_back(DynamicArray* array){

    // Mierzę czas
    Timer timer;
    timer.start();
    array->pop_back();
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        POP_BACK,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::remove_element(DynamicArray* array){

    // Generuję indeks
    unsigned index = RandomNumberGenerator::getIntegers(1, 0, array->getLength()).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    array->remove(index);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        REMOVE,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}

ExaminationRecord ArrayExamination::find_element(DynamicArray* array){

    // Generuję szukany element
    int new_element = RandomNumberGenerator::getIntegers(1, INT_MIN, INT_MAX).front();

    // Mierzę czas
    Timer timer;
    timer.start();
    array->find(new_element);
    timer.stop();

    // Zapisuje zebrane dane w formie rekordu pliku .csv
    return { 
        ARRAY,
        FIND,
        timer.getResult(seconds),
        timer.getResult(miliseconds),
        timer.getResult(microseconds)
    };

}