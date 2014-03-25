# MSH
## Beta Version


### Created by Ne02ptzero (Louis Solofrizzo), Fusiow (Ryad Kharif) and Ivory9334 (Aurelien Ardjoune)

Stable version for **MacOSX**
Work on **Linux**, but no manual completion (options & description of command)

## What's MSH ?
Msh is a colorful shell to help beginners in learning Linux, but also to confirm that users desire to enjoy a visual comfort. 

![alt text](screens/screen1.png)
____

![alt text](screens/screen2.png)

____

![alt text](screens/screen3.png)

____

![alt text](screens/screen5.png)

____

#### Why? 
- The command is colored in blue if it exists, otherwise red. 
- When the command is good, all options for this command are posters suggestions. 
- In addition, there is an auto-completion on the options that allows to know the list of options for a command, and their utilites. 
- Autocompletion also on files as well as folders. 

#### Builtins: 
- Builtins environment (env, setenv and unsetenv) 
- Alias 
- Local Variables 
- Job Control 
- Configuration file 
- Advanced prompt

____

![alt text](screens/screen4.png)

For more information see the documentation (docs /).

#### Installation: 
##### -Compilation: 
git clone https://github.com/Ne02ptzero/msh.git && cd msh && make
##### -Installation:
make install;

(For 42 students)

make install42;  *(Copy the binary to ~/.brew/bin)*

Launch with "msh"

You don't want the amazing colored read ? Launch with -no-color options.
