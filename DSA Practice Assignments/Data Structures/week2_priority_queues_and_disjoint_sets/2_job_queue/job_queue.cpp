#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>

using namespace std;


class JobQueue {
    private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {
	  assigned_workers_.resize(jobs_.size());
	  start_times_.resize(jobs_.size());

	  auto cmp = [](const pair<int, long long> left, const pair<int, long long> right) {
		  if ((left.second) == (right.second))
			  return (left.first > right.first);
		  else
              return ((left.second) > (right.second));
      };

	  std::priority_queue<pair<int, long long>, vector< pair<int, long long> >, decltype(cmp)> worker_finish_time(cmp);

	  for (int i = 0; i < jobs_.size(); ++i) {
		  int duration = jobs_[i];
		  int next_worker = 0;
		  pair<int, long long> min_worker_finish_time_pair;
		  if (worker_finish_time.size() < num_workers_) {
			  min_worker_finish_time_pair = make_pair(i, 0);
		  }
		  else
		  {
			  min_worker_finish_time_pair = worker_finish_time.top();
			  worker_finish_time.pop();
		  }
		  next_worker = min_worker_finish_time_pair.first;

		  assigned_workers_[i] = next_worker;
		  start_times_[i] = min_worker_finish_time_pair.second;
		  worker_finish_time.push(make_pair(next_worker, (min_worker_finish_time_pair.second + duration)));
	  }
  }


    public:
        void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
