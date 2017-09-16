#include <iostream>
using namespace std;
 /* ����������ζ����Ʊ��λ����ͬ������
 * 
 * @param m ����m
 * @param n ����n
 * @return ����
 */
int countBitDiff(int m, int n)
{
    int diff = m ^ n;
    
    int count = 0;
    while (diff) {
        diff = diff & (diff - 1);
        ++count;
    }
    
    return count;

}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << countBitDiff(m, n) << '\n';

    return 0;
}
