function Gmatrix=G_u(U)
% Calculates the time-varying input-coupling matrix G(U(t)) for the case of a vehicle
% stabilized in pitch and roll :only yaw and yaw rate vary (see script sim_nav.m)
% U = [Vu; Vv; psi; r; z]
global T
cpsi=cos(U(3)); spsi=sin(U(3));
if U(4)==0
    alfa=T*cpsi;
    beta=T*spsi;
else    
    crt=cos(U(4)*T); srt=sin(U(4)*T);
    alfa=(cpsi*srt+spsi*(crt-1))/U(4);
    beta=(spsi*srt-cpsi*(crt-1))/U(4);
end
Gmatrix=[alfa  -beta; beta alfa];
