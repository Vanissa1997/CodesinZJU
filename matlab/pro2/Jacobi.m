function Jacobi( n,A,b,ep,N )
% Jacobi��������AΪϵ������,nΪ������
% epΪ���ȣ���x(k)-x(k-1)�ľ���ֵ�����û�����룬��Ĭ��0.0001��
% NΪ���������������û�����룬��Ĭ��Ϊ100��
if nargin<4 %û����������������
    N=100;
end
if nargin<3 %û�����뾫��
    ep=0.0001;
end
[l,m]=size(A);
nb=length(b);
if m~=n|l~=n
    error('A���Ƿ���');
    return;
end
if nb~=n
    error('b�ĳ��Ȳ�����A�Ľ���');
    return;
end
x=zeros(n,1);
y=zeros(n,1);
for k=1:N
    emax=0;%��ʼ��|yi-xi|��
    for i=1:n
        sum=0;
        for j=1:n
            sum=sum+A(i,j)*x(j);
        end
        y(i)=(b(i)+A(i,i)*x(i)-sum)/A(i,i);
        if abs(y(i)-x(i))>emax %Ѱ��max|y(i)-x(i)|
            emax=abs(y(i)-x(i));
        end
    end
    if emax<ep %������С�ھ���ʱ�Ϳ��������
        disp(y);
        disp(k); %ʵ�ʵ�������
        return;
    else
        x=y;
    end
end
error('�������������涨ֵ��ʧ��');
return;   
end

