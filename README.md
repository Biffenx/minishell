# minishell
First step in the creation of a shell. In this project, you will create a mini-shell capable of reading and evaluating simple user commands. 
Reading will involve trivial lexical analysis and parsing of the command. Evaluation will involve searching for the corresponding binary on the machine 
and execute it, or execute the relevant code in the case of a “built-in” command in the shell.

## Mandatory Part
* You must program a mini UNIX command interpreter.
* This interpreter must display a prompt (a simple "$> " for example) and wait till
you type a command line, validated by pressing enter.
* The prompt is shown again only once the command has been completely executed.
* The command lines are simple, no pipes, no redirections or any other advanced
functions.
* The executable are those you can find in the paths indicated in the PATH variable.
* In cases where the executable cannot be found, it has to show an error message and
display the prompt again.
* You must manage the errors without using errno, by displaying a message adapted
to the error output.
* You must deal correctly with the PATH and the environment (copy of system char
**environ).
* You must implement a series of builtins: echo, cd, setenv, unsetenv, env, exit.
* You can choose as a reference whatever shell you prefer.
* You must manage expansions $ and ˜

## Bonuses
My code includes some bonuses
* Management of signals and in particular Ctrl-C. 
* Management of execution rights in the PATH.
* History.
* The separation of commands with ";".

Score:

![alt text](115.png?s=100)


