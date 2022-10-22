#include <iostream>
#include<stack>
using namespace std;
void input(stack<char> &s)
{
   string str;
   cin>>str;
   int i=0;
   while(i<str.size()){
       s.push(str[i]);
       i++;
   }
}
int get(stack<char> &s, char ch) {
   int i = 0;
       while (!s.empty()) {
           if (s.top() != ch && i != 0)
               break;i++;
           s.pop();
       }
   return i;
}
bool chk(stack<char> s, char ch)
{
   char ch1;
   if(ch=='0')
       ch1='1';
   else
       ch1='0';
   if (s.empty())
       return true;
   int i = 0, j = 0;
   i = get(s, ch);
   j = get(s, ch1);
   if (i != j)
       return false;
   return chk(s, ch);
}
int main()
{
   cout << "Enter input in stack :-";
   stack<char> s;
   input(s);
   char ch = s.top();
   if (chk(s, ch))
       cout
               << "true\n";
   else
       cout << "false\n";
}
//Logic-2
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
void push(string s, stack<char> &st, int &i, char ch)
{
    if (s[i] != ch)
        return;
    st.push(s[i]);
    i += 1;
    push(s, st, i, ch);
}
void pop(string &s, stack<char> &st, int &i, char ch)
{
    if (s[i] == ch || i == s.size())
        return;
    st.pop();
    i += 1;
    pop(s, st, i, ch);
}
bool chk(string s, stack<char> &st, char ch)
{
    static int i = 0;
    if (i == s.size())
    {
        i = 0;
        return true;
    }
    push(s, st, i, ch);
    pop(s, st, i, ch);
    if (!st.empty())
        return false;
    return chk(s, st, ch);
}
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    if (chk(s, st, s[0]))
        cout << "true\n";
    else
        cout << "false\n";
}
