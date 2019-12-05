//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/475/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
bool isPrime(ll n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
ll power(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a;
	ll tmp = power(a, k >> 1);
	tmp = (tmp * tmp) % MOD;
	return k % 2 ? (tmp * a) % MOD : tmp;
}
string int_to_string(int n)
{
	string res = "";
	while(n / 10 > 0)
	{
		res += n % 10 + '0';
		n /= 10;
	}
	res += n % 10 + '0';
	string ans = "";
	for(int i = res.size() - 1; i >= 0; i--)
		ans += res[i];
	return ans;
}
ll string_to_int(string s)
{
	ll res = 0;
	for(int i = 0; i < s.size(); i++)
		res += (s[i] - '0') * power(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}
 
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<int> g[n * m];
	string hor, ver;
	cin>>hor>>ver;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			if(hor[i] == '<') g[i * m + j + 1].pb(i * m + j);
			else g[i * m + j].pb(i * m + j + 1);
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n - 1; j++){
			if(ver[i] == 'v') g[j * m + i].pb((j + 1) * m + i);
			else g[(j + 1) * m + i].pb(j * m + i);
		}
	}

	int res = 0;
	for(int i = 0; i < n * m; i++){
		int tmp = 1;
		queue<int> q;
		vector<bool> visited(n * m);
		q.push(i);
		visited[i] = true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(!visited[x]){
					visited[x] = true;
					tmp++;
					q.push(x);
				}
			}
		}
		if(tmp == n * m) res++;
	}
	if(res == n * m) cout<<"YES\n";
	else cout<<"NO\n";
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}
