//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
Complex operator+ (Complex num1, Complex num2){
    Complex added = Complex();
    added.a = num1.a + num2.a;
    added.b = num1.b + num2.b;
    return added;
}

ostream& operator<< (ostream& output, Complex& number){
    return cout << number.a << "+" << "i" << number.b << endl;
}
