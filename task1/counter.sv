module counter#(
    parameter WIDTH = 8
)(
    input logic [WIDTH - 1: 0] incr,
    input logic rst,
    input logic en,
    input logic clk,

    output logic [WIDTH - 1: 0] count
);

always @(posedge clk) begin
    if (rst) count <= {WIDTH{1'b0}};
    else if (en) count <= count + incr;
    else count <= count;
end
    
endmodule
