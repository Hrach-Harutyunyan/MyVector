#include "myVector.h"

template <typename T>
myVector<T>::myVector ()
        : m_size{}
        , m_capacity{5}
        , m_buffer{new T[m_capacity]}
{ }

template <typename T>
myVector <T>::~myVector () {
    delete [] m_buffer;
    m_buffer = nullptr;
}

template <typename T>
size_t  myVector <T>::size (){
    return m_size;
}

template <typename T>
size_t  myVector <T>::capacity (){
    return m_capacity;
}

template <typename T>
void myVector <T>::push_back (const T& elem) {
    if(m_size == m_capacity) {
        m_capacity *= 2;
        T* tmp = new T[m_capacity];

        for (size_t i = 0; i < m_size; i++) {
            tmp[i] = m_buffer[i];
        }
        delete [] m_buffer;
        m_buffer = tmp;
        tmp = nullptr;
    }
    m_buffer[m_size] = elem;
    m_size++;
}

template <typename T>
void myVector <T>::pop_back () {
    if (m_size > 0){
        m_size --;
    }
}

template <typename T>
void myVector<T>::shrink_to_fit () {
    if (m_capacity > m_size){
        m_capacity = m_size;
    }
}

template <typename T>
void myVector <T>::resize (const size_t otherSize) {
    if (otherSize > m_size){
        if(m_capacity < otherSize){
            while (m_capacity < otherSize){
            m_capacity *= 2;
            }
            T* tmp = new T [m_capacity];
            for (size_t i = 0; i < m_size; i++){
                tmp[i] = m_buffer[i];
            }
            delete[] m_buffer;
            m_buffer = tmp;
            tmp = nullptr;
            m_size = otherSize;
        }else {
            size_t tmp_size = m_size;
            m_size = otherSize;
            for (size_t i = tmp_size; i < m_size; i++){
                m_buffer[i] = 0;
            }
            
        }               
    }else {
        m_size = otherSize;
    }
}

template <typename T>
bool myVector <T>::empty (){
    return !m_size;
}

template <typename T>
void myVector <T>::erase (const size_t index){
    if (index >= 0 && index < m_size){
        m_size--; 
        T* tmp = new T [m_size];
        for (size_t i = 0, j = 0; i < m_size+1, j < m_size; i++, j++) {
            if (i == index) {
                j--;
                continue;
            }else{
                tmp[j] = m_buffer[i];
            }
        }
        delete[] m_buffer;
        m_buffer = tmp;
        tmp = nullptr;       
    }
}

template <typename T>
void myVector <T>::insert (const size_t index, const T& num) {
    if (index >= 0 && index <= m_size){
        m_size ++;
        T* tmp = new T[m_size];
        for (size_t i = 0, j = 0; i < m_size, j < m_size; i++, j++){
            if (i == index){
                tmp[i] = num;
                j--;
            }else{
                tmp[i] = m_buffer[j];
            }          
        }
        delete[] m_buffer;
        m_buffer = tmp;
        tmp = nullptr;
    }
}

template <typename T>
void myVector <T>::clear(){
    if(m_size > 0){
        m_size = 0;
    }
}

template <typename T>
void myVector <T>::reserve(const size_t newCapacity){
    if (m_capacity < newCapacity){
        T* tmp = new T [m_capacity];
        for (int i = 0; i < m_size; i++){
            tmp[i] = m_buffer[i];
        }
        delete[] m_buffer;
        m_buffer = tmp;
        tmp = nullptr;
        m_capacity = newCapacity;
    }
}

template <typename T>
size_t myVector <T>::at(const size_t index){
    if (index >= 0 && index < m_size){
        return m_buffer[index];
    }else {
        std::cout << "out of Range:" << std::endl; 
    }   
}

template <typename T>
T& myVector <T>::operator[](size_t index){
    return m_buffer[index];
}
