#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// a b cip_sk a_poz
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    ll N, pak=1, r=1, pos=0, pirm=1, cipari=2;
    bool tri = false;
    cin >> N;
    while(1) {
        if(N>9*9*pak) {
            if(pak==1 && N>9*9*4050000225000000 && !tri) {
                N -= 9*9*4050000225000000;
                tri = true;
                pak = 89999999;
                cipari = 89999999;
            }
            else {
                N -=(9*9*pak);
                if(pak==1) pak+=2;
                else ++pak;
                ++cipari;
            }
            //cout << "cipari - " << cipari << " N:" << N << " katra:" << 9*pak << endl;
        }
        else if(N>9*pak) {
            int cips = N/(9*pak);
            N -= cips*(9*pak);
            r+=cips;
            //cout << "r - " << r << " N:" << N << endl;
        }
        else {
            //cout << "N: " << N << " r:" << r << " pak:" << pak << "\n";
            if(cipari==2) {
                if(N<=r){
                    cout << r << " " << N-1 << " " << cipari << " " << 1;// << " /1.";
                    return 0;
                }
                else {
                    cout << r << " " << N << " " << cipari << " " << 1;// << " /2.";
                    return 0;
                }
            }
            while(1) {
                ll oo, atl;
                oo = N/2;
                atl = N%2;
                if(oo < r || (oo==r && atl==0)) {
                    if(atl==0) {
                        oo--;
                        cout << oo << " " << r << " " << cipari << " " << 2;// << " 1.eks";
                        return 0;
                    }
                    else {
                        cout << r << " " << oo << " " << cipari << " " << 1;// << " 2.eks";
                        return 0;
                    }
                }
                else {
                    N -= 2*r;
                }

                oo = N/r;
                atl = N%r;
                //cout << "Mazie: N=" << N << " oo=" << oo << " atl=" << atl << endl;
                atl--;
                if(atl<0) {oo--; atl=r-1;}
                if(oo < pak-2) {
                    if(oo==0) {
                        cout << atl << " " << r << " " << cipari << " " << 3;// << " /3.1";
                        return 0;
                    }
                    else {
                        cout << atl << " " << r << " " << cipari << " " << 3+oo;// << " /3.2";
                        return 0;
                    }
                }
                else {
                    N -= r*(pak-2);
                }

                oo=N/(9-r);
                atl=N%(9-r);
                //cout << "Lielie: N=" << N << " oo=" << oo << " atl=" << atl << " r=" << r << endl;
                if(atl==0) {oo--; atl=(9-r);}
                if(oo < (pak-2)) {
                    cout << r+atl << " " << r << " " << cipari << " " << cipari-oo;// << " /4.1";
                    return 0;
                }
                else {
                    N -= (pak-2)*(9-r);
                    oo = N/2;
                    atl = N%2;
                    if(atl==0) {
                        oo--;
                        cout << r << " " << r+1+oo << " " << cipari << " " << 1;// << " 3.eks";
                        return 0;
                    }
                    else {
                        cout << r+1+oo << " " << r << " " << cipari << " " << 2;// << " 4.eks";
                        return 0;
                    }

                }
            }
        }
    }
    return 0;
}
