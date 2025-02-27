#include<iostream>
using namespace std;
class Engine{
    bool isRunning;
    public:
    Engine() : isRunning(false){}
    void start(){
        if(!isRunning){
            isRunning=true;
          cout<<"Engine Started"<<endl;  
        }
        else{
          cout<<"Engine is already Started"<<endl;    
        }
    } 
        void stop(){
        if(isRunning){
            isRunning=false;
          cout<<"Engine Stopped"<<endl;  
        }
         else{
          cout<<"Engine is already Stopped"<<endl;    
        }
    } 
};
 class Car{
 private:
   Engine engine;
 public:
 
//  Car(bool move):engine(isRunning){}
    void startCar() {
        engine.start();
    }
    void stopCar() {
        engine.stop();
    }
 };
 
int main() {
Car car;
car.startCar();
car.stopCar();

}