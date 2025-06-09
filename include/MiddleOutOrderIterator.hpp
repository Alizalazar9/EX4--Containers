//alizalazar9@gmail.com
// Iterator for traversing elements from the middle outwards (center → right → left)

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace mycontainers {

    // Templated class for middle-out order iteration over a container of type T
    template<typename T>
    class MiddleOutOrderIterator {
    private:
        std::vector<T> ordered; // Stores the elements arranged in middle-out order
        size_t index;           // Current index in the ordered vector

    public:
        // Constructor
        // elements: original elements from the container
        // is_begin: true for begin iterator, false for end
        MiddleOutOrderIterator(const std::vector<T>& elements, bool is_begin) {
            std::vector<T> sorted = elements;
            std::sort(sorted.begin(), sorted.end()); // First sort the elements

            int mid = sorted.size() / 2; // Calculate the center index
            int left = mid - 1;
            int right = (sorted.size() % 2 == 0) ? mid : mid + 1;

            // If the list isn't empty, build the middle-out order
            if (!sorted.empty()) {
                if (sorted.size() % 2 != 0) {
                    // If size is odd, include the middle element first
                    ordered.push_back(sorted[mid]);
                }
                // Then add elements alternating right and left of center
                while (left >= 0 || right < (int)sorted.size()) {
                    if (right < (int)sorted.size()) {
                        ordered.push_back(sorted[right++]);
                    }
                    if (left >= 0) {
                        ordered.push_back(sorted[left--]);
                    }
                }
            }

            // Set iterator position: 0 for begin, size for end
            index = is_begin ? 0 : ordered.size();
        }

        // Dereference operator: returns the current element
        const T& operator*() const {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            return ordered[index];
        }

        // Pre-increment: moves to the next element
        MiddleOutOrderIterator& operator++() {
            if (index >= ordered.size()) {
                throw std::out_of_range("Dereferencing end iterator.");
            }
            ++index;
            return *this;
        }

        // Comparison operators
        bool operator==(const MiddleOutOrderIterator& other) const {
            return index == other.index;
        }

        bool operator!=(const MiddleOutOrderIterator& other) const {
            return !(*this == other);
        }
    };

} // namespace mycontainers
