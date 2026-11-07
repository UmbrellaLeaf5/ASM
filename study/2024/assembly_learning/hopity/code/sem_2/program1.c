float sum_elements(float arr[], unsigned length)
{
    float result = 0;
    for(int i = 0; i <= length - 1; ++i)
        result += arr[i];
    return result;
}