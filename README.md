# Minishell – A Unix Shell Implementation in C

Minishell is a core systems programming project in the 42 curriculum that challenges students to recreate a simplified version of a Unix shell using the C programming language.
This project goes far beyond simple scripting—it requires a deep understanding of process control, parsing, memory management, and Unix system calls. The goal is to replicate the behavior of a real shell like **bash**.

Everything is built from scratch—no shortcuts. No `system()` calls, no built-in libraries for parsing—we had to write our own parser, manage memory manually, and handle processes and file descriptors directly using system calls like `fork()`, `execve()`, and `dup2()`.

## Key Features
- Command parsing with support for:
  - Quoting ( ', " )
  - Escaping ( \\ )
  - Environment variable expansion ($VAR)
- Built-in commands (e.g. cd, echo, pwd, export, unset, env, exit)
- Pipes ( | ) and redirections (<, >, >>, <<)
- Heredoc support
- Signal handling (Ctrl+C, Ctrl+\, etc.)
- Custom prompt
- Execution of both built-in and external binary commands using execve()
