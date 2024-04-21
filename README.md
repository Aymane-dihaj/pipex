# PIPEX

- What is pipex?
    
    pipex reproduce the behavior of the shell pipe `|` command in c,
    
    It launches as `./pipex infile cmd1 cmd2 outfile`
     and behaves as this line does in the shell `< infile cmd1 | cmd2 > outfile`.
    
    The general idea: we read from `infile` ,execute cmd1 with infile as input, send the output, to cmd2, which will to `outfile` 
    
    - `pipe()` send the output of the first `execve()` as input to the second `execve()` ; `fork()` runs two processes(two commands) in one single program; `dup2()` swaps our files with stdin and stdout.
    
    ```c
    // each cmd needs a stdin (input) and returns an output (to stdout)
       
        infile                                             outfile
    as stdin for cmd1                                 as stdout for cmd2            
           |                        PIPE                        ↑
           |           |---------------------------|            |
           ↓             |                       |              |
          cmd1   -->    end[1]       ↔       end[0]   -->     cmd2           
                         |                       |
                cmd1   |---------------------------|  end[0]
               output                             reads end[1]
             is written                          and sends cmd1
              to end[1]                          output to cmd2
           (end[1] becomes                      (end[0] becomes 
            cmd1 stdout)                           cmd2 stdin)
    ```
    
    pipe take an array of two int such as `int end[2]`, and links them together.
    
    in a pipe, what is done in `end[0]` is visible to `end[1]`, and vice versa. plus, `pipe(`
    
    `)` assigns an fd to each end.
    

# functions you need in pipex project:

- **pipe:**
    
    The pipe function in c library is used to create a pipe, A pipe is a one-way communication channel between two processes, allowing them to pass data. it returns two files descriptors, one for reading and one for writing.
    
- **fork:**
    
    The fork function in c creates a new process that is a copy of the current process. The new process and the current process run at the same time. the new process is called the child, and the current process is called the parent. The child process gets a new process ID, and the parent process can get the child’s ID. The child and the parent can communicate with each other.
    
- **dup2:**
    
    The dup2 function in C creates a copy of an existing file descriptor and assigns it to a new file descriptor. This means that the new file descriptor refres to the same file or device as the old file descriptor. it can be used to redirect standard input, output and error file descriptors or to share a file descriptor between multiple processes.
    
- **wait:**
    
    The wait function in c library is used to wait for a child process to terminate and obtain its exit status.
    
    The wait function takes a single argument, a pointer to an integer, which is used to store the exit status of the child process.
    
- **waitpid:**
    
    The `waitpid` function in c library is used to wait for a specific child process to terminate and obtain its exit status. it is similar to the wait() function, but it allows the caller to specify which child process to wait for, by providing its process ID as an argument
    
    The `waitpid()` function takes three arguments:
    
    - pid: the process ID of the child process to wait for
    - status: a pointer to an integer that will be used to store the exit status of the child process
    - options: a bitwise OR of zero or more of the following constants: WNOHANG, WUNTRACED, WCONTINUED
