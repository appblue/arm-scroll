# Apple Silicon (M2) Terminal Scroll

Simple scroll in terminal written in ARM64v8 assembly language using SYSCALLs.

## Running

```shell
$ make
as -o arm-scroll.o arm-scroll.s
gcc -o arm-scroll arm-scroll.o
$ ./arm-scroll
                           ##  ##  ######  ##      ##       ####           #####
                           ##  ##  ##      ##      ##      ##  ##          ##
                           ##  ##  ##      ##      ##      ##  ##          ##
                           ######  ####    ##      ##      ##  ##          ####
                           ##  ##  ##      ##      ##      ##  ##          ##
                           ##  ##  ##      ##      ##      ##  ##          ##
                           ##  ##  ######  ######  ######   ####           ##

^C
```

## Notes

The code contains very naive implementation of `delay()` function using `select()` system call with `NONBLOCKING` flag and timeout set.

## TODO

* fix the `delay()` funtion to accept the parameter - right now it's hardcoded.