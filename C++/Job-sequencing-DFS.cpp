struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n , [](const Job &a , const Job &b){return a.dead!=b.dead?a.dead<b.dead : a.profit>b.profit;});
        priority_queue<int,vector<int> , greater<int>> q;
        int prof = 0;int max_prof = 0;
        int cur_time = 0;
        for(int i =0;i<n;i++)
        {
            if(arr[i].dead>=cur_time+1)
            {
                prof+=arr[i].profit;
                q.push(arr[i].profit);
                cur_time++;
            }
            else
            {
                if(arr[i].profit>q.top())
                {
                    prof+=arr[i].profit-q.top();
                    q.pop();
                    q.push(arr[i].profit);
                }
            }
            max_prof = max(max_prof , prof);
        }
        return {q.size() , max_prof};
    } 
};
