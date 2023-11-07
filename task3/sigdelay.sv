module sigdelay #(
    parameter   ADDRESS_WIDTH = 9,
                DATA_WIDTH  = 8
)(
    input logic [ADDRESS_WIDTH - 1: 0] offset,
    input logic rst,
    input logic wr,
    input logic rd,
    input logic clk,
    input logic [DATA_WIDTH - 1: 0] mic_signal,

    output logic [DATA_WIDTH - 1: 0] delayed_signal
);

logic [ADDRESS_WIDTH - 1: 0] wr_addr;
logic [ADDRESS_WIDTH - 1: 0] rd_addr = {wr_addr} + {offset};
    
counter counter(
    .incr (1),
    .rst (rst),
    .en (1),
    .clk (clk),

    .count (wr_addr)
);

ram2ports ram2ports(
    .clk (clk),

    .rd_en (rd),
    .wr_en (wr),

    .rd_addr (rd_addr),
    .wr_addr (wr_addr),
    .din (mic_signal),
    
    .dout (delayed_signal)
);

endmodule
