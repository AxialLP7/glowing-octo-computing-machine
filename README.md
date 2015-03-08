# glowing-octo-computing-machine
Scanner created for Computer Theory and Automaton

This is a language scanner that determines if a given string is within a language given the grammar of the language.

It checks for the following:
1) Errors 
2) Identifiers
3) Real Numbers
4) Integer

Our language has the following constraints in their grammar:

Identifiers are represented exclusively by 'a' and 'b' with the following regular expression to represent its grammar rules: (a b^+)

Real Numbers are represented by digits 2 and 3 with the following regular expression: (d^*.d^+) where d represents digits 2 and 3 

Intergers are represented by digits 2 and 3 with the following regular expression: (d^+) where d represents digits 2 and 3 

All of the above grammar rules can easily be modified to be more inclusive of the range of whole alphanumerics that make up the natural language.
