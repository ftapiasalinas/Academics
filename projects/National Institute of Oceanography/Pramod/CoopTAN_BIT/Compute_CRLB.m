function CRLBs = Compute_CRLB(dhT_dX,Std_merror,T)
% ++++ Compute CRLB
tanonly =1;
LoadFilterNoises;
P0hat   = Sd0*Sd0';
PHI     = eye(4);
sdx     = std_pnx*sqrt(T);% process noise std dev for translation error in x
sdy     = std_pny*sqrt(T);% process noise std dev for translation error in y
sdbx    = std_pnbecx*sqrt(T);% process noise std dev for translation error in x
sdby    = std_pnbecy*sqrt(T);% process noise std dev for translation error in x
Qk = diag([sdx^2 sdy^2 sdbx^2 sdby^2]);   % Process noise intensity matrix (of the PF part of state vector)

J_prev = inv(P0hat);
[rr,N] = size(Std_merror);

%% TANSBN
clear dhT_dX_t;
J_prev=inv(P0hat);
mm = 1:2;
dhT_dX_t(:,:,:,1) = dhT_dX(:,mm,:);
for t=1:N
    J=calc_filter_information_matrix6(PHI,J_prev,Qk,dhT_dX_t,Std_merror(mm,t),t);
    CRLBt(:,:,t)=inv(J);
    J_prev=J;
    scalar_bound_pos(t) = sqrt(trace(CRLBt(1:2,1:2,t)));
    scalar_bound_bec(t) = sqrt(trace(CRLBt(3:4,3:4,t)));
end

%% TAN Only
if tanonly
clear dhT_dX_t CRLBt;
P0hat   = Sd0(1:2,1:2)*Sd0(1:2,1:2)';
J_prev=inv(P0hat);
mm = 1;
PHI = eye(2);
dhT_dX_t(:,:,:,1) = dhT_dX(:,mm,:);
Qk = diag([sdx^2 sdy^2]);
for t=1:N
    J=calc_filter_information_matrix6(PHI,J_prev,Qk,dhT_dX_t,Std_merror(mm,t),t);
    CRLBt(:,:,t)=inv(J);
    J_prev=J;
    scalar_bound_pos_tanonly(t) = sqrt(trace(CRLBt(1:2,1:2,t)));
    %scalar_bound_bec(t) = sqrt(trace(CRLBt(3:4,3:4,t)));
end
CRLBs = [scalar_bound_pos;scalar_bound_bec;scalar_bound_pos_tanonly];
else
CRLBs = [scalar_bound_pos;scalar_bound_bec];   
end

