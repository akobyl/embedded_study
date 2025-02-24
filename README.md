# Embedded C Programming Study Repository

This repository is a collection of common embedded and system low-level programming questions which may come up in interviews.  There are some test cases as well to help ensure everything works as expected!

## Topics

- [x] Double Linked List
- [x] Circular Buffer
- [ ] Simple malloc
- [ ] Memory alligned malloc
- [ ] Sample RTOS sensor data collection
- [ ] Hash table
- [ ] Merge sort

## How to use

### Requirements

* Install [CMake](https://cmake.org/download/)
* Install gcc


### Building and Testing

1. In the root directory of the repository, run `make build`
2. To test, run `make test`
3. For detailed output, execute the full gtest binary `cd build && ./test_collection`


### Example output

```bash
❯ make test
Running tests...
Test project /home/andy/dev/embedded_study/build
      Start  1: DoubleLinkedListTest.CreateList
 1/10 Test  #1: DoubleLinkedListTest.CreateList .....   Passed    0.00 sec
      Start  2: DoubleLinkedListTest.ReverseList
 2/10 Test  #2: DoubleLinkedListTest.ReverseList ....   Passed    0.00 sec
      Start  3: DoubleLinkedListTest.ReverseList2
 3/10 Test  #3: DoubleLinkedListTest.ReverseList2 ...   Passed    0.00 sec
      Start  4: CircularBuffer.testCreate
 4/10 Test  #4: CircularBuffer.testCreate ...........   Passed    0.00 sec
      Start  5: CircularBuffer.testDestroy
 5/10 Test  #5: CircularBuffer.testDestroy ..........   Passed    0.00 sec
      Start  6: CircularBuffer.testWriteSingle
 6/10 Test  #6: CircularBuffer.testWriteSingle ......   Passed    0.00 sec
      Start  7: CircularBuffer.testWriteDouble
 7/10 Test  #7: CircularBuffer.testWriteDouble ......   Passed    0.00 sec
      Start  8: CircularBuffer.testWrite
 8/10 Test  #8: CircularBuffer.testWrite ............   Passed    0.00 sec
      Start  9: CircularBuffer.testReset
 9/10 Test  #9: CircularBuffer.testReset ............   Passed    0.00 sec
      Start 10: CircularBuffer.testOverflow
10/10 Test #10: CircularBuffer.testOverflow .........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 10

Total Test time (real) =   0.02 sec
```
