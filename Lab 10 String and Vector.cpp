#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath> 
#include<string>
using namespace std;
bool isArm(vector<int> &v);
void extract(string &s);

void extract(string &s){
	//Get the right part of "(" in string s if any
	int pos=s.find("(",0);
	if(pos!=string::npos){
		s=s.substr(pos+1,s.length()-pos-1);
	}
	//Get the left part of ")" in string s if any
	pos=s.find(")",0);
	if(pos!=string::npos){
		s=s.substr(0,pos);
	}
}

bool isArm(vector<int>&v){
	int p=v.size();
	int decimal=0;
	int power=0;
	for(int i=0;i<p;i++){
		decimal+=v[i]*pow(10,p-i-1);
		power+=pow(v[i],p);	
	}
	v.push_back(decimal);
	if(power==decimal){
		return true;
	}else{
		return false;
	}	
}

int main(){
	string s;
	vector <char> c; //c stores the alphabets in string s
	vector <int> cnum;//cnum[i] stores the number of c[i] in string s
	vector<int> num; //num stores the digits in string s
	
	cout<<"Please enter a string : ";
	cin>>s;
	extract(s); //Get the right string part ( )
	cout<<"Target String : "<<s<<endl;

	int index;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=45&&int(s[i])<=57){ //Check if s[i] is a digit
			int temp=int(s[i])-'0';
		    num.push_back(temp);
		}else if(!isspace(s[i])){
			index=-1;
			for(int j=0;j<c.size();j++){
			//Check if s[i] ,which is an alphabet,has appeared before
				if(c[j]==s[i]){ 
					index=j;
					break;
				}
			}
			
			if(index!=-1){ //s[i] has appeared before
				cnum[index]++;
			}
			else{ //s[i] appears at the first time
				c.push_back(s[i]);
				cnum.push_back(1);
			}
		}
	}
	
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<" : "<<cnum[i]<<endl;		
	}
	cout<<"Target Number : ";
	
	if(num.size()>0){ //Check if string s contains any digit
	for(int i=0;i<num.size();i++){
			cout<<num[i];	
	}
	cout<<endl;
	
    int number= num[num.size()-1];
	if(isArm(num)){ //if the digit number is ArmStrong number
		cout<<number<<" is an Armstrong number.\n";
	}
	else{
		cout<<number<<" is NOT an Armstrong number.\n";
	}
		
	}
	else{
		cout<<"none\nall characters\n";	
	}	
}


