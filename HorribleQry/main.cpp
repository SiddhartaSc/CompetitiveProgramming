#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

template <
	typename T,
	typename U,
	template <typename> class apply_range,
	class monoid_operator = std::plus<T>,
	class update_composition = std::plus<U>
>
class SegmentTreeRangeUpdates {
	const T identity;
	const U update_identity;

	struct Node {
		int x, y;
		T v;
		U p;
		std::shared_ptr<Node> l, r;

		Node(int x, int y, const T &v, const U &id) : x(x), y(y), v(v), p(id) {};
	};

	const monoid_operator op = monoid_operator();
	const update_composition compose = update_composition();
	const apply_range<Node> ap = apply_range<Node>();

	std::shared_ptr<Node> root = nullptr;

	std::shared_ptr<Node> build_st(int x, int y, const std::vector<T> &a){
		if (x == y)
			return std::make_shared<Node>(x, y, a[x], update_identity);

		auto node = std::make_shared<Node>(x, y, identity, update_identity);
		node->l = build_st(x, (x+y)/2, a);
		node->r = build_st((x+y)/2+1, y, a);
		node->v = op(node->l->v, node->r->v);

		return node;
	}

	void push(const std::shared_ptr<Node> &node){
		node->v = ap(node->p, node);

		if (node->x != node->y){
			node->l->p = compose(node->p, node->l->p);
			node->r->p = compose(node->p, node->r->p);
		}

		node->p = update_identity;
	}

	T query_st(const std::shared_ptr<Node> &node, int l, int r){
		push(node);

		if (node->y < l || r < node->x)
			return identity;

		if (l <= node->x && node->y <= r)
			return node->v;

		return op(
			query_st(node->l, l, r),
			query_st(node->r, l, r)
		);
	}

	void update_st_range(const std::shared_ptr<Node> &node, int l, int r, const U &u){
		push(node);

		if (r < node->x || node->y < l)
			return;

		if (l <= node->x && node->y <= r){
			node->p = u;
			push(node);
			return;
		}

		update_st_range(node->l, l, r, u);
		update_st_range(node->r, l, r, u);

		node->v = op(node->l->v, node->r->v);
	}

public:
	SegmentTreeRangeUpdates(const std::vector<T> &a, T idT = T(), U idU = U())
		: identity(idT), update_identity(idU) {
		root = build_st(0, a.size()-1, a);
	}

	T query(int l, int r){
		return query_st(root, l, r);
	}

	void update(int l, int r, const U &u){
		update_st_range(root, l, r, u);
	}
};

#include <cstdio>

typedef long long ll;

using namespace std;

struct update {
	int type;
	ll v; // type 0 = sum, type 1 = replace
	update(int t, ll v) : type(t), v(v) {}
};

template <typename node>
struct apply_range {
	ll operator () (const update &u, const shared_ptr<node> &n) const {
		int L = n->y - n->x + 1;

		if (u.type == 1)
			return u.v * L;

		return
			n->v + u.v * L;
	}
};

struct add {
	ll operator () (const ll &a, const ll &b) const {
		return a + b;
	}
};

struct compose {
	update operator () (update a, update b) const {
		if (a.type == 1) return a;
		b.v += a.v;
		return b;
	}
};

long long T, N, Q;

int main(){
	scanf("%lld", &T);

	while ( T-- ) {
		scanf("%lld %lld", &N, &Q);

		vector<ll> v(N);

		for (int i = 0; i < N; i++){
			scanf("%lld", &v[i]);
		}

		SegmentTreeRangeUpdates<ll,update,apply_range,add,compose> st(v, 0, 0);

            //printf("%lld\n", st.query(x, y).snd);
			//st.update(x, y, update(op == 0, val));
	}
}
