//alizalazar9@gmail.com
// OrderIterator: Iterates through elements in the order they were inserted

#pragma once
#include <vector>
#include <stdexcept>

namespace mycontainers {

    // Template class for iterating over container elements in insertion order
    template<typename T>
    class OrderIterator {
    private:
        std::vector<T> ordered; // Copy of the original elements in insertion order
        size_t index;           // Current position in the iteration

    public:
        // Constructor initializes iterator with elements and sets index based on begin/end
        OrderIterator(const std::vector<T>& elements, bool is_begin) {
            ordered = elements;                        // Copy elements in the order added
            index = is_begin ? 0 : ordered.size();     // Set index to start or past-the-end
        }

        // Dereference operator returns the element at the current index
        const T& operator*() const {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            return ordered[index];
        }

        // Prefix increment operator advances the iterator
        OrderIterator& operator++() {
            if (index >= ordered.size()) throw std::out_of_range("Dereferencing end iterator.");
            ++index;
            return *this;
        }

        // Equality comparison: true if both iterators point to the same index
        bool operator==(const OrderIterator& other) const {
            return index == other.index;
        }

        // Inequality comparison: true if iterators point to different indices
        bool operator!=(const OrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
