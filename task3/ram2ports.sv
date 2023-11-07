module ram2ports #(
    parameter   ADDRESS_WIDTH = 9,
                DATA_WIDTH = 8
)(
    input   logic                             clk,

    input   logic                           wr_en,
    input   logic                           rd_en,

    input   logic     [ADDRESS_WIDTH - 1: 0]  wr_addr,
    input   logic     [ADDRESS_WIDTH - 1: 0]  rd_addr,
    input   logic     [DATA_WIDTH - 1: 0]     din,
    output  logic     [DATA_WIDTH - 1: 0]     dout

);
    
logic [DATA_WIDTH - 1: 0] ram_array [(2**ADDRESS_WIDTH) - 1: 0];
/*
initial begin
    $display("init ram.");
    for (int init_addr = 0; init_addr < 2**ADDRESS_WIDTH - 1; init_addr++) begin
        ram_array[init_addr] <= {DATA_WIDTH{1'b1}};
    end;
    $display("init finished.");
end;
*/
always_ff @(posedge clk) begin

    if((wr_en == 1'b1) && (rd_en == 1'b1))begin
        ram_array[rd_addr] <= din;
        dout <= ram_array[wr_addr];
    end;
    //$monitor("wr_addr: %0d, ram_array[wr_addr]: %0d, din: %0d, wr_en: %0d, rd_en: %0d",wr_addr , ram_array[wr_addr], din, wr_en, rd_en);
end;
endmodule
