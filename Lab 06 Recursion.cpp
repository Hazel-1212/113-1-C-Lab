/*For Example
 Total amount: 4
4 ways
? Total of 4 ways to use 1, 2, 3tomaketheamount of 4
 (1, 1, 1, 1) (1, 1, 2) (2, 2) (1, 3)
1 */

/*The main program should prompt user to input one number 
amount and print out the corresponding answer. 

?Note that you should use recursivemethodonly, 
or you will not get any points.*/

#include<iostream> 
#include<cstdlib>

using namespace std;

int countWays(int amount,int unit);

int countWays(int amount,int unit){
	int sum=0;
	if(amount==1||amount==0){
		return 1;
	}
	else if(amount<0){
		return 0;
	}
	else{
		for(int j=unit;j>0;j--){
			
		sum+=countWays(amount-j,j);	
	}
		}
		
		return sum;
		
	}


int main(){
	int amount;
	cout<<"Total amount: ";
	cin>>amount;
	cout<<countWays(amount,3)<<" ways";
	
	
	
}
