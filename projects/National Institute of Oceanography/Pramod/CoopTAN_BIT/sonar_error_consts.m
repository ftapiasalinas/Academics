function [k1,k2,k3,k4] = sonar_error_consts(errorlevel)
% define constants used to calculate the parameters of normal distribution 
% of the sonar measurement error: e(k)~N(ud,sd) 
% 3 versions of this function: sonar_error_conts_1ow, sonar_error_conts_med, and sonar_error_conts_high
% with different levels of constants
% must be coherent in the different scripts using this error model
switch errorlevel
    case 0
        k1=0; k2=0; 
        k3=0; k4=0; 
    case 1        
        k1=0; k2=0; 
        k3=0.01; k4=0.01; 
    case 2
        k1=0; k2=0; 
        k3=0.018; k4=0.018; 
    case 3
        k1=-0.01; k2=-0.01; 
        k3=0.018; k4=0.018; 
    otherwise
        disp ('Unknown error level (in sonar_error_consts.m)')
end