#ifndef _STACK_H
#define _STACK_H

#include "exceptions.h"

const int STACK_SIZE = 64;
template <class StackType>

class Stack {
public:
    Stack(void) { count = 0; }
    ~Stack(void) { }

    void clear(void) { count = 0; }
    int size(void) { return count; }
    bool isEmpty(void) { return count == 0; }

    void push(const StackType &d) throw (ContainerFullException) {

        if (count == STACK_SIZE)
            throw ContainerFullException("Stack");

        data[count] = d;

        count++;
    }

    StackType pop(void) throw (ContainerEmptyException) {

        if (!count)
            throw ContainerEmptyException("Stack");

        count--;

        return data[count];

    }

    StackType peek(void) throw (ContainerEmptyException) {

        if (!count)
            throw ContainerEmptyException("Stack");

        return data[count-1];
    }

private:
    StackType
            data[STACK_SIZE];
    int
            count;
};

#endif