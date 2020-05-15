#include "garbageCollector.h"

extern "C" int Subtract(int num1, int num2)
{
    return num1 - num2;
}

extern "C" int Add(int num1, int num2)
{
    return num1 + num2;
}

extern "C" int getInfo(int num)
{
    return garbageCollector::prueba(num);
}

extern "C" void get_md5_string(string s)
{
    s = "hoasdasdasdasd";
}