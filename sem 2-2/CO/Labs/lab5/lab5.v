`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:19:41 04/14/2013 
// Design Name: 
// Module Name:    lab5 
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
module CtrlUnit ( input clk, input Reset, input [5:0] opcode, output reg RegDst, output reg RegWrite, output reg
PCWriteCond, output reg PCWrite, output reg IorD, output reg MemRead, output reg MemWrite, output reg
MemtoReg, output reg IRWrite, output reg ALUSrcA, output reg [1:0] PCSource, output reg [1:0] ALUSrcB, output
reg [1:0] ALUop);

reg [3:0] currstate;
reg [5:0] opcodereg;
begin
always@(negedge clk)
	
	 
		if(Reset)
			begin
				currstate =  3'b000;
				RegDst=0;
				RegWrite = 0;
				PCWriteCond = 0;
				PCWrite = 0;
				IorD = 0;
				MemRead = 0;
				MemWrite = 0;
				MemtoReg = 0;
				IRWrite = 0;
				ALUSrcA = 0;
				PCSource = 0;
				ALUSrcB = 0;
				ALUop = 0;
			end
		else
			begin
				if(currstate == 3'b000)
					begin
						opcodereg = opcode;
						
						RegDst=0;
						RegWrite = 0;
						PCWriteCond = 0;
						PCWrite = 1;
						IorD = 0;
						MemRead = 1;
						MemWrite = 0;
						MemtoReg = 0;
						IRWrite = 1;
						ALUSrcA = 0;
						PCSource = 0;
						ALUSrcB = 1;
						ALUop = 0;
						currstate = 3'b001;
					end
				
				else if(currstate == 3'b001)
					begin
						PCWrite = 0;
						MemRead = 0;
						IRWrite = 0;
						ALUSrcB = 2'd3;
						currstate = 3'b010;
					end
				
				else if(currstate == 3'b010)
					begin
						if(opcode == 6'd0)
							begin
								ALUSrcA = 1;
								ALUop = 2'd2;
								ALUSrcB = 0;
								currstate = 3'b011;
							end
						else if(opcode==6'd4)
							begin
								PCSource = 1;
								PCWriteCond = 1;
								ALUSrcA = 1;
								ALUop = 2'd1;
								ALUSrcB = 0;
								currstate = 3'b000;
							end
						else if(opcode == 6'd2)
							begin
								PCWrite = 1;
								PCSource = 2'd2;
								currstate = 3'b000;
							end
						else if(opcode == (6'b010111 ||  6'b101011))
							begin
								ALUSrcA = 2'd1;
								ALUSrcB = 2'd2;
								currstate= 3'b011;
							end
							
					
					end //end of else if currstate = 3'b010
				
				else if(currstate == 3'b011)
					begin
						if(opcode == 6'd0)
							begin
								RegDst = 1;
								RegWrite = 1;
								currstate = 3'b000;
							end
						else if(opcode == 6'b101011)
							begin
								IorD = 1;
								MemWrite = 1;
								currstate = 3'b000;
							end
						else if(opcode == 6'b010111)
							begin
								IorD = 1;
								MemRead = 1;
								currstate = 3'b100;
							end
							
					end //end of currstate = 3'b011
				else if(currstate==3'b100)
					begin
						RegWrite = 1;
						MemtoReg = 1;
						currstate = 3'b000;
					end
			end

	end
endmodule


module testbench;

reg clk,Reset;
reg [5:0] opcode;
wire  RegDst,RegWrite,PCWriteCond,PCWrite,IorD,MemRead,MemWrite,MemtoReg,IRWrite,ALUSrcA;
wire [1:0] ALUSrcB,PCSource,ALUop;


CtrlUnit c1(clk,Reset,opcode,RegDst,RegWrite,PCWriteCond,PCWrite,IorD,MemRead,MemWrite,MemtoReg,
IRWrite,ALUSrcA,PCSource,ALUSrcB, ALUop);

initial 
	begin
	$monitor($time,"clk = %b ,Reset = %b ,opcode = %b,RegDst = %b ,RegWrite = %b ,PCWriteCond = %b ,PCWrite = %b ,IorD = %b ,MemRead = %b ,MemWrite = %b ,MemtoReg = %b ,IRWrite = %b ,ALUSrcA = %b ,PCSource = %d ,ALUSrcB = %d ,ALUop = %d",clk,Reset,opcode,RegDst,RegWrite,PCWriteCond,PCWrite,IorD,MemRead,MemWrite,MemtoReg,
IRWrite,ALUSrcA,PCSource,ALUSrcB, ALUop);
	clk =0;
	end

initial 
repeat(12)
	begin
	#1 clk=~clk;
	end

initial 
begin
#1 Reset = 1'b1;
#3 Reset = 1'b0;opcode = 6'd4;
end
 
endmodule










