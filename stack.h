/**
 * @file stack.h
 * Definition of the Stack class.
 *
 * You **should not** modify this file for the PA!
 *
 */
#ifndef _STACK_H_
#define _STACK_H_

#define DEFAULTCAPACITY 4 // Initial capicity of the array.
#define EXPANSIONFACTOR 2 // Factor to increase or decrease capacity on resize.
#define SHRINKWHEN 4      // When size <= capacity/SHRINKWHEN, resize down

#include <cstddef>
using namespace std;

template <class T> class Stack
{
 public:
  Stack();

  ~Stack();

  /**
   * Adds the parameter object to the top of the Stack.
   *
   * @param newItem The object to be added to the Stack.
   */
  void push(const T &newItem);

  /**
   * Removes the object on top of the Stack, and returns it.
   *
   * @return The element that was at the top of the Stack.
   */
  T pop();

  /**
   * Finds the object on top of the Stack, and returns it to the caller.
   * Unlike pop(), this operation does not alter the Stack itself.
   *
   * @return The element at the top of the Stack.
   */
  T peek();

  /**
   * Determines if the Stack is empty.
   *
   * @return Whether or not the stack is empty (bool).
   */
  bool empty() const;

  /**
   * Return the maximum number of items the stack can hold.
   *
   * Note: This is an implementation detail we would normally hide.
   * We include it here for testing purposes.
   */
  size_t capacity() const;

  /**
   * Return the number of items on the stack.
   */
  size_t size() const;

 private:
  /**
   * The maximum number of items the stack can store without a resize
   */
  size_t max_items;

  /**
   * The number of items currently in the stack
   */
  size_t num_items;

  /**
   * The dynamic array representing our Stack
   */
  T *items;

  /**
   * Resize the the member variable `items`.
   * Don't forget to free up any memory that is no longer used.
   *
   * @param n The size of the stack after resizing
   */
  void resize(size_t n);
};

#include "stack.cpp" // needed for template instantiation

#endif
