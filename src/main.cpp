#include<bits/stdc++.h>
using namespace std;

map<string,string>mp;
void Initialise()
{
    mp["even"]="even.cpp";
    mp["odd"]="odd.cpp";
    mp["even_odd"]="even_odd.cpp";
}
void solve(string s)
{   Initialise();
    stringstream ss(s);
    string token;
    bool check=false;
    while(ss>>token)
    {
        if(mp[token]!="")
        {
            check=true;
            cout<<mp[token]<<endl;
        }

    }
    if(!check)
    cout<<"token not found\n";
}
void start()
{
    string s;
    
    cout<<"Press __ to Stop The Program"<<endl;
    cout<<endl;
    cout<<"Enter Your Query: ";
    getline(cin,s);
    while(s!="__")
    {   solve(s);
        cout<<endl;
        cout<<"Enter Your Query: ";
        
       getline(cin,s);
    }


}
void print()
{  
    cout<<"****** ****** ****** *          * ******  ****** "<<endl;
    cout<<"  *    *    * *    *  *        *    *     *      "<<endl;
    cout<<"  *    *    * *    *   *      *     *     *      "<<endl;
    cout<<"  *    ****** * * **    *    *      *     ****** "<<endl;
    cout<<"* *    *    * *   *      *  *       *          * "<<endl;
    cout<<"  *    *    * *    *      *       ******  ****** "<<endl;\

    cout<<endl<<endl;
}
int main()
{
    print();
    start();
}
