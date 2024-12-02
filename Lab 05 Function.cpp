#include<iostream>
#include<cmath> 
using namespace std;
int Date2Day(int y,int m,int d);
void printDay(int date);
void printCalendar(int year,int month,int day,int date);
bool is_leap(int year);

bool is_leap(int year){
	/*If the year is divisible by 4 and not by 100, or the
year is divisible by 400, it is a leap year.*/
if(year%4==0){
	if(year%100==0&&year%400!=0){
		return false;
	}
	else{
		return true;
		
	}
}
else{
	return false;
}
}





int Date2Day(int y,int m,int d){
	int date;
	date=y+(y-1)/4-(y-1)/100+(y-1)/400;
	date=date%7;
	//cout<<"date of 1/1: "<<date<<endl;
	//cout<<"leap: "<<is_leap(y)<<endl;
	
	if(is_leap(y)){
		switch(m){
			case 1:
				date=date+d;
				break;
			case 2:
				date=date+31+d;
				break;
			case 3:
				date=date+31+29+d;
				break;
			case 4:
				date+=31+29+31+d;
				break;
			case 5:
				date+=31+29+31+30+d;
				break;
			case 6:
				date+=31+29+31+30+31+d;
				break;
			case 7:
				date+=31+29+31+30+31+30+d;
				break;
			case 8:
				date+=31+29+31+30+31+30+31+d;
				break;
			case 9:
				date+=31+29+31+30+31+30+31+31+d;
				break;
			case 10:
				date+=31+29+31+30+31+30+31+31+30+d;
				break;
			case 11:
				date+=31+29+31+30+31+30+31+31+30+31+d;
				break;
			case 12:
				date+=31+29+31+30+31+30+31+31+30+31+30+d;
				break;
		}
		
	}
	else{
		switch(m){
			case 1:
				date=date+d;
				break;
			case 2:
				date=date+31+d;
				break;
			case 3:
				date=date+31+28+d;
				break;
			case 4:
				date+=31+28+31+d;
				break;
			case 5:
				date+=31+28+31+30+d;
				break;
			case 6:
				date+=31+28+31+30+31+d;
				break;
			case 7:
				date+=31+28+31+30+31+30+d;
				break;
			case 8:
				date+=31+28+31+30+31+30+31+d;
				break;
			case 9:
				date+=31+28+31+30+31+30+31+31+d;
				break;
			case 10:
				date+=31+28+31+30+31+30+31+31+30+d;
				break;
			case 11:
				date+=31+28+31+30+31+30+31+31+30+31+d;
				break;
			case 12:
				date+=31+28+31+30+31+30+31+31+30+31+30+d;
				break;
		}
	}
	date=(date-1)%7;
	return date;
}


void printDay(int date){
	switch(date){
		case 0:
			cout<<"Sunday"<<endl;
			break;
		case 1:
			cout<<"Monday"<<endl;
			break;
		case 2:
			cout<<"Tuesday"<<endl;
			break;
		case 3:
			cout<<"Wednesday"<<endl;
			break;
		case 4:
			cout<<"Thursday"<<endl;
			break;
		case 5:
			cout<<"Friday"<<endl;
			break;
		case 6:
			cout<<"Saturday"<<endl;
			break;
	}
}
	

void printCalendar(int year,int month,int day,int date){
	int day1=Date2Day(year,month,1);
	int a[5][7];
	int b[100]={0};
	int numOfday;
	int leap;
	cout<<" SU MO TU WE TH FR SA";
	switch(month){
		case 1:
			numOfday=31;
			break;
		case 2:
			if(year%4==0){
	if(year%100==0&&year%400!=0){
		leap=0;
	}
	else{
		leap=1;
		
	}
}
else{
	leap=0;
}
			if(leap==1){
				numOfday=29;
			}else{
				numOfday=28;
			}
			break;
		case 3:
			numOfday=31;
			break;
		case 4:
			numOfday=30;
			break;
		case 5:
			numOfday=31;
			break;
		case 6:
			numOfday=30;
			break;
		case 7:
			numOfday=31;
			break;
		case 8:
			numOfday=31;
			break;
		case 9:
			numOfday=30;
			break;
		case 10:
			numOfday=31;
			break;
		case 11:
			numOfday=30;
			break;
		case 12:
			numOfday=31;
			break;
	}
	
	
	for(int i=1;i<=numOfday;i++){
		b[i-1+day1]=i;
	}
	
	for(int i=0;i<=42;i++){
		if(i%7==0){
			cout<<"\n";
		}
		if(b[i]==0){
			cout<<"   ";
		}
		else if(b[i]<10){
			cout<<"  "<<b[i];
		}
		else{
			cout<<" "<<b[i];
		}
		if(i>28&&b[i+1]==0){
			if((i+1)%7==7){
				cout<<"\n";
				break;
			}else{
				cout<<"\n";
				break;
			}
			
		}
		
		
		
	}
}

int main(){
	int year,month,day;
	while(1){
	cout<<"Input the date:";
	cin>>year>>month>>day;
	
	if(year==0||month==0||day==0){
		break;
	}
	
	
	

		//print Monday...
	printDay(Date2Day(year,month,day));
	printCalendar(year,month,day,Date2Day(year,month,day));
	cout<<"--------------------"<<endl;
	
	}
	
	
	
	
	
}
