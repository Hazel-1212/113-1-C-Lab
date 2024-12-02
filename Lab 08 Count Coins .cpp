#include<iostream>
#include<cstdlib>
using namespace std;
int calc(int index,int array[],int sum,int accu,int n);

int main(){
    int n,sum;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the target sum: ";
    cin>>sum;
    cout<<"Enter the elements of the array: "<<endl;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int accu=0;	
    cout<<"Closest sum to "<<sum<<" without exceeding it is: ";
            cout<<calc(0,array,sum,accu,n)<<endl;
} 

int calc(int index,int array[],int sum,int accu,int n){ //index:From where to n 
    int a,b;
    if(index>n-1){ //**超過array儲存量時回傳累計值!!
        
        return accu;
    }
    else{
        if(accu+array[index]<sum){ //1.小於Target 
        b=calc(index+1,array,sum,accu,n);
        a=calc(index+1,array,sum,accu+array[index],n);
            if(a>b){
               return a;
            }else{
               return b;
            }
        }
        else if(array[index]+accu==sum){  //2. 等於Target
        return sum;
        }
        else{                      //3. 大於Target 
        return calc(index+1,array,sum,accu,n);
        }
    }			
}
