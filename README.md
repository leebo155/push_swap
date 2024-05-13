# push_swap
 A very simple and a highly straightforward algorithm project: data must be sorted.

## Introduction
* The project is to create a program that uses two stacks to sort ascending to `stack a`.
* The `stack a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The `stack b` is empty.
* And must output the commands used as the sort progresses.
* The commands are as follows.

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
