function GuassSeidel( n,A,b,ep,N )
% 高斯赛德尔迭代法 A为系数矩阵，n为阶数，ep为精度，N为最大迭代次数
% 若没有输入ep和N，则默认为0.0001和100
if nargin<4 %没有输入最大迭代次数
    N=100;
end
if nargin<3 %没有输入精度
    ep=0.0001;
end
[l,m]=size(A);
nb=length(b);
if m~=n|l~=n
    error('A不是方阵');
    return;
end
if nb~=n
    error('b的长度不等于A的阶数');
    return;
end
x=zeros(n,1);
for k=1:N
    emax=0;%初始化|xi-t|；
    for i=1:n
        t=x(i);
        sum=0;
        for j=1:n
            sum=sum+A(i,j)*x(j);
        end
        x(i)=(b(i)+A(i,i)*x(i)-sum)/A(i,i);
        if abs(x(i)-t)>emax %寻找max|xk-1-xk|
            emax=abs(x(i)-t);
        end
    end
    if emax<ep %最大误差小于精度时就可以输出了
        disp(x);
        disp(k);%实际迭代次数
        return;
    end
end
error('迭代次数超过规定值，失败');
return;       
end

