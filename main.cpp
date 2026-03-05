#include <iostream>

template <class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c)
{
  T* result = nullptr;
  if (c == nullptr)
  {
    result = new T[sa + sb]; // Нужен конструктор по умолчанию
  }
  else
  {
    result = c;
  }
  try
  {
    size_t lead = 0;
    for (size_t i = 0; i < sa; ++i)
    {
      result[lead++] = a[i]; //тип Т должен содержать оператор присваивания 
    }
        
    for (size_t j = 0; j < sb; ++j)
    {
      result[lead++] = b[j]; // нужен оператор присваивания
    }
 
    for (size_t i = 0; i < sa + sb - 1; ++i) 
    {
      for (size_t j = 0; j < sa + sb - i - 1; ++j) 
      {
        if (result[j] > result[j + 1])
        {
          T temp = result[j]; // должен быть копирующий конструктор
          result[j] = result[j + 1]; //нужен оператор присваивания
          result[j + 1] = temp; //нужен оператор присваивания
        }
      }
    }
  }
  catch (...)
  {
    if (c == nullptr)
    {
      delete [] result; //должен иметь деструктор
    }
    throw;
  }
  return result;
}
