/******************************************************************************
 * Course: CSC XXX – Data Structures
 * Semester: Spring 2026
 * Assignment: 1 – Stacks and Queues (Linked List Implementation)
 *
 * Description:
 * This header file defines the node structure and the Stack and Queue
 * classes using a singly linked list implementation.
 *
 * Author: Cameron Buck
 ******************************************************************************/

#ifndef SQLL_H
#define SQLL_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

/**
 * node
 * ---------------------------------------------------------
 * A singly linked list node used for both Stack and Queue.
 */
struct node
{
    string data;
    node* next;

    node(string &value)
    {
        data = value;
        next = nullptr;
    }
};

/**
 * Stack (LIFO)
 * ---------------------------------------------------------
 * Linked-list implementation of a stack.
 */
class Stack
{
private:
    node* top;

public:
    Stack();
    ~Stack();

    void push(string &value);
    string pop();
    string peek();
    bool isEmpty();
    void display();
};

/**
 * Queue (FIFO)
 * ---------------------------------------------------------
 * Linked-list implementation of a queue.
 */
class Queue
{
private:
    node* front;
    node* rear;

public:
    Queue();
    ~Queue();

    void enqueue(string &value);
    string dequeue();
    bool isEmpty();
    void display();
};

/* Task 3 */
double evaluateExpression(string& expr);

/* Task 4 */
void josephus(int n, int k);

#endif

