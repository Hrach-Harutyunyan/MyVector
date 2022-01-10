#include <iostream>

template <typename T>

class myVector
{
private:
    size_t m_size {};
    size_t m_capacity {};
    T* m_buffer = nullptr;

public:
    myVector ();
    size_t size ();
    size_t capacity ();
    void push_back (const T&);
    void pop_back ();
    void shrink_to_fit ();
    void resize (const size_t);
    bool empty ();
    void erase (const size_t);
    void insert (const size_t, const T&);
    void clear ();
    void reserve (const size_t);
    size_t at (const size_t );
    T& operator[] (const size_t );
    ~myVector ();
};
