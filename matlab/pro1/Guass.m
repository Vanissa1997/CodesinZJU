function Guass( A,b,n,E )
% A是系数矩阵，n是阶数
% E是一个人为设定的较小的数，当元素小于E时，便认为它足够小，等于0
%求解方程Ax=b

lengthb=length(b);
[m,n]=size(A);
%判断A是否为方阵
if m~=n
    disp('A不是方阵');
    return;
end
%判断A，b是否符合输入条件
if m~=lengthb
    disp('b的长度不等于A的阶数');
    return;
end

for k=1:n-1
    max=0;%选主元
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
        %交换行
        for j=k:n
            temp1=A(row,j);
            A(row,j)=A(k,j);
            A(k,j)=temp1;
        end
        temp2=b(row);
        b(row)=b(k); 
        b(k)=temp2;
    end
    %消元计算
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
    %回代求解
    b(n)=b(n)/A(n,n);
    for c=n-1:-1:1
        for j=c+1:n
            b(c)=b(c)-A(c,j)*b(j);   
        end
        b(c)=b(c)/A(c,c);
    end
end
fprintf('x=[');
fprintf('%.5f ',b);%输出时保留5位小数
fprintf(']\n');
end
