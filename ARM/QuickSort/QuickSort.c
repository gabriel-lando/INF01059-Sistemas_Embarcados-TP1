#define MAX 50

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

 
int main(){
	int vetor[MAX] = {35, 66, 78, 97, 70, 18, 42, 3, 65, 16, 59, 23, 31, 16, 82, 10, 29, 50, 26, 73, 73, 75, 51, 39, 29, 99, 12, 16, 33, 91, 57, 43, 74, 74, 97, 41, 47, 20, 9, 96, 63, 25, 7, 1, 95, 89, 59, 37, 91, 74};
    
	quick_sort(vetor, 0, MAX - 1);

	return 0;
}


