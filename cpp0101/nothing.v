module nothing (
    input wire a,
    input wire b,
    output wire y
);

assign y = a & b;


initial begin 

$display("Hello World!");
$finish;

end



endmodule
