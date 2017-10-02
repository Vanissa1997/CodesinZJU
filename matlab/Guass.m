function [ X ] = Guass( A,b )
% 列主元高斯消元法求解线性方程组AX=b
% A为n阶系数矩阵，X为未知元
n=length(b);
%判断方程组是否有解
rank_A=rank(A);
rank_b=rank(b);
if rank_b>rank_A
    disp('方程组无解')
end
if rank_A==rank_b&rank_A~=n
    disp('方程组有无数组解')
end




end

