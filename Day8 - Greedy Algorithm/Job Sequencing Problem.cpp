/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
  vector<int> JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      vector<int> slot(maxi+1, -1);

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         int pos = arr[i].dead;
         while(pos>0 && slot[pos]!=-1){
             pos --;
         }
            if (pos>0) {
               slot[pos] = i;
               countJobs++;
               jobProfit += arr[i].profit;
            }
         
      }

      return {countJobs, jobProfit};
   }
};
