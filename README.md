# push_swap
 A very simple and a highly straightforward algorithm project: data must be sorted.

## Introduction
* The project is to create a program that uses two stacks to sort ascending to `stack a`.
* The `stack a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The `stack b` is empty.
* And must output the commands used as the sort progresses.
* The commands are as follows.

  sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.   
  sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.   
  ss : sa and sb at the same time   
   <img alt="image" src="https://github.com/leebo155/push_swap/blob/main/img/push_swap1.jpg">   

  pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.   
  pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.   
  <img alt="image" src="https://github.com/leebo155/push_swap/blob/main/img/push_swap2.jpg">   

  ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.   
  rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.   
  rr : ra and rb at the same time.   
  <img alt="image" src="https://github.com/leebo155/push_swap/blob/main/img/push_swap3.jpg">

  rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  rrr : rra and rrb at the same time.
  <img alt="image" src="https://github.com/leebo155/push_swap/blob/main/img/push_swap4.jpg">
  
## Makefile
| Rules | Description |
| ----- | ----------- |
| all | Compile a program push_swap. |
| bonus | Compile a program checker. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a push_swap. |

## Usage
* Run normally and output commands as follows.
  ```shall
  ./push_swap 4 2 1 5
  ```
  
* Output:
  ```shall
  ra
  pb
  pb
  rb
  sa
  pa
  pa
  ```

* If the arguments are duplicated or not int, an error is output.
  ```shall
  ./push_swap 3 2 2 4
  Error
  ./push_swap 3 2 2147483648
  Error
  ./push_swap 3 2 one
  Error
  ```

* You can run a large number of arguments by entering the following.
  ```shall
  ARG=$(seq 500 | sort -R); ./push_swap $ARG
  ```

* The checker can enter the same argument as push_swap and enter the output of push_swap to verify that it is running correctly.
  ```shall
  ./checker 4 2 1 5
  ra
  pb
  pb
  rb
  sa
  pa
  pa
  (ctrl-D)OK
  ```

* You can also deliver and run the input right away.
  ```shall
  ARG="3 2 1 4"; ./push_swap $ARG | ./checker $ARG
  ```
  ```shall
  ARG=$(seq 500 | sort -R); ./push_swap $ARG | ./checker $ARG
  ```
