#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vll vector<int>





// Initializer in C++
/*
    Initializer is used to initialize data member of a class.
    The list of members to be initialized is indicated with constructor as a seperated list followed by a colon.
*/
/*
class fun{
    int a,b;
public:
    fun():a(1),b(1){  }
    void show(){ cout<<a<<" "<<b<<endl; }
};
int32_t main(){
    fun f1;
    f1.show();
    return 0;
}
// Here both constructor and initializer will work but there are some cases where only initializer is a solution
*/
/*
// In case of const member variable, we can't use constructor
class fun{
    int a,b;
    const int c;
public:
    fun():c(1){
        a=0;b=0;
    }
    void showdata(){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};
int32_t main(){
    fun f;
    f.showdata();
    return 0;
}
*/
/*
class fun{
    int a,b;
    const int c;
    int &d;
public:
    fun(int x):c(1),d(x){
        a=1;b=1;
    }
    void showdata(){
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
};
int32_t main(){
    int x=2;
    fun f(x);
    f.showdata();
    return 0;
}
*/

// Deep Copy and Shallow Copy

/*
    How we can create a copy of an abject
    1. using copy constructor
    2. using copy assignment operator
*/

/*
class Dummy{
    int a,b;
public:
    void setdata(int x,int y){ a=x;b=y; }
    void showdata(){ cout<<"a="<<a<<" b="<<b<<endl; }
};
int32_t main(){
    Dummy d1;
    d1.setdata(3,4);
    d1.showdata();
    Dummy d2=d1;            // copy constructor
    d2.showdata();
    Dummy d3;
    d3=d1;                  // assignment operator
    d3.showdata();
    return 0;
}
*/
/*
class Dummy{
    int a,b,*p;
public:
    Dummy(){ a=0;b=0;p=new int; }
    Dummy(Dummy &d){ a=d.a;b=d.b;p=d.p; }           // shallow copy just address is copied so now both are pointing at same address
    void setdata(int x,int y,int z){ a=x;b=y;*p=z; }
    void showdata(){ cout<<"a="<<a<<" b="<<b<<" p="<<*p<<" address="<<p<<endl; }
};
int32_t main(){
    Dummy d1;
    d1.setdata(3,4,5);
    d1.showdata();
    Dummy d2=d1;            // copy constructor
    d2.showdata();
    Dummy d3;
    d3=d1;                  // assignment operator
    d3.showdata();
    return 0;
}
*/
/*
class Dummy{
    int a,b,*p;
public:
    Dummy(){ a=0;b=0;p=new int; }
    Dummy(Dummy &d){ a=d.a;b=d.b;p=new int; *p=*(d.p); }            // Deep copy a new variable is created first and then it's data is copied
    void setdata(int x,int y,int z){ a=x;b=y;*p=z; }
    void showdata(){ cout<<"a="<<a<<" b="<<b<<" p="<<*p<<" address="<<p<<endl; }
};
int32_t main(){
    Dummy d1;
    d1.setdata(3,4,5);
    d1.showdata();
    Dummy d2=d1;            // copy constructor
    d2.showdata();
    Dummy d3;
    d3=d1;                  // assignment operator
    d3.showdata();
    return 0;
}
*/

// Type conversion

// (A) Primitive type to Primitive type
/*
int32_t main(){
    int x=10;
    double d=x;             // no data loss
    cout << d << endl;
    return 0;
}
*/
/*
int32_t main(){
    double d=2.3;
    int x=d;                // data lost
    cout << x << endl;
    return 0;
}
*/

// (B) Primitive type to class type (eg: c1=x;)
// --> It can be done using constructor

/*
class Complex{
    int a,b;
public:
    Complex(){ a=0;b=0; }
    Complex(int k){ a=k;b=0; }
    void showdata(){ cout << "a=" << a << " b=" << b << endl;}
};
int32_t main(){
    int x=5;
    Complex c1;
    c1=x;
    c1.showdata();
    return 0;
}
*/

// (C) class type to primitive type (eg: x=c1;)
// --> It is done by casting operator
/*
class Complex{
    int a,b;
public:
    Complex(){ a=0;b=0; }
    void setdata(int x,int y){ a=x;b=y; }
    void showdata(){ cout<<"a="<<a<<" b="<<b<<endl;}
    operator int(){
        return a;
    }
};
int32_t main(){
    Complex c1;
    c1.setdata(3,4);
    c1.showdata();
    int x;
    x=c1;
    cout << x << endl;
    return 0;
}
*/

// (D) class type to another class type (eg: c1=i1;)
// It can be done by both using constructor and casting operator

// using constructor
/*
class Product{
    int m,n;
public:
    void setdata(int x,int y){ m=x;n=y; }
    void showdata(){ cout<<"m="<<m<<" n="<<n<<endl; }
    int getm(){ return m; }
    int getn(){ return n; }
};
class Item{
    int a,b;
public:
    Item(){ a=0;b=0; }
    Item(Product &p){ a=p.getm();b=p.getn(); }
    void setitem(int x,int y){ a=x;b=y; }
    void showitem(){ cout<<"a="<<a<<" b="<<b<<endl; }
};
int32_t main(){
    Item I1;
    Product P1;
    P1.setdata(2,3);
    P1.showdata();
    I1=P1;
    I1.showitem();
    return 0;
}
*/

// Using Casting operator

/*
class Item{
    int a,b;
public:
    Item(){ a=0;b=0; }
    void setitem(int x,int y){ a=x;b=y; }
    void showitem(){ cout<<"a="<<a<<" b="<<b<<endl; }
};
class Product{
    int m,n;
public:
    void setdata(int x,int y){ m=x;n=y; }
    void showdata(){ cout<<"m="<<m<<" n="<<n<<endl; }
    operator Item(){
        Item i;
        i.setitem(m,n);
        return i;
    }
};
int32_t main(){
    Item I1;
    Product P1;
    P1.setdata(2,3);
    P1.showdata();
    I1=P1;
    I1.showitem();
    return 0;
}
*/


// Exception Handling
/*
    Exception is any abnormal behaviour, run-time error.
    Exception are off beat situation in our program our program should be ready to handle it with appropriate response.
    C++ provides a built in error handling mechanism that is called exception handling.
    using exception handling we can more easily manage and responds to runtime errors.
    keyWords:= try,catch,throw
    program statements that you want to monitor for exception are contained in try block
    if any exceptions are ccured within the try block, it is thrown (using throw);
    the exception is caught, using catch and processed.
*/
/*CODE*/
/*
int32_t main(){
    cout << "First line" << endl;
    try{
        cout << "Inside try block before throw" << endl;
        throw 10;
        cout << "Inside try block after throw" << endl;
    }
    catch(int32_t e){                   // as 10 is thrown then it should be caught using int not long long int
        cout << "Inside catch block" << endl;
        cout << "Caught error is:=" << e << endl;
    }
    cout << "Last lime" << endl;
    return 0;
}
*/

/*
int32_t main(){
    cout << "First line" << endl;
    try{
        cout << "Inside try block before throw" << endl;
        throw 10.0;
        cout << "Inside try block after throw" << endl;
    }
    catch(int32_t e){                   // as 10 is thrown then it should be caught using int not long long int
        cout << "Inside int32_t catch block" << endl;
        cout << "Caught error is:=" << e << endl;
    }
    catch(double d){
        cout << "Inside double catch block" << endl;
        cout << "Caught error is:=" << d << endl;
    }
    cout << "Last lime" << endl;
    return 0;
}
*/

/*
int32_t main(){
    cout << "First line" << endl;
    try{
        cout << "Inside try block before throw" << endl;
        int x=3;
        if(x==1)    throw 10;
        else if(x==2)   throw 20;
        else    throw 'a';
        cout << "Inside try block after throw" << endl;
    }
    catch(int32_t e){                   // as 10 is thrown then it should be caught using int not long long int
        cout << "Inside int32_t catch block" << endl;
        cout << "Caught error is:=" << e << endl;
    }
    catch(double d){
        cout << "Inside double catch block" << endl;
        cout << "Caught error is:=" << d << endl;
    }
    catch(...){                         // If nothing matches then default block will execute
        cout << "Auto block" << endl;
    }
    cout << "Last lime" << endl;
    return 0;
}
*/

/*
void fun2(){
    cout << "Inside fun2" << endl;
    throw 10;
}
void fun(){
    cout << "Inside fun" << endl;
    try{
        fun2();
    }
    catch(double d){
        cout << "Inside double catch block" << endl;
        cout << "Caught block value is:=" << d << endl;
    }
}
int32_t main(){
    cout << "First line" << endl;
    try{
        fun();
    }
    catch(int32_t x){
        cout << "Inside int32_t catch block" << endl;
        cout << "Caught block value is:=" << x << endl;
    }
    return 0;
}
*/



// Namespace in c++
/*
    Header files contains only function declaration not function definition or coding
    Function Coding or definition is stored in some library file
Syntax-> namespace Myspace{
            --declaration
        }
    Namespace is a group of declarations, in c++ a lot of declaration are grouped together in a namespace;
    Namespace is not a class so we cant create its object
    Namespace definition doesn't terminates with semicolon (;)
    Namespace definition must be done at global scope or nested inside another namespace;
    we can use alias for namespace name; eg:  namespace ms=Myspace;
    namespace name can be unNamed;
*/
/*CODE*/
/*
namespace Myspace{
    int x;
    void f1();
    class car{
        public:
            void fun1();
    };
    car c1;
}
void Myspace::f1(){
    cout << "F1" << endl;
}
void Myspace::car::fun1(){
    cout << "Fun1" << endl;
}
using namespace Myspace;
int32_t main(){
    x=5;
    cout << x << endl;
    f1();
    c1.fun1();

    return 0;
}
*/


// Virtual Destructor

// In early binding compiler only looks at the type of the pointer, so compiler only map with destructor of that class not for it's child class;
/*CODE*/
/*
class base{
    public:
        base(){ cout << "Base formed " << endl;}
        ~base(){ cout << "Base deleted" << endl; }
};
class derived: public base {
    public:
        derived(){ cout << "derived formed" << endl; }
        ~derived(){ cout << "derived deleted" << endl; }
};


int32_t main(){
    derived *d=new derived();
    base *b=d;
    delete b;
    return 0;
}
*/

// we only have to write virtual for the base class not for the child class, all of its decendent class destructor automatically becomes virtual;
/*CODE*/
/*
class base{
    public:
        base(){ cout << "Base formed " << endl;}
        virtual ~base(){ cout << "Base deleted" << endl; }
};
class derived: public base {
    public:
        derived(){ cout << "derived formed" << endl; }
        ~derived(){ cout << "derived deleted" << endl; }
};


int32_t main(){
    derived *d=new derived();
    base *b=d;
    delete b;
    return 0;
}
*/


// Nested class

// Sometimes we only need to use a class inside another class, individually that class doesn't makes any sense. so in that situation nested class is useful.
/*CODE*/
/*
class Student{
    int roll_no;
    string name;
    class Address{
        int house_no;
        string pincode;
        string street;
        string state;
    public:
        void setAddress(int hn,string pc,string st,string se){
            house_no=hn;pincode=pc;street=st;state=se;
        }
        void showAddress(){
            cout<<house_no<<"/"<<street<<"/"<<state<<"/"<<pincode<<endl;
        }
    };
    Address add;
public:
    void setData(int rn,string ne,int hn,string pc,string st,string se){
        roll_no=rn;name=ne;
        add.setAddress(hn,pc,st,se);
    }
    void showData(){
        cout<<"Roll no->"<<roll_no<<"/"<<"Name->"<<name<<"/";
        add.showAddress();
    }
};

int32_t main(){
    Student s1;
    s1.setData(101,"Ujjwal",54,"854114","Pothia","Bihar");
    s1.showData();
    return 0;
}
*/



