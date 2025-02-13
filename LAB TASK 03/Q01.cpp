#include <iostream>
#include<string>
using namespace std;
class user{
public:
int age;
string name;
};
int main(){
user User;
User.age=24;
User.name="Teo";
cout << "My name is " << User.name << " and I'm " << User.age << " years old." << endl;
}