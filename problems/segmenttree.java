/*maximim sum of sub array using segment tree*/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.lang.Math.*;


class Ideone
{
	int st[];
	Ideone(int[] arr,int n){
		int x=(int)(Math.ceil(Math.log(n)/Math.log(2)));
		int pow=2*(int)Math.pow(2,x)-1;
		st=new int[pow];
		constructSegtree(arr,0,n-1,0);

	}
	public  int getmid(int ss,int se){
		return ss+((se-ss)/2);
	}
	public int constructSegtree(int[] arr,int ss,int se,int si){
		if(ss==se){
			
			st[si]=arr[ss];
			return st[si];
		
		}
		int mid=getmid(ss,se);
		int a1=(constructSegtree(arr,ss,mid,2*si+1));
		int a2=constructSegtree(arr,mid+1,se,2*si+2);
		st[si]=Math.max(a1,Math.max(a2,a1+a2));
		
		return st[si];
	}
	public  int getsumUtil(int ss,int se,int qs,int qe,int si){
		if(qs<=ss && qe>=se){
			return st[si];
		}
		if(se<qs||ss>qe){
			return 0;
		}
		int mid=getmid(ss,se);
		int sum=getsumUtil(ss,mid,qs,qe,2*si+1)+getsumUtil(mid+1,se,qs,qe,2*si+2);
		return sum;
	}
	public  int getsum(int n,int qs,int qe){
		if(qs<0 ||qs>n-1||qs>qe){
			return -1;
		}
		return getsumUtil(0,n-1,qs,qe,0);
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++){//input array
			arr[i]=sc.nextInt();
		}
		Ideone tree=new Ideone(arr,n);
		int m=sc.nextInt();
		for(int j=0;j<m;j++){
			int x=sc.nextInt();//x is left index y is right index
			int y=sc.nextInt();
			System.out.println(tree.getsum(n,x,y));
		}


	}
}