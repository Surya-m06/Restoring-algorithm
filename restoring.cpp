#include<iostream>
using namespace std;
void display(int acc[8],int X[8]){
    cout<<"Accumulator: ";
    for(int k=0;k<8;k++){cout<<acc[k];}
    cout<<"  "<<"register: ";
    for(int k=0;k<8;k++){cout<<X[k];}
    cout<<endl;
}
int main(){
    int X[8],Y[8],acc[8]={0,0,0,0,0,0,0,0};
    
    string x,y;
    cout<<"input X:";
    cin>>x;
    cout<<"input Y:";
    cin>>y;
    for(int i=0;i<8;i++){
        X[i]=x[i]-'0';
        Y[i]=y[i]-'0';
    }
    display(acc,X);
    for(int i=0;i<8;i++){
        cout<<"step :"<<i+1<<endl;
        for(int j=0;j<7;j++){
            acc[j]=acc[j+1];
        }
        acc[7]=X[0];
        for(int j=0;j<7;j++){
            X[j]=X[j+1];
        }
        display(acc,X);
        int carry=0,temp,sub;
        int ACC_TEMP[8];
        for(int j=0;j<8;j++){ACC_TEMP[j]=acc[j];}
        for(int j=7;j>=0;j--){
             temp=acc[j];
             sub=(temp^Y[j]);
             sub=(sub^carry);
             acc[j]=sub;
             carry = (temp == 0 && Y[j] == 1) || (carry == 1 && (temp ^ Y[j]) == 0);

        }
        display(acc,X);
        if(acc[0]==0){
            X[7]=1;
        }
        else{
            for(int j=0;j<8;j++){acc[j]=ACC_TEMP[j];}
            X[7]=0;
        }
        display(acc,X);
    }
}