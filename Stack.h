#pragma once

#include "config.h"
#include "data.h"

/*
 * INSTRUCTIONS:
 * Make sure that the head file `config.h` is included in your file.
 * include this file after including the `config.h`.
 * define the `INTERFACE` macro in your project file: #define INTERFACE ...
 * Assign `ARRAY` OR `LINKED_LIST` as the values for this macro
 * `ARRAY` extends to 1, and `LINKED_LIST` extends to 2
 * these values are defined in the `config.h` head file (this is why you should include it first!)
 * 
 * The 'Stack class is defined as a template class.
 * 
 * 
 * --------------- Contact ------------------
 * Github:      aria138585
 * Email:       ariamosaferi@gmail.com
*/

#if CORE == ARRAY
template<typename T>
class Stack
{
    friend std::ostream &operator<<(std::ostream& out, Stack& stack);

 public:
    Stack(int size)
    {
        this->Size = size;
        Array = new T[size];
        top = nullptr;
        top_index = -1;
    }
    Stack(const Stack &other)
    {
        this->Size = other.Size;
        this->Array = new T[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->Array[i] = other.Array[i];
        }
        this->top_index = other.top_index;
        this->top = &(this->Array[this->top_index]);
    }
    ~Stack()
    {
        if (top != nullptr)
        {
            delete [] Array;
        }
        else
        {
            delete Array;
        }
        top = nullptr;
    }
    Stack operator=(const Stack &other)
    {
        if (this == &other)
            return *this;
        delete [] this->Array;
        this->Size = other.Size;
        this->Array = new T[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->Array[i] = other.Array[i];
        }
        this->top_index = other.top_index;
        this->top = &(this->Array[this->top_index]);
        return *this;
    }
    void push(data Data)
    {
        if (top == &Array[Size - 1]) // Overflow handler
        {
            std::cerr << "Error: Stack overflow.\n";
            throw std::runtime_error("Stack overflow");
        }
        else if (top == nullptr)
        {
            top = &Array[0];
            *top = Data;
            top_index = 0;
            return;
        }
        top++;
        top_index++;
        *top = Data;
    }
    T pop()
    {
        if (top == nullptr) // Underflow handler
        {
            std::cerr << "Error: Stack underflow.\n";
            throw std::runtime_error("Stack underflow");
        }
        data popping_value = *top;
        top_index--;
        top = (top_index == -1) ? nullptr : top - 1;
        return popping_value;
    }
    data get_top() const
    {
        return *top;
    }
 private:
    int Size;
    T *Array;
    T *top;
    int top_index;
};

#elif CORE == LINKED_LIST
#include "LinkedList.h"
template<typename T>
class Stack
{
    Stack(int size)
    {
        this->Size = size;
        this->top = nullptr;
    }
    Stack(const Stack &other)
    {
        this->Size = other.Size;
        this->List = other.List;
    }
    ~Stack()
    {
        List.clear();
    }
    Stack operator=(const Stack &other)
    {
        this->clear();
        this->Size = other.Size;
        this->List = other.List;
    }
    void push(T Data)
    {
        if (top_index == Size)
        {
            std::cerr << "Error: Stack overflow.\n";
            return;
        }
        List.append(new Node<T>(Data));
        top_index++;
    }
    T pop()
    {
        if (top_index == 0)
        {
            std::cerr << "Error: Stack underflow.\n";
            return 0;
        }
        T last = List[top_place];
        List.Remove(new Node<T>(List[top_place]));
        top_place--;
        return last;
    }
    Node<T> get_top() const
    {
        return List[top_place];
    }

private:
    LinkedList<T> List;
    Node<T> *top;
    int Size, top_place;
};

#else
    #error No intereface is defined!

#endif