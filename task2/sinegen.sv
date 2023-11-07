module sinegen #(
    parameter WIDTH = 8
)(
    input logic [WIDTH - 1: 0] incr,
    input logic rst,
    input logic en,
    input logic clk,

    output logic [WIDTH - 1: 0] data1,
    output logic [WIDTH - 1: 0] data2
);

logic [WIDTH - 1: 0] addr1;
logic [WIDTH - 1: 0] addr2;
    
counter counter1_(
    .incr (1),
    .rst (rst),
    .en (en),
    .clk (clk),

    .count (addr1)
);

counter counter2_(
    .incr (1),
    .rst (rst),
    .en (en),
    .clk (clk),

    .count (addr2)
);

rom2ports rom2ports(
    .clk (clk),

    .addr1 (addr1),
    .addr2 (addr2 + incr),
    

    .dout1 (data1),
    .dout2 (data2)
);


endmodule
