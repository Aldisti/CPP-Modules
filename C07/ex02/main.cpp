#include <iostream>
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 5

int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << numbers << std::endl;
    std::cout << numbers[-1] << std::endl;
    numbers.append(15);
    std::cout << numbers[-1] << std::endl;
    std::cout << numbers.count(15) << std::endl;

    Array<int>   tmp(numbers);

    std::cout << tmp.size() << tmp << std::endl;
    std::cout << numbers.size() << numbers << std::endl;

    std::cout << (tmp == numbers) << (tmp != numbers) << std::endl;
    
    tmp += numbers;

    std::cout << (tmp == numbers) << (tmp != numbers) << std::endl;
    std::cout << tmp.index(15) << " " << tmp.index(5) << std::endl;

    Array<int>  test(10);
    for (int i = 0; i < 10; i++)
        test[i] = i % 3;
    
    std::cout << test << std::endl;
    test.remove(0, 2);
    std::cout << test << std::endl;
    test.remove(2, -1);
    std::cout << test << std::endl;

    test.insert(2, 5);
    test.insert(-1, 8);
    test.insert(1000, 13);

    std::cout << test << std::endl;
    test.reverse();
    std::cout << test << std::endl;

    std::cout << test.min() << std::endl;
    std::cout << test.max() << std::endl;

    test.sort();

    std::cout << test << std::endl;

    return (0);
}
