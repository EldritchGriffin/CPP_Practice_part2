#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
        T &operator[](unsigned int index);
        unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    *this = copy;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        delete [] _array;
        _array = new T[copy._size];
        for (unsigned int i = 0; i < copy._size; i++)
            _array[i] = copy._array[i];
        _size = copy._size;
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size || index < 0)
        throw std::out_of_range("Out of range");
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

#endif