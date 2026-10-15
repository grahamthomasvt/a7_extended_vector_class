#pragma once
#include <algorithm> // max
#include <stdexcept> // out_of_range and invalid_argument
#include <utility> // move

namespace dsac::array {
///Simplified version of std::vector
/// @tparam T the element type    
template <typename T>
class Vector {
    private:
        /// capacity of the array
        int cap{0};

        /// number of actual entries
        int sz{0};

        /// pointer to array of elements
        T* data{nullptr};

    public:
        /// TODO: Constructs an empty vector
        Vector() = default;

        /// TODO: Constructs a vector with the specified number of elements
        /// Each Element is Value Initialized
        /// @param n number of elements in the vector
        Vector(int n);

        /// TODO: Returns the current capacity of the underlying array
        /// @return the size of the underlying array
        int capacity() const;

        /// TODO: Returns the number of elements stored
        /// @return the number of elements stored
        int size() const;

        /// TODO: Tests whether the vector is empty.
        /// @return true if the vector is empty, false otherwise
        bool empty() const;

        /// TODO: Returns const reference to the element at index i
        /// behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        const T& operator[](int i) const;

        /// TODO: Returns reference to the element at index i
        /// behavior is undefined if i is out of bounds
        /// @param i index of desired element
        /// @return element at index i
        T& operator[](int i);

        /// TODO: Returns const reference to the element at index i
        /// raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        const T& at(int i) const;

        /// TODO: Returns reference to the element at index i
        /// raises out_of_range exception with invalid index
        /// @param i index of desired element
        /// @return element at index i
        /// @throw out_of_range exception if index is invalid for current vector
        T& at(int i);

        /// TODO: Returns a const reference to the first element
        /// behavior is undefined if vector is empty
        /// @return reference to first element
        const T& front() const;

        /// TODO: Returns a live reference to the first element
        /// behavior is undefined if vector is empty
        /// @return reference to first element
        T& front();

        /// TODO: Returns a const reference to the last element
        /// behavior is undefined if vector is empty
        /// @return reference to last element
        const T& back() const;

        /// TODO: Returns a live reference to the last element
        /// behavior is undefined if vector is empty
        /// @return reference to last element
        T& back();

        /// TODO: Inserts an element at end of the vector
        /// @param elem   the new element
        void push_back(const T& elem);

        /// TODO: Removes the last element from the vector
        /// Calls shrink() after removing the element to reduce unused capacity when appropriate
        /// Behavior is undefined if the vector is empty
        void pop_back();

        /// TODO: Inserts an element at index i; 
        /// behavior is undefined if i is out of bounds
        /// @param i      index at which new element should be placed
        /// @param elem   the new element
        void insert(int i, const T& elem);

        /// TODO: Removes the element at index i and shifts subsequent elements left
        /// Calls shrink() after removing the element to reduce unused capacity when appropriate
        /// Behavior is undefined if i is out of bounds
        /// @param i index of element to be removed
        void erase(int i);

        /// TODO: Requests that the vector capacity be at least as large as the indicated capacity
        /// The function has no effect if the current capacity is already large enough
        /// @param minimum the minimum capacity after the operation
        void reserve(int minimum);
    
        /// TODO: Changes the capacity of the vector to new_cap
        /// Existing elements are preserved in their current order
        /// new_cap must be at least as large as the current size
        /// If new_cap is 0, no array is allocated
        /// @param new_cap the new capacity of the vector
        void reallocate(int new_cap);

        /// TODO: Reduces the capacity of the vector when there is substantial unused space
        /// If the size is at most one-fourth of the current capacity, reduces the capacity by half
        /// This function does not reduce the capacity below 1
        void shrink();
        
        /// TODO: Removes unused capacity from the vector
        /// Reduces the capacity to match the current size
        /// If the vector is empty, the capacity becomes 0
        /// The function has no effect if capacity is already equal to size
        void shrink_to_fit();

    private:
        /// TODO: Write a helper function to make a deep copy of another vector
        /// Copy the capacity and size
        /// Allocate a new array and copy all existing elements
        /// Assume the current vector has data as nullptr
        void clone(const Vector& other);

        /// TODO: Write helper function to transfer ownership from another vector
        /// Transfer the capacity, size, and data pointer
        /// Reset the source vector to an empty state
        /// Assume the current vector has data as nullptr
        void transfer(Vector& other);

    public:
        /// TODO: Destructor
        ~Vector();

        /// TODO: Write the copy constructor
        /// Create an independent copy of the given vector
        Vector(const Vector& other);

        /// TODO: Write the copy assignment operator
        /// Handle self-assignment and release existing memory
        /// Copy the contents of the given vector
        /// Return a reference to the current vector
        Vector& operator=(const Vector& other);

        /// TODO: Write the move constructor
        /// Transfer ownership of the resources from the given vector
        /// Leave the source vector empty
        Vector(Vector&& other);

        /// TODO: Write the move assignment operator
        /// Handle self-assignment and release existing memory
        /// Transfer ownership of the resources from the given vector
        /// Return a reference to the current vector
        Vector& operator=(Vector&& other);

    public:
        /// TODO: Implement a bidirectional iterator for the Vector class
        /// Store a pointer to the vector and the current index
        /// Provide operations to access elements, move forward and backward,
        /// and compare iterator positions
        class iterator {
            friend class Vector;
            private:
                Vector* vec;
                int ind;
            public:
                /// TODO: Initialize the iterator with a vector pointer and an index
                iterator(Vector* v=nullptr, int i=-1);
                
                /// TODO: Return a reference to the element at the current position
                T& operator*() const;

                /// TODO: Return a pointer to the element at the current position
                T* operator->() const;

                /// TODO: Move to the next element and return the updated iterator
                iterator& operator++();

                /// TODO: Move to the next element and return the previous iterator
                iterator operator++(int);

                /// TODO: Move to the previous element and return the updated iterator
                iterator& operator--();

                /// TODO: Move to the previous element and return the previous iterator
                iterator operator--(int);

                /// TODO: Return true if both iterators refer to the same vector and index
                bool operator==(iterator rhs) const;
                
                /// TODO: Return true if the iterators refer to different positions or vectors
                bool operator!=(iterator rhs) const;
        };

    public:
        /// TODO: Implement a bidirectional const_iterator for the Vector class
        /// Store a pointer to a constant vector and the current index
        /// Allow read-only access to elements
        /// Support forward and backward movement and iterator comparisons
        class const_iterator {
            private:
                const Vector* vec;
                int ind;
            
            public:
                /// TODO: Initialize the const_iterator with a vector pointer and an index
                const_iterator(const Vector* v=nullptr, int i=-1);

                /// TODO: Return a constant reference to the current element
                const T& operator*() const;

                /// TODO: Return a pointer to the current element without allowing modification
                const T* operator->() const;

                /// TODO: Move forward and return the updated iterator
                const_iterator& operator++();

                /// TODO: Move forward and return the previous iterator
                const_iterator operator++(int);

                /// TODO: Move backward and return the updated iterator
                const_iterator& operator--();

                /// TODO: Move backward and return the previous iterator
                const_iterator operator--(int);

                /// TODO: Compare the vector pointers and indices for equality
                bool operator==(const_iterator rhs) const;

                /// TODO: Determine whether two const_iterators are different
                bool operator!=(const_iterator rhs) const;
        };
    public:
        /// TODO: Write the function to return an iterator to the first element
        iterator begin();

        /// TODO: Write the function to return an iterator past the last element
        iterator end();

        /// TODO: Write the function to return a const_iterator to the first element
        const_iterator begin() const;

        /// TODO: Write the function to return a const_iterator past the last element
        const_iterator end() const;

        /// TODO: Write the function to insert an element before the iterator position
        /// Inserts an element immediately before the given iterator position
        /// @param it     iterator defining the insertion position
        /// @param elem   the new element
        /// @return iterator of newly inserted element
        iterator insert(iterator it, const T& elem);

        /// TODO: Write the function to erase an element at the iterator position
        /// Removes the element at the given iterator position
        /// @param it iterator defining the position of element to be removed
        /// @return iterator just beyond the removed element
        iterator erase(iterator it)
    
}; // Vector class

}  // namespace dsac::array
