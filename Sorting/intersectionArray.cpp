class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0;
        bool flag=false;
        std::vector<int> v;
        
        //Using two pointers i and j over the two arrays which helps
        //in storing the elements which are present in both the arrays.
        while (i < n && j < m)
        {
            //Updating the pointer i if we have identical 
            //elements at consecutive position in arr1.
            if (i > 0 && arr1[i-1] == arr1[i])
            {
                i++;
                continue;
            }
            
            //Comparing element of the arrays arr1 and arr2 at pointers
            //i and j and storing only the elements which are present in
            //both the arrays and updating the pointers.
            if (arr1[i] < arr2[j])
                i++;
            else if (arr2[j] < arr1[i])
                j++;
            else
            {
                v.push_back(arr2[j]);
                flag=true;
                i++; 
                j++;
            }
        }
        
        //If no common element is present in both arrays,
        //we store -1 in the list.
        if(flag==false)
            v.push_back(-1);
            
        //returning the list containing the intersection of the two arrays.    
        return v;
    }
};