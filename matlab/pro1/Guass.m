function Guass( A,b,n,E )
% A��ϵ������n�ǽ���
% E��һ����Ϊ�趨�Ľ�С��������Ԫ��С��Eʱ������Ϊ���㹻С������0
%��ⷽ��Ax=b

lengthb=length(b);
[m,n]=size(A);
%�ж�A�Ƿ�Ϊ����
if m~=n
    disp('A���Ƿ���');
    return;
end
%�ж�A��b�Ƿ������������
if m~=lengthb
    disp('b�ĳ��Ȳ�����A�Ľ���');
    return;
end

for k=1:n-1
    max=0;%ѡ��Ԫ
    for i=k:n
        if abs(A(i,k))>max
            max=abs(A(i,k));
            row=i;
        end
    end
    if max<E
        disp('det(A)=0');
        return;
    end
    if row>k
        %������
        for j=k:n
            temp1=A(row,j);
            A(row,j)=A(k,j);
            A(k,j)=temp1;
        end
        temp2=b(row);
        b(row)=b(k); 
        b(k)=temp2;
    end
    %��Ԫ����
    for i=k+1:n
        A(i,k)=A(i,k)/A(k,k);
        for j=k+1:n
            A(i,j)=A(i,j)-A(i,k)*A(k,j);
        end
        b(i)=b(i)-A(i,k)*b(k);
    end     
end
if abs(A(n,n))<E
    disp('det(A)=0');
    return;
else
    %�ش����
    b(n)=b(n)/A(n,n);
    for c=n-1:-1:1
        for j=c+1:n
            b(c)=b(c)-A(c,j)*b(j);   
        end
        b(c)=b(c)/A(c,c);
    end
end
fprintf('x=[');
fprintf('%.5f ',b);%���ʱ����5λС��
fprintf(']\n');
end
