.PHONY:	all

all:	arm-scroll

arm-scroll:	arm-scroll.s
	as -o arm-scroll.o arm-scroll.s
	gcc -o arm-scroll arm-scroll.o
