//alizalazar9@gmail.com
// ReverseOrderIterator: Iterates over elements in reverse of insertion order

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

    // Template class for reverse iteration over container elements
    template<typename T>
    class ReverseOrderIterator {
    private:
        std::vector<T> ordered; // Copy of elements reversed from original order
        size_t index;           // Current index in the reversed vector

    public:
        // Constructor initializes the iterator with reversed elements
        ReverseOrderIterator(const std::vector<T>& elements, bool is_begin) {
            ordered = elements;                        // Copy original elements
            std::reverse(ordered.begin(), ordered.end()); // Reverse the order
            index = is_begin ? 0 : ordered.size();     // Begin from start or end
        }

        // Dereference operator returns the current element
        const T& operator*() const {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            return ordered[index];
        }

        // Prefix increment operator advances the iterator
        ReverseOrderIterator& operator++() {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            ++index;
            return *this;
        }

        // Equality operator: true if both iterators point to same index
        bool operator==(const ReverseOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality operator: true if iterators are at different positions
        bool operator!=(const ReverseOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
