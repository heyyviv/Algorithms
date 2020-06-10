''' Program is based on Euler's product formula which has nlogn complexity
In number theory, the totient φ of a positive integer n is defined to be the number of positive integers less than or equal to n that are coprime to n. '''
import java.util.*; 
  
class GFG { 
	
	public static int precise(int n){
		float result=n;
		for(int i=2;i*i<n;i++){
			if(n%p==0){
				while(n%p==0){
					n=n/p
				}
				result=result*(1.0-(1.0/float(p)));
			}

		}
		if(n>1){
			result=result*(1.0-(1.0/float(n)));
		}
		return int(result);

		
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t>0){
			int n=sc.nextInt();
			int result=precise(n);
			System.out.println(result);

			t--;
		}
	}
    
} 
