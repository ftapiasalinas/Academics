
module DFF(input d_1b,output reg q_1b,input Write_1b,input clk);

always@(negedge clk)
	begin
		if(Write_1b)
			q_1b<= d_1b;
		else
			q_1b<=q_1b;
	end
endmodule	


module DFFlevel(input d_1b,output reg q_1b,input Write_1b,input clk);

always@(clk or Write_1b or d_1b)
	begin
		if(clk == 0)
			begin
				if(Write_1b)
					q_1b<= d_1b;
				else
					q_1b<=q_1b;
			end
	end
endmodule	

module leftshift(input [15:0] unshift,output reg [15:0] shifted);
always@(unshift)
	begin
		shifted = unshift<<1;
	end
endmodule



module sext6to16(input [5:0] unextended,output reg [15:0] extended);
always @(unextended)
	begin
		if(unextended[5])
			extended = {10'b1111111111,unextended};
		else
			extended = {10'b0000000000,unextended};

	end
endmodule

module sext9to16(input [8:0] unextended,output reg [15:0] extended);

always @(unextended)
	begin
		if(unextended[8])
		extended = {7'b1111111,unextended};
		else
		extended = {7'b0000000,unextended};

	end
endmodule

module zeroext6to16(input [5:0] unextended,output reg [15:0] extended);
always@(unextended)
	begin
	extended = {10'd0,unextended};
	end	
endmodule

module zeroext4to16(input [3:0] unextended,output reg [15:0] extended);
always@(unextended)
	begin
	extended = {12'b000000000000,unextended};
	end	
endmodule


module Mux2to1(input [15:0]Dout_3b,input [15:0]second,output reg [15:0]Qout_3b,input Read_1b);

always @ (Dout_3b or Read_1b or second)
	begin
		if(Read_1b == 1)
			Qout_3b = Dout_3b;
		else if(Read_1b == 0)
		Qout_3b = second;
	end
endmodule

module Mux4to1(input [15:0]Din0_1b,input [15:0]Din1_1b,input [15:0] Din2_1b,input [15:0] Din3_1b,
output reg [15:0] Dout_1b,input [1:0]Addr_2b);

always @(Din0_1b or Din1_1b or Din2_1b or Din3_1b or Addr_2b)
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

module Mux8to1 (input [15:0] outr0,input [15:0] outr1,input [15:0] outr2,input [15:0] outr3,
input [15:0] outr4,input [15:0] outr5,input [15:0] outr6,input [15:0] outr7,output reg [15:0] outbus,
input [2:0] sel);


always@(outr0 or outr1 or outr2 or outr3 or outr4 or outr5 or outr6 or outr7 or sel)
begin
case(sel)
3'd0:outbus=outr0;
3'd1:outbus=outr1;
3'd2:outbus=outr2;
3'd3:outbus=outr3;
3'd4:outbus=outr4;
3'd5:outbus=outr5;
3'd6:outbus=outr6;
3'd7:outbus=outr7;
default:outbus=16'bx;
endcase
end
endmodule
	

module register(input [15:0] in_reg,output [15:0] out_reg,input reg_write,input  clk);


DFF d1(in_reg[0],out_reg[0],reg_write,clk);
DFF d2(in_reg[1],out_reg[1],reg_write,clk);
DFF d3(in_reg[2],out_reg[2],reg_write,clk);
DFF d4(in_reg[3],out_reg[3],reg_write,clk);
DFF d5(in_reg[4],out_reg[4],reg_write,clk);
DFF d6(in_reg[5],out_reg[5],reg_write,clk);
DFF d7(in_reg[6],out_reg[6],reg_write,clk);
DFF d8(in_reg[7],out_reg[7],reg_write,clk);
DFF d9(in_reg[8],out_reg[8],reg_write,clk);
DFF d10(in_reg[9],out_reg[9],reg_write,clk);
DFF d11(in_reg[10],out_reg[10],reg_write,clk);
DFF d12(in_reg[11],out_reg[11],reg_write,clk);
DFF d13(in_reg[12],out_reg[12],reg_write,clk);
DFF d14(in_reg[13],out_reg[13],reg_write,clk);
DFF d15(in_reg[14],out_reg[14],reg_write,clk);
DFF d16(in_reg[15],out_reg[15],reg_write,clk);

endmodule

module decoder3to8(input [2:0] destreg,output reg[7:0] decout);

always@(destreg)
begin
	case(destreg)
		3'd0:decout=8'b00000001;
		3'd1:decout=8'b00000010;
		3'd2:decout=8'b00000100;
		3'd3:decout=8'b00001000;
		3'd4:decout=8'b00010000;
		3'd5:decout=8'b00100000;
		3'd6:decout=8'b01000000;
		3'd7:decout=8'b10000000;

	endcase
end 
endmodule

module RegisterFile( input[2:0] srca, input[2:0] srcb, input[2:0] destreg,input [15:0] writedata,
output [15:0] outbusa, output [15:0] outbusb,input  regwrite,input clk,input reset,output [15:0] out_reg0,
output [15:0] out_reg1 ,output [15:0] out_reg2,output [15:0] out_reg3,output [15:0] out_reg4,output [15:0] out_reg5,
output [15:0] out_reg6,output [15:0] out_reg7);

wire [7:0] temp_dec;
reg a,b,c,d,e,f,g,h;
wire a1,b1,c1,d1,e1,f1,g1,h1;

reg [15:0] in_reg1,in_reg2,in_reg3,in_reg4,in_reg5,in_reg6,in_reg7,in_reg0;

decoder3to8 d67(destreg,temp_dec);
 
and a109(a1,temp_dec[0],regwrite);
and a2(b1,temp_dec[1],regwrite);
and a3(c1,temp_dec[2],regwrite);
and a4(d1,temp_dec[3],regwrite);
and a5(e1,temp_dec[4],regwrite);
and a6(f1,temp_dec[5],regwrite);
and a7(g1,temp_dec[6],regwrite);
and a8(h1,temp_dec[7],regwrite);

register r0(in_reg0, out_reg0, a, clk);
register r1(in_reg1, out_reg1, b, clk);
register r2(in_reg2, out_reg2, c, clk);
register r3(in_reg3, out_reg3, d, clk);
register r4(in_reg4, out_reg4, e, clk);
register r5(in_reg5, out_reg5, f, clk);
register r6(in_reg6, out_reg6, g, clk);
register r7(in_reg7, out_reg7, h, clk);


Mux8to1 m1( out_reg0,out_reg1, out_reg2, out_reg3, out_reg4, out_reg5, out_reg6, out_reg7, outbusa, srca);
Mux8to1 m2( out_reg0,out_reg1, out_reg2, out_reg3, out_reg4, out_reg5, out_reg6, out_reg7, outbusb, srcb);


always@(srca or srcb or destreg or writedata or regwrite or clk or reset)
begin
	if(reset)
	begin
		in_reg0 = 16'd0;
		in_reg1 = 16'd8;
		in_reg2 = 16'd20;
		in_reg3 = 16'd32;
		in_reg4 = 16'd1;
		in_reg5 = 16'd5;
		in_reg6 = 16'd1;
		in_reg7 = 16'd0;
		
		a=1'b1;
		b=1'b1;
		c=1'b1;
		d=1'b1;
		e=1'b1;
		f=1'b1;
		g=1'b1;
		h=1'b1;

	end
	else 
	begin
		in_reg2 = writedata;
		in_reg3 = writedata;
		in_reg4 = writedata;
		in_reg5 = writedata;
		in_reg6 = writedata;
		in_reg7 = writedata;
		in_reg1 = writedata;
		
		a=a1;
		b=b1;
		c=c1;
		d=d1;
		e=e1;
		f=f1;
		g=g1;
		h=h1;
		
	end

end


endmodule

module register8bit(input [7:0] in_reg,output [7:0] out_reg,input reg_write,input  clk);

DFFlevel da(in_reg[0],out_reg[0],reg_write,clk);
DFFlevel db(in_reg[1],out_reg[1],reg_write,clk);
DFFlevel dc(in_reg[2],out_reg[2],reg_write,clk);
DFFlevel dd(in_reg[3],out_reg[3],reg_write,clk);
DFFlevel de(in_reg[4],out_reg[4],reg_write,clk);
DFFlevel df(in_reg[5],out_reg[5],reg_write,clk);
DFFlevel dg(in_reg[6],out_reg[6],reg_write,clk);
DFFlevel dh(in_reg[7],out_reg[7],reg_write,clk);

endmodule

module mux32to2(input [7:0] in1,input [7:0] in2,input [7:0] in3,input [7:0] in4,
input [7:0] in5,input [7:0] in6,input [7:0] in7,input [7:0] in8,
input [7:0] in9,input [7:0] in10,input [7:0] in11,input [7:0] in12,
input [7:0] in13,input [7:0] in14,input [7:0] in15,input [7:0] in16,
input [7:0] in17,input [7:0] in18,input [7:0] in19,input [7:0] in20,
input [7:0] in21,input [7:0] in22,input [7:0] in23,input [7:0] in24,
input [7:0] in25,input [7:0] in26,input [7:0] in27,input [7:0] in28,
input [7:0] in29,input [7:0] in30,input [7:0] in31,input [7:0] in32,
input [4:0] select,output reg [15:0] selected);

always@(*)
begin
	case(select)
		5'd0:
				selected = {in1,in2};
		5'd1:
				selected = {in2,in3};
		
		5'd2:
				selected = {in3,in4};
		5'd3:
				selected = {in4,in5};
		
		5'd4:
				selected = {in5,in6};
		5'd5:
				selected = {in6,in7};
		
		5'd6:
				selected = {in7,in8};
		5'd7:
				selected = {in8,in9};
		
		5'd8:
				selected = {in9,in10};
		5'd9:
				selected = {in10,in11};
		
		5'd10:
				selected = {in11,in12};
		5'd11:
				selected = {in12,in13};
		
		5'd12:
				selected = {in13,in14};
		5'd13:
				selected = {in14,in15};
		
		5'd14:
				selected = {in15,in16};
		5'd15:
				selected = {in16,in17};
			
		5'd16:
				selected = {in17,in18};
		5'd17:
				selected = {in18,in19};
		
		5'd18:
				selected = {in19,in20};
		5'd19:
				selected = {in20,in21};
		
		5'd20:
				selected = {in21,in22};
		5'd21:
				selected = {in22,in23};
		
		5'd22:
				selected = {in23,in24};
		5'd23:
				selected = {in24,in25};
		
		5'd24:
				selected = {in25,in26};
		5'd25:
				selected = {in26,in27};
		
		5'd26:
				selected = {in27,in28};
		5'd27:
				selected = {in28,in29};
		
		5'd28:
				selected = {in29,in30};
		5'd29:
				selected = {in30,in31};
		
		5'd30:
				selected = {in31,in32};
		5'd31:
				selected = {in32,in1};
		
	endcase

end
endmodule

module decoder5to32(input [4:0] addr,output reg [31:0] out);
always@(addr)
	begin
		case(addr)
		5'd0:out = {30'd0,2'b11};
		5'd1:out = {29'd0,2'b11,1'd0};
		5'd2:out = {28'd0,2'b11,2'd0};
		5'd3:out = {27'd0,2'b11,3'd0};
		5'd4:out = {26'd0,2'b11,4'd0};
		5'd5:out = {25'd0,2'b11,5'd0};
		5'd6:out = {24'd0,2'b11,6'd0};
		5'd7:out = {23'd0,2'b11,7'd0};
		5'd8:out = {22'd0,2'b11,8'd0};
		5'd9:out = {21'd0,2'b11,9'd0};
		5'd10:out = {20'd0,2'b11,10'd0};
		5'd11:out = {19'd0,2'b11,11'd0};
		5'd12:out = {18'd0,2'b11,12'd0};
		5'd13:out = {17'd0,2'b11,13'd0};
		5'd14:out = {16'd0,2'b11,14'd0};
		5'd15:out = {15'd0,2'b11,15'd0};
		5'd16:out = {14'd0,2'b11,16'd0};
		5'd17:out = {13'd0,2'b11,17'd0};
		5'd18:out = {12'd0,2'b11,18'd0};
		5'd19:out = {11'd0,2'b11,19'd0};
		5'd20:out = {10'd0,2'b11,20'd0};
		5'd21:out = {9'd0,2'b11,21'd0};
		5'd22:out = {8'd0,2'b11,22'd0};
		5'd23:out = {7'd0,2'b11,23'd0};
		5'd24:out = {6'd0,2'b11,24'd0};
		5'd25:out = {5'd0,2'b11,25'd0};
		5'd26:out = {4'd0,2'b11,26'd0};
		5'd27:out = {3'd0,2'b11,27'd0};
		5'd28:out = {2'd0,2'b11,28'd0};
		5'd29:out = {1'd0,2'b11,29'd0};
		5'd30:out = {2'b11,30'd0};
		5'd31:out = {1'b1,30'd0,1'b1};
		default:out = 32'd0;
			
		endcase
end	


endmodule
module memory(input [15:0] addr,output [15:0] memout,input memwrite,input memread,
input [15:0] writedata,input clk,input reset);

	wire [7:0] m1,m2,m3,m4,m5,m6,m7,m8,m9,m10;
	wire [7:0] m21,m22,m23,m24,m25,m26,m27,m28,m29,m30;
	wire [7:0] m11,m12,m13,m14,m15,m16,m17,m18,m19,m20;
	wire [7:0] m31,m32;
	wire [15:0] result;
	wire [31:0] decout;
	
	reg [7:0] in1,in2,in3,in4,in5,in6,in7,in8,in9,in10;
	reg [7:0]  in21,in22,in23,in24,in25,in26,in27,in28,in29,in30;
	reg [7:0]  in11,in12,in13,in14,in15,in16,in17,in18,in19,in20;
	reg [7:0]  in31,in0;
	
	reg [31:0] writeen;

	decoder5to32 decabc(addr[4:0],decout);
	
	
	register8bit rm0(in0,m1,writeen[0],clk); //add 
	register8bit rm1(in1,m2,writeen[1],clk); //rt = 001 rs = 010
	
	register8bit rm2(in2,m3,writeen[2],clk);//sub
	register8bit rm3(in3 ,m4,writeen[3],clk);//rt = 001 rs = 010
	
	register8bit rm4(in4 ,m5,writeen[4],clk);//divu
	register8bit rm5(in5 ,m6,writeen[5],clk);
	
	register8bit rm6(in6 ,m7,writeen[6],clk);//mfhi
	register8bit rm7(in7 ,m8,writeen[7],clk);//rd = 001
	
	register8bit rm8(in8 ,m9,writeen[8],clk);//mflo
	register8bit rm9(in9 ,m10,writeen[9],clk);//rd = 010
	
	register8bit rm10(in10 ,m11,writeen[10],clk);//mtlh
	register8bit rm11(in11 ,m12,writeen[11],clk); //rs = 011 rt = 010
	
	register8bit rm12(in12 ,m13,writeen[12],clk);//sll
	register8bit rm13(in13 ,m14,writeen[13],clk);//rt = 001 rs = 010
	
	register8bit rm14(in14 ,m15,writeen[14],clk);//srl	
	register8bit rm15(in15 ,m16,writeen[15],clk);//rt = 001 rs = 010
	
	register8bit rm16(in16 ,m17,writeen[16],clk);//sra
	register8bit rm17(in17 ,m18,writeen[17],clk);//rt = 001 rs = 010
	
	register8bit rm18(in18 ,m19,writeen[18],clk);//lw
	register8bit rm19(in19 ,m20,writeen[19],clk);//rt= 011 rs = 010
 	
	register8bit rm20(in20 ,m21,writeen[20],clk);//sw	
	register8bit rm21(in21 ,m22,writeen[21],clk);
	
	register8bit rm22(in22 ,m23,writeen[22],clk);//bne
	register8bit rm23(in23 ,m24,writeen[23],clk);
	
	register8bit rm24(in24 ,m25,writeen[24],clk);//lui  
	register8bit rm25(in25 ,m26,writeen[25],clk);
	
	register8bit rm26(in26 ,m27,writeen[26],clk);//ori
	register8bit rm27(in27 ,m28,writeen[27],clk);
	
	register8bit rm28(in28,m29,writeen[28],clk);//jr
	register8bit rm29(in29 ,m30,writeen[29],clk);
	

	register8bit rm30(in30,m31,writeen[30],clk); // for store we hard code these //jal
	register8bit rm31(in31,m32,writeen[31],clk);
	

	mux32to2 m378(m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,
	m17,m18,m19,m20,m21,m22,m23,m24,m25,m26,m27,m28,m29,m30,m31,m32,addr[4:0],result);
	
	
	always@(addr or memwrite or memread or writedata or clk or reset)
	begin
		if(reset)
		begin
			{in0,in1} = {8'b00000100,8'b10100000};	//add rs,rd = 010 rt = 001
			
			in2 = 8'b00001011;	in3 = 8'b00100000;//sub  rs,rd = 010 rt = 110 
			
			in4 = 8'b00001110;	in5 = 8'b10100000 ;//divu  rs = 010 rt = 101
			
			in6= 8'b10100000;  	in7 = 8'b10100001;//mfhi rd = 010
			
			in8 = 8'b10100000;	in9 = 8'b10110010 ;	//mflo rd = 011
			
			in10 = 8'b10100001;	in11 = 8'b00110011 ;	//mtlh  rhigh = 011 rlow = 010
			
			in12 = 8'b00100000;	in13 = 8'b10100100;	//sll rt = 001 rd = 010 shfby<<2 
			
			in14 = 8'b00100000;	in15 = 8'b10100101 ;	//srl rt = 001 rd = 010 shftby>>2
			
			in16 = 8'b00100000;	in17 = 8'b10100110;	//sra rt = 001 rd = 010 shftby>>2
			
			in18 = 8'b01100101;	in19 = 8'b10110111;	//lw rt = 011 rd = 011 sext = 000000 
			
			in20 = 8'b00001100;	in21 = 8'b10101001 ;	//bne rt = 001 rs = 010 jump to jal
			
			in22 = 8'b10000000;	in23 = 8'b00111010 ;	//lui rd = 011 8'imm = 1000 0000:8'd0;
			
			in24 = 8'b00000101;	in25 = 8'b10101011 ;	//ori rt = 011 rd = 010 zeroext of 000 001
			
			in26 = 8'b00001110;	in27 = 8'b11001100 ;	//jr sext = 000010111 rs = 100
			
			in28 = 8'b00000101;	in29 = 8'b10101101 ;	//jal 6'b(PC+2):ext = 0000 0000 1 <<1 
			
			in30 = 8'b000000 11;	in31 = 8'b1 010 1000;	//sw rt = 011 rs = 010 
			
			writeen = 32'b11111111111111111111111111111111;
			
		end
		else
		begin
			in0 = writedata[15:8];
			in1= writedata[7:0];
			
			in2 = writedata[15:8];
			in3= writedata[7:0];
			
			in4 = writedata[15:8];
			in5= writedata[7:0];
										
			in6 = writedata[15:8];
			in7= writedata[7:0];
										
			
			in8 = writedata[15:8];
			in9= writedata[7:0];
										
			in10 = writedata[15:8];
			in11= writedata[7:0];
										
			in12 = writedata[15:8];
			in13= writedata[7:0];
										
			in14= writedata[15:8];
			in15= writedata[7:0];
										
			in16 = writedata[15:8];
			in17= writedata[7:0];
										
			in18 = writedata[15:8];
			in19= writedata[7:0];
										
			in20= writedata[15:8];
			in21= writedata[7:0];
										
			in22= writedata[15:8];
			in23= writedata[7:0];
										
			in24= writedata[15:8];
			in25= writedata[7:0];
										
			in26 = writedata[15:8];
			in27= writedata[7:0];
										
			in28 = writedata[15:8];
			in29= writedata[7:0];
										
			in30= writedata[15:8];
			in31= writedata[7:0];
										
			if(memwrite)
				writeen = decout;
			else
				writeen = 32'd0;
		end		
	end
	Mux2to1 m2to1(result,16'd0,memout,memread);

endmodule

  
module Alu(input [2:0] aluop,input [15:0] src1,input [15:0] src2,output  reg [15:0] aluout,
output reg [15:0] remainder,output reg nzero);

reg [15:0] temp;				
always@(aluop or src1 or src2)
	begin
	
		nzero = 1'b0;
		remainder= 1'b0;
		case (aluop)
			
			3'b000:
			begin
			
			aluout = src1 + src2;
						//$display($time,"aluou = %b souc1 = %b souc2 = %b",aluout, src1 , src2);
						
			end
			
			 
			3'b001:
					begin
						aluout = src1 - src2;
						if(aluout!=0)
							begin
						
							nzero = 1;
							end
						else
							begin
							//$display($time," lower aluou = %b souc1 = %b souc2 = %b",aluout, src1 , src2);
							nzero = 0; 
							end
					end
			
			3'b010:
					begin 
						aluout = src1/src2;
						remainder =src1 % src2;
					end
			3'b011:				
				aluout = src1 | src2;
				
			
			3'b100:
			   aluout = src2 << src1; //sll
			
			3'b101:
			aluout = $signed(src2) >>> src1; // sra
		
			3'b110:aluout = src2 >> src1; //srl
			
								
		endcase
	end
endmodule
/*ctrl*/


module CtrlUnit ( input clk, input Reset, input [3:0] opcode,input [2:0] func,output reg RegWrite,
output reg PCWrite, output reg IorD, output reg MemRead,output reg MemWrite,output reg IRWrite,
output reg [2:0] src1,output reg [1:0] PCSource, output reg [1:0] src2, output reg [2:0] ALUop,
output reg highwrite,output reg lowwrite,output reg branch,output reg lowsrc,output reg highsrc,
output reg [2:0] wdata);


reg [3:0] opcodereg;
reg [2:0] curState;

always@(negedge clk)
begin
	if(1)
	begin
		
		if (Reset==1'b1)
			begin 

			 	 curState = 3'b000;
				 wdata = 3'd0;
				 RegWrite = 1'd0;  PCWrite = 1'd1;   IorD = 1'd0;    
				 MemRead = 1'd0;   MemWrite = 1'd0;  IRWrite = 1'd0;   src1 = 3'd0;  
				 PCSource = 2'd3;  src2 = 2'd0;      ALUop = 3'd0;     highwrite=1'd0; 
				 lowwrite=1'd0 ;   branch=1'd0;      lowsrc=1'd0;      highsrc=1'd0;

			end
		else 
			begin

				if (curState == 3'b000)//first cycle
					begin
						 wdata = 3'd0;
						RegWrite = 1'd0;  PCWrite = 1'd1;   IorD = 1'd0;    
						 MemRead = 1'd1;   MemWrite = 1'd0;  IRWrite = 1'd1;   src1 = 3'd0;  
						 PCSource = 2'd0;  src2 = 2'd1;      ALUop = 3'd0;     highwrite=1'd0; 
						 lowwrite=1'd0 ;   branch=1'd0;      lowsrc=1'd0;      highsrc=1'd0;
						curState = 3'b001;
					end//end first cycle

				else if (curState == 3'b001)//second cycle
					begin
					 opcodereg = opcode;
					 
						if (opcode == 4'b0000)//for add sub and div
							begin
								case(func)
									3'd1:ALUop=3'd0;//add
									3'd2:ALUop=3'd1;//sub	
									3'd3:ALUop=3'd2;//div
								endcase
						  		RegWrite = 1'b0; 
								PCWrite = 1'b0;   MemRead = 1'b0;
								IRWrite = 1'b0;   src2=2'd3; 
								curState = 3'b010;
								
							end
						else if(opcodereg == 4'b0001)//mfhi
							begin
								PCWrite = 1'd0;
								MemRead = 1'd0;
								IRWrite = 1'd0;
								wdata = 3'd1;
								RegWrite = 1'd1;
								curState = 3'b000; //mfhi ends in second cycle
							end
						else if (opcodereg == 4'b0010)//mflo
							begin
								PCWrite = 1'd0;
								MemRead = 1'd0;
								IRWrite = 1'd0;
								wdata = 3'd2;
								RegWrite = 1'd1; 
								curState = 3'b000;//mflo ends in second cycle
							end
						else if (opcodereg == 4'b0011) // mtlh
							begin
								PCWrite = 1'd0;
								MemRead = 1'd0;
								IRWrite = 1'd0;
								highwrite = 1'd1;
								lowwrite = 1'd1;
								curState = 3'b000;

							end
						else if (opcodereg == 4'b0100  || opcodereg == 4'b0101 
						|| opcodereg == 4'b0110 || opcodereg == 4'b0111 || opcodereg == 4'b1000
						|| opcodereg == 4'b1001 || opcodereg == 4'b1011)//sll srl sra lw sw bne ori 
							begin
								PCWrite = 1'd0;
								MemRead = 1'd0;
								IRWrite = 1'd0;
								src2=2'd3;
								curState = 3'b010;
							end
							
						else if (opcodereg == 4'b1010) // lui
							begin
								PCWrite = 1'd0;	
								MemRead = 1'd0;
								IRWrite = 1'd0;
								wdata = 3'd5;
								RegWrite = 1'b1;
								curState = 3'b000;//lui over in second cycle
							end
						
						else if (opcodereg == 4'b1100) // jr
							begin
								MemRead = 1'd0;
								IRWrite = 1'd0;
								src1 = 3'd1;
								src2 = 2'd2;
								PCWrite = 1'd0;
								curState = 3'b010;
							end
						
						else if (opcodereg == 4'b1101) // jal
							begin
							
								PCSource =2'd2;
								RegWrite = 1'd1;	
								MemRead = 1'd0;
								IRWrite = 1'd0;
								wdata = 3'd4;
								PCWrite = 1'b1;
								curState = 3'b000;//jal over in second cycle
							end
					end
					
				else if (curState == 3'b010)//third cycle
					begin
						highwrite = 1'b0;
						lowwrite = 1'b0;
						if (opcodereg == 4'b0000)//add sub or div
							begin
								
								src1 = 3'd1;
								src2 = 2'd0;
								curState = 3'b011;
								if(func==3'd3)//change for divu
									begin
										highwrite = 1'd1;
										lowwrite = 1'd1;
										highsrc = 1'd1;   
										lowsrc = 1'd1;
										curState = 3'b000;
									end
							end
						else if (opcodereg == 4'b0100) //sll
							begin
								src1=3'd2;
								src2=2'd0;
								ALUop = 3'b100;
								curState = 3'b011;
								
							end
						else if (opcodereg == 4'b0101) //srl
							begin
								src1=3'd2;
								src2=2'd0;
								ALUop = 3'b101;
								curState = 3'b011;
								
							end
						else if (opcodereg == 4'b0110) //sra
							begin
								src1=3'd2;
								src2=2'd0;
								ALUop = 3'b110;
								curState = 3'b011;
							end
						else if( opcodereg == 4'b0111 || opcodereg == 4'b1000)//load or store
							begin
								src1=3'd3;	
								src2=2'd0;
								curState = 3'b011;
							end
							
						else if (opcodereg == 4'b1001)// bne
							begin
								branch = 1'b1;
								PCSource = 2'd1;
								PCWrite = 1'd1;
								ALUop = 3'b001;
								curState = 3'b000; // bne over in third cycle
							end
							
						else if (opcodereg == 4'b1011)//ori
							begin
								src1=3'd4;	
								src2=2'd0;
								ALUop = 3'b011;
								curState = 3'b011;
							end
							
							
						else if (opcodereg == 4'b1100) // jr
							begin
							PCWrite = 1'd1;
							curState = 3'b000;
							end
							
										
					end
				
				else if (curState == 3'b011)//fourth cycle
					begin
						if (opcodereg == 4'b0000)//for r type instructions
							begin
								if(func == 3'd1 || func == 3'd2)
									RegWrite = 1'd1;
								
									curState = 3'b000;
							end
						else if (opcodereg == 4'b0100 || opcodereg == 4'b0101 || opcodereg == 4'b0110) //sll srl sra
							begin
								RegWrite = 1'd1;
								curState = 3'b000;
							end
						
						else if( opcodereg == 4'b0111)//load
							begin
								IorD = 1'b1;
								MemRead =1'b1;
								curState = 3'b100;
							end	
						
						else if( opcodereg == 4'b1000)// store
							begin
								IorD =1'b1;
								MemWrite = 1'b1;
								curState = 3'b000;
							end
						
						else if (opcodereg == 4'b1011)//ori
							begin
								RegWrite = 1'b1;
								curState = 3'b000;
							end
						
						
					end
			
				else if (curState == 3'b100)//fifth cycle
					begin
						if( opcodereg == 4'b0111)//lw
							begin
								IorD = 1'b0;
								MemRead =1'b0;
								wdata = 3'd3;
								RegWrite = 1'b1;
								
							end	
					
					curState = 3'd0;//lw over in fifth cycle
					end


				
		end //for else part of reset
		end//of always
	end
endmodule

module registerlevel(input [15:0] in_reg,output [15:0] out_reg,input reg_write,input  clk);

	DFFlevel d1a(in_reg[0],out_reg[0],reg_write,clk);
	DFFlevel d2a(in_reg[1],out_reg[1],reg_write,clk);
	DFFlevel d3a(in_reg[2],out_reg[2],reg_write,clk);
	DFFlevel d4a(in_reg[3],out_reg[3],reg_write,clk);
	DFFlevel d5a(in_reg[4],out_reg[4],reg_write,clk);
	DFFlevel d6a(in_reg[5],out_reg[5],reg_write,clk);
	DFFlevel d7a(in_reg[6],out_reg[6],reg_write,clk);
	DFFlevel d8a(in_reg[7],out_reg[7],reg_write,clk);
	DFFlevel d9a(in_reg[8],out_reg[8],reg_write,clk);
	DFFlevel d10a(in_reg[9],out_reg[9],reg_write,clk);
	DFFlevel d11a(in_reg[10],out_reg[10],reg_write,clk);
	DFFlevel d12a(in_reg[11],out_reg[11],reg_write,clk);
	DFFlevel d13a(in_reg[12],out_reg[12],reg_write,clk);
	DFFlevel d14a(in_reg[13],out_reg[13],reg_write,clk);
	DFFlevel d15a(in_reg[14],out_reg[14],reg_write,clk);
	DFFlevel d16a(in_reg[15],out_reg[15],reg_write,clk);

endmodule

//multi
module multi(input clk,input reset,output [15:0] pcout,output [15:0] tomem,output [15:0] toir,
output [15:0] out_reg0,
output [15:0] out_reg1 ,output [15:0] out_reg2,output [15:0] out_reg3,output [15:0] out_reg4,output [15:0] out_reg5,
output [15:0] out_reg6,output [15:0] out_reg7,output [15:0] IR,
output [15:0] tohigh, output [15:0] high ,output [15:0] tolow, output [15:0] low,output regwrite, 
output pcwrite,output iord,output memwrite,output memread,output irwrite,output highwrite,
output lowwrite,output highsrc,output lowsrc,output nzero,output andout,output branch);

wire [15:0] aluout,writedata,outbusa,outbusb,mdrtor,forshift,
alusrc1,mux2,mux3,mux4,mux5,alusrc2,alures,remainder,pcin,jal,muxout,froma,fromb;

wire [1:0] src2,pcsrc;
wire [2:0] wdata,src1,aluop;


 
register pc(pcin,pcout,pcwrite,clk); //PC register

Mux2to1 miord(aluout,pcout,tomem,iord); // I or D mux

memory mem(tomem,toir,memwrite,memread,froma,clk,reset); //memory

registerlevel Insreg1(toir,IR,irwrite,clk); // instruction register

CtrlUnit ctrl1(clk,reset,IR[3:0],IR[12:10],regwrite,pcwrite,iord,memread,memwrite,irwrite,
src1,pcsrc,src2,aluop,highwrite,lowwrite,branch,lowsrc,highsrc,wdata); // ctrl unit

register mdr(toir,mdrtor,1'b1,clk); // mdr register

Mux8to1 m81(aluout,high,low,mdrtor,pcout,{IR[15:8],8'd0},16'd0,16'd0,writedata,wdata); //mux for selecting data to write in reg file

RegisterFile regfile(IR[6:4],IR[9:7],IR[6:4],writedata,outbusa,outbusb,regwrite,clk,reset,out_reg0,out_reg1 , out_reg2, 
out_reg3, out_reg4,out_reg5,out_reg6,out_reg7); 

register busa(outbusa,froma,1'b1,clk);//busa
 
register busb(outbusb,fromb,1'b1,clk); //busb

zeroext4to16 shift(IR[15:12],forshift);//for Ir[3:0] calculation

sext6to16 lworsw(IR [15:10],mux2);//for lw or sw

zeroext6to16 zx6(IR[15:10],mux4);//for ori

Mux8to1 msrc1(pcout,froma,forshift,mux2,mux4,16'd0,16'd0,16'd0,alusrc1,src1); // alu src 1

leftshift ls(mux2,mux3);//for leftshift

sext9to16 sex9(IR[15:7],mux5);//for jr

leftshift ls1(mux5,jal);//for jal

Mux4to1 m82(fromb,16'd2,mux5,mux3,alusrc2,src2);//alu src 2

Alu al(aluop,alusrc1,alusrc2,alures,remainder,nzero);//alu called

register aluou(alures,aluout,1'b1,clk);//alu register

Mux2to1 mhigh(remainder,outbusa,tohigh,highsrc);//to select wd for high reg

Mux2to1 mlow(alures,outbusb,tolow,lowsrc);//to select wd for low reg

register rhigh(tohigh,high,highwrite,clk);//high reg

register rlow(tolow,low,lowwrite,clk);//low reg

and abranch(andout,branch,nzero);//and for branch

Mux2to1 mbranch(aluout,pcout,muxout,andout);//mux for branch

Mux4to1 pcsource(alures,muxout,{pcout[15:10],jal[9:0]},16'd0,pcin,pcsrc);	//pc source register

endmodule

module testbench;
reg clk,reset;
wire [15:0] IR,out_reg0,out_reg1 , out_reg2, 
out_reg3, out_reg4,out_reg5,out_reg6,out_reg7, pcout, tomem, toir,tohigh,high,tolow,low;
wire regwrite, pcwrite, iord, memwrite, memread, irwrite, highwrite,
lowwrite, highsrc, lowsrc, nzero, andout, branch;

multi mul1(clk, reset, pcout, tomem, toir,  out_reg0,out_reg1 , out_reg2, 
out_reg3, out_reg4,out_reg5,out_reg6,out_reg7,
IR,tohigh,high,tolow,low,regwrite,pcwrite, iord, memwrite, memread, irwrite, highwrite,
lowwrite, highsrc, lowsrc, nzero, andout, branch);

initial 
begin
clk = 0;
end
initial 
begin
repeat(112)
#1 clk = ~clk;
end

initial
begin
$monitor($time,"  reset =%b , pcout =%b , tomem =%b , toir =%b ,  outreg2=%d,outreg3=%d IR = %b regwrite = %b ,pcwrite = %b, iord = %b memwrite = %b memread= %b, irwrite = %b highwrite = %b lowwrite = %b, highsrc = %b, lowsrc = %b, nzero = %b, andout = %b, branch = %b",
reset, pcout, tomem, toir,  out_reg2,out_reg3,IR,regwrite,pcwrite, iord, memwrite, memread, irwrite, highwrite,
 lowwrite, highsrc, lowsrc, nzero, andout, branch);
end

initial 
	begin
		#1 reset = 1'b1;
		#2 reset = 1'b0;
	end
endmodule 