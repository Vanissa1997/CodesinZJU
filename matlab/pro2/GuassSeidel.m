function GuassSeidel( n,A,b,ep,N )
% ��˹���¶������� AΪϵ������nΪ������epΪ���ȣ�NΪ����������
% ��û������ep��N����Ĭ��Ϊ0.0001��100
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
for k=1:N
    emax=0;%��ʼ��|xi-t|��
    for i=1:n
        t=x(i);
        sum=0;
        for j=1:n
            sum=sum+A(i,j)*x(j);
        end
        x(i)=(b(i)+A(i,i)*x(i)-sum)/A(i,i);
        if abs(x(i)-t)>emax %Ѱ��max|xk-1-xk|
            emax=abs(x(i)-t);
        end
    end
    if emax<ep %������С�ھ���ʱ�Ϳ��������
        disp(x);
        disp(k);%ʵ�ʵ�������
        return;
    end
end
error('�������������涨ֵ��ʧ��');
return;       
end

