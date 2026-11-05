// Write a program for analysis of Quick sort by using deterministic and randomized variants.

#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class quickSort{
    vector<int> arr;
    public:
    quickSort(){
        getInput();
    }
    void getInput(){
        int n;
        cout<<"Enter number of elements : ";
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;i++){
            cout<<"Enter element "<<i<<" : ";
            cin>>arr[i];
        }
        printArr(arr);
    }
    void printArr(vector<int>&arr){
        int n=arr.size();
        cout<<"Elements :  ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void printArr(){
        printArr(arr);
    }
    

    int partition(int low,int high,vector<int>&arr){
        int idx=low-1;
        int pivot=arr[high];
        for(int i=low;i<high;i++){
            if(arr[i]<=pivot){
                idx++;
                swap(arr[i],arr[idx]);
            }
        }
        swap(arr[high],arr[idx+1]);
        return idx+1;
        
    }
    
    void deterministic(int low,int high,vector<int>&arr){
        if(low<high){
            printState(low,high,high,arr);
            
            int p=partition(low,high,arr);
            deterministic(low,p-1,arr);
            deterministic(p+1,high,arr);
        }
    }
    void deterministic(vector<int>arr){
        vector<int>vect=arr;
        int n=vect.size();
        deterministic(0,n-1,vect);
        
        cout<<"Sorted array : "<<endl;
        printArr(vect);
    }
    void deterministic(){
        deterministic(arr);
    }
    
    void randomized(int low,int high,vector<int>&arr){
        if(low<high){
            int randIdx=low+rand()%(high-low+1);
            
            printState(low,high,randIdx,arr);
            
            swap(arr[randIdx],arr[high]);
            
            int p=partition(low,high,arr);
            
            randomized(low,p-1,arr);
            randomized(p+1,high,arr);
        }
    }
    void randomized(vector<int>arr){
        vector<int> vect(arr);
        int n=vect.size();
        randomized(0,n-1,vect);
        
        cout<<"Sorted array : "<<endl;
        printArr(vect);
    }
    void randomized(){
        randomized(arr);
    }
    
    void printState(int low,int high,int pivotIdx,vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            cout<<arr[i];
            if(i==low)cout<<"]L";
            if(i==high)cout<<"]H";
            if(i==pivotIdx)cout<<"<-P";
            cout<<"\t";
        }
        cout<<endl;
    }
    
};

int main(){
    srand(time(0));

    quickSort q;
    // q.deterministic({7,3,5,6,2,1,4});
    // q.randomized({7,3,5,6,2,1,4});

    string menu="1. Enter array. \n2. Sort deterministic. \n3. Sort randomized. \n4. Show array. \n5. Exit.";
    cout<<menu<<endl;

    while(true){
        int choice;
        cout<<endl<<"Enter choice : ";
        cin>>choice;
        if(choice==1){
            q.getInput();
        }else if(choice==2){
            q.deterministic();
        }else if(choice==3){
            q.randomized();
        }else if(choice==4){
            q.printArr();
        }else if(choice==5){
            cout<<"Thank You !"<<endl;
            break;
        }else{
            cout<<"Invalid input"<<endl;
        }
    }
    return 0;
}