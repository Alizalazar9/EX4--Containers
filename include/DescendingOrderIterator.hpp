//alizalazar9@gmail.com
// Iterator for traversing elements in descending sorted order

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

    // Templated class for descending order iteration over a container of type T
    template<typename T>
    class DescendingOrderIterator {
    private:
        std::vector<T> ordered; // Stores a sorted (descending) copy of the input elements
        size_t index;           // Current index in the sorted vector

    public:
        // Constructor
        // elements: the original container's elements
        // is_begin: true to start at beginning (index 0), false to represent end iterator
        DescendingOrderIterator(const std::vector<T>& elements, bool is_begin) {
            ordered = elements;                                             // Copy elements
            std::sort(ordered.begin(), ordered.end(), std::greater<T>());  // Sort in descending order
            index = is_begin ? 0 : ordered.size();                          // Set starting index
        }

        // Dereference operator: accesses the current element
        const T& operator*() const {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            return ordered[index];
        }

        // Pre-increment operator: advances the iterator
        DescendingOrderIterator& operator++() {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            ++index;
            return *this;
        }

        // Equality operator: checks if iterators are at the same position
        bool operator==(const DescendingOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality operator
        bool operator!=(const DescendingOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
