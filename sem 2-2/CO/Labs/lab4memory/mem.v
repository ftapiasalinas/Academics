`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:38:50 04/14/2013 
// Design Name: 
// Module Name:    mem 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module D_FF(input d_1b,output reg q_1b,input Write_1b,input clk);

always@(negedge clk)
	begin
		if(Write_1b)
			q_1b<= d_1b;
	end
endmodule	

module Mux4to1(input Din0_1b,input Din1_1b,input Din2_1b,input Din3_1b,output reg Dout_1b,input [1:0]Addr_2b);

always @(*)
	begin
		case(Addr_2b)
		2'd0:
				Dout_1b = Din0_1b;
		2'd1:
				Dout_1b = Din1_1b;
		2'd2:
				Dout_1b = Din2_1b;
		2'd3:
				Dout_1b = Din3_1b;
		endcase
	end
endmodule  

module Mux2to1(input [2:0]Dout_3b,input [2:0]Zero_3b,output reg [2:0]Qout_3b,input Read_1b);

always @ (*)
	begin
		if(Read_1b)
			Qout_3b = Dout_3b;
		else
		Qout_3b = Zero_3b;
	end
endmodule	

module Decoder2to4(input [1:0]Addr_2b,output reg [3:0]Loc_4b);

always @ (*)
	begin
		case(Addr_2b)
			2'd0:
					Loc_4b= 4'b0001;
			2'd1:
					Loc_4b = 4'b0010;
			2'd2:
					Loc_4b = 4'b0100;
			2'd3:
					Loc_4b = 4'b1000;
		endcase
	end
	
endmodule

module Memory( input [2:0]Din_3b,input [1:0]Addr_2b,input WE_1b,input Read_1b,output [2:0]Qout_3b,input clk);

wire [3:0] line;
wire [2:0] first,second,third,fourth;
wire [2:0] fromtomux; 
wire w1,w2,w3,w4;

Decoder2to4 dec(Addr_2b,line);

and a1(w1,WE_1b,line[0]);
and a2(w2,WE_1b,line[1]);
and a3(w3,WE_1b,line[2]);
and a4(w4,WE_1b,line[3]);

D_FF d11(Din_3b[0],first[0],w1,clk);
D_FF d12(Din_3b[1],first[1],w1,clk);
D_FF d13(Din_3b[2],first[2],w1,clk);

D_FF d21(Din_3b[0],second[0],w2,clk);
D_FF d22(Din_3b[1],second[1],w2,clk);
D_FF d23(Din_3b[2],second[2],w2,clk);

D_FF d31(Din_3b[0],third[0],w3,clk);
D_FF d32(Din_3b[1],third[1],w3,clk);
D_FF d33(Din_3b[2],third[2],w3,clk);

D_FF d41(Din_3b[0],fourth[0],w4,clk);
D_FF d42(Din_3b[1],fourth[1],w4,clk);
D_FF d43(Din_3b[2],fourth[2],w4,clk);

Mux4to1 m1(first[0],second[0],third[0],fourth[0],fromtomux[0],Addr_2b);
Mux4to1 m2(first[1],second[1],third[1],fourth[1],fromtomux[1],Addr_2b);
Mux4to1 m3(first[2],second[2],third[2],fourth[2],fromtomux[2],Addr_2b);


Mux2to1 m4(fromtomux,3'b000,Qout_3b,Read_1b);

endmodule

module testbench;

reg [2:0]Din_3b;
reg [1:0] Addr_2b;
reg We_1b,Read_1b,clk;
wire [2:0] Qout_3b;

Memory m14(Din_3b,Addr_2b,We_1b,Read_1b,Qout_3b,clk);
 
initial 
	begin 
	$monitor($time,"clk = %b  Din = %b write = %b read = %b output = %b",clk,Din_3b,We_1b,Read_1b,Qout_3b);
	end
initial
begin
clk = 0;
end
	
initial
begin
	repeat(15)
	#1 clk = ~clk;
	end
	
initial
begin
#1 We_1b = 1'b1;Din_3b = 3'b110;Addr_2b = 2'b01;Read_1b=1'b0;
#1 Read_1b = 1'b1;Addr_2b = 2'b01;We_1b = 1'b0;
end
endmodule
 
  
 
 
 
 
 