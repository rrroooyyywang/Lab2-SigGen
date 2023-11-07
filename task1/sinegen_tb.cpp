#include "Vsinegen.h"
#include "Vbuddy.cpp"
#include "verilated_vcd_c.h"
#include "verilated.h"

int main(int argc, char **argv, char **env){
    Verilated::commandArgs(argc, argv);

    Vsinegen* sinegen = new Vsinegen;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    sinegen->trace (tfp, 99);
    tfp->open("sinegen.vcd");

    while (vbdOpen() != 1){
        printf("connecting");
    }
    vbdClear();
    vbdHeader("Lab 2: Sinegen");

    sinegen->clk = 1;
    sinegen->rst = 1;
    sinegen->en = 1;
    sinegen->incr = 1;

     // run simulation for many clock cycles
    for (int i = 0; i < 1000000; i++){

        // dump variables into VCD file and toggle clock
        for (int clk=0; clk<2; clk++){
            tfp->dump(2*i+clk);    // unit is in ps!!!
            sinegen->clk = !sinegen->clk;
            sinegen->eval();
        }

        //Send count value to buddy
        sinegen->incr = vbdValue();
        vbdPlot(int(sinegen->dout), 0, 255);
        
        //end of buddy output sectiPon
        
        std::cout << vbdFlag() << std::endl;
        std::cout << int(sinegen->dout) << std::endl;
        sinegen->rst = 0;

        if (Verilated::gotFinish() || (vbdGetkey()=='q')) exit(0);

    }
    vbdClose();
    tfp ->close();
    exit(0);

}
