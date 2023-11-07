module sinegen #(
    parameter WIDTH = 8
)(
    input logic [WIDTH - 1: 0] incr,
    input logic rst,
    input logic en,
    input logic clk,

    output logic [WIDTH - 1: 0] dout
);

logic [WIDTH - 1: 0] addr;
    
counter counter_(
    .incr (incr),
    .rst (rst),
    .en (en),
    .clk (clk),

    .count (addr)
);

rom rom_(
    .addr (addr),
    .clk (clk),

    .dout (dout)
);


endmodule
