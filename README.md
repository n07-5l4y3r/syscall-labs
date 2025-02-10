Collected work from 2021,
mainly game hacking resources.

Contains among other things an unclean R3->R0 call gate,
with some work it can be safely updated again.
Abuses a bug in win32k.sys or win32u.dll where the instruction pointer is loaded from a pointer inside a RW data page. With a kernel write primitive, you can either place a callgate in an executable memory area of the kernel or simply use gadgets.
Once the callgate is stored, incrementing the current thread from r3 to r0 is a simple matter of a normal syscall that allows cr3 antics and physical memory rw from an r3 process natively.

TL;DR using this method makes syscall/heavensgate feel like good old win7/xp

had some nasty bsod's while using the phys mem write primitive, take it as POC and only that.
