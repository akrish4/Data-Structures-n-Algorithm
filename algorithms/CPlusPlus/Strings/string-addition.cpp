#include<bits/stdc++.h>
using namespace std;

string findSum(string X, string Y) {
    string ans="";
       int n=X.size();
       int m=Y.size();
       reverse(X.begin(),X.end());
       reverse(Y.begin(),Y.end());
       int i=0;
       int j=0;
       
       int carry=0;
       while(i<n and j<m)
       {
           int sum=(X[i]-'0')+(Y[j]-'0')+carry;
           carry=sum/10;
           ans+=to_string(sum%10);
           i++;
           j++;
       }
       while(i<n)
       {
           int sum=(X[i]-'0')+carry;
           carry=sum/10;
           ans+=to_string(sum%10);
           i++;
       }
       while(j<m)
       {
           int sum=(Y[j]-'0')+carry;
           carry=sum/10;
           ans+=to_string(sum%10);
           j++;
       }
       while(carry>0)
       {
           ans+=to_string(carry%10);
           carry=carry/10;
       }
       reverse(ans.begin(),ans.end());
       int pos=0;
       for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='0')
                pos++;
            else
                break;
        }
        if(pos==0)
        {
            return ans.substr(pos);
        }
       return ans.substr(pos);
    }

    int main()
    {
        string a="111";
        string b="999";
        cout<<findSum(a,b);
    }