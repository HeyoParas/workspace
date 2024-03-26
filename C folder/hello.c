int trap(int* arr, int n){
    int i,max=0,water=0,a,maxin;
    for(i=0;i<n;i++)
        if(max<=arr[i]){
            max=arr[i];
            maxin=i;
        }
    a=arr[0];
    for(i=0;i<=maxin ;i++){
        if(a>=arr[i])
            water+=a-arr[i];
        else{
            a=arr[i];
        }
    }
    a=arr[n-1];
    for(i=n-1;i>=maxin;i--){
        if(a>=arr[i])
            water+=a-arr[i];
        else
            a=arr[i];
    }
    return water;
}