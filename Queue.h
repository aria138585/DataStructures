#pragma once

#include "config.h"

/**
 * INSTRUCTIONS:
 * Make sure that the head file `config.h` is included.
 * include this file after including the `config.h`.
 * define the `CORE` macro in your project file: ```#define CORE ...```
 * Assign `ARRAY` OR `LINKED_LIST` as the values for this macro
 * `ARRAY` extends to 1, and `LINKED_LIST` extends to 2
 * these values are defined in the `config.h` head file (this is why you should include it first!)
 *
 *
 * --------------- Contact ------------------
 * Github:      aria138585
 * Email:       ariamosaferi@gmail.com
 */

#if CORE == ARRAY
template <typename T>
class Queue
{
    Queue();
    ~Queue();

private:
    int Size;
    T *Array, *Head, *Tail;
};

#elif CORE == LINKED_LIST
#include "LinkedList.h"
template <typename T>
class Queue
{
    Queue();
    ~Queue();

private:
    LinkedList<T> List;
    Node<T> *Head, *Tail;
};

#else
#error The core is not chosen!
#endif