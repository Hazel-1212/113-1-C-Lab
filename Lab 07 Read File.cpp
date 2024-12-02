#include <iostream>
#include <cmath>
#include <cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


int  main(){
	char name[20];
	cout<<"Please write the input file name: ";
	cin>>name;
	
ifstream fileIn(name);
ofstream fileOut("output.txt");



int number[5][5];
if(fileIn.fail()){
	cout<<"Error";
	exit(1);
}

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
				fileIn>>number[j][i];
		}
	
	}
	
	
	
	int sum[5];
	
	for(int i=0;i<5;i++){
		sum[i]=0;
		for(int j=0;j<5;j++){
				sum[i]+=pow(number[i][j],2);
		}
		
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
				cout<<setw(5)<<number[i][j]<<" ";
				fileOut<<setw(5)<<number[i][j]<<" ";
		}
		cout<<" = "<<sum[i]<<"\n";
		fileOut<<" = "<<sum[i]<<"\n";
	}
	
	int max=sum[0];
	
	for(int i=0;i<5;i++){
	if(sum[i]>max){
		max=sum[i];
	}
	}
	fileOut<<"Max value is "<<max<<endl;
	cout<<"Max value is "<<max<<endl;

fileIn.close();
fileOut.close();

}
