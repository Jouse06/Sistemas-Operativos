# Questions

***Explain the exact output format of the `ls -l`command. What does the first column represent?***
  - The ls -l command displays a detailed list of files and directories in the current directory.
  - The first column represents the file type and permissions.

***What is the difference between ps, ps -l, and ps -eaf?***
  - ps displays a snapshot of the current processes.
  - ps -l displays a detailed list of processes.
  - ps -eaf displays a full list of all processes.

***What does the command cat f1 f2 | grep hola | wc > fichero do? Break it down pipe by pipe.***
  - cat f1 f2 concatenates the contents of f1 and f2.
  - grep hola filters the output to only include lines containing "hola".
  - wc counts the number of lines, words, and characters in the output.
  - > fichero redirects the output to the file "fichero".

  ***What permissions are represented by `chmod 0666`?***
  - `chmod 0666` sets read and write permissions for the owner, group, and others.
