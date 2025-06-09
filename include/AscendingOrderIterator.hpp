//alizalazar9@gmail.com
// Iterator for traversing elements in ascending sorted order

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

    // Templated class for ascending order iteration over a container of type T
    template<typename T>
    class AscendingOrderIterator {
    private:
        std::vector<T> ordered; // Stores a sorted copy of the input elements
        size_t index;           // Current index in the sorted vector

    public:
        // Constructor
        // elements: the original container's elements
        // is_begin: true if we want to start from the beginning, false if from the end
        AscendingOrderIterator(const std::vector<T>& elements, bool is_begin) {
            ordered = elements;                             // Copy elements
            std::sort(ordered.begin(), ordered.end());      // Sort in ascending order
            index = is_begin ? 0 : ordered.size();          // Set starting index
        }

        // Dereference operator: returns reference to the current element
        const T& operator*() const {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            return ordered[index];
        }

        // Pre-increment operator: advances the iterator
        AscendingOrderIterator& operator++() {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            ++index;
            return *this;
        }

        // Equality comparison operator
        bool operator==(const AscendingOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality comparison operator
        bool operator!=(const AscendingOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
