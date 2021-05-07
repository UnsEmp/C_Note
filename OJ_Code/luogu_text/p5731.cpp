#include <cstdio>
#include <set>
using namespace std;
int main()
{
    set<int> st;
    set<int>::iterator it;
    for(int i = 1;i <= 5;i++){
        st.insert(i); 
    }
    st.clear();
    printf("%d",st.size());
    return 0;
}