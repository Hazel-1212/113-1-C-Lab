#include<iostream>	
#include <iomanip>
#include <limits> 
using namespace std;
int n;
int row_i,col_i;//h ; w
int row_k,col_k;
int conv_size_row;
int conv_size_col;
int pooling_size_row;
int pooling_size_col;
int c(int** image,int** kernal,int r,int c);
int pool(int** conv,int** kernal,int r,int c);

int main(){   
    cin>>n;
    int** image;
    int** kernal;
    
    for(int p=0;p<n;p++){//test case number
    
	//cin image
	cin>>col_i>>row_i;
	image=new int*[row_i];
	for(int i=0;i<row_i;i++){
    	image[i]=new int[col_i];
	}
	
	for(int i=0;i<row_i;i++){
		for(int j=0;j<col_i;j++){
    	    cin>>image[i][j];
	  }
	}
	//cin kernal
	cin>>col_k;
	row_k=col_k;
	kernal=new int*[row_k];
	for(int i=0;i<row_k;i++){
    	kernal[i]=new int[col_k];
	}
	
	for(int i=0;i<row_k;i++){
		for(int j=0;j<col_k;j++){
    	    cin>>kernal[i][j];
	  }
	}
	
	

	//Convolution
	conv_size_row=row_i-row_k+1;
    conv_size_col=col_i-col_k+1;
    int** conv=new int*[conv_size_row];
    for(int i=0;i<conv_size_row;i++){
    	conv[i]=new int[conv_size_col];
	}
	
	for(int j=0;j<conv_size_row;j++){
        for(int k=0;k<conv_size_col;k++){
             conv[j][k]=c(image,kernal,j,k);
        }
        
    }
		
    cout<<"Convolution:"<<endl;
    for(int j=0;j<conv_size_row;j++){
        for(int k=0;k<conv_size_col;k++){
            cout<<setw(10)<< conv[j][k]; 
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    
    //Pooling
    pooling_size_row=(conv_size_row)/2;
    pooling_size_col=(conv_size_col)/2;
    int** pooling=new int*[pooling_size_row];
    
	for(int i=0;i<pooling_size_row;i++){
    	pooling[i]=new int[pooling_size_col];
	}
	
	for(int j=0;j<pooling_size_row;j++){
        for(int k=0;k<pooling_size_col;k++){
             pooling[j][k]=pool(conv,kernal,j,k);
        }
        
    }
    
	cout<<"Pooling:"<<endl;
    for(int j=0;j<pooling_size_row;j++){
        for(int k=0;k<pooling_size_col;k++){
            cout<<setw(10)<< pooling[j][k];  
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int j=0;j<conv_size_row;j++){	
		delete [] conv[j];
	}
	delete [] conv;
	
	
	for(int j=0;j<pooling_size_row;j++){
		delete [] pooling[j];
	}
    delete [] pooling;
  
    
    for(int j=0;j<row_i;j++){
		delete [] image[j];
	}
	delete [] image;
	
	
	for(int j=0;j<row_k;j++){
		delete [] kernal[j];
	}
	delete [] kernal;
	
	
	} 	  
	return 0;
}

int c(int** image,int** kernal,int r,int c){//conv[r][c]之位置 //從image左上角數算  int image_r=r; 
    int sum=0;
	for(int i=r;i<r+row_k;i++){//左上角的image位置 
		for(int j=c;j<c+col_k;j++){//左上角的image位置 
		      sum+=image[i][j]*kernal[i-r][j-c];
	    }
	}
	return sum;
}

int pool(int** conv,int** kernal,int r,int c){//pooling[r][c]之位置
	int max=numeric_limits<int>::min();;
	for(int i=r*2;i<r*2+2;i++){//左上角的位置 
		for(int j=c*2;j<c*2+2;j++){//左上角的位置 
		    if(conv[i][j]>max){
		    	max=conv[i][j];
			}
		      
	    }
	}
	return max;
}
