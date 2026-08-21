#include <iostream>
#include "Vnothing.h"  // Gerado pelo Verilator
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vnothing* top = new Vnothing; // Instancia seu módulo Verilog

    // Teste 1: a=1, b=1 -> y deve ser 1
    top->a = 1;
    top->b = 1;
    top->eval(); // Executa a lógica do circuito
    std::cout << "Se a=1 e b=1, entao y = " << (int)top->y << std::endl;

    // Teste 2: a=1, b=0 -> y deve ser 0
    top->a = 1;
    top->b = 0;
    top->eval();
    std::cout << "Se a=1 e b=0, entao y = " << (int)top->y << std::endl;

    delete top;
    return 0;
}
