#include <bits/stdc++.h>
using namespace std;
class A {
    private:
        int x=5;
    public:
        virtual void display()
        {
            cout<<"value of x: "<<x<<endl;
        }
        
};





class B: public A {
    private:
        int y=10;
    public:
        void display()
        {
            cout<<"value of y: "<<y<<endl;
        }

};

int main()
{
    A *a;
    B b;
    a = &b;
    a->display();

    return 0;
}