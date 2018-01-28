int cstrrev(char a[])
{
    int temp,len=strlen(a),j=len-1;
    for(int i=0; i<len/2; i++,--j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
void BigMul(char a[],char b[],char res[])
{
    cstrrev(a);
    cstrrev(b);
    int ta[5000],tb[5000],lena=strlen(a),lenb=strlen(b);
    int i,j;
    for(i=0; i<lena; ++i)ta[i]=a[i]-'0';
    for(j=0; j<lenb; ++j)tb[j]=b[j]-'0';
    for(i=lena+lenb; i>=0; --i)res[i]=0;
    for(i=0; i<lena; ++i)
    {
        for(j=0; j<lenb; ++j)
        {
            res[i+j]+=ta[i]*tb[j];
            res[i+j+1]+=res[i+j]/10;
            res[i+j]%=10;
        }
    }
    i=lena+lenb;
    while(i>1&&!res[i-1])--i;
    while(i>0)
        res[--i]+='0';
    cstrrev(a);
    cstrrev(b);
    cstrrev(res);
}
