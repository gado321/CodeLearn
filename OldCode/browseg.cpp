#define sz(a) (int)a.size()
#define FOR(i, a, n) for(int i = a; i <= n; i++)
#define FORD(i, a, n) for(int i = a; i >= n; i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPD(i, n) for(int i = n - 1; i >= 0; i--)
#define ALL(a) a.begin(), a.end()
#define MS(a, i) memset(a, i, sizeof(a))
#define BOST ios_base::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
#define fr front
#define pp pop_back
#define pb push_back
#define puf push_front
#define pof pop_front
#define REV(a) reverse(a.begin(), a.end()) 
#define db(x) cout << #x << " == " << x << endl
#define _ << ", " <<
#define RM RAND_MAX + 1
#define llR (long long)rand()

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
typedef vector<ii> vii;

const int N = (int)3e5 + 7;

int n, x, y;
int root[N];
vi g[N];

void get_root(int u, const int &dif)
{
	queue <int> q;
	q.push(u);
	root[u] = u;

	while(sz(q))
	{
		u = q.front();
		q.pop();
		for(int v : g[u])
		{
			if(v == dif) continue;
			if(!root[v]) 
			{
				root[v] = root[u];
				q.push(v);
			}
			if(root[v] == dif)
			{
				root[v] = -1;
				q.push(v);
			}
		}	
	}
}

int main()
{
    freopen("browseg.inp","r",stdin);
    freopen("browseg.out","w",stdout);

    cin >> n >> x >> y;
    REP(i, n - 1)
    {
    	int u, v; cin >> u >> v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    get_root(y, x);
    get_root(x, y);

    int cntx = 0, cnty = 0;
    FOR(i, 1, n)
    {
    	cntx += (root[i] == x);
    	cnty += (root[i] == y);
    }	

    cout << ll(ll(n - 1) * (ll)n) - ll((ll)cntx * (ll)cnty);

    return 0;
}
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		adj[u].push_back(v);	
		adj[v].push_back(u);
	}
	maxi = (long long)(n * n( - 1));
	
	return 0;
}