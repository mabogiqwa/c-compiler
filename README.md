# c-compiler
Building a mechanism that can translate C into machine code.

## Design decisions
The compiler will be 32-bit, little-endian with a flat memory model. It will process identifiers such as conditionals, loops, functions, and integers for now.

## Preprocessing
This component will handle include declarations, macros, and conditional compilations.

## Lexical Analysis
Turns characters into tokens. Token types include identifiers, numbers, operators, and symbols.

## Parser
Turns tokens into an abstract syntax tree.

## Semantic Analysis
Going to involve symbol tables and with checking whether rules are enforced.

## Intermediate Representation
Turns abstract syntax trees into a simpler, lower-level form. We could use a 3-address code. This helps simplify optimization and code generation. Also decouples frontend and backend.

## Code generation
The goal is that the intermediate representation is turned into 32-bit machine code or assembly. This will require a stack frame layout, register usage and how expressions map to instructions.

## Linking
Provides a form of runtime support.
