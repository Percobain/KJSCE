#include<iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>
#define MAX 100
int *binaryadd(int b[] , int c[] , int segments)
{
	int carry=0,i;
	int *d = new int[MAX];
		for(i=segments-1;i>=0;i--)
		{
			if(b[i]==1 && c[i]==1 && carry==0)
			{
				d[i] = 0;
				carry = 1;
			}
			else if(b[i]==1 && c[i]==1 && carry==1)
			{
				d[i] = 1;
				carry = 1;
			}
			else if(b[i]==0 && c[i]==0 && carry==0)
			{
				d[i] = 0;
				carry = 0;
			}
			else if(b[i]==0 && c[i]==0 && carry==1)
			{
				d[i] = 1;
				carry = 0;
			}
			else if(b[i]==1 && c[i]==0 && carry==0)
			{
				d[i]=1;
				carry = 0;
			}
			else if(b[i]==1 && c[i]==0 && carry==1)
			{
				d[i] = 0;
				carry = 1;
			}
			else if(b[i]==0 && c[i]==1 && carry==0)
			{
				d[i] = 1;
				carry = 0;
			}
			else if(b[i]==0 && c[i]==1 && carry==1)
			{
				d[i] = 0;
				carry = 1;
			}
			else 
				break;

		}
		return d;
}
int main()
{
		int bits,a[MAX],b[MAX],c[MAX],i,j,segments;
		cout<<"\n/*/*/*/*/*/*/*/*/*/===CHECKSUM===*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n";
		cout<<"\nEnter no of bits: ";
		cin>>bits;
		if(bits%2!=0)
		{
			cout<<"\nenter even bit no.\n";
			exit(1);
		}
		for(i=0;i<bits;i++)
		{
			cout<<"\nEnter ["<<i+1<<"] : ";
			cin>>a[i];
		}
		cout<<"\n\nMain Message = ";
		for(i=0;i<bits;i++){ cout<<a[i];}

		segments = bits/2;

		for(i=0;i<segments;i++)
			b[i] = a[i];

		for(i=segments,j=0;i<bits;i++,j++)
		{
			c[j] = a[i];
		}

		cout<<"\n\nAfter dividing 2 types : ";
		for(i=0;i<segments;i++){ cout<<b[i];}
		cout<<" | ";
		for(i=0;i<segments;i++){ cout<<c[i];}

		int *f , tmp[MAX];
		f = binaryadd(b,c,segments);
		cout<<"\n\nafter adding previous 2 terms: ";
		for(i=0;i<segments;i++){tmp[i] = f[i]; cout<<f[i];}

		int addone[MAX];
		for(i=0;i<segments-1;i++)
		{
			addone[i]=0;			
		}				
		addone[i] = 1;
		cout<<"\n\nadd this data to above result : ";
		for(i=0;i<segments;i++)
		{
			cout<<addone[i];
		}
		int *t,l[MAX];
		t = binaryadd(tmp,addone,segments);
		cout<<"\n\nNew data : ";
		for(i=0;i<segments;i++){
				cout<<t[i];
			
		}
		cout<<"\n\naftre compliment: ";
		for(i=0;i<segments;i++){
			if(t[i]==0)
				t[i] = 1;
			else
				t[i] = 0;
			
			l[i] = t[i];
			cout<<t[i];
		}
		int q[MAX];
		cout<<"\n\nreceiver side : \n";
		int *s = binaryadd(tmp,l,segments);
		
		cout<<"\n\nAfter Adding Transmitted Msg and Original Message : ";
		for(i=0;i<segments;i++){q[i] = s[i]; cout<<s[i];}
		int *z = binaryadd(s,addone,segments);
		cout<<"\n\nafter adding 1 : ";
		for(i=0;i<segments;i++){cout<<z[i];}
		cout<<"\n\nafter compliment : ";
		for(i=0;i<segments;i++){
			if(z[i]==0)
				z[i] = 1;
			else 
				z[i] = 0;
				
			cout<<z[i];
		}
		cout<<endl;
return 0;
}