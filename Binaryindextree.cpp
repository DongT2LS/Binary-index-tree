#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
int n,a[100000],h[100000],res;
 
using namespace std;
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    h[1] = 1; res = 1;
    for(int i=2;i<=n;i++){
        if(a[i] < a[h[1]]){
            h[1] = i;
        }
        else
        if(a[i] > a[h[res]]){
            res++;
            h[res] = i;
        }
        else{
            int l = 1 , r = res;
            while(l < r){
                int mid = (l+r+1)/2;
                if(a[i] > a[h[mid]])
                    l = mid;
                else
                    r = mid - 1;
            }
            int mid = l;
            if(a[i] > a[h[mid]] and a[i] < a[h[mid+1]])
                h[mid+1] = i;
        }
    }
    printf("%d",res);
    return 0;
} 
