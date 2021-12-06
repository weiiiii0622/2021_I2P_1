#include <stdio.h>

int N, count, die;
int nums[50];
int status[50];

int find(int, int, int);
void bubble_sort(int*);

int main(){


    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    bubble_sort(nums);

    for(int i=N-1; i>=0; i--){
        if(status[i] == 0){
            find(nums[i], i, i-1);
        }
    }

    for(int i=0; i<N; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    for(int i=0; i<N; i++){
        printf("%d ", status[i]);
        // if(status[i] == 0){
        //     printf("%d\n", nums[i]);
        //     break;
        // }
    }

    return 0;
}

void bubble_sort(int* arr){
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int find(int target, int location, int right){
    printf("hi\n");
    int left=0;
    int temp_count=0;
    while(left < right){
        int x = target-nums[left]-nums[right];
        if(x == 0){
            status[location] = 1;
            status[left] = 1;
            status[right] = 1;
            count += 3;
            temp_count += 1;
            for(int i=right-1; i>=2; i--){
                if(status[i] == 0){
                    find(nums[i], i, i-1);
                }
            }

        }
        else if(x > 0){
            left++;
        }
        else if(x < 0){
            right--;
        }
    }

    if(temp_count == 0){
        die = target;
    }
    
    return 0;
}