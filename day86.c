int mySqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return mid;

        if (mid * mid < n) {
            ans = mid;      // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", mySqrt(n));

    return 0;
}
