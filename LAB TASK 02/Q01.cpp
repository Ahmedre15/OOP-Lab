#include <iostream>
#include <string>
using namespace std;
int main(int argc,char *argv[]){
	int sum = 0;
	    if (argc > 1) {
	    	int numbers[argc-1];
        for(int i=1;i<argc;i++){
        	numbers[i-1]=stoi(argv[i]);
        }
        int *ptr=numbers;
        
        for(int i=0;i<argc-1;i++){
        	sum=sum+*(ptr+i);
        	
        }cout<< "Sum is : "<< sum <<endl;
    } else {
        cout << "Please provide arguments.\n";
    }
	
	
	return 0;
}
