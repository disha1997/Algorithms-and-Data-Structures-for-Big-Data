 
// Online C compiler to run C program online
 #include<stdio.h>

int a[7] = {1,9,6,4,2,7,5};
int b[7] = {0,0,0,0,0,0,0};

Merge(int low, int mid, int high)
{
    int h,i,j;
	h = low; 
	i = low;
	j = mid+1;
	int k;
   // printf("mid in merge=%d low %d, high %d \n",mid,low,high);
	while((h <= mid)&& (j <= high)) {
		if(a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		}
		else {
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if(h > mid)
	{
		for (k=j;j<=high;j++) {
			b[i] = a[k];
			i++;
		}
	}
	else {
		for (k=h;k<= mid;k++) {
			b[i] = a[k];
			i++;
		}
	}
	for (k=low;k<=high;k++) 
		a[k] = b[k];
} 

Merge_Sort(int low, int high)
{   int mid;
	if(low <  high)
	{
		mid = (low + high) / 2;
			//printf("mid =%d , low %dhigh %d\n",mid,low,high);
		Merge_Sort(low, mid);
		Merge_Sort(mid+1, high);
		Merge(low, mid, high);
	}
	return;
}

int main(){
	int i=0;
	Merge_Sort(0,6);
	for(i=0;i<7;i++){
		printf("%d",a[i]);
	}
}
