# Project Description

 - A very simple program that follows the principle of a simple shell, it reads stdin, parses the command, and executes with execvp.
 - Before it executes, it forks the process.

## TODO

- [x] Adding cd as a built-in command 
- [x] Interpreter sign doesn't work, fix that
- [ ] In the main file, the function usage is wonky, find a better way around that
- [ ] Need to find a better way to implement built-in commands
- [x] ctrl+d (EOF) doesn't work, because we dont use while(getline >0), I have to find a better implementation
- [ ] If I can find a way, I want to add pipes
- [x] Provide more comments to easily explain the program
- [x] Adding redirection, although it's way easier than pipes
