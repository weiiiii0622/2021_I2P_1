#include <stdio.h>

int N, count, die;
int nums[301];
int status[301];

void find(int, int);
void bubble_sort(int*);

int main(){


    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }

    bubble_sort(nums);

    find(nums[N-1], N-1);

    for(int i=0; i<N; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    for(int i=0; i<N; i++){
        printf("%d ", status[i]);
    }
    printf("\n");

    if(count != N-1){
        printf("%d\n", die);
    }
    else{
        for(int i=0; i<N-1; i++){
            if(status[i] == 0){
                printf("%d\n", nums[i]);
                break;
            }
        }
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

void find(int target, int location){
    
    if(count == N-1){
        return;
    }

    int left=0;
    int right = location-1;
    int temp_count=0;

    while(left < right){
        if(status[right] == 1){
            right--;
        }
        else if(status[left] == 1){
            left++;
        }
        else{
            int x = target-nums[left]-nums[right];
            if(x == 0){
                status[location] = 1;
                status[left] = 1;
                status[right] = 1;
                count += 3;
                temp_count += 1;
                printf("left=(%d,%d),right=(%d,%d),tar=(%d,%d)\n", left,nums[left],right,nums[right],location,nums[location]);
                
                for(int i=0; i<N; i++){
                    printf("%d ", nums[i]);
                }
                printf("\n");

                for(int i=0; i<N; i++){
                    printf("%d ", status[i]);
                }
                printf("\n");

                int i = location-1;
                while(status[i] != 0 && i>=2){
                    i--;
                }
                if(i >= 2){
                    find(nums[i], i);
                }

                if(count < N-1){
                    count -= 3;
                    status[location] = 0;
                    status[left] = 0;
                    status[right] = 0;
                    left++;
                    right--;
                    temp_count--;
                }
            }
            else if(x > 0){
                left++;
            }
            else if(x < 0){
                right--;
            }
        }

    }

    if(temp_count == 0){
        die = target;
    }
    
    return ;
}