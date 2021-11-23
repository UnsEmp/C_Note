#include <cstdio>
using namespace std;
int main()
{
    int Ga1,Si1,Kn1,Ga2,Si2,Kn2;
    scanf("%d.%d.%d %d.%d.%d",&Ga1,&Si1,&Kn1,&Ga2,&Si2,&Kn2);
    printf("%d.%d.%d",Ga1 + Ga2 + ((Si1 + Si2 + ((Kn1 + Kn2) / 29)) / 17),(Si1 + Si2 + ((Kn1 + Kn2) / 29)) % 17,(Kn1 + Kn2) % 29);
    return 0;
}