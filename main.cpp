#include <iostream>
																		//Krewn Solotions//Febuary 2013
using namespace std;													//I could call classes but this is all about containment
int i,j,ki,kj,k;														//no need to reinitialize on each loop, as oposed to the arrays & const ints.
int main(){top:
    bool b=1;
    cout<<"##################################"<<endl<<"<############SQUARE##############>"<<endl<<"##################################";
    cout<<endl<<"Enter size:";cin>>k;                       			//Hello my Name is Kevin's row reducer I like to row reduce square matricies.
    const int n=k;														//allows for arrays to change size on each go through
    double lam[n];														//array for eigen values //**Code Incomplete**// find a purpose. live to excecute what you need to do
    double u[n];														//utility
    int t[n];															//utility, for switching ints.
    int rop[n];															//row of piviot in jth column
    int cop[n];															//column of piviot in jth row
    for(k=0;k<n;k++){rop[k]=n;cop[k]=n;}								//fill rop and cop with ineligible values.
    double det=1;														//determinate has to start somewhere.
    double a[n][n];														//This is the matrix
    double I[n][n];														//This will become the inverse if invertable
    for(k=0;k<7;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                switch(k){
                case 0://read
                    cout<<"A("<<i<<","<<j<<"):";
                    cin>>a[i][j];
                    if(i==j){I[i][j]=1;}
                    else if(1){I[i][j]=0;}
                    if(i==n-1&&j==n-1){cout<<endl;}
                    break;
                case 1:one://write a
                    if(a[i][j]==-0){a[i][j]=0;}
                    cout<<a[i][j];
                    if(j<n-1){cout<<",";}
                    else if(1){cout<<";"<<endl;}
                    break;
                case 2:two://write i
                    if(i==0&&j==0){for(kj=0;kj<n;kj++){cout<<"##";}cout<<endl;}
                    if(I[i][j]==-0){I[i][j]=0;}
                    cout<<I[i][j];
                    if(j<n-1){cout<<",";}
                    else if(1){cout<<";"<<endl;}
                    if(i==n-1&&j==n-1){cout<<endl;}
                    break;
                case 3://reduce
                    if(a[i][j]&&rop[j]==n&&cop[i]==n){					//find a value
                        rop[j]=i;cop[i]=j;								//put a box around it
                        det=det*a[i][j];								//factor it out
                        for(ki=0;ki<n;ki++)
                        {lam[ki]=a[ki][j];}
                        for(kj=n-1;kj>=0;kj--){
                            a[i][kj]/=lam[i];
                            I[i][kj]/=lam[i];							//everything done to a is tracked on I
                            for(ki=0;ki<n;ki++){						//for all the rows
                                if(cop[ki]<cop[i]||cop[ki]==n){			//if the row has a pivot to the left of current box or no pivot
                                    a[ki][kj]-=a[i][kj]*lam[ki];		//clear the column
                                    I[ki][kj]-=I[i][kj]*lam[ki];		//&track
                                }}}}
                    break;
                case 4:													//echelon & find determinate
                    switch(i){
                    case 0:
                        if(cop[j]==n){det=0;}							//if any columns don't have pivots, det=0
                    case 1:
                        if(det!=0){
                            if(j!=rop[j]){								//a pivot for each column should be in each row.
                                for(kj=0;kj<n;kj++){
                                    lam[kj]=a[j][kj];
                                    u[kj]=I[j][kj];
                                    a[j][kj]=a[rop[j]][kj];
                                    I[j][kj]=I[rop[j]][kj];
                                    a[rop[j]][kj]=lam[kj];
                                    I[rop[j]][kj]=u[kj];
                                    }
                                    det*=-1;							//switch rows untill there in the right order.
                                t[0]=cop[j];
                                t[1]=rop[cop[j]];
                                cop[j]=j;
                                cop[rop[j]]=t[0];
                                rop[t[0]]=t[0];
                                rop[j]=j;
                                }}}
                        break;
                case 5:goto one;										//print anwser
                case 6:goto two;										//print inverse
}}}}
cout<<"determinate="<<det<<endl;										//print determinate

goto top;
}
