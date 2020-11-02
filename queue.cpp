/**
 * @file queue.cpp
 * Implementation of the Queue class.
 *
 * Modify and turn in this file for the PA!
 *
 */

#include <chrono>
#include <string>

class TimeIt {
  public:
    TimeIt(std::string name, size_t n1, size_t n2):name_(name), n1_(n1), n2_(n2),
      start_(std::chrono::high_resolution_clock::now()){
      printf("%s (%ld, %ld) >>\n", name.c_str(), n1_, n2_);
    }
    ~TimeIt(){
      std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> t = end - start_;
      printf("%s (%ld, %ld) << takes %f (s)\n", name_.c_str(), n1_, n2_, t.count());
    }
  private:
    std::string name_;
    size_t n1_, n2_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};


/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
 */
template <class T> void Queue<T>::enq(T const &newItem)
{
 // TimeIt("Queue::enq", stack_1.size(), stack_2.size());
  while (!stack_2.empty()) {
    stack_1.push(stack_2.pop());
  }
  stack_1.push(newItem);
}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The object that used to be at the front of the Queue.
 */
template <class T> T Queue<T>::deq()
{
 // TimeIt("Queue::deq", stack_1.size(), stack_2.size());
  if (stack_1.size() == 1) return stack_1.pop();

  while (!stack_1.empty()) {
    stack_2.push(stack_1.pop());
  }
  return stack_2.pop();
}

/**
 * Finds the object at the front of the Queue, and returns it to the
 * caller. Unlike deq(), this operation does not alter the queue.
 *
 * @return The item at the front of the queue.
 */
template <class T> T Queue<T>::peek()
{
 // TimeIt("Queue::peek", stack_1.size(), stack_2.size());
  /**
   * @todo Your code here! You will need to replace the following line.
   */
  while (!stack_1.empty()) {
    stack_2.push(stack_1.pop());
  }
  return stack_2.peek();
}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
 */
template <class T> bool Queue<T>::empty() const
{
  return (stack_1.empty() && stack_2.empty());
}
