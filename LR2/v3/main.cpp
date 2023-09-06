#include "Set/Set.h"

using namespace mySet;

int test1()
{/*
    Set<int> s1;
    s1.addElement(1);
    s1.addElement(2);
    s1.addElement(3);
    ConstSetIterator<int>it1(s1);
    int d = 0;

    while (it1.check(__LINE__, __FILE__))
    {
        printf("cur element = %d\n", *it1);
        //scanf("%d", &d);
        it1++;
    }

    s1.removeElement(2);
    ConstSetIterator<int>it(s1);
    while (it < s1.cend())
    {
        printf("cur element = %d\n", *it);
        //scanf("%d", &d);
        it++;
    }
    return 0;*/
}

int test2()
{
    Set<int> s1;
    s1.addElement(1);
    s1.addElement(2);
    s1.addElement(3);
    ConstSetIterator<int>it1(s1);
    int d = 0;

    while (it1 < s1.cend())
    {
        //*it1 = 10;
        it1++;
        std::cout << *it1 << " ";
    }
    s1.output();
    return 0;
}

int test3()
{
    Set<int> s1;
    s1.addElement(2);
    s1.addElement(5);
    s1.addElement(4);
    ConstSetIterator<int>it1(s1);
    int d = 0;

    while (it1 < s1.cend())
    {
        it1++;
    }
    std::cout << s1;
    return 0;
}
int test4()
{
    const Set<int> s1(3, 1, 4, 2);
    //std::ostream n = std::cout;
    std::cout << s1;
    return 0;
}
int test5()
{
    std::cout << "Тест 5 <Операции со множествами: Объединение>: " << std::endl;
    Set<int> s1(3, 1, 4, 2);
    Set<int> s2(4, 1, 4, 3, 5);
    std::cout << "s1" << s1 << "s2" << s2 << "unification()" << s1.unification(s2) << std::endl;
    //std::ostream n = std::cout;
    Set<int> s3(5, 1, 2, 3, 4, 5);
    Set<int> s4(4, 9, 8, 7, 6);
    std::cout << "s3" << s3 << "s4" << s4 << "+" << (s3 + s4) << std::endl;
    s3 += s4;
    std::cout << "s4" << s4 << "+=" << s3 << std::endl;

    Set<int> s5(5, 1, 2, 3, 4, 5);
    Set<int> s6(4, 9, 8, 7, 6);
    std::cout << "s3" << s5 << "s4" << s6 << "|" << (s5 | s6) << std::endl;
    s3 |= s4;
    std::cout << "s4" << s4 << "|=" << s3 << std::endl;
    return 0;
}
int test6()
{
    std::cout << "Тест 6 <Операции со множествами: Пересечение>: " << std::endl;
    Set<int> s1(3, 1, 4, 2);
    Set<int> s2(4, 1, 4, 3, 5);
    std::cout << "s1" << s1 << "s2" << s2 << "intersection()" << s1.intersection(s2) << std::endl;
    //std::ostream n = std::cout;
    Set<int> s3(5, 1, 2, 3, 4, 5);
    Set<int> s4(4, 9, 8, 7, 6);
    std::cout << "s3" << s3 << "s4" << s4 << "*" << (s3 * s4) << std::endl;
    s3 *= s4;
    std::cout << "s4" << s4 << "*=" << s3 << std::endl;

    Set<int> s5(5, 1, 2, 3, 4, 5);
    Set<int> s6(4, 9, 8, 7, 6);
    std::cout << "s3" << s5 << "s4" << s6 << "&" << (s5 & s6) << std::endl;
    s3 &= s4;
    std::cout << "s4" << s4 << "&=" << s3 << std::endl;
    return 0;
}
int test7()
{
    std::cout << "Тест 7 <Операции со множествами: Разность>: " << std::endl;
    Set<int> s1(3, 1, 4, 2);
    Set<int> s2(4, 1, 4, 3, 5);
    std::cout << "s1" << s1 << "s2" << s2 << "difference()" << s1.difference(s2) << std::endl;
    //std::ostream n = std::cout;
    Set<int> s3(5, 1, 2, 3, 4, 5);
    Set<int> s4(4, 9, 8, 7, 6);
    std::cout << "s3" << s3 << "s4" << s4 << "-" << (s3 - s4) << std::endl;
    s3 -= s4;
    std::cout << "s4" << s4 << "-=" << s3 << std::endl;

    Set<int> s5(5, 1, 2, 3, 4, 5);
    Set<int> s6(4, 9, 8, 7, 6);
    std::cout << "s3" << s5 << "s4" << s6 << "/" << (s5 / s6) << std::endl;
    s3 /= s4;
    std::cout << "s4" << s4 << "/=" << s3 << std::endl;
    return 0;
}
int test8()
{
    std::cout << "Тест 8 <Операции со множествами: Симметрическая Разность>: " << std::endl;
    Set<int> s1(3, 1, 4, 2);
    Set<int> s2(4, 1, 4, 3, 5);
    std::cout << "s1" << s1 << "s2" << s2 << "symetric_difference()" << s1.symmetric_difference(s2) << std::endl;
    //std::ostream n = std::cout;
    Set<int> s3(5, 1, 2, 3, 4, 5);
    Set<int> s4(4, 9, 8, 7, 6);
    std::cout << "s3" << s3 << "s4" << s4 << "%" << (s3 % s4) << std::endl;
    s3 %= s4;
    std::cout << "s4" << s4 << "%=" << s3 << std::endl;

    return 0;
}
int test9()
{
    printf("Тест 9 <<Исключения>>:\n");
    //throw new SetException();
    try
    {
        throw new SetMemoryException(__LINE__, __FILE__, typeid(test6).name());
    }
    catch (SetMemoryException *err)
    {
        std::cout << err->what();
    }
    try
    {
        throw new SetIncorrectIteratorException(__LINE__, __FILE__, typeid(test6).name());
    }
    catch (SetIncorrectIteratorException *err)
    {
        std::cout << err->what();
    }
    return 0;
}
int main()
{
    printf("Test 1 pass: \n");
    test1();
    printf("Test 2 pass: \n");
    test2();
    printf("Test 3 pass: \n");
    test3();
    printf("Test 4 pass: \n");
    test4();
    printf("Test 5 pass: \n");
    test5();
    printf("Test 6 pass: \n");
    test6();
    printf("Test 7 pass: \n");
    test7();
    printf("Test 8 pass: \n");
    test8();
    printf("Test 9 pass: \n");
    test9();
    return 0;
}
