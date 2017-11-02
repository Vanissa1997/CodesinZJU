function Jacobi( n,A,b,ep,N )
% Jacobi迭代法，A为系数矩阵,n为阶数；
% ep为精度，即x(k)-x(k-1)的绝对值，如果没有输入，则默认0.0001；
% N为最多迭代次数，如果没有输入，则默认为100；
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
y=zeros(n,1);
for k=1:N
    emax=0;%初始化|yi-xi|；
    for i=1:n
        sum=0;
        for j=1:n
            sum=sum+A(i,j)*x(j);
        end
        y(i)=(b(i)+A(i,i)*x(i)-sum)/A(i,i);
        if abs(y(i)-x(i))>emax %寻找max|y(i)-x(i)|
            emax=abs(y(i)-x(i));
        end
    end
    if emax<ep %最大误差小于精度时就可以输出了
        disp(y);
        disp(k); %实际迭代次数
        return;
    else
        x=y;
    end
end
error('迭代次数超过规定值，失败');
return;   
end

