# C - Stacks, Queues - LIFO, FIFO

## What is Stack in C?

A stack in C is nothing but a linear data structure that follows the LIFO rule
(Last In First Out). In a stack, both insertion and deletion take place from
just one end, that is, from the top.

# 0.push, pall**

**The push opcode**

The opcode push pushes an element to the stack.

    Usage: push <int>
        where <int> is an integer
    if <int> is not an integer or if there is no argument given to push, print
    the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
        where is the line number in the file
    You won’t have to deal with overflows. Use the atoi function


**The pall opcode**

The opcode pall prints all the values on the stack, starting from the top of the stack.

    Usage pall
    Format: see example
    If the stack is empty, don’t print anything

julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$


Example

 [![asciicast](https://asciinema.org/a/tXSM9lQ84DxUuvK3llJRsplfb.sgv)](https://asciinema.org/a/tXSM9lQ84DxUuvK3llJRsplfb.sgv)

