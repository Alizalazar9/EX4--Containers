// alizalazar9@gmail.com
// This is a simple demo to check that all iterators and container operations work

#include <iostream>
#include "include/MyContainer.hpp"

using namespace std;
using namespace mycontainers;

int main() {
    // Create a container of integers
    MyContainer<int> container;

    // Add some values (including a duplicate 15 to test removal)
    cout << "=== Adding Elements ===" << endl;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    container.add(15); // adding 15 again to test removing all of it later

    cout << "Container after addition: " << container << endl;
    cout << "Size: " << container.size() << endl;

    // Now remove the value 15 (should remove both instances)
    cout << "\n=== Removing Element 15 ===" << endl;
    try {
        container.remove(15);  // if no 15s were found, this would throw
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Container after removal: " << container << endl;
    cout << "Size: " << container.size() << endl;

    // Try out all iterators below:

    // Sorted from smallest to largest
    cout << "\nAscending Order Iterator: " << endl;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Sorted from largest to smallest
    cout << "\n Descending Order Iterator: " << endl;
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Alternates: smallest, largest, next smallest, next largest, etc.
    cout << "\n Side Cross Order Iterator: " << endl;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Prints elements in reverse of the order they were added
    cout << "\n Reverse Order Iterator: " << endl;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Just prints in the exact order they were added
    cout << "\n Order Iterator (Insertion Order) " << endl;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // Starts from the middle value (sorted) and jumps outwards
    cout << "\n Middle Out Order Iterator " << endl;
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
