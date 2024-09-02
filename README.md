## What's Lox

Lox is a dynamically typed, interpreted script language, which is designed by Robert Nystrom for his book [*Crafting interpreters*](https://craftinginterpreters.com/).

## What's cpplox

A virtual machine(VM) for the Lox programming language implemented in *modern C++*. The original book utilizes C to build the VM, referred to as `clox`. To maintain consistency, I chose the name `cpplox` for the C++ implementation💅.

I started this project just to get *my hands dirty* while learning *modern C++*.

## How to build

```sh 
$ bazel run :cpplox
```
