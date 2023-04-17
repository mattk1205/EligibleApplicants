#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> BestApplicants(const vector<pair<float, float> >& applicants);

vector<int> naiveBestApplicants(const vector<pair<float, float> >& applicants)
{
   vector<int> sol;

   for (int i = 0; i < applicants.size(); i++)
	{
	    bool eligible = true;
	    for (int j = 0; j < applicants.size(); j++)
		{
		   if ((i != j) && (applicants[i].first < applicants[j].first) && (applicants[i].second > applicants[j].second))
			{
			    eligible = false;
			    break;
			}
		}
	    if (eligible)
		sol.push_back(i);
	}
   return sol;
}

int main(int argc, char** argv)
{
  int n;


  ifstream ifile(argv[1]);
  vector<pair<float, float> > applicants;

  ifile >> n;

  cout << "n : " << n << endl;
  for (int i = 0; i < n; i++)
	{
  	   float p, q;
	   ifile >> p >> q;
	   applicants.push_back(make_pair(p, q));
	}

    auto start_time = std::chrono::high_resolution_clock::now();
    vector<int> sol = naiveBestApplicants(applicants);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();


  cout << "Solution for Naive : ";
  for (int i = 0; i < sol.size(); i++)
	cout << sol[i] << " ";
    cout << endl << "Time:" << duration << endl;


    auto start_time2 = std::chrono::high_resolution_clock::now();
    vector<int> sol2 = BestApplicants(applicants);
    auto end_time2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2).count();

  cout << "Solution for Recursive : ";
  for (int i = 0; i < sol2.size(); i++)
	cout << sol2[i] << " ";
  cout << endl << "Time" << duration2 << endl;

  return 0;
}
