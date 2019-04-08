template <typename T>
bool my_binary_search(T* arr, int arr_size, T val)
{
	int left = 0, right = arr_size - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == val)
			return true;
		else if (arr[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}