//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
     bool static comp(Item a, Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1>r2;
}
    public:

    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        
        int curr_weight = 0;
        double final_profit = 0.0;
        
        for(int i=0;i<n;i++){
            if(curr_weight+arr[i].weight <= W){
                curr_weight += arr[i].weight;
                final_profit += arr[i].value;
            }
            else{
                int remain = W-curr_weight;
                final_profit += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return final_profit;
    }
        
};
