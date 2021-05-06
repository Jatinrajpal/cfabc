#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
// #define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define vv(type)        vector<vector<type>>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define db(x)             cout<<x<<" "
#define db1(x)             cout<<x<<"\n"
#define db2(x,y)         cout<<x<<" "<<y<<"\n"
#define db3(x,y,z)         cout<<x<<" "<<y<<" "<<z<<"\n"
#define rep(i,n)         for(int i=0;i<(n);++i)
#define repA(i,a,n)     for(int i=a;i<=(n);++i)
#define repD(i,a,n)     for(int i=a;i>=(n);--i)
#define so(a)             sort(a.begin(),a.end())
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
// to find all local maximaa and minima in O(n)
    // for (int i=1;i<=n;i++)
    //    {
    //        if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
    //       ans.push_back(p[i]);
    //    }
int dx[] = { -1, 1, -1, 0, 0, -1, 1, 1 };
int dy[] = { -1, -1, 1, -1, 1, 0, 0, 1 };
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
int modular_expo(int x, int y, int m)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans % m * x % m) % m;
        x = (x % m * x % m) % m;
        y /= 2;
    }
    return ans % m ;
}
int power(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x);
        x *= x;
        y /= 2;
    }
    return ans;
}
void SieveOfEratosthenes(int n,bool prime[])
{
    // bool prime[n + 1];
    memset(prime, true, n);

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
           for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
}
bool isPowerOfFour(unsigned int n)
{
    int count = 0;
 
    /*Check if there is only one bit set in n*/
    if ( n && !(n&(n-1)) )
    {
        /* count 0 bits before set bit */
        while(n > 1)
        {
            n >>= 1;
            count += 1;
        }
 
        /*If count is even then
        return true else false*/
        return (count%2 == 0)? 1 :0;
    }
 
    /* If there are more than 1 bit set
    then n is not a power of 4*/
    return 0;
}
bool is_power_of_4(int x)
{
    // Binary represntation of 3 -> "11"
    int chkbit = 3;
    // Check if the number has only one set bit
    if ((x & (x - 1)) != 0)
        return false;
    // Left-shift the number by 2 bits and check
    // if last two bits are zeros.
    while ((chkbit & x) == 0)
        x >>= 2;
    // Return true iff the last bit is set.
    return ((x & chkbit) == 1);
}
void bfsb(int a,int bdist[],int dist[],int n,vector<int> adj[])
{
    queue<int> q;
    q.push(a);
    bdist[a]=0;
    while(!q.empty())
    {
        // cout<<"d";
        int x=q.front();
        q.pop();
        for(auto i:adj[x])
        {
            if(bdist[i]==-1)
            {
                bdist[i]=bdist[x]+1;
                q.push(i);
            }
        }
    }
}
void bfs(int a,int bdist[],int dist[],int n,vector<int> adj[])
{
    queue<int> q;
    q.push(a);
    dist[a]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto i:adj[x])
        {
            if(dist[i]==-1)
            {
                dist[i]=dist[x]+1;
                q.push(i);
            }
        }
    }
}
void solve()
{

    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
        w(t)
        {
            int n,k,a;
            cin>>n>>k>>a;
            set<int> s;
            vector<int> adj[n+1];
            int dist[n+1]={-1};
            int bdist[n+1]={-1};
            for(int i=0;i<k;i++)
            {
                int v;
                cin>>v;
                s.insert(v);
            }
            for(int i=0;i<n-1;i++)
            {
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            bfs(a,bdist,dist,n,adj);
            // for(auto i:dist)
            // {
            //     cout<<i<<" ";
            // }
            // for(auto i:bdist)
            // {
            //     cout<<i<<" ";
            // }
            
            vector<int> res;

            vector<int> zes;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    bdist[j]=-1;
                }
                bfsb(i,bdist,dist,n,adj);
                int maxi=-INT_MAX;
                int sac=-INT_MAX;
                for(int j=1;j<=n;j++)
                {
                    if(s.find(j)!=s.end())
                    {
                        if(dist[j]-bdist[j]>maxi)
                        {
                            maxi=dist[j]-bdist[j];
                            sac=j;
                        }
                    }
                }
                res.push_back(maxi);
                zes.push_back(sac);
            }
            for(int i=0;i<res.size();i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<"\n";
            for(int i=0;i<zes.size();i++)
            {
                cout<<zes[i]<<" ";
            }
            cout<<"\n";
            
        }

}

int32_t main()
{
        solve();
    return 0;
}
