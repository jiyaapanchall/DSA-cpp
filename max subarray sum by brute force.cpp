for(int i = 0; i < n; i++) {

    int sum = 0;

    for(int j = i; j < n; j++) {

        sum += arr[j];

        maxSum = max(maxSum, sum);
    }
}