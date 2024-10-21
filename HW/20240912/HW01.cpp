#include<iostream>
using namespace std;

int main(){
    int n=0, ans=0;                                     //define variables

    cout<<"Enter a natural integer:";

    while(cin>>n){                                      //debug
        if(n<=0){
            cout<<"Invalid number!\n";
            system("pause");
            system("cls");
            cout<<"Enter a natural integer:";
        }
        else{
            break;
        }
    }

    if(n>0){                                         //print out the diagram by rows
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                ans=i*j;
                if(i<=9){
                    cout<<j<<"* "<<i<<"=";
                }
                else{
                    cout<<j<<"*"<<i<<"=";
                }

                if(ans<10){
                    cout<<"  "<<ans<<"  ";
                }
                else if(ans>=10 && ans<100){
                    cout<<" "<<ans<<"  ";
                }
                else{
                    cout<<ans<<"  ";
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}
