#pragma once
#include <iostream>

//(a)
using constant = int;

template <typename T>
class CustomVector {

private:

    //(b)
    constant m_reallocationGrowthRate { 2 };
    size_t m_size { 0 };
    size_t m_capacity { 1 };
    T* m_memPtr { nullptr };

protected:
    //(c.1) are helper functions like these necessary or extra clutter
    bool isEmpty(){
        return m_size == 0;
    }
    bool isFullCapacity(){
        return m_size == m_capacity;
    }
    //(c.2) this or throwing errors 
    bool boundsChecker(int index){
        return ((index <= m_size) ? true : false);
    }

    //(d) how is my spacing? Should I space out lines more frequently, is there a certain style?
    // optimize isFullCapacity If
    void insertValueAtEnd(T v){
        // if (isEmpty()){
        //     m_size++;
        //     m_capacity = m_size * m_reallocationGrowthRate;
        //     m_memPtr = new T(m_capacity);
        //     *m_memPtr = v;
        // } else {
        //     *(m_memPtr + m_size) = v;
        //     m_size++;

        //     //memory reallocation
        //     if (isFullCapacity()){
        //         T temp_array[m_size];
        //         for (int x = 0; x < m_size; x++){
        //             temp_array[x] = *(m_memPtr + x);
        //         }
        //         m_capacity = 2 * m_capacity;
        //         delete m_memPtr;
        //         m_memPtr = new T(m_capacity);
        //         for (int x = 0; x < m_size; x++){
        //             *(m_memPtr + x) = temp_array[x];
        //         }
             
        //     }
        // }

        //check capacity - WHAT
        // if full capacity - WHY
        // pay the current session cost not future
        if (isFullCapacity())
        {
            // calc new cap - HOW
            m_capacity = m_capacity * m_reallocationGrowthRate; 
            // alloc new ptr - HOW
            T* new_memPtr = new T(m_capacity);
            // copy from prev to new - WHAT
            // compiler optimizes x++ to ++x
            for (int x = 0; x < m_size; ++x)
            {
                *(new_memPtr + x) = *(m_memPtr + x);
            }
            // delete prev ptr - HOW
            delete m_memPtr;
            // setting the addr to the newly allocated memory - HOW 
            m_memPtr = new_memPtr;
               std::cout << "insert successful memory has been reallocated to a larger vector"
                "with a current size of: " << m_size << " and a capacity of: "<< m_capacity << std::endl;
        }
        *(m_memPtr + m_size) = v;
        m_size++;
    }
    
    T getValueAt(int index){
        return *(m_memPtr + index);
    }
    
    size_t getSize(){
        return m_size;
    }

public:

    CustomVector(): m_memPtr {new T(m_capacity)}{}

    void pushBack(T value){
        insertValueAtEnd(value);
    }
    
    //read and write enabled through reference return type
    T& operator[](int index){
        if(boundsChecker(index)){
            return getValueAt(index);
        }
    }
    
    void remove(int index){
        if(boundsChecker(index)){
            while(index != m_size){
                *(m_memPtr + index) = *(m_memPtr + index + 1);
                index++;
            }
            m_size--;
        }
    }

    size_t size(){
        return getSize();
    }
    

};