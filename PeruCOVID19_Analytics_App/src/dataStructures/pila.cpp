
#include "../../includes/dataStructures/pila.h"

// Implementa del constructor
template <typename T>
Stack<T>::Stack() : top(-1) {}

// Implementación de push
template <typename T>
void Stack<T>::push(const T& value) {
    if (isFull()) {
        throw std::overflow_error("La pila está llena");
    }
    elements[++top] = value;
}

// Implementación de pop
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("La pila está vacía");
    }
    return elements[top--];
}

// Implementación de isEmpty
template <typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

// Implementación de isFull
template <typename T>
bool Stack<T>::isFull() const {
    return top == MAX_SIZE - 1;
}

