#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
//  Count

//  count(begin, end, value): 범위 내에 포함되어 있는 원소 중에서 value의 개수를 찾는다
//  count_if(begin, end, p): 범위 내에 포함되어 있는 원소 중에서 조건 p에 해당하는 것의 개수를 찾는다
//  O(N)
    vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
    for (int i=1; i<=5; i++) {
        cout << i << ": " << count(a.begin(), a.end(), i); cout << '\n';
    }
    int even = count_if(a.begin(), a.end(), [](int x) {
        return x % 2 == 0;
    });

// Fill

// fill(begin, end, value): 범위만큼 value 값으로 채운다.
// 주로 다음 Test case로 넘어가기전에 vector 를 초기화 할 때 사용…
// O(N)
//    vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
    fill(a.begin(), a.end(), 0);
    for (int x : a) {
        cout << x << ' ';
    }


// Rotate

// rotate(begin, mid, end): 범위 내 원소들을 mid를 기준으로 왼쪽으로 회전시킨다
// begin에는 mid에 있던 값이 end-1에는 mid-1에 들어있던 값이 들어간다
// O(N)
    vector<int> b = {0, 1, 2, 3, 4, 5};
    rotate(b.begin(), b.begin()+2, b.end());
    for (int x : b) {
        cout << x << ' '; // 0 1 2 3 4 5 ==> 2 3 4 5 0 1
    }

// Sort

// sort(begin, end): 범위 내 원소들을 <를 기준으로 정렬한다.
// sort(begin, end, cmp): 범위 내 원소들을 cmp를 기준으로 정렬한다.
    int n;
    cout<<"\ninput value: ";
    scanf("%d",&n);
    vector<pair<int,int>> a1(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a1[i].first,&a1[i].second);
    }
    sort(a.begin(),a.end());
    for (int i=0; i<a.size(); i++) {
        printf("%d %d\n",a1[i].first, a1[i].second);
    }

//  min/max

    // min(a, b);
    // min(a, b, cmp);
    // min(initializer_list);
    // min(initializer_list, cmp);
    // max(a, b);
    // max(a, b, cmp);
    // max(initializer_list);
    // max(initializer_list, cmp);


// 그 외

// binary_search
// binary_search(begin, end, value): 범위 내에서 value를 찾으면 true, 못 찾으면 false
// binary_search(begin, end, value, cmp): 범위 내에서 value를 cmp를 기준으로 찾으면 true, 못 찾으면 false

// swap
// swap(a, b): a와 b에 들어있던 값을 바꾼다

// reverse
// reverse(begin, end) 범위 내 원소들의 순서를 역순으로 만든다
// O(N)

// find
// find(begin, end, value): 범위 내에 포함되어 있는 원소 중에서 value의 iterator
// find_if(begin, end, p): 범위 내에 포함되어 있는 원소 중에서 조건 p에 해당하는 것의 iterator
// 못 찾으면 end를 리턴
// O(N)
}