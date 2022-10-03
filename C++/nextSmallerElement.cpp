#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Brutforce Approach 
void nextSmallerElement(int* arr, int n, vector<int>& ans) {
    for (int i = 0; i < n; i++) {
        int next = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                next = arr[j];
                break;
            }
        }
        ans.push_back(next);
    }
}

// Optimized solution
vector<int> nextSmallerElement2(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    int size = arr.size();
    vector<int> result(size);
    for (int i = size - 1; i >= 0; i--) {
        int item = arr[i];
        while (st.top() >= item) {
            st.pop();
        }
        // result.push_back(st.top());
        result[i] = st.top();
        st.push(item);
    }
    return result;
}

// prev smaller element
vector<int> prevSmallerElement2(vector<int>& arr) {
    stack<int> st;
    st.push(-1);
    int size = arr.size();
    vector<int> result(size);
    for (int i = 0; i < size; i++) {
        int item = arr[i];
        while (st.top() >= item) {
            st.pop();
        }
        // result.push_back(st.top());
        result[i] = st.top();
        st.push(item);
    }
    return result;
}

int main() {
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(4);
    vect.push_back(3);
    vector<int> result = prevSmallerElement2(vect);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}