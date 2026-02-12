/******************************************************************************
 * Course: CSC XXX – Data Structures
 * Semester: Spring 2026
 * Assignment: 1 – Stacks and Queues
 *
 * Description:
 * This file implements:
 *  - Stack operations (push, pop)
 *  - Queue operations (enqueue, dequeue)
 *  - Dijkstra’s Two-Stack Algorithm
 *  - Josephus Problem solution
 *
 * Author: Cameron Buck
 ******************************************************************************/

#include "sqll.h"

//////////////////////// STACK IMPLEMENTATION ////////////////////////

Stack::Stack()
{
    top = nullptr;
}

/**
 * Destructor
 * Frees all dynamically allocated nodes.
 * Time Complexity: O(n)
 */
Stack::~Stack()
{
    while (!isEmpty())
        pop();
}

/**
 * push
 * Inserts a new element at the top of the stack.
 * Time Complexity: O(1)
 */
void Stack::push(string &value)
{
    node* newNode = new node(value);
    newNode->next = top;
    top = newNode;
}

/**
 * pop
 * Removes and returns the top element of the stack.
 * Throws runtime_error if empty.
 * Time Complexity: O(1)
 */
string Stack::pop()
{
    if (isEmpty())
        throw runtime_error("Stack is empty");

    node* temp = top;
    string value = temp->data;
    top = top->next;
    delete temp;

    return value;
}

string Stack::peek()
{
    if (isEmpty())
        throw runtime_error("Stack is empty");

    return top->data;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::display()
{
    node* current = top;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//////////////////////// QUEUE IMPLEMENTATION ////////////////////////

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue()
{
    while (!isEmpty())
        dequeue();
}

/**
 * enqueue
 * Inserts element at the rear of the queue.
 * Time Complexity: O(1)
 */
void Queue::enqueue(string &value)
{
    node* newNode = new node(value);

    if (isEmpty())
    {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/**
 * dequeue
 * Removes and returns the front element.
 * Throws runtime_error if empty.
 * Time Complexity: O(1)
 */
string Queue::dequeue()
{
    if (isEmpty())
        throw runtime_error("Queue is empty");

    node* temp = front;
    string value = temp->data;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return value;
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

void Queue::display()
{
    node* current = front;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//////////////////////// TASK 3 – DIJKSTRA ////////////////////////

/**
 * evaluateExpression
 *
 * Implements Dijkstra’s Two-Stack Algorithm.
 *
 * Algorithm:
 * 1. If token is a number → push to value stack.
 * 2. If token is operator → push to operator stack.
 * 3. If token is ')' → pop two values and one operator,
 *    evaluate, and push result back.
 *
 * Expression must be fully parenthesized.
 *
 * Time Complexity: O(n)
 */
double evaluateExpression(string& expr)
{
    Stack ops;
    Stack vals;

    string token;
    stringstream ss(expr);

    while (ss >> token)
    {
        if (token == "(")
            continue;

        else if (token == "+" || token == "-" ||
                 token == "*" || token == "/" ||
                 token == "^")
        {
            ops.push(token);
        }
        else if (token == ")")
        {
            string op = ops.pop();
            double right = stod(vals.pop());
            double left = stod(vals.pop());

            double result;

            if (op == "+") result = left + right;
            else if (op == "-") result = left - right;
            else if (op == "*") result = left * right;
            else if (op == "/") result = left / right;
            else result = pow(left, right);

            string resStr = to_string(result);
            vals.push(resStr);
        }
        else
        {
            vals.push(token);
        }
    }

    return stod(vals.pop());
}

//////////////////////// TASK 4 – JOSEPHUS ////////////////////////

/**
 * josephus
 *
 * Solves the Josephus problem using a queue.
 *
 * Logic:
 *  - Enqueue soldiers 1 through n.
 *  - Rotate k-1 soldiers to rear.
 *  - Remove kth soldier.
 *  - Repeat until one remains.
 *
 * Time Complexity: O(nk)
 */
void josephus(int n, int k)
{
    Queue q;

    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        q.enqueue(s);
    }

    while (n > 1)
    {
        for (int i = 1; i < k; i++)
        {
            string temp = q.dequeue();
            q.enqueue(temp);
        }

        q.dequeue();
        n--;
    }

    cout << "Survivor: " << q.dequeue() << endl;
}
