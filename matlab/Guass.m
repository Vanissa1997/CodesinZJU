function [ X ] = Guass( A,b )
% ����Ԫ��˹��Ԫ��������Է�����AX=b
% AΪn��ϵ������XΪδ֪Ԫ
n=length(b);
%�жϷ������Ƿ��н�
rank_A=rank(A);
rank_b=rank(b);
if rank_b>rank_A
    disp('�������޽�')
end
if rank_A==rank_b&rank_A~=n
    disp('���������������')
end




end

