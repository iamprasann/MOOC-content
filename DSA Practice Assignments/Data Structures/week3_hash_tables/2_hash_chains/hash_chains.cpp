#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::cin;

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {

    int bucket_count;
    vector<list<string>> elems;

    size_t hash_func(const string& s) const {
        static const size_t x = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * x + s[i]) % prime;
        return hash % bucket_count;
    }

    public:
    explicit QueryProcessor(int bucket_count) {
		this->bucket_count = bucket_count;
		list<string> l;
		for (size_t i = 0; i < bucket_count; i++)
		{
			this->elems.push_back(l);
		}
	}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        /*if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }*/

        if (query.type == "check") {
			if (query.ind < elems.size()) {
				auto L = elems[query.ind];
				for (auto s : L)
					std::cout << s << " ";
				std::cout << endl;
			}
        }
        else{
            int hash_idx=hash_func(query.s);
            auto it = std::find(elems[hash_idx].begin(), elems[hash_idx].end(), query.s);
            if (query.type == "find")
				writeSearchResult(it != elems[hash_idx].end());
			else if (query.type == "add") {
				if (it == elems[hash_idx].end())
					elems[hash_idx].push_front(query.s);
			}
			else if (query.type == "del") {
				if (it != elems[hash_idx].end())
					elems[hash_idx].erase(it);
			}
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
