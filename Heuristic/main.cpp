#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T& x, T y) { if (x < y)x = y; }
template<class T>void chmin(T& x, T y) { if (x > y)x = y; }


const int TryMax = 255000;
class Solve {
private:
    vector<int> X, Y;
    int N;
    vector<int> ans;
    double Score(vector<int> points) {       //OK
        double ret = 0;
        rep(i, N) {
            ret += dist(points[i], points[i + 1]);
        }
        return ret;
    }
    int random(int a, int b) {
        int rnd = rand();
        return a + rnd % (b - a + 1);
    }
    double RandDouble() {
        return 1.0 * rand() / RAND_MAX;
    }
    double dist(int i, int j) {
        return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
    }
    void Show() {
        for (auto a : ans)cout << a + 1 << endl;
    }
    void Easy(){
        rep(i,N)ans.push_back(i);
    }
    void Greedy() {
        int now = 0;
        vector<bool> vis(N, false);
        ans.push_back(0);
        vis[0] = true;
        rep(i, N - 1) {
            int cur = INF;
            int res = -1;
            rep(nex, N) {
                if (vis[nex])continue;
                if (dist(now, nex) < cur) {
                    cur = dist(now, nex);
                    res = nex;
                }
            }
            ans.push_back(res);
            vis[res] = true;
            now = res;
        }
        ans.push_back(0);
    }
    void Climb() {
        int q = TryMax;
        int currentMax = Score(ans);
        //cout<<currentMax<<endl;
        while (q--) {
            int L = random(1, N);
            int R = random(1, N);
            if (R < L)swap(L, R);
            reverse(ans.begin() + L, ans.begin() + R);
            int ChangedScore = Score(ans);
            if (currentMax > ChangedScore) {
                reverse(ans.begin() + L, ans.begin() + R);
            }
            else {
                currentMax = ChangedScore;
            }
        }
        //cout<<currentMax<<endl;
    }
    void Yakinamasi() {
        //cout<<Score(ans)<<endl;
        int CurrentMax = Score(ans);
        for (int t = 1; t <= TryMax; t++) {
            int L = random(1, N);
            int R = random(1, N);
            if (L > R)swap(L, R);
            reverse(ans.begin() + L, ans.begin() + R);

            double NewScore = Score(ans);

            double T = 10.00 - 9.00 * t / TryMax;
            double difference = (CurrentMax-NewScore)/T;
            double P = exp(min(0.0,difference));
            if(RandDouble()<P)CurrentMax=NewScore;
            else reverse(ans.begin()+L,ans.begin()+R);
        }
    }
public:

    void Scan(int _N) {      //OK
        X.resize(_N), Y.resize(_N);
        N = _N;
        rep(i, N) {
            cin >> X[i] >> Y[i];
        }
    }
    void solve() {
        //Climb();
        Greedy();
        Climb();
        Yakinamasi();
        Show();
        //cout<<Score(ans)<<endl;
        //cout<<1e6/Score(ans)<<endl;
        //cout<<time<<endl;
    }
};
int main() {
    int N;
    cin >> N;
    Solve solver;
    solver.Scan(N);
    solver.solve();
}