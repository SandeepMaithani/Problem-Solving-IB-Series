int sum=0,i,x,y,n1=A.size();
    for(i=0;i<n1-1;i++){
        x=abs(A[i]-A[i+1]);
        y=abs(B[i]-B[i+1]);
        sum+=max(x,y);
    }
return sum;
}
