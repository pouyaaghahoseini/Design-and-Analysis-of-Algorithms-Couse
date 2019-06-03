#include <iostream>
using namespace std;
long int Arr[1000000];
long int size;
long int counter = 0;

void merge(long int *a,long int beggining, long int middle, long int end,long int &counter){
    long int i,j,k;
    long int l_size=middle - beggining +1;
    long int r_size=end - middle;
    long int left[l_size];
    long int right[r_size];
    for(i=0; i<l_size; i++)
        left[i]=a[i+beggining];
    for(j=0; j<r_size; j++)
        right[j]=a[j+middle+1];
    i=0;
    j=0;
    k=beggining;
    while (i<l_size && j<r_size){
        if (left[i] < right[j]){
            a[k]=left[i];
            i++;
            k++;
        }
        else if (left[i] >= right[j]){
            counter += l_size-i;
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while (i<l_size){
        a[k]=left[i];
        i++;
        k++;
    }
    while (j<r_size){
        a[k]=right[j];
        j++;
        k++;
    }
};
void mergesort(long int *a, long int b, long int e,long int &c) {
    long int mid;
    if (b < e) {
        mid = (b + e) / 2;
        mergesort(a, b, mid, c);
        mergesort(a, mid + 1, e, c);
        merge(a, b, mid, e, c);
    }
}
int main() {
    cin>>size;
    for (long int i=0; i<size; i++)
        cin>>Arr[i];
    mergesort(Arr,0,size-1,counter);
//    for (int i=0; i<size; i++)
//        cout<<Arr[i];
//    cout<<endl;
    counter = counter % 1000000007;
    cout<<counter;

}
