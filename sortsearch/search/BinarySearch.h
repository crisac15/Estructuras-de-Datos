#include "ISearch.h"

class BinarySearch : public ISearch
{
public:
    BinarySearch()
    {
    }
    int search(List<int> *pNumberList, int pKey)
    {
        int low = 0;
        int high = pNumberList->getSize();

        int i = 0;

        while (low <= high)
        {
            i++;
            int mid = low + (high - low) / 2;

            if (*pNumberList->find(mid) == pKey)
            {
                return mid;
            }
            else if (*pNumberList->find(mid) < pKey)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            if (mid <= high)
            {
                return -1;
            }
        }
        return -1;
    }
};