function [sigma_alpha, stdm, kstdm, cut_grad, cut_range, K] = sonar_physic_consts(theta)
% Establishes constants used by physicial/statistical model of sonar
% INPUTS : theta = beam-witdth (deg)
% OUTPUTS : 
%   sigma_alpha = std.dev.of the slope of the micro-facet (parameter of surface roughness) (see FC-324, FC-343)
%   stdm = additive const of std dev used in statistical model of measurements
%   kstdm = mulitiplicative const of std dev used in statistical model of measurements
%   cut_grad = cut-off constant used to attenuate effect of |grad| on error
%   cut_range = cut-off constant used to attenuate effect of range (depth) on error
%   K = constant factor dependent on sonar beam-width

sigma_alpha = deg2rad(30); % std.dev.of the slope of the micro-facet in rad (parameter of surface roughness) (see FC-372, FC-343)
stdm=0.01; % additive const of std dev used in statistical model of measurements
kstdm=0.01; % mulitiplicative const of std dev used in statistical model of measurements
cut_grad=10; % cut-off constant used to attenuate effect of |grad| on error
cut_range=25; % cut-off constant used to attenuate effect of range (depth) on error

switch theta
    case 1
        K=0.01; % 
    case 5        
        K=0.025; % constant used in statistical simul. model of sonar error
    case 10
        K=0.07;
    case 20
        K=0.14;
    otherwise
        disp('Beam-width not recognized in function: sonar_physic_consts()')
        return
end

