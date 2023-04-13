# MINISHELL

### Navigating in the deepwater of a shell

## Introduction

Minishell it's a program that behaves like a shell. This was the most challenge project since the beginning of the course (at least in this point).

The shell display a prompt that have his own builtin functions, PATH, enviroment variables and working history. He can deal with multiple redirects, pipes, exit codes and signals. 

## Challenges

* Parse :
  The parse it's pretty much like the linux shell, and mimic that behaviour was the hardest part of this project. To fully understand that order it was necessary hundreds of tests in the Linux Shell; reproduce that behaviour with the ties imposed by the school was a nice and hard challenge.

* Dealing with Processes :
  This was the first time that I have to deal with process, dup and PID's. It's fundamental use "pipes" with dup2 to achieve the goal of this project, so it's essential learn beyond the surface of FD to be approved. Also, we must deal with signals sended by each process to verify if something goes wrong at any point of the programn.

* Algorithm :
   I started to develop the programn without know how to build his foundation and flow. So, after a month of work I had to recriate it from the scratch to make it more robust and easy to understand.


