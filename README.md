# OSWork

System Calls, Processes and Threads

### How to setup
Clone and run make

```
> git clone https://github.com/ianwright27/OSWork.git
> make
> cd bin
> ls
```

### Output:
```
Question1 Question2 Question3
```

## Bugs/Deviation that couldn't be resolved
Upon trying to achieve parallel program executing with **fork(), exec() and wait()** system calls, there is a certain misbehaviour caused by fork(). On examining the problem, especially when I used **fork() in a loop**, it will replicate the entire process. 
Since using it in loops can be a dangerous move, I forked in every instance while calling exec() in the child process.
The list of executables, are stored in **"executables.txt"** file. Reduced the number to 2 programs.
After running, I noticed "/bin/neofetch" (for example) will be executed twice as seen below.

![](image.png)
