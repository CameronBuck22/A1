/******************************************************************************
 * Main Driver Program
 *
 * Provides menu interface to test:
 *  - Stack
 *  - Queue
 *  - Expression evaluation
 *  - Josephus problem
 ******************************************************************************/

#include "sqll.h"

int main()
{
    Stack stack;
    Queue queue;

    int choice;
    string input;
    int n, k;

    do {
        cout << "\n1. Push\n2. Pop\n3. Enqueue\n4. Dequeue\n";
        cout << "5. Evaluate Expression\n6. Josephus\n7. Exit\n";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cin >> input;
                stack.push(input);
                break;

            case 2:
                cout << stack.pop() << endl;
                break;

            case 3:
                cin >> input;
                queue.enqueue(input);
                break;

            case 4:
                cout << queue.dequeue() << endl;
                break;

            case 5:
                getline(cin, input);
                cout << evaluateExpression(input) << endl;
                break;

            case 6:
                cin >> n >> k;
                josephus(n, k);
                break;
        }

    } while (choice != 7);

    return 0;
}
