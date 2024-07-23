After checking out what packers were, I stumbled across UPX: an open-source executable packer designed to compress and reduce the size of executable files while retaining their functionality.
Downloaded it and realized that command `upx` does not work, rather, one needs to use `upx-ucl`...

```
upx-ucl -d ./out
strings out | grep "flag"
```
This command gave me thsi output `Password correct, please see flag: 7069636f4354467b5539585f556e5034636b314e365f42316e34526933535f65313930633366337d `\
The random hex looking command was thrown into cyberchef, converted from hex to reveal the flag.
