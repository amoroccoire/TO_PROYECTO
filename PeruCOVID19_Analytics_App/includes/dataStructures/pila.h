#ifndef PILA_H
#define PILA_H

#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T elements[MAX_SIZE];
    int top;

public:
    Stack();
    void push(const T& value);
    T pop();
    bool isEmpty() const;
    bool isFull() const;
};

#endif  // PILA_H
