The difference in output occurs because the stdout stream uses line buffer, so the write() system call is not invoked by printf("Hello"). 
Instead it is put into a buffer, which gets copied by fork. In the second example the '\n' symbol in the end of "Hello" causes the write() systemcall and the buffer is empty at the time of fork.
