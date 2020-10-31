/**
 * @file queue.h
 * Definition of the Queue class.
 *
 * You **should not** modify this file for the PA!
 *
 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

/**
 * Queue class: represents a standard queue. Templated to hold elements of
 * any type. **You must only use the two private member Stacks as your
 * storage space! You cannot create new private member variables to hold
 * your objects!** It is up to you to determine how to use them, however.
 *
 * Your Queue class should take O(1) time per operation over n operations
 * (amortized). There is an obvious solution that takes \Theta(n) time per
 * operation over n operations, but this will not recieve full marks.
 *
 * You **should not** modify this file for the PA!
 *
 */
template <class T> class Queue
{
 public:
  /**
   * Adds the parameter object to the back of the Queue.
   *
   * @note This should take O(1) time per operation amortized over n ops!
   *
   * @param newItem object to be added to the Queue.
   */
  void enq(const T &newItem);

  /**
   * Removes the object at the front of the Queue, and returns it to
   * the caller. You may assume that this function is only called
   * when the Queue is non-empty.
   *
   * @note This should take O(1) time per operation amortized over n ops!
   *
   * @return The item that used to be at the front of the Queue.
   */
  T deq();

  /**
   * Finds the object at the front of the Queue, and returns it to
   * the caller. Unlike deq(), this operation does not alter the
   * queue. You may assume that this function is only called when the
   * Queue is non-empty.
   *
   * @note This should take O(1) time per operation amortized over n ops!
   *
   * @return The item at the front of the queue.
   */
  T peek();

  /**
   * Determines if the Queue is empty.
   *
   * @note This should take O(1) time per operation amortized over n ops!
   *
   * @return bool which is true if the Queue is empty, false
   *	otherwise.
   */
  bool empty() const;

 private:
  Stack<T> stack_1; /**< One of the two Stack objects you must use. */
  Stack<T> stack_2; /**< The other of the two Stack objects you must use. */
};
#include "queue.cpp"
#endif
