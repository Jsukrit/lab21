#include<iostream>

using namespace std;

int main(int  argc,char *argv[]){
    int count=0,sum = 0,num = 0;
    double average;
    if(argc == 1){
        cout << "Please input numbers to find average.";
    }
    else{
    for(int i = 0 ; i < argc-1 ;i++){
        num = atoi(argv[i+1]);
        sum = sum + num;
        count ++;
    }
    average = sum/count;
    cout << "---------------------------------"<< endl;
    cout << "Average of " << count << " numbers = " << average << endl ;
    cout << "---------------------------------";
    }    
}
