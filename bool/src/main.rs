// tool to print boolean tables
// this includes all 16 boolean logic functions of
// two input systems, there are 2^(2^n) logic functions
// for n input variables. This means that for a signle
// input 2^(2^1) = 4 functions for a single var
// and 16 for a 2 input system.
//
// For a single input system the outputs are
// Name      BoolFnc    Meaning
// null         0        Always 0
// identity     1        Always 1
// transfer     A        Pass value of A
// not         ~A        Pass negated value of A
//
//
// For two input systems
//
// Name
//
// Null
// Identity
// Transfer A
// Transfer B
// NOT A
// NOT B
// AND
// NAND
// OR
// NOR
// Implication ~A + B
// Implication A + ~B
// XOR
// XNOR


fn main() {
    println!("Hello, world!");
}
